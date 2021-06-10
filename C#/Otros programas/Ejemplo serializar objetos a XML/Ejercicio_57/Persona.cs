using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace Ejercicio_57
{
    public class Persona
    {
        static XmlTextWriter xmlWriter;
        static XmlTextReader xmlReader;
        static XmlSerializer xmlSerializer = new XmlSerializer(typeof(Persona));
        string nombre;
        string apellido;

        public Persona()
        { }

        public Persona(string nombre, string apellido)
        {
            this.Nombre = nombre;
            this.Apellido = apellido;
        }

        public string Nombre { get => nombre; set => nombre = value; }
        public string Apellido { get => apellido; set => apellido = value; }

        public static bool Guardar(Persona persona)
        {
            if (persona != null)
            {
                using (xmlWriter = new XmlTextWriter("personas.xml", Encoding.ASCII))
                {
                    xmlSerializer.Serialize(xmlWriter, persona);
                }
                return true;
            }
            else
            {
                return false;
            }
        }

        public static Persona Leer(string rutaArchivo)
        {
            Persona auxPersona;
            if (rutaArchivo != null && rutaArchivo != "")
            {
                using (xmlReader = new XmlTextReader(rutaArchivo))
                {
                    auxPersona = (Persona)xmlSerializer.Deserialize(xmlReader);
                }
                return auxPersona;
            }
            else
            {
                return null;
            }
        }

        public override string ToString()
        {
            StringBuilder datosPersona = new StringBuilder();
            datosPersona.AppendLine("Nombre: " + this.Nombre);
            datosPersona.AppendLine("Apellido: " + this.Apellido);

            return datosPersona.ToString();
        }
    }
}
