using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CentralitaHerencia
{
    public enum TipoLlamada
    {
        Local,
        Provincial,
        Todas
    }
    
    public abstract class Llamada
    {

        protected float duracion;
        protected string nroDestino;
        protected string nroOrigen;

        public float Duracion
        {
            get 
            {
                return this.duracion; 
            }
        }

        public string NroDestino
        {
            get 
            {
                return this.nroDestino; 
            }
        }

        public string NroOrigen
        {
            get 
            {
                return this.nroOrigen; 
            }
        }

        public abstract float CostoLlamada
        {
            get;
        }

        public Llamada(float duracion, string nroDestino, string nroOrigen)
        {
            this.duracion = duracion;
            this.nroDestino = nroDestino;
            this.nroOrigen = nroOrigen;
        }

        protected virtual string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("\tNro. Origen: {0}\n", this.NroOrigen);
            sb.AppendFormat("\tNro. Destino: {0}\n", this.NroDestino);
            sb.AppendFormat("\tDuracion: {0}\n", this.Duracion);

            return sb.ToString();
        }

        public static bool operator !=(Llamada l1, Llamada l2)
        {
            return !(l1 == l2);
        }

        public static bool operator ==(Llamada l1, Llamada l2)
        {
            return (l1.Equals(l2) && l1.NroOrigen == l2.NroOrigen && l1.NroDestino == l2.NroDestino);
        }

        public static int OrdenarPorDuracion(Llamada llamada1, Llamada llamada2)
        {
            if (llamada1.Duracion < llamada2.Duracion)
            {
                return -1;
            }
            else if (llamada1.Duracion > llamada2.duracion)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}
