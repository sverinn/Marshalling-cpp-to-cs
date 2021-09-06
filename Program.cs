using System;
using System.Runtime.InteropServices;

namespace Marshalling
{
    class Program
    {
        internal static class Import
        {
            [DllImport(@"MarshallingDLL.dll")]
            internal static extern IntPtr getData();
        }

        // Declares a managed prototype for unmanaged function.
        [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Unicode)]
        public class pItem
        {
            public int a;

            [MarshalAs(UnmanagedType.LPStr)] //we read const char* 
            public string str;

            public IntPtr items; //store a pointer (as int? no idea what's going on here)
        }

        public static pItem getData()
        {
            pItem testItem = new pItem { a = 0, str = "undefined", items = IntPtr.Zero }; //initialize a pItem
            IntPtr ItemPtr = Import.getData(); //get a pointer from dll
            testItem = Marshal.PtrToStructure<pItem>(ItemPtr); //read data located at a pointer
            return testItem;
        }

        static void Main(string[] args)
        {
            pItem myItem = getData();
            Console.WriteLine(myItem.a.ToString() + "; " + myItem.str + "; " + myItem.items.ToString());
        }
    }
}
