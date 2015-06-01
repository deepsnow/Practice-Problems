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
            int result = Int32.MaxValue;

            List<string> progValues = apStr.Split(' ').ToList();
            int valCount = progValues.Count;

            int A = GetIntVal(progValues[0]);
            int B = GetIntVal(progValues[1]);
            int C = GetIntVal(progValues[2]);
            int D = GetIntVal(progValues[3]);

            int deltaAB = B - A;
            int deltaBC = C - B;
            int deltaCD = D - C;

            if ((deltaAB == deltaBC) && (deltaBC == deltaCD))
            {
                int prevValue = D;
                for (int i = 4; i < valCount; i++)
                {
                    int currValue = GetIntVal(progValues[i]);
                    if (currValue != (prevValue + deltaCD))
                        result = prevValue + deltaCD;
                    prevValue = currValue;
                }
            }
            else
            {
                if (deltaAB == deltaBC)
                {
                    result = C + deltaAB;
                }
                else if (deltaAB == deltaCD)
                {
                    result = C - deltaCD;
                }
                else
                {
                    result = B - deltaBC;
                }
            }

            return result;
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

        [Test]
        public void FindMissingNumber_SecondInput_AnomalyFound()
        {
            var f = new ApAnomalyFinder(new ReadInputsSecond());
            int answer = f.FindMissingNumber();
            Assert.AreEqual(answer, 3);
        }

        [Test]
        public void FindMissingNumber_ThirdInput_AnomalyFound()
        {
            var f = new ApAnomalyFinder(new ReadInputsThird());
            int answer = f.FindMissingNumber();
            Assert.AreEqual(answer, 5);
        }

        [Test]
        public void FindMissingNumber_FourthInput_AnomalyFound()
        {
            var f = new ApAnomalyFinder(new ReadInputsFourth());
            int answer = f.FindMissingNumber();
            Assert.AreEqual(answer, 20);
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

    class ReadInputsSecond : IReadInputs
    {
        public int GetNumInputs()
        {
            return 5;
        }

        public string GetApString()
        {
            return "1 5 7 9 11";
        }
    }

    class ReadInputsThird : IReadInputs
    {
        public int GetNumInputs()
        {
            return 5;
        }

        public string GetApString()
        {
            return "1 3 7 9 11";
        }
    }

    class ReadInputsFourth : IReadInputs
    {
        public int GetNumInputs()
        {
            return 8;
        }

        public string GetApString()
        {
            return "-16 -10 -4 2 8 14 26 32";
        }
    }
}
