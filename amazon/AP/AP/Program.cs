using System;
using System.Collections.Generic;
using System.Linq;
using NUnit.Framework;

namespace AP
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }

    class ApAnomalyFinder
    {
        private IReadInputs ri;

        public ApAnomalyFinder(IReadInputs reader)
        {
            ri = reader;
        }

        private int GetIntVal(string strVal)
        {
            return Int32.Parse(strVal); // add error handling
        }

        public int FindMissingNumber()
        {
            //int N = ri.GetNumInputs();
            string apStr = ri.GetApString();
            int prevValue = Int32.MaxValue;
            List<ApEntry> deltaInfos = new List<ApEntry>();
            int currPosition = 0;
            int result = Int32.MaxValue;

            List<string> progValues = apStr.Split(' ').ToList();

            foreach (var currValStr in progValues)
            {
                int currValue = GetIntVal(currValStr);
                if (prevValue != Int32.MaxValue)
                {
                    int diff = currValue - prevValue;

                    if (deltaInfos.Count < 3)
                        deltaInfos.Add(new ApEntry() {delta = diff, position = currPosition});
                    if (deltaInfos.Count == 3)
                    {
                        List<int> distinctDeltas = deltaInfos.Select(x => x.delta).Distinct().ToList();

                        if (distinctDeltas.Count == 2)
                        {
                            result = LocateAndReturnMissingValue(deltaInfos, distinctDeltas, progValues);
                            break;
                        }
                        else
                        {
                            //ditch youngest delta and add newest, unless it's different
                        }
                    }
                }

                prevValue = currValue;
                currPosition++;
            }

            return result;
        }

        private int LocateAndReturnMissingValue(List<ApEntry> deltaInfos, List<int> distinctDeltas, List<string> progValues)
        {
            int indexOfAnomalousDelta = 0;
            int indexOfNonAnomDelta = 1;

            int candidateDistinctDelta = distinctDeltas[indexOfAnomalousDelta];
            if (deltaInfos.Where(x => x.delta == candidateDistinctDelta).Count() == 2)
            {
                indexOfAnomalousDelta = 1;
                indexOfNonAnomDelta = 0;
            }
            int anomylousDelta = distinctDeltas[indexOfAnomalousDelta];

            int indexNearAnomalyInAp = deltaInfos.Single(x => x.delta.Equals(anomylousDelta)).position;

            return GetIntVal(progValues[indexNearAnomalyInAp]) - distinctDeltas[indexOfNonAnomDelta];
        }
    }

    class ApEntry
    {
        public int position;
        public int delta;
    }

    [TestFixture]
    class ApAnomalyFinderTests
    {
        [SetUp]
        public void Init()
        {            

        }

        [Test]
        public void FindMissingNumber_HappyPathInput_AnomalyFound()
        {
            var f = new ApAnomalyFinder(new ReadInputsHappyPath());
            int answer = f.FindMissingNumber();
            Assert.AreEqual(answer, 7);
        }
    }

    interface IReadInputs
    {
        int GetNumInputs();
        string GetApString();
    }

    class ReadInputsHappyPath : IReadInputs
    {
        public int GetNumInputs()
        {
            //string numValuesStr = Console.ReadLine(); // replace usage of Console.Readline with a mockable interface after learning/writing lightweight IoC Container
            //return Int32.Parse(numValuesStr); // add error handling

            return 5;
        }

        public string GetApString()
        {
            //return Console.ReadLine(); // ditto: replace with mockable interface
            return "1 3 5 9 11";
        }
    }
}
