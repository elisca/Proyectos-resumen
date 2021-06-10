using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CentralitaHerencia
{
    public class Centralita
    {
        List<Llamada> listaDeLlamadas;
        protected string razonSocial;

        public float GananciasPorLocal
        {
            get
            {
                return this.CalcularGanancia(TipoLlamada.Local);
            }
        }

        public float GananciasPorProvincial
        {
            get
            {
                return this.CalcularGanancia(TipoLlamada.Provincial);
            }
        }

        public float GananciasPorTotal
        {
            get
            {
                return this.CalcularGanancia(TipoLlamada.Todas);
            }
        }

        public List<Llamada> Llamadas
        {
            get 
            {
                return this.listaDeLlamadas; 
            }
        }

        void AgregarLlamada(Llamada nuevaLlamada)
        {
            this.listaDeLlamadas.Add(nuevaLlamada);
        }

        private float CalcularGanancia(TipoLlamada tipo)
        {
            float recaudacion = 0;

            foreach (Llamada auxLlamada in this.Llamadas)
            {
                switch (tipo)
                { 
                    case TipoLlamada.Local:
                        if (auxLlamada is Local)
                        {
                            recaudacion += ((Local)auxLlamada).CostoLlamada;
                        }
                        break;
                    case TipoLlamada.Provincial:
                        if (auxLlamada is Provincial)
                        {
                            recaudacion += ((Provincial)auxLlamada).CostoLlamada;
                        }
                        break;
                    case TipoLlamada.Todas:
                        if (auxLlamada is Local)
                        {
                            recaudacion += ((Local)auxLlamada).CostoLlamada;
                        }
                        else if (auxLlamada is Provincial)
                        {
                            recaudacion += ((Provincial)auxLlamada).CostoLlamada;
                        }
                        break;
                }
            }

            return recaudacion;
        }

        public Centralita()
        {
            this.listaDeLlamadas = new List<Llamada>();
        }

        public Centralita(string nombreEmpresa):this()
        {
            this.razonSocial = nombreEmpresa;
        }

        string Mostrar()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendFormat("Razon social: {0}\n", this.razonSocial);
            sb.AppendFormat("Ganancia total: ${0}\n", this.GananciasPorTotal);
            sb.AppendFormat("Ganancia por llamadas locales: ${0}\n", this.GananciasPorLocal);
            sb.AppendFormat("Ganancia por llamadas provinciales: ${0}\n", this.GananciasPorProvincial);

            foreach (Llamada auxLlamada in this.Llamadas)
            {
                if (auxLlamada is Local)
                {
                    sb.AppendFormat("{0}", auxLlamada.ToString());
                }
                else if (auxLlamada is Provincial)
                {
                    sb.AppendFormat("{0}", auxLlamada.ToString());
                }
            }

            return sb.ToString();
        }

        public static bool operator !=(Centralita c, Llamada llamada)
        {
            return !(c == llamada);
        }

        public static Centralita operator +(Centralita c, Llamada nuevaLlamada)
        {
            if (c != nuevaLlamada)
            {
                c.AgregarLlamada(nuevaLlamada);
            }
            else
            {
                throw new CentralitaException("La llamada que intenta ser ingresada al sistema ya existe.", "Centralita", "Operador +");
            }
            return c;
        }

        public static bool operator ==(Centralita c, Llamada llamada)
        {
            bool llamadaExistente = false;

            foreach (Llamada auxLlamada in c.Llamadas)
            { 
                if(auxLlamada == llamada)
                {
                    llamadaExistente = true;
                    break;
                }
            }
            return llamadaExistente;
        }
        
        public void OrdenarLlamadas()
        {
            this.listaDeLlamadas.Sort(Llamada.OrdenarPorDuracion);
        }

        public override string ToString()
        {
            return this.Mostrar();
        }
    }
}
