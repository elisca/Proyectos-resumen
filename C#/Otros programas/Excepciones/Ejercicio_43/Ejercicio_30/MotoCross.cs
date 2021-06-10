using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    public class MotoCross:VehiculoDeCarrera
    {
        short cilindrada;

        public short Cilindrada
        {
            get 
            {
                return this.cilindrada; 
            }
            set 
            {
                if (value > 0)
                {
                    this.cilindrada = value;
                }
            }
        }

        public override string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine(base.MostrarDatos());
            sb.AppendLine("Cilindrada: " + this.Cilindrada);

            return sb.ToString();
        }

        public MotoCross(short numero, string escuderia):base(numero, escuderia)
        { }

        public MotoCross(short numero, string escuderia, short cilindrada):this(numero, escuderia)
        {
            this.Cilindrada = cilindrada;
        }

        public static bool operator !=(MotoCross m1, MotoCross m2)
        {
            return !(m1 == m2);
        }

        public static bool operator ==(MotoCross m1, MotoCross m2)
        {
            return ((m1.Escuderia == m2.Escuderia) && (m1.Numero == m2.Numero) && (m1.Cilindrada == m2.Cilindrada));
        }
    }
}
