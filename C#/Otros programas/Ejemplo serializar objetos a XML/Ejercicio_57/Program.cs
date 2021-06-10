using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_57
{
    class Program
    {
        static void Main(string[] args)
        {
            Persona persona = new Persona("Ezequiel", "Lisca");
            Persona leerPersona;

            Persona.Guardar(persona);
            Console.WriteLine("Se guardo una persona.");
            leerPersona = Persona.Leer("personas.xml");
            Console.WriteLine("Se leyo una persona en otra instancia.");
            Console.Write(leerPersona.ToString());
            Console.ReadKey();
        }
    }
}
