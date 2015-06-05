using System;
using System.Collections.Generic;

namespace JimSkyscrapers
{
    class Program
    {
        static void Main(string[] args)
        {
            var ri = new ReadInput();
            long numScrapers = ri.ReadNumScrapers();
            List<long> heights = ri.ReadScraperHeights();
            List<Tuple<int, int>> paths = new List<Tuple<int, int>>();

            for (int i=0; i<numScrapers; i++)
            {
                long currH = heights[i];

                for (int j=(i+1); j<numScrapers; j++)
                {
                    if (heights[j] > currH)
                        break;
                    if (heights[j] == currH)
                        paths.Add(new Tuple<int, int>(i+1, j+1));
                }
            }

            Console.WriteLine(paths.Count * 2);
        }
    }

    class ReadInput
    {
        public long GetLongValue(string valStr)
        {
            return Int64.Parse(valStr);
        }

        public long ReadNumScrapers()
        {
            return GetLongValue(Console.ReadLine());
        }

        public List<long> ReadScraperHeights()
        {
            var line = Console.ReadLine();
            var nums = line.Split(' ');
            var heights = new List<long>();
            foreach (var height in nums)
            {
                heights.Add(GetLongValue(height));
            }
            return heights;
        }
    }
}
