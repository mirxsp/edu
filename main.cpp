#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <string>
#define _USE_MATH_DEFINES
using namespace std;


const double CHAR_RATIO=2;
const int BUFFER_LENGTH = 100;
const int BUFFER_HEIGHT = 100/CHAR_RATIO;
int MAX_INS = 0;
int buffer[BUFFER_HEIGHT+1][BUFFER_LENGTH+1]{};

struct PNT{
    double X;
    double Y;
    PNT()
    {
        this->X = 0;
        this->Y = 0;
    }
    PNT(double x,double y)
    {
        this->X=x;
        this->Y=y;
    }
};



PNT areaS(0,0),areaE(0,0);

typedef bool(*dCh)(PNT,double*);

void PNTToBuf(PNT p){
    int x =(p.X-areaS.X)/(areaE.X-areaS.X)*BUFFER_LENGTH;
    int y =(p.Y-areaS.Y)/(areaE.Y-areaS.Y)*BUFFER_HEIGHT;
    if(x<0)x=0;
    if(y<0)y=0;
    buffer[y][x]++;
    if(buffer[y][x]>MAX_INS)MAX_INS=buffer[y][x];
}

//Polygon x opt

bool polyIDI(PNT dot,double* options)
{
    int j = options[0];
    bool isInside = 0;
    for(int i = 1;i<=options[0];i++)
    {
        PNT eS(options[i*2-1],options[i*2]),eE(options[j*2-1],options[j*2]);
        if((eS.Y>dot.Y != eE.Y>dot.Y) && eS.X+(dot.Y-eS.Y)/(eE.Y-eS.Y)*(eE.X-eS.X)>(dot.X)){

            isInside=!isInside;
        }
        j = i;
    }
    return isInside;
}

//Circle 1 opt


bool circIDI(PNT dot,double* options){
    double x = dot.X,y=dot.Y,r=options[0];
    return (x*x+y*y)<=r*r;
}

//Lissajous 2 opt

bool lisIDI(PNT dot,double* options)
{
    double lsjb = options[1],lsja = options[0];
    bool isInside = 0;
    double period = M_PI/lsjb;
    double t = asin(dot.Y)/lsjb,x;
    for(int d = 0;d<2*lsjb;d++){
        x = sin(lsja*(t+period*d)+M_PI/2);
        if(dot.X>x)isInside=!isInside;
    }
    return isInside;
}
//
double areaCount(dCh func,int itt,double* opt)
{
    int dotsInside = 0;
    for(int i = 0;i<itt;i++)
    {
        PNT rnd;
        rnd.X = areaS.X+(rand()*1.0/RAND_MAX)*(areaE.X-areaS.X);
        rnd.Y = areaS.Y+(rand()*1.0/RAND_MAX)*(areaE.Y-areaS.Y);
        if(func(rnd,opt)){
            dotsInside++;
            PNTToBuf(rnd);
        }
    }
    return dotsInside*1.0/itt*(areaE.X-areaS.X)*(areaE.Y-areaS.Y);
}
//visual
HANDLE hnd = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int a,int b)
{
    SetConsoleTextAttribute(hnd,(WORD)(a|b<<4));
}

void outputBuf()
{
    for(int i = BUFFER_HEIGHT;i>=0;i--)
    {
        for(int j = 0;j<BUFFER_LENGTH;j++)
        {
            int in = buffer[i][j];
            if(in==0)setColor(0,0);
            else if(in>=MAX_INS*0.9)setColor(3,0);
            else if(in>=MAX_INS*0.7)setColor(9,0);
            else if(in>=MAX_INS*0.4)setColor(1,0);
            else setColor(7,0);
            cout << (char)178;
            setColor(7,0);
        }
        cout << endl;
    }
}

int main(int argc,char *argv[])
{
    srand(time(NULL));
    const int itt = 1000000;
    int mode = stoi(argv[1]);
    double* options;
    if(mode>=3)
    {
        cout << "Using: " << argv[0] << "[mode] [params]"<<endl;
        return 0;
    }
    if(mode==0)
    {
        int psize = stoi(argv[2]);
        options = new double[psize*2+1];
        options[0]=psize;
        PNT mx(0,0),mn(1,1);
        for(int i = 1;i<=psize;i++)
        {
            double genX=rand()*1.0/RAND_MAX;
            double genY=rand()*1.0/RAND_MAX;
            if(mn.X>genX)mn.X=genX;
            if(mn.Y>genY)mn.Y=genY;
            if(mx.X<genX)mx.X=genX;
            if(mx.Y<genY)mx.Y=genY;;
            options[i*2-1]=genX;
            options[i*2]=genY;
            //cout << "(" << genX << "," << genY<< ")" << endl;
        }
        areaS = mn;
        areaE = mx;
        cout<<"AREA="<<areaCount(polyIDI,itt,options) << endl;
    }
    if(mode==1)
    {
        double radius = stoi(argv[2]);
        options=new double[1];
        options[0]=radius;
        PNT mn(-radius,-radius);
        PNT mx(radius,radius);
        areaS = mn;
        areaE = mx;
        cout << "AREA=" << areaCount(circIDI,itt,options) << endl;
    }
    if(mode==2){
        double a = stoi(argv[2]),b=stoi(argv[3]);
        options=new double[2];
        options[0]=a;
        options[1]=b;
        PNT mn(-1,-1);
        PNT mx(1,1);
        areaS = mn;
        areaE = mx;
        cout << "AREA=" << areaCount(lisIDI,itt,options) << endl;
    }
    setColor(3,0);cout << ">=" << (INT)(MAX_INS*0.9) << endl;
    setColor(9,0);cout << ">=" << (INT)(MAX_INS*0.7) << endl;
    setColor(1,0);cout << ">=" << (INT)(MAX_INS*0.4) << endl;
    setColor(7,0);cout << ">0 && <" << (INT)(MAX_INS*0.4) << endl;
    setColor(7,0);
    outputBuf();
    return 0;
}

////struct POLYGON{
////    int psize;
////    PNT* vertex;
////    POLYGON(int n)
////    {
////        this->psize=n;
////        vertex = new PNT[n];
////    }
////};


////struct LISSAJOUS{
////    double a,b,A,B,delta;
////    LISSAJOUS(double ia,double ib)
////    {
////        this->a = ia;
////        this->b = ib;
////        this->delta = M_PI/2;
////        this->B = 1;
////        this->A = 1;
////    }
////};


////struct CIRCLE{
////    double radius;
////    CIRCLE(double rd){
////        this->radius=rd;
////    }
////};
