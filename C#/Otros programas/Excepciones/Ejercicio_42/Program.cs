using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_42
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                OtraClase otraClase = new OtraClase();
                otraClase.MetodoInstancia();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);

                if (!object.ReferenceEquals(e.InnerException, null))
                {
                    do
                    {
                        e = e.InnerException;
                        Console.WriteLine(e.Message);
                    } while (!object.ReferenceEquals(e.InnerException, null));
                }
            }

            Console.ReadKey();
        }
    }
}
