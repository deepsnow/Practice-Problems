using System;
//using System.Collections.Generic;
//using System.Linq;
//using System.Text;

namespace google_string_reverse
{
    class Program
    {
        static void Main(string[] args)
        {
            //char[] input = new char[] {'i','n','p','u','t'};
            string input = "doug is working hard";
            System.Console.WriteLine(input);
            char[] output = Reverse(input.ToCharArray(), input.Length);
            System.Console.WriteLine(output);

            input = "oneword";
            System.Console.WriteLine(input);
            output = Reverse(input.ToCharArray(), input.Length);
            System.Console.WriteLine(output);

            input = "two words";
            System.Console.WriteLine(input);
            output = Reverse(input.ToCharArray(), input.Length);
            System.Console.WriteLine(output);

            input = "";
            System.Console.WriteLine("empty str: " + input);
            output = Reverse(input.ToCharArray(), input.Length);
            System.Console.WriteLine(output);
        }

        static char[] Reverse(char[] input, int input_length)
        {
            char[] result = new char[input_length];
            int curr_r_boundary = input_length-1;
            int curr_result_index = 0;

            for (int i = input_length-1; i >= 0; i--)
            {
                if (input[i] == ' ')
                {
                    for (int j = i + 1; j <= curr_r_boundary; j++)
                    {
                        result[curr_result_index] = input[j];
                        curr_result_index++;
                    }
                    result[curr_result_index] = ' ';
                    curr_result_index++;
                    curr_r_boundary = i-1;
                }
                if (i == 0)
                {
                    for (int j = i; j <= curr_r_boundary; j++)
                    {
                        result[curr_result_index] = input[j];
                        curr_result_index++;
                    }
                }
            }
            
            return result; 
        }
    }
}
