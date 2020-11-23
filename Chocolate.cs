using System;
using System.Collections.Generic;
using System.Text;

namespace lab3
{
    class Chocolate : Sweet
    {
        public enum Types
        {
            Dark,
            Milk,
            White,
            Mixed
        };
        public Types Type { get; set; }
        public double PalmOilAmount { get; set; }

        public double getPalmOilPercentage()
        {
            return PalmOilAmount / Weight * 100;
        }
    }
}
