using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Escalas_Temperatura
{
    public class Fahrenheit
    {
        private double cantidad;

        public Fahrenheit():this(0)
        { }

        public Fahrenheit(double cantidad)
        {
            this.cantidad = cantidad;
        }

        public double GetCantidad()
        {
            return this.cantidad;
        }

        public static implicit operator Fahrenheit(double cant)
        {
            Fahrenheit auxK = new Fahrenheit(cant);
            return auxK;
        }

        public static explicit operator Kelvin(Fahrenheit tempF)
        {
            double cantK = (tempF.GetCantidad() + 459.67) * 5 / 9;
            Kelvin auxK = new Kelvin(cantK);
            return auxK;
        }

        public static explicit operator Celsius(Fahrenheit tempF)
        {
            double cantC = (tempF.GetCantidad() - 32) * 5 / 9;
            Celsius auxC = new Celsius(cantC);
            return auxC;
        }

        public static bool operator ==(Fahrenheit tempF, Kelvin tempK)
        {
            if (tempF.GetCantidad() == ((Fahrenheit)tempK).GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator ==(Fahrenheit tempF, Celsius tempC)
        {
            if (tempF.GetCantidad() == ((Fahrenheit)tempC).GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator ==(Fahrenheit tempF1, Fahrenheit tempF2)
        {
            if (tempF1.GetCantidad() == tempF2.GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator !=(Fahrenheit tempF, Kelvin tempK)
        {
            return !(tempF == tempK);
        }

        public static bool operator !=(Fahrenheit tempF, Celsius tempC)
        {
            return !(tempF == tempC);
        }

        public static bool operator !=(Fahrenheit tempF1, Fahrenheit tempF2)
        {
            return !(tempF1 == tempF2);
        }

        public static Fahrenheit operator +(Fahrenheit tempF, Kelvin tempK)
        {
            double cantF = tempF.GetCantidad() + ((Fahrenheit)tempK).GetCantidad();
            Fahrenheit auxF = new Fahrenheit(cantF);
            return auxF;
        }

        public static Fahrenheit operator +(Fahrenheit tempF, Celsius tempC)
        {
            double cantF = tempF.GetCantidad() + ((Fahrenheit)tempC).GetCantidad();
            Fahrenheit auxF = new Fahrenheit(cantF);
            return auxF;
        }

        public static Fahrenheit operator -(Fahrenheit tempF, Kelvin tempK)
        {
            double cantF = tempF.GetCantidad() - ((Fahrenheit)tempK).GetCantidad();
            Fahrenheit auxF = new Fahrenheit(cantF);
            return auxF;
        }

        public static Fahrenheit operator -(Fahrenheit tempF, Celsius tempC)
        {
            double cantF = tempF.GetCantidad() - ((Fahrenheit)tempC).GetCantidad();
            Fahrenheit auxF = new Fahrenheit(cantF);
            return auxF;
        }
    }
}
