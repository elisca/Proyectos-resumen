using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Ejercicio_13
{
    class Program
    {
        static void Main(string[] args)
        {
            NumeroBinario nBin = "110";
            NumeroDecimal nDec = 12;
            double resDec = 0;
            string resBin = null;

            resDec = nDec + nBin;
            Console.WriteLine("{0}d + {1}b = {2}d", (double)nDec, (string)nBin, resDec);

            resDec = nDec - nBin;
            Console.WriteLine("{0}d - {1}b = {2}d", (double)nDec, (string)nBin, resDec);

            nBin = "1100";
            nDec = 2;

            resBin = nBin + nDec;
            Console.WriteLine("{0}b + {1}d = {2}d", (string)nBin, (double)nDec, resBin);

            resBin = nBin - nDec;
            Console.WriteLine("{0}b - {1}d = {2}d", (string)nBin, (double)nDec, resBin);

            Console.WriteLine("Convertir {0}b a decimal: {1}", (string)nBin, Conversor.BinarioDecimal((string)nBin));
            Console.WriteLine("Convertir {0}d a binario: {1}", (double)nDec, Conversor.DecimalBinario((double)nDec));

            Console.WriteLine("Igualdad entre {0}b y {1}d = {2}", (string)nBin, (double)nDec, (nBin == nDec).ToString());
            Console.WriteLine("Desigualdad entre {0}b y {1}d = {2}", (string)nBin, (double)nDec, (nBin != nDec).ToString());

            nBin = "110";
            nDec = 6;

            Console.WriteLine("Igualdad entre {0}b y {1}d = {2}", (double)nDec, (string)nBin, (nDec == nBin).ToString());
            Console.WriteLine("Desigualdad entre {0}b y {1}d = {2}", (double)nDec, (string)nBin, (nDec != nBin).ToString());

            Console.ReadKey();
        }
    }
}
