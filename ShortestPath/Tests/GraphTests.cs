using System;
using System.Collections.Generic;
using NUnit.Framework;
using ShortestPath;

namespace Tests
{
    [TestFixture]
    public class GraphTests
    {
        private Node Origin { get; set; }
        private Node NodeA { get; set; }
        private Node NodeB { get; set; }
        private Node NodeC { get; set; }
        private Node NodeD { get; set; }
        private Graph SampleGraph { get; set; }

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

        [SetUp]
        private void Init()
        {
            Origin = new Node(0, 0);
            NodeA = new Node(-10, 5);      // sqrt(125)
            NodeB = new Node(-8, 7);       // sqrt(113)
            NodeC = new Node(1, 11);       // sqrt(122)
            NodeD = new Node(12, 9);       // sqrt(225)
            SampleGraph = new Graph(Origin, NodeA, NodeB, NodeC, NodeD); 
        }

        [Test]
        public void TestMostProximatePoint()
        {
            Assert.True(SampleGraph.GetMostProximate().Equals(NodeB));
        }

        [Test]
        public void TestComputeShortestPath()
        {
            SampleGraph.ComputeShortestPath();

            Assert.True(SampleGraph.ShortestPath.Count == 4);

            Assert.AreEqual(NodeB, SampleGraph.ShortestPath[0]);
            Assert.AreEqual(NodeA, SampleGraph.ShortestPath[1]);
            Assert.AreEqual(NodeC, SampleGraph.ShortestPath[2]);
            Assert.AreEqual(NodeD, SampleGraph.ShortestPath[3]);

            Console.WriteLine("Results from Djikstra's Algorithm:");
            Console.WriteLine("Num times computed most proximate Node: {0}", SampleGraph.GetMostProximateCallCount);
            Console.WriteLine("Num arc lengths computed and sorted across the above calculations: {0}", SampleGraph.NumArcLengthsComputedAndSorted);
        }

        //[Test]
        //public void TestComputeShortestPathBruteForce()
        //{
        //    SampleGraph.ComputeShortestPathBruteForce();

        //    Assert.True(SampleGraph.ShortestPath.Count == 4);

        //    Assert.AreEqual(NodeB, SampleGraph.ShortestPath[0]);
        //    Assert.AreEqual(NodeA, SampleGraph.ShortestPath[1]);
        //    Assert.AreEqual(NodeC, SampleGraph.ShortestPath[2]);
        //    Assert.AreEqual(NodeD, SampleGraph.ShortestPath[3]);

        //    Console.WriteLine("Results from brute force approach:");
        //    Console.WriteLine("Num times computed most proximate Node: {0}", SampleGraph.GetMostProximateCallCount);
        //    Console.WriteLine("Num arc lengths computed and sorted across the above calculations: {0}", SampleGraph.NumArcLengthsComputedAndSorted);
        //}

        [Test]
        public void TestComputePermutations()
        {
            List<List<Node>> resultLists = SampleGraph.ComputeAllPaths();
            Assert.True(resultLists.Count == 24);

            SampleGraph.ComputeShortestPathBruteForce();

            Assert.True(SampleGraph.ShortestPath.Count == 4);

            Assert.AreEqual(NodeB, SampleGraph.ShortestPath[0]);
            Assert.AreEqual(NodeA, SampleGraph.ShortestPath[1]);
            Assert.AreEqual(NodeC, SampleGraph.ShortestPath[2]);
            Assert.AreEqual(NodeD, SampleGraph.ShortestPath[3]);

            Console.WriteLine("Results from brute force algorithm:");
            Console.WriteLine("Num pathways computed: {0}", resultLists.Count);
            Console.WriteLine("Num arc lengths computed and sorted across the above calculations: {0}", SampleGraph.NumArcLengthsComputedAndSorted);
        }
    }
}
