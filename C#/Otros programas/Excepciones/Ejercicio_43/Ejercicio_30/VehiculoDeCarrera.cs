using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    public abstract class VehiculoDeCarrera
    {
        short cantidadCombustible;
        bool enCompetencia;
        string escuderia;
        short numero;
        short vueltasRestantes;

        public VehiculoDeCarrera(short numero, string escuderia)
        {
            this.Numero = numero;
            this.Escuderia = escuderia;
        }

        public short CantidadCombustible
        {
            get
            {
                return this.cantidadCombustible; 
            }
            set
            {
                if (value >= 0)
                {
                    this.cantidadCombustible = value;
                }
            }
        }

        public short VueltasRestantes
        {
            get 
            {
                return this.vueltasRestantes; 
            }
            set
            {
                if (value >= 0)
                {
                    this.vueltasRestantes = value;
                }
            }
        }

        public bool EnCompetencia
        {
            get 
            {
                return this.enCompetencia; 
            }
            set 
            {
                this.enCompetencia = value; 
            }
        }

        public string Escuderia
        {
            get 
            {
                return this.escuderia; 
            }
            set 
            {
                if (value != null)
                {
                    this.escuderia = value;
                }
            }
        }

        public short Numero
        {
            get 
            {
                return this.numero; 
            }
            set 
            {
                if (value >= 0)
                {
                    this.numero = value;
                }
            }
        }

        public static bool operator !=(VehiculoDeCarrera v1, VehiculoDeCarrera v2)
        {
            return !(v1 == v2);
        }

        public static bool operator ==(VehiculoDeCarrera v1, VehiculoDeCarrera v2)
        {
            return ((v1.numero == v2.numero) && (v1.escuderia == v2.escuderia));
        }

        public virtual string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Escuderia: " + this.Escuderia + " Numero: " + this.Numero + " En competencia: " + this.EnCompetencia + " Vueltas restantes: " + this.VueltasRestantes + " Combustible restante: " + this.CantidadCombustible);

            return sb.ToString();
        }
    }
}
