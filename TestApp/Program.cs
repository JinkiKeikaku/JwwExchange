using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TestApp {
    static class Program {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main() {
            //string MyPath = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetEntryAssembly().Location);
            //var b = NativeDllDir.Set(MyPath + @"\x86", MyPath + @"\x64");
            string assemblyDir = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
            AppDomain.CurrentDomain.AssemblyResolve += (_, e) => {
                if (e.Name.StartsWith("JwwHelper,", StringComparison.OrdinalIgnoreCase)) {
                    string fileName = Path.Combine(assemblyDir,
                    string.Format("JwwHelper_{0}.dll", (IntPtr.Size == 4) ? "x86" : "x64"));
                    Debug.WriteLine($"LoadAssembly::{fileName}");
                    return Assembly.LoadFile(fileName);
                }
                return null;
            };

            Application.SetHighDpiMode(HighDpiMode.SystemAware);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
