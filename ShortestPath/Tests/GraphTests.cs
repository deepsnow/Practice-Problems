using System;
using System.Collections.Generic;
using NUnit.Framework;
using ShortestPath;

namespace Tests
{
    [TestFixture]
    public class GraphTests
    {
        [Test]
        public void TestDistanceCalc()
        {
            Node n1 = new Node(6.8, 4.4);
            Node n2 = new Node(-3.7, -11.2);

            Arc a = new Arc(n1, n2);

            // the Google calculated arc length = (((6.8 - (-3.7)) ^ 2) + ((4.4 - (-11.2)) ^ 2)) ^ (1/2) = 18.8045207331

            double expectedResult = 18.8045207331;
            double diff = Math.Abs(expectedResult - a.Length);

            Assert.True(diff < 0.0000000001); // The expected (previously calculated) value has 10 digits after the decimal place.
            // Therefore, the difference between the computed value and the expected value must be less than 1 * (10 ^ (-10)).
        }

        [Test]
        public void TestMostProximatePoint()
        {
            Node origin = new Node(0, 0);
            Node A = new Node(-10, 5);      // sqrt(125)
            Node B = new Node(-8, 7);       // sqrt(113)
            Node C = new Node(1, 11);       // sqrt(122)
            Node D = new Node(12, 9);       // sqrt(225)

            Graph graph = new Graph(origin, A, B, C, D);

            Assert.True(graph.GetMostProximate() == B);
        }

        [Test]
        public void TestComputeShortestPath()
        {
            Node origin = new Node(0, 0); // should make this a fixture setup
            Node A = new Node(-10, 5);
            Node B = new Node(-8, 7);
            Node C = new Node(1, 11);
            Node D = new Node(12, 9);

            Graph graph = new Graph(origin, A, B, C, D);

            graph.ComputeShortestPath();

            Assert.True(graph.ShortestPath.Count == 4);

            Assert.AreEqual(B, graph.ShortestPath[0]);
            Assert.AreEqual(A, graph.ShortestPath[1]);
            Assert.AreEqual(C, graph.ShortestPath[2]);
            Assert.AreEqual(D, graph.ShortestPath[3]);

            Console.WriteLine("Results from Djikstra's Algorithm:");
            Console.WriteLine("Num times computed most proximate Node: {0}", graph.GetMostProximateCallCount);
            Console.WriteLine("Num arc lengths computed and sorted across the above calculations: {0}", graph.NumArcLengthsComputedAndSorted);
        }
    }
}
