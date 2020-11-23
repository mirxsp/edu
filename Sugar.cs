using System;
using System.Collections.Generic;
using System.Text;

namespace lab3
{
    class Sugar : Sweet
    {
        public enum Types
        {
            Noncrystaline, //Homogeneous (hard\chewy)
            Crystaline //Include small crystall (creamy)
        };


        public Types Type { get; set; }
        public double Hardness { get; set; }

    }
}
