using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ejercicio_13
{
    class NumeroDecimal
    {
        private double numero;

        private NumeroDecimal(double numero)
        {
            this.numero = numero;
        }

        public static double operator +(NumeroDecimal numDec, NumeroBinario numBin)
        {
            double auxConvNumDec = Conversor.BinarioDecimal((string)numBin);
            NumeroDecimal auxNumDec = new NumeroDecimal(auxConvNumDec);

            auxNumDec = (double)auxNumDec + (double)numDec;
            return (double)auxNumDec;
        }

        public static double operator -(NumeroDecimal numDec, NumeroBinario numBin)
        {
            double auxConvNumDec = Conversor.BinarioDecimal((string)numBin);
            NumeroDecimal auxNumDec = new NumeroDecimal(auxConvNumDec);

            auxNumDec = (double)auxNumDec - (double)numDec;
            return (double)auxNumDec;
        }

        public static bool operator ==(NumeroDecimal numDec, NumeroBinario numBin)
        {
            double auxConvNumDec = Conversor.BinarioDecimal((string)numBin);
            NumeroDecimal auxNumDec = new NumeroDecimal(auxConvNumDec);

            if ((double)auxConvNumDec == (double)numDec)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

        public static bool operator !=(NumeroDecimal numDec, NumeroBinario numBin)
        {
            return !(numDec == numBin);
        }

        public static implicit operator NumeroDecimal(double numDec)
        {
            NumeroDecimal auxNumDec = new NumeroDecimal(numDec);

            return auxNumDec;
        }

        public static explicit operator double(NumeroDecimal numDec)
        {
            double auxNumDec = numDec.numero;

            return auxNumDec;
        }
    }
}
