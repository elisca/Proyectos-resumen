using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CentralitaHerencia
{
    public class Provincial : Llamada
    {
        public enum Franja
        { 
            Franja_1,
            Franja_2,
            Franja_3
        }

        protected Franja franjaHoraria;

        public override float CostoLlamada
        {
            get
            {
                return this.CalcularCosto();
            }
        }

        private float CalcularCosto()
        {
            float costo = 0;
            
            switch((int)franjaHoraria)
            {
                //Franja 1
                case 0:
                    costo = 0.99f * this.Duracion;
                    break;
                //Franja 2
                case 1:
                    costo = 1.25f * this.Duracion;
                    break;
                //Franja 3
                case 2:
                    costo = 0.66f * this.Duracion;
                    break;
            }

            return costo;
        }

        public override bool Equals(object obj)
        {
            return (obj is Provincial);
        }

        protected override string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("Llamada Provincial:\n");
            sb.AppendFormat(base.Mostrar());
            sb.AppendFormat("Costo de llamada: ${0}\n", this.CostoLlamada);
            sb.AppendFormat("Franja horaria: {0}\n", this.franjaHoraria);

            return sb.ToString();
        }

        public Provincial(Franja miFranja, Llamada llamada):this(llamada.NroOrigen, miFranja, llamada.Duracion, llamada.NroDestino)
        { }

        public Provincial(string origen, Franja miFranja, float duracion, string destino):base(duracion, destino, origen)
        {
            this.franjaHoraria = miFranja;
        }

        public override string ToString()
        {
            return this.Mostrar();
        }
    }
}
