using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Escalas_Temperatura
{
    public class Celsius
    {
        private double cantidad;

        public Celsius():this(0)
        { }

        public Celsius(double cantidad)
        {
            this.cantidad = cantidad;
        }

        public double GetCantidad()
        {
            return this.cantidad;
        }

        public static implicit operator Celsius(double cant)
        {
            Celsius auxK = new Celsius(cant);
            return auxK;
        }

        public static explicit operator Kelvin(Celsius tempC)
        {
            double cantC = ((tempC.GetCantidad() * 1.8 + 32) + 459.67) * 5 / 9;
            Kelvin auxK = new Kelvin(cantC);
            return auxK;
        }

        public static explicit operator Fahrenheit(Celsius tempC)
        {
            double cantC = tempC.GetCantidad() * 1.8 + 32;
            Fahrenheit auxF = new Fahrenheit(cantC);
            return auxF;
        }

        public static bool operator ==(Celsius tempC, Kelvin tempK)
        {
            if (tempC.GetCantidad() == ((Celsius)tempK).GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator ==(Celsius tempC, Fahrenheit tempF)
        {
            if (tempC.GetCantidad() == ((Celsius)tempF).GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator ==(Celsius tempC1, Celsius tempC2)
        {
            if (tempC1.GetCantidad() == tempC2.GetCantidad())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator !=(Celsius tempC, Kelvin tempK)
        {
            return !(tempC == tempK);
        }

        public static bool operator !=(Celsius tempC, Fahrenheit tempF)
        {
            return !(tempC == tempF);
        }

        public static bool operator !=(Celsius tempC1, Celsius tempC2)
        {
            return !(tempC1 == tempC2);
        }

        public static Celsius operator +(Celsius tempC, Kelvin tempK)
        {
            double cantC = tempC.GetCantidad() + ((Celsius)tempK).GetCantidad();
            Celsius auxC = new Celsius(cantC);
            return auxC;
        }

        public static Celsius operator +(Celsius tempC, Fahrenheit tempF)
        {
            double cantC = tempC.GetCantidad() + ((Celsius)tempF).GetCantidad();
            Celsius auxC = new Celsius(cantC);
            return auxC;
        }

        public static Celsius operator -(Celsius tempC, Kelvin tempK)
        {
            double cantC = tempC.GetCantidad() - ((Celsius)tempK).GetCantidad();
            Celsius auxC = new Celsius(cantC);
            return auxC;
        }
        public static Celsius operator -(Celsius tempC, Fahrenheit tempF)
        {
            double cantC = tempC.GetCantidad() - ((Celsius)tempF).GetCantidad();
            Celsius auxC = new Celsius(cantC);
            return auxC;
        }
    }
}
