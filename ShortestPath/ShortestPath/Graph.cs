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

        public Graph(Node origin, params Node[] destinations)
        {
            _origin = origin;
            if (destinations != null)
            {
                _points = new List<Node>();
                _points.AddRange(destinations);
            }
        }

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

        public void ComputeShortestPathBruteForce()
        {
            List<List<Node>> allPossiblePaths = ComputeAllPaths(_points);

            List<Tuple<List<Node>, double>> allPathsWithLengths = new List<Tuple<List<Node>, double>>();

            foreach (List<Node> pathway in allPossiblePaths)
            {
                Arc aOne = new Arc(_origin, pathway[0]);
                Arc aTwo = new Arc(pathway[0], pathway[1]);
                Arc aThree = new Arc(pathway[1], pathway[2]);
                Arc aFour = new Arc(pathway[2], pathway[3]);
                double length = aOne.Length + aTwo.Length + aThree.Length + aFour.Length;

                allPathsWithLengths.Add(new Tuple<List<Node>, double>(pathway, length));
            }

            NumArcLengthsComputedAndSorted = allPossiblePaths.Count*4;

            allPathsWithLengths.Sort((x, y) => x.Item2.CompareTo(y.Item2));
            _shortestPath = allPathsWithLengths[0].Item1;
        }

        public List<List<Node>> ComputeAllPaths(List<Node> points = null)
        {
            if (points == null)
                points = _points;

            int numPoints = points.Count;

            if (numPoints == 2) // base case
            {
                var firstList = new List<Node>(2);
                firstList.Add(points[0]);
                firstList.Add(points[1]);
                var secondList = new List<Node>(2);
                secondList.Add(points[1]);
                secondList.Add(points[0]);

                var resultLists = new List<List<Node>>(2);
                resultLists.Add(firstList);
                resultLists.Add(secondList);

                return resultLists;
            }
            else // recursive case
            {
                var resultLists = new List<List<Node>>();

                for (int i = 0; i < numPoints; i++)
                {
                    Node ni = points[i];

                    var subList = from pt in points // find the remaining Nodes in caller's list
                                  where pt != ni
                                  select pt;
                    var subLists = ComputeAllPaths(subList.ToList()); // make recursive call
                    foreach(var seq in subLists)
                    {
                        var currList = new List<Node>();
                        currList.Add(ni);
                        currList.AddRange(seq);
                        resultLists.Add(currList);
                    }
                }

                return resultLists;   
            }
        }
    }
}
