using System;

namespace StrangeGrid
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = new ReadInput().ReadLine();
            
            bool rIsEven = ((input.R % 2) == 0);
            long rowFactor = 0;
            long colFactor = 0;
            if (rIsEven)
            {
                rowFactor = ((input.R - 2)/2);
                colFactor = 1;
            }
            else
            {
                rowFactor = ((input.R - 1) / 2);
            }

            long result = (10 * rowFactor) + (((input.C - 1) * 2) + colFactor);

            Console.WriteLine(result);
        }
    }

    class ReadInput
    {
        public long GetLongValue(string valStr)
        {
            return Int64.Parse(valStr);
        }

        public Input ReadLine()
        {
            var line = Console.ReadLine();
            var nums = line.Split(' ');
            var input = new Input();
            input.R = GetLongValue(nums[0]);
            input.C = GetLongValue(nums[1]);

            return input;
        }
    }

    class Input
    {
        public long C;
        public long R;
    }
}
