using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_38
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Ejercicio Nº39 Guía 2017";
            SobreSobreescrito sobreSobrecarga = new SobreSobreescrito();

            Console.WriteLine("Propiedad: {0}", sobreSobrecarga.MiPropiedad);
            Console.WriteLine("Metodo: {0}", sobreSobrecarga.MiMetodo());
            
            Console.ReadKey();
        }
    }
}
