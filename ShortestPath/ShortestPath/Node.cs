using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ShortestPath
{
    public class Node
    {
        public double X { get; set; }
        public double Y { get; set; }

        public Node(double x, double y)
        {
            X = x;
            Y = y;
        }
    }
}
