using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_30
{
    public enum TipoCompetencia
    { 
        F1,
        MotoCross
    }

    public class Competencia
    {
        short cantidadCompetidores;
        short cantidadVueltas;
        List<VehiculoDeCarrera> competidores;
        TipoCompetencia tipo;

        public short CantidadCompetidores
        {
            get 
            {
                return this.cantidadCompetidores; 
            }
            set 
            {
                if (value >= 0)
                {
                    this.cantidadCompetidores = value;
                }
            }
        }

        public short CantidadVueltas
        {
            get 
            {
                return this.cantidadVueltas; 
            }
            set 
            {
                if (value >= 0)
                {
                    this.cantidadVueltas = value;
                }
            }
        }

        public VehiculoDeCarrera this[int i]
        {
            get
            {
                if (i < this.competidores.Count())
                {
                    return this.competidores[i];
                }
                else
                {
                    return null;
                }
            }
        }

        public TipoCompetencia Tipo
        {
            get 
            {
                return this.tipo; 
            }
            set 
            {
                this.tipo = value; 
            }
        }

        private Competencia()
        {
            this.competidores = new List<VehiculoDeCarrera>();
        }

        public Competencia(short cantVueltas, short cantCompetidores, TipoCompetencia tipo):this()
        {
            this.CantidadVueltas = cantVueltas;
            this.CantidadCompetidores = cantCompetidores;
            this.Tipo = tipo;
        }

        public string MostrarDatos()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("Tipo de competencia: " + this.Tipo + " Cantidad de competidores: " + this.CantidadCompetidores + " Cantidad de vueltas: " + this.CantidadVueltas);
            foreach (VehiculoDeCarrera auxVeh in this.competidores)
            {
                sb.AppendLine(auxVeh.MostrarDatos());
            }
            
            return sb.ToString();
        }

        public static bool operator !=(Competencia c, VehiculoDeCarrera a)
        {
            return !(c == a);
        }

        public static bool operator -(Competencia c, VehiculoDeCarrera a)
        {
            if (c == a)
            {
                c.competidores.Remove(a);
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator +(Competencia c, VehiculoDeCarrera a)
        {
            Random rndCombustible = new Random();
            bool vehiculoExistente = false;

            try
            {
                foreach (VehiculoDeCarrera auxVeh in c.competidores)
                {
                    if (auxVeh == a)
                    {
                        vehiculoExistente = true;
                    }
                }

                if ((c.competidores.Count() < c.CantidadCompetidores) && (c == a) && !vehiculoExistente)
                {
                    c.competidores.Add(a);
                    a.EnCompetencia = true;
                    a.VueltasRestantes = c.CantidadVueltas;
                    a.CantidadCombustible = (short)rndCombustible.Next(15, 100);
                    return true;
                }
                else
                {
                    return false;
                }
            }

            catch (CompetenciaNoDisponibleException cnde)
            {
                throw new CompetenciaNoDisponibleException("Competencia incorrecta", "Competencia", "Operador +", cnde);
            }

            finally 
            {}
        }

        public static bool operator ==(Competencia c, VehiculoDeCarrera a)
        {
            if ((a is AutoF1 && c.Tipo == TipoCompetencia.F1) || (a is MotoCross && c.Tipo == TipoCompetencia.MotoCross))
            {
                return true;
            }
            else
            {
                throw new CompetenciaNoDisponibleException("El vehículo no corresponde a la competencia", "Competencia", "Operador ==");
            }
        }
    }
}
