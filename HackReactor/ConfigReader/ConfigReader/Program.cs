

using ADG.DependencyInjection;

namespace ConfigReader
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new ConfigStreamReader();
            ServiceContainer.RegisterInstance(sr);

            var reader = new ConfigReader2(@"C:\authentic\file\path.txt");
            reader.ReadConfigFile();
        }
    }
}
