using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ejercicio_42
{
    class OtraClase
    {
        public void MetodoInstancia()
        {
            try
            {
                new MiClase("");
            }
            catch (UnaException e)
            {
                throw new MiException("Capturadas excepciones de constructores. MiException lanzara excepcion...", e);
            }
        }
    }
}
