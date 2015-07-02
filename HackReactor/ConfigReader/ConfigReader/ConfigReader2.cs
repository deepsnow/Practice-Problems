using System;
using System.Collections.Generic;
using System.IO;
using ADG.DependencyInjection;
using Moq;
using NUnit.Framework;

namespace ConfigReader
{
    public class ConfigReader2
    {
        private Dictionary<string, string> settings;
        private string configFilePath;

        public ConfigReader2(string filePath)
        {
            settings = new Dictionary<string, string>();
            configFilePath = filePath;
        }

        public void ReadConfigFile()
        {
            try
            {
                using (var sr = ServiceLocator.Get<IStreamReader>()) // decouple the file system dependency with a dependency injection container
                {
                    sr.Init(configFilePath);
                    String line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        var substrings = line.Split(',');
                        settings.Add(substrings[0], substrings[1]);
                    }
                }
            }
            catch (Exception e)
            {
                throw new Exception(string.Format("Error accessing config file \'{0}\'. Error message: {1}", configFilePath, e.Message));
            }
        }
    }

    public interface IStreamReader : IDisposable
    {
        string ReadLine();
        void Init(string filePath);
    }

    public class ConfigStreamReader : IStreamReader
    {
        private StreamReader sr;
        
        public void Init(string filePath)
        {
            sr = new StreamReader(filePath);
        }

        public string ReadLine()
        {
            return sr.ReadLine();
        }

        public void Dispose()
        {
            sr.Dispose();
        }
    }

    [TestFixture]
    public class ConfigReader2Tests
    {
        private Mock<IStreamReader> mockReader;
        private readonly string phonyFilePath = @"C:\phony\file\path.txt";

        [SetUp]
        public void Init()
        {
            mockReader = new Mock<IStreamReader>();
            ServiceContainer.RegisterInstance(mockReader.Object);
        }

        [Test]
        public void ReadConfigFile_FileOpenedAndContentsRead()
        {
            mockReader.Setup(x => x.Init(It.IsAny<string>()));
            mockReader.Setup(y => y.ReadLine());
            mockReader.Setup(z => z.Dispose()); // confirms that Dispose() call is made implicity via the using statement

            var cr = new ConfigReader2(phonyFilePath);
            cr.ReadConfigFile();
            
            mockReader.VerifyAll();
        }

        [Test]
        public void ReadConfigFile_FileOpenFailed_ExceptionThrown()
        {
            mockReader.Setup(x => x.Init(It.IsAny<string>())).Throws<Exception>();
            var cr = new ConfigReader2(phonyFilePath);
            bool result = false;

            try
            {
                cr.ReadConfigFile();
            }
            catch (Exception exc)
            {
                if (exc.Message.Contains(phonyFilePath))
                    result = true;
            }
            
            Assert.True(result);
        }
    }
}

