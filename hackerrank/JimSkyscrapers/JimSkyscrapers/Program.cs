using System;
using System.Collections.Generic;
using System.Linq;

namespace JimSkyscrapers
{
    class Program
    {
        static void Main(string[] args)
        {
            var ri = new ReadInput();
            long numScrapers = ri.ReadNumScrapers();
            List<long> heights = ri.ReadScraperHeights();
            Dictionary<long, long> currNeighbors = new Dictionary<long, long>();
            long validPathsCount = 0;

            for (int i = 0; i < numScrapers; i++)
            {
                long currH = heights[i];
                if (currNeighbors.ContainsKey(currH))
                {
                    currNeighbors[currH] += 1;
                    validPathsCount += (2 * currNeighbors[currH]);
                }
                else
                {
                    currNeighbors.Add(currH, 0);
                }

                foreach (var currKey in currNeighbors.Where(x => x.Key < currH).ToList())
                    currNeighbors.Remove(currKey.Key);
            }

            Console.WriteLine(validPathsCount);
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
