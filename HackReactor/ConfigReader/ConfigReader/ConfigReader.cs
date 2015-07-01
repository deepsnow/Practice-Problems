using System;
using System.Collections.Generic;
using System.IO;
using NUnit.Framework;

namespace ConfigReader
{
    public class ConfigReader
    {
        private Dictionary<string, string> settings;
        private string configFilePath;

        public ConfigReader(string filePath)
        {
            settings = new Dictionary<string, string>();
            configFilePath = filePath;
        }

        public void ReadConfigFile()
        {
            try
            {
                using (StreamReader sr = new StreamReader(configFilePath)) // file system dependency!!!
                {
                    String line;
                    while ((line = sr.ReadLine()) != null) // file system dependency!!!
                    {
                        var substrings = line.Split(',');
                        settings.Add(substrings[0], substrings[1]);
                    }
                }
            }
            catch (Exception e)
            {
                throw new Exception(string.Format("Error config file \'{0}\'. Error message: {1}", configFilePath, e.Message));
            }
        }
    }

    [TestFixture]
    public class ConfigReaderTests
    {
        [Test]
        public void ReadConfigFile_FileOpenedAndContentsRead()
        {
            var cr = new ConfigReader(@"C:\phony\file\path.txt");
            cr.ReadConfigFile();
            
            // Problems:
            // 1- This test will almost certainly fail wherever it's executed because the phony file path will be found not to exist, which will cause an exception to be thrown.
            // 2- Even if an exception were not thrown, we have no way to ensure that StreamReader's ReadLine() and Dispose() methods are called as they must be.
            //      (Dispose() is called implicitely by the using statement.)
        }
    }
}
