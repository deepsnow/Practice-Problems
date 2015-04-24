using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ShortestPath
{
    public class Node //: IEqualityComparer<Node>
    {
        public double X { get; set; }
        public double Y { get; set; }

        public Node(double x, double y)
        {
            X = x;
            Y = y;
        }

        // See http://msdn.microsoft.com/en-us/library/ms173110(v=vs.100).aspx.
        // I think that I want my unit tests to be based on instance field value compares not on object identity comparisons.
        // So, I've implemented IEqualityComparer<T>. But, in hindsight, I think that wasn't necessary.

        //public bool Equals(Node a, Node b)
        //{
        //    if ((a == null) || (b == null))
        //        return false;

        //    double diffX = Math.Abs(a.X - b.X);
        //    double diffY = Math.Abs(a.Y - b.Y);

        //    //return ((diffX < 0.000000000000001) && (diffY < 0.000000000000001)); // is this threshold too small?
        //    return ((diffX < 0.01) && (diffY < 0.01));
        //}

        //public int GetHashCode(Node a)
        //{
        //    return a.X.GetHashCode();
        //}
    }
}
