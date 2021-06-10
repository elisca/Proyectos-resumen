using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ejercicio_13
{
    class NumeroBinario
    {
        private string numero;

        private NumeroBinario(string numero)
        {
            this.numero = numero;
        }

        public static implicit operator NumeroBinario(string numBin)
        {
            NumeroBinario auxNumBin = new NumeroBinario(numBin);

            return auxNumBin;
        }

        public static string operator +(NumeroBinario numBin, NumeroDecimal numDec)
        {
            double auxConvNumDec = Conversor.BinarioDecimal((string)numBin);
            string auxConvNumBin = null;
            NumeroDecimal auxNumDec = auxConvNumDec;
            NumeroBinario auxNumBin;

            auxNumDec = (double)auxNumDec + (double)numDec;
            auxConvNumBin = Conversor.DecimalBinario((double)auxNumDec);
            auxNumBin = new NumeroBinario(auxConvNumBin);

            return (string)auxNumBin;
        }

        public static bool operator ==(NumeroBinario numBin, NumeroDecimal numDec)
        {
            double auxNumDec = Conversor.BinarioDecimal((string)numBin);

            if (auxNumDec == (double)numDec)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public static bool operator !=(NumeroBinario numBin, NumeroDecimal numDec)
        {
            return !(numBin == numDec);
        }

        public static explicit operator string(NumeroBinario numBin)
        {
            string auxNumBin = numBin.numero;

            return auxNumBin;
        }

        public static string operator -(NumeroBinario numBin, NumeroDecimal numDec)
        {
            double auxConvNumBin = Conversor.BinarioDecimal((string)numBin);
            double auxConvNumDec = auxConvNumBin - (double)numDec;
            string aNumBin = Conversor.DecimalBinario(auxConvNumDec);

            NumeroBinario auxNumBin = new NumeroBinario(aNumBin);
            
            return (string)auxNumBin;
        }
    }
}
