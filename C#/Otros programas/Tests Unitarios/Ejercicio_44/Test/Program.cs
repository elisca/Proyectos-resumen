using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CentralitaHerencia;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            // Mi central
            Centralita c = new Centralita("Fede Center");
            
            // Mis 4 llamadas
            Local l1 = new Local("Bernal", 30, "Rosario", 2.65f);
            Provincial l2 = new Provincial("Morón", Provincial.Franja.Franja_1, 21, "Bernal");
            Local l3 = new Local("Lanús", 45, "San Rafael", 1.99f);
            Provincial l4 = new Provincial(Provincial.Franja.Franja_3, l2);

            // Las llamadas se irán registrando en la Centralita.
            // La centralita mostrará por pantalla todas las llamadas según las vaya registrando.
            try
            {
                c = c + l1;
                c = c + l2;
                c = c + l3;
                c = c + l4;
                c.OrdenarLlamadas();
                Console.WriteLine(c.ToString());
            }
            catch (CentralitaException ce)
            {
                if (ce.InnerException == null)
                {
                    Console.WriteLine("ERROR: {0} Clase: {1} Método: {2}", ce.Message, ce.NombreClase, ce.NombreMetodo);
                }
                else
                {
                    Console.WriteLine("Orígen del error: {0}", ce.InnerException.Message);
                }
            }
            finally
            {
                Console.ReadKey();
            }
        }
    }
}
