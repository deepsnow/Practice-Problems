using System;

namespace ShortestPath
{
    public class Arc
    {
        private Node source;
        private Node destination;

        private double _length = 0.0;
        public double Length
        {
            get
            {
                if (Math.Abs(_length - 0.0) < 0.001)
                {
                    _length = Math.Sqrt(
                        Math.Pow( (source.X - destination.X), 2 )
                        + Math.Pow( (source.Y - destination.Y), 2 ));
                }
                return _length;
            }
        }

        public Node Destination { get { return destination; } }

        public Arc(Node n1, Node n2)
        {
            source = n1;
            destination = n2;
        }
    }
}
