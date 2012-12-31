using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ShortestPath
{
    public class Graph
    {
        private List<Node> _points;
        private Node _origin;
        private List<Node> _shortestPath = new List<Node>();

        public List<Node> ShortestPath
        {
            get
            {
                return _shortestPath;
            }
        }

        public int GetMostProximateCallCount { get; private set; }
        public int NumArcLengthsComputedAndSorted { get; private set; }

        public void ComputeShortestPath()
        {
            GetMostProximateCallCount = 0;
            NumArcLengthsComputedAndSorted = 0;

            Node n = GetMostProximatePrivate(_origin, _points);
            while (n != null)
            {
                _shortestPath.Add(n);
                _points.Remove(n);
                n = GetMostProximatePrivate(n, _points);
            }
        }

        private Node GetMostProximatePrivate(Node origin, List<Node> points)
        {
            GetMostProximateCallCount += 1;

            List<Arc> arcLengths = new List<Arc>();
            foreach (Node n in points)
            {
                arcLengths.Add(new Arc(origin, n));
            }
            arcLengths.Sort((x, y) => x.Length.CompareTo(y.Length));
            NumArcLengthsComputedAndSorted += arcLengths.Count;

            return (arcLengths.Count == 0) ? null : arcLengths[0].Destination;
        }

        public Node GetMostProximate()
        {
            return GetMostProximatePrivate(_origin, _points);
        }

        public Graph(Node origin, params Node[] destinations)
        {
            _origin = origin;
            if (destinations != null)
            {
                _points = new List<Node>();
                _points.AddRange(destinations);
            }
        }
    }
}
