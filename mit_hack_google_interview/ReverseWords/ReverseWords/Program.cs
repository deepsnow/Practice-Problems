using NUnit.Framework;

namespace ReverseWords
{
    class Program
    {
        static void Main(string[] args)
        {
        }
    }

    class StringOps
    {
        public void ReverseStringInPlace(char[] theStr, int startIndex, int length)
        {
            bool isLenEven = ((length%2) == 0);
            char temp;

            for (int i = startIndex, j = (length-1); i < j; i++, j--)
            {
                temp = theStr[i];
                theStr[i] = theStr[j];
                theStr[j] = temp;

                if (isLenEven)
                {
                    if (i == (j - 1))
                        break;
                }
                else
                {
                    if (i == (j - 2))
                        break;
                }
            }
        }

        public void ReverseWordsInSentenceInPlace(char[] theStr, int length)
        {
            int beginCurrWord = 0;

            for(int i = 0; i < length; i++)
            {
                if (theStr[i] == ' ')
                {
                    ReverseStringInPlace(theStr, beginCurrWord, i);
                    beginCurrWord = i + 1;
                }
            }

            ReverseStringInPlace(theStr, beginCurrWord, length);
        }
    }

    [TestFixture]
    class StringOpsTests
    {
        [Test]
        public void ReverseStringInPlace_SeussInput_CharReversalSucceeds()
        {
            string input = "the cat in the hat";
            char[] inputArray = input.ToCharArray();
            var so = new StringOps();
            so.ReverseStringInPlace(inputArray, 0, inputArray.Length);
            string output = new string(inputArray);

            Assert.AreEqual(output, "tah eht ni tac eht");
        }

        [Test]
        public void ReverseWordsInSentenceInPlace_SeussInput_WordReversalSucceeds()
        {
            string input = "the cat in the hat";
            char[] inputArray = input.ToCharArray();
            int len = inputArray.Length;
            var so = new StringOps();
            so.ReverseStringInPlace(inputArray, 0, len);
            so.ReverseWordsInSentenceInPlace(inputArray, len);
            string output = new string(inputArray);

            Assert.AreEqual(output, "hat the in cat the");
        }
    }
}
