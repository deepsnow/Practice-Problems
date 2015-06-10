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
            long validPathsCount = 0;
            Skyscraper currScraper = null;

            for (int i = 0; i < numScrapers; i++)
            {
                long currH = heights[i];

                var newScraper = new Skyscraper() { count = 0, height = currH, prevBuilding = null };


                if (currScraper == null)
                {
                    currScraper = newScraper;
                }
                else
                {
                    var iter = currScraper;
                    while (iter != null)
                    {
                        if (currH == iter.height)
                        {
                            iter.count++;
                            validPathsCount += (2 * iter.count);
                            currScraper = iter;
                            break;
                        }
                        else if (currH < iter.height)
                        {
                            newScraper.prevBuilding = iter;
                            currScraper = newScraper;
                            break;
                        }
                        else
                        {
                            if (iter.prevBuilding == null)
                                currScraper = newScraper;
                        }
                        iter = iter.prevBuilding;
                    }
                }
            }

            Console.WriteLine(validPathsCount);
        }
    }

    class Skyscraper
    {
        public long height;
        public long count;
        public Skyscraper prevBuilding;
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
