using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Escalas_Temperatura
{
    public class Kelvin
    {
        private double cantidad;

        public Kelvin():this(0)
        { }

        public Kelvin(double cantidad)
        {
            this.cantidad = cantidad;
        }

        public double GetCantidad()
        {
            return this.cantidad;
        }

        public static implicit operator Kelvin(double cant)
        {
            Kelvin auxK = new Kelvin(cant);
            return auxK;
        }

        public static explicit operator Fahrenheit(Kelvin tempK)
        {
            double cantF = tempK.GetCantidad() * 9 / 5 - 459.67;
            Fahrenheit auxF = new Fahrenheit(cantF);
            return auxF;
        }

        public static explicit operator Celsius(Kelvin tempK)
        {
            double cantC = (((Fahrenheit)tempK).GetCantidad() - 32) * 5 / 9;
            Celsius auxC = new Celsius(cantC);
            return auxC;
        }

        public static bool operator ==(Kelvin tempK, Fahrenheit tempF)
        {
            if (tempK.GetCantidad() == ((Kelvin)tempF).GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator ==(Kelvin tempK, Celsius tempC)
        {
            if (tempK.GetCantidad() == ((Kelvin)tempC).GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator ==(Kelvin tempK1, Kelvin tempK2)
        {
            if (tempK1.GetCantidad() == tempK2.GetCantidad())
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        public static bool operator !=(Kelvin tempK, Fahrenheit tempF)
        {
            return !(tempK == tempF);
        }

        public static bool operator !=(Kelvin tempK, Celsius tempC)
        {
            return !(tempK == tempC);
        }

        public static bool operator !=(Kelvin tempK1, Kelvin tempK2)
        {
            return !(tempK1 == tempK2);
        }

        public static Kelvin operator +(Kelvin tempK, Fahrenheit tempF)
        {
            double cantK = tempK.GetCantidad() + ((Kelvin)tempF).GetCantidad();
            Kelvin auxK = new Kelvin(cantK);
            return auxK;
        }

        public static Kelvin operator +(Kelvin tempK, Celsius tempC)
        {
            double cantK = tempK.GetCantidad() + ((Kelvin)tempC).GetCantidad();
            Kelvin auxK = new Kelvin(cantK);
            return auxK;
        }

        public static Kelvin operator -(Kelvin tempK, Fahrenheit tempF)
        {
            double cantK = tempK.GetCantidad() - ((Kelvin)tempF).GetCantidad();
            Kelvin auxK = new Kelvin(cantK);
            return auxK;
        }

        public static Kelvin operator -(Kelvin tempK, Celsius tempC)
        {
            double cantK = tempK.GetCantidad() - ((Kelvin)tempC).GetCantidad();
            Kelvin auxK = new Kelvin(cantK);
            return auxK;
        }
    }
}
