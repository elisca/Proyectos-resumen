using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ejercicio_13
{
    internal class Conversor
    {
        internal static string DecimalBinario(double numDec)
        {
            string numBin = null;
            long numDecimal = (long)numDec;
            byte modDecimal=0;

            if (numDec >= 0)
            {
                while (numDecimal > 0)
                {
                    modDecimal = (byte)(numDecimal % 2);
                    numDecimal /= 2;

                    numBin = modDecimal.ToString() + numBin;
                }
                numBin = numDecimal.ToString() + numBin;
                
                return numBin;
            }
            else
            {
                return "Error.";
            }
        }

        internal static double BinarioDecimal(string numBin)
        {
            long numDec = 0, numExp = 0;
            int indice = 0;

            for(int i=numBin.Length-1; i>=0; i--)
            {
                if (numBin[indice] == '1')
                {
                    numExp = (long)Math.Pow(2, i);
                    numDec += numExp;
                }
                else if (numBin[indice] != '0')
                {
                    return double.MinValue;
                }
                indice++;
            }

            return numDec;
        }
    }
}
