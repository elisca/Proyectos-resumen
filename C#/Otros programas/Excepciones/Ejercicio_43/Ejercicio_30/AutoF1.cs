using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    public class AutoF1:VehiculoDeCarrera
    {
        short caballosDeFuerza;

        public short CaballosDeFuerza
        {
            get 
            {
                return this.caballosDeFuerza; 
            }
            set 
            {
                if (value >= 0)
                {
                    this.caballosDeFuerza = value;
                }
            }
        }

        public AutoF1(short numero, string escuderia):base(numero, escuderia)
        { }

        public AutoF1(short numero, string escuderia, short caballosDeFuerza):this(numero, escuderia)
        {
            this.CaballosDeFuerza = caballosDeFuerza;
        }

        public override string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine(base.MostrarDatos());
            sb.AppendLine("Caballos de fuerza: " + this.CaballosDeFuerza);

            return sb.ToString();
        }

        public static bool operator !=(AutoF1 a1, AutoF1 a2)
        {
            return !(a1 == a2);
        }

        public static bool operator ==(AutoF1 a1, AutoF1 a2)
        {
            return ((a1.Escuderia == a2.Escuderia) && (a1.Numero == a2.Numero) && (a1.CaballosDeFuerza == a2.CaballosDeFuerza));
        }
    }
}
