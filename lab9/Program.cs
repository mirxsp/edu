using System;
using System.Text;
using System.Text.RegularExpressions;
namespace lab9
{
    class Program
    {
        static void Main(string[] args)
        {

            //string s = "abc bcd ads ajsdf sad";
            //string s1 = "bcf"
            //Console.WriteLine(Regex.IsMatch(s,@"\b"+s1+@"\b",RegexOptions.IgnoreCase));

            //string s = "abc bcd ads ajsdf sad";
            //int n;
            //int.TryParse(Console.ReadLine(), out n);
            //MatchCollection match = Regex.Matches(s, @"\b\w{" + n + @"}\b");
            //foreach(Match m in match)
            //{
            //    Console.WriteLine(m);
            //}

            //string s = "abc x xa dsa xdf b bcd f ads d g  ajsdf sad s d q w";
            //Console.WriteLine(Regex.Replace(s, @"\b\w{1}\b", ""));

            //string s = "Абв Обг гро ртк лет оыыыдв";
            //Console.WriteLine(Regex.Replace(s, @"\b[аиеёоуыэюя][а-я]+\b", "", RegexOptions.IgnoreCase));

            //string s = "Абв asd SD афыв фыовлц ff ааыя zqw";
            //Console.WriteLine(Regex.Replace(s, @"\b[a-z]+\b", "...",RegexOptions.IgnoreCase));

            /*
            string s = "100.4 100.2 100 200 100.4";
            double sum = 0;
            MatchCollection match = Regex.Matches(s, @"\b(\d+\.\d+)\b");
            foreach (Match m in match)
            {
                sum += double.Parse(m.Value);
            }
            String res = Regex.Replace(s, @"\b(\d+\.\d+)\b", "");
            match = Regex.Matches(res, @"\b\d+.{0}\b"); 
            foreach (Match m in match)
            {
               sum += int.Parse(m.Value);
            }
            Console.WriteLine(sum);
            */

            /*
            string s = "My phone number is 12-12-12, but you can use 123-123 or 124-02-22 instead";
            MatchCollection match = Regex.Matches(s, @"(\d{2}-\d{2}-\d{2})|(\d{3}-\d{3})|(\d{2,3}-\d{2}-\d{2})");
            foreach(Match m in match)
            {
                Console.WriteLine(m);
            }
            */

            /*
            string s = "22.12.2002, 20.11.1999, 1.1.1923, 1.1.1888,31.11.1911, 23.12.2024";
            MatchCollection matches = Regex.Matches(s, @"([1-2][0-9]|[1-9]|[3][0-1])\.(1[0-2]|[1-9])\.(19[0-9]{2}|200[0-9]|201[0-2])");
            foreach(Match m in matches)
            {
                Console.WriteLine(m);
            }
            */

            /*
            string s = "mail@asdsad.com asdads@asd asda@ sadsasd asdas asdmams@amil.ow asdasd@mas.";
            MatchCollection matches = Regex.Matches(s, @"\b\w+@\w+\.\w+\b");
            foreach(Match m in matches)
            {
                Console.WriteLine(m);
            }
            */

            
            string s = "00:00:00 24:60:60 7:07:07 24:59:59 25:60:50 23:61:00 23:00:61";
            MatchCollection matches = Regex.Matches(s, @"\b([0-1][0-9]|2[0-4]):([0-5][0-9]|60):([0-5][0-9]|60)\b");
            foreach(Match m in matches)
            {
                Console.WriteLine(m);
            }

            //TASK 1

        }
    }
}
