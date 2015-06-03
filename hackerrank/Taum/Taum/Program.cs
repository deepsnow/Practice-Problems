using System;

namespace Taum
{
    class Program
    {
        static void Main(string[] args)
        {
            var shopper = new Shopper();
            var ri = new ReadInput();
            long numTestCases = ri.ReadNumCases();
            for (long i=0; i<numTestCases; i++)
            {
                var sl = ri.ReadNextCase();
                Console.WriteLine(shopper.ComputeLowestCost(sl));
            }
        }
    }

    class Shopper
    {
        public long ComputeLowestCost(ShoppingList sl)
        {
            long bCost = (sl.B*sl.X);
            long bCostAlt = (sl.B * (sl.Y + sl.Z));
            if (bCostAlt < bCost)
                bCost = bCostAlt;

            long wCost = (sl.W * sl.Y);
            long wCostAlt = (sl.W * (sl.X+ sl.Z));
            if (wCostAlt < wCost)
                wCost = wCostAlt;

            return bCost + wCost;
        }
    }

    class ReadInput
    {
        private long GetIntVal(string strVal)
        {
            return Int64.Parse(strVal);
        }

        public long ReadNumCases()
        {
            return GetIntVal(Console.ReadLine());
        }

        public ShoppingList ReadNextCase()
        {
            var sl = new ShoppingList();
            var line1 = Console.ReadLine().Split(' ');
            sl.B = GetIntVal(line1[0]);
            sl.W = GetIntVal(line1[1]);
            var line2 = Console.ReadLine().Split(' ');
            sl.X = GetIntVal(line2[0]);
            sl.Y = GetIntVal(line2[1]);
            sl.Z = GetIntVal(line2[2]);

            return sl;
        }
    }

    class ShoppingList
    {
        public long B;
        public long W;
        public long X;
        public long Y;
        public long Z;
    }
}
