using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_42
{
    class MiClase
    {
        public MiClase()
        {
            try
            {
                MiClase.MetodoEstatico();
            }
            catch (DivideByZeroException de)
            {
                throw de;
            }
        }

        public MiClase(string atributo)
        {
            try
            {
                new MiClase();
            }
            catch (DivideByZeroException de)
            {
                throw new UnaException("Lanzando UnaException...", de);
            }
        }

        public static void MetodoEstatico()
        {
            throw new DivideByZeroException();
        }
    }
}
