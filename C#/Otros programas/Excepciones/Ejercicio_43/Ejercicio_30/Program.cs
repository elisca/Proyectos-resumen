using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Ejercicio_30
{
    class Program
    {
        static void Main(string[] args)
        {
            Competencia abuDhabi = new Competencia(10, 3, TipoCompetencia.F1);
            Competencia monza = new Competencia(5, 1, TipoCompetencia.MotoCross);
            
            AutoF1[] autos = new AutoF1[4];
            MotoCross[] motos = new MotoCross[2];

            autos[0] = new AutoF1(1, "Mc Laren Mercedes", 100);
            autos[1] = new AutoF1(1, "Ferrari", 110);
            autos[2] = new AutoF1(1, "Red Bull Racing", 120);
            autos[3] = new AutoF1(1, "India Forces", 95);

            motos[0] = new MotoCross(1, "Ducati", 600);
            motos[1] = new MotoCross(2, "Ducati", 550);

            try
            {
                if (abuDhabi + motos[0])
                {
                    Console.WriteLine("ERROR: Se pudo agregar una moto a una competencia de F1 y no se lanzó la excepción esperada.");
                }

                Console.WriteLine("{0}", abuDhabi.MostrarDatos());

                foreach (AutoF1 auxAutoF1 in autos)
                {
                    if (abuDhabi + auxAutoF1)
                    {
                        Console.WriteLine("Se pudo agregar un auto a la competencia.");
                        Console.WriteLine("{0}", auxAutoF1.MostrarDatos());
                    }
                    else
                    {
                        Console.WriteLine("No se pudo agregar un auto a la competencia.");
                        Console.WriteLine("{0}", auxAutoF1.MostrarDatos());
                    }
                    Thread.Sleep(1000);
                }

                Console.ReadKey();
                Console.Clear();

                Console.WriteLine("{0}", monza.MostrarDatos());

                if (monza + autos[0])
                {
                    Console.WriteLine("Se pudo agregar un auto F1 a una competencia de Moto Cross.");
                }
                else
                {
                    Console.WriteLine("No se pudo agregar un auto F1 a una competencia de Moto Cross.");
                }

                foreach (MotoCross auxMotoCross in motos)
                {
                    if (monza + auxMotoCross)
                    {
                        Console.WriteLine("Se pudo agregar una moto a la competencia.");
                        Console.WriteLine("{0}", auxMotoCross.MostrarDatos());
                    }
                    else
                    {
                        Console.WriteLine("No se pudo agregar una moto a la competencia.");
                        Console.WriteLine("{0}", auxMotoCross.MostrarDatos());
                    }
                    Thread.Sleep(1000);
                }
            }
            catch (CompetenciaNoDisponibleException cnde2)
            {
                Console.WriteLine(cnde2.ToString());
            }
            finally
            { }

            Console.ReadKey();
        }
    }
}
