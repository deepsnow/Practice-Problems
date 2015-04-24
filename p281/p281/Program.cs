using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace p281
{
    class Program
    {
        static int Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Improper arguments passed on the command line:");
                string args_rep = string.Empty;
                args.ToList().ForEach(arg => { args_rep += (arg + " "); });
                if (args_rep.Length > 0)
                    Console.WriteLine(args_rep);
                Console.WriteLine();
                Console.WriteLine("Usage example:");
                Console.WriteLine("p281.exe 10.0 1.0");
                return 1;
            }

            double hypotenuse_length = 0.0;
            double velocity = 0.0;
            
            bool parseLen = double.TryParse(args[0], out hypotenuse_length);
            if (!parseLen)
            {
                Console.WriteLine("Could not parse hypotenuse length: {0}", args[0]);
            }
            bool parseVelocity = double.TryParse(args[1], out velocity);
            if (!parseVelocity)
            {
                Console.WriteLine("Could not parse Speed: {0}", args[1]);
            }

            double xval = hypotenuse_length;
            double yval = 0.0;
            double prev_yval = 0.0;
            double count = 0.0;
            double delta = 0.0;

            while (xval > (hypotenuse_length / 2.0))
            {
                xval = hypotenuse_length - (velocity * (++count));
                yval = Math.Round(
                    Math.Sqrt((hypotenuse_length * hypotenuse_length) - (xval * xval))
                    , 2);
                delta = Math.Round(yval - prev_yval, 2);
                Console.WriteLine("xval: {0:F2}\tyval: {1:F2}\tdelta: {2:F2}", xval, yval, delta);
                prev_yval = yval;
            }

            return 0;
        }
    }
}
