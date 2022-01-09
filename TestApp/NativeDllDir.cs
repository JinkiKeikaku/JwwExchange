using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace TestApp {
    class NativeDllDir {
        /// <summary>
        /// DllImport用に、x86用のDLLのあるディレクトリとx64用のDLLのあるディレクトリを設定します。
        /// </summary>
        /// <param name="x86DllDir">x86環境用のDLLを配置したディレクトリを指定します。指定しなければカレントディレクトリとなります。</param>
        /// <param name="x64DllDir">x64環境用のDLLを配置したディレクトリを指定します。指定しなければカレントディレクトリとなります。</param>
        /// <returns>設定に成功したらtrue。</returns>
        /// <exception cref="PlatformNotSupportedException">x86でもx64でもない場合の例外です。</exception>
        public static bool Set(string x86DllDir = null, string x64DllDir = null) {
            // 既に設定されているものをリセット
            SetDllDirectory(null);

            if (IntPtr.Size == 8) {
                Debug.WriteLine("64bit");
                // 64bitっぽい
                return SetDllDirectory(string.IsNullOrEmpty(x64DllDir) ? "." : x64DllDir);
            }
            if (IntPtr.Size == 4) {
                Debug.WriteLine("32bit");
                // 32bitっぽい
                return SetDllDirectory(string.IsNullOrEmpty(x86DllDir) ? "." : x86DllDir);
            }

            // いずれでもない
            throw new PlatformNotSupportedException();
        }

        [DllImport("kernel32.dll", CharSet = CharSet.Auto, SetLastError = true)]
        private static extern bool SetDllDirectory(string path);
        //[System.Runtime.InteropServices.DllImport("kernel32", SetLastError = true)]
        //private static extern bool SetDllDirectory(string lpPathName);
    }
}
