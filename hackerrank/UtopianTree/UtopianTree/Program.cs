using System;

namespace UtopianTree
{
    class Program
    {
        static void Main(string[] args)
        {
            var ri = new ReadInputsConsole();
            int testCases = ri.GetNumTestCases();
            var utp = new UtopianTreePredictor();
            for (int i = 0; i < testCases; i++)
            {
                int cycles = ri.GetNumCyclesForTestCase();
                Console.WriteLine(utp.ComputeHeightFromCycleCount(cycles));
            }
        }
    }

    class UtopianTreePredictor
    {
        public int ComputeHeightFromCycleCount(int cycles)
        {
            int height = 1;

            for (int i = 0; i < cycles; i++)
            {
                if ((i % 2) == 0)
                    height *= 2;
                else
                    height += 1;
            }

            return height;
        }
    }

    interface IReadInputs
    {
        int GetNumTestCases();
        int GetNumCyclesForTestCase();
    }

    public class ReadInputsBase
    {
        public int GetIntValue(string valStr)
        {
            return Int32.Parse(valStr);
        }
    }

    public class ReadInputsConsole : ReadInputsBase, IReadInputs
    {
        public int GetNumTestCases()
        {
            return GetIntValue(Console.ReadLine());
        }

        public int GetNumCyclesForTestCase()
        {
            return GetIntValue(Console.ReadLine());
        }
    }
}
