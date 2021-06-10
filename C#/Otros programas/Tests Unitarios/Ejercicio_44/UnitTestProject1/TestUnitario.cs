using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using CentralitaHerencia;

namespace UnitTestProject1
{
    [TestClass]
    public class TestUnitario
    {
        [TestMethod]
        public void ComprobarCentralitaExceptionLocal()
        {
            //Arrange
            Centralita c = new Centralita();
            Local l1 = new Local("1111", 10, "2222", 10);
            Local l2 = new Local("1111", 20, "2222", 20);
            Local l3 = new Local("0000", 10, "1111", 10);
            bool excepcionLlamadaIdentica = false;

            //Act
            try
            {
                c = c + l1;
                c = c + l2;
            }
            catch (CentralitaException ce)
            {
                excepcionLlamadaIdentica = true;
            }

            try
            {
                c = c + l3;
            }
            //Assert
            catch (CentralitaException ce2)
            {
                Assert.Fail();
            }

            Assert.AreEqual(excepcionLlamadaIdentica, true);
        }

        [TestMethod]
        public void ComprobarCentralitaExceptionProvincial()
        {
            //Arrange
            Centralita c = new Centralita();
            Provincial p1 = new Provincial("#10", Provincial.Franja.Franja_1, 10, "#20");
            Provincial p2 = new Provincial("#10", Provincial.Franja.Franja_1, 20, "#20");
            Provincial p3 = new Provincial("#20", Provincial.Franja.Franja_2, 30, "#30");
            bool excepcionLlamadaIdentica = false;

            //Act
            try
            {
                c = c + p1;
                c = c + p2;
            }
            catch (CentralitaException ce)
            {
                excepcionLlamadaIdentica = true;
            }

            try
            {
                c = c + p3;
            }
            //Assert
            catch (CentralitaException ce2)
            {
                Assert.Fail();
            }

            Assert.AreEqual(excepcionLlamadaIdentica, true);
        }

        [TestMethod]
        public void ComprobarCentralitaExceptionLocalProvincial()
        {
            //Arrange
            Local l1 = new Local("1111", 10, "2222", 10);
            Local l2 = new Local("1111", 20, "2222", 20);
            Provincial p1 = new Provincial("#10", Provincial.Franja.Franja_1, 10, "#20");
            Provincial p2 = new Provincial("#10", Provincial.Franja.Franja_1, 20, "#20");
            
            //Act y Assert
            Assert.IsTrue((l1 == l2 && l1 != p1 && l1 != p2) && (l2 != p1 && l2 != p2) && (p1 == p2));
        }
        [TestMethod]
        public void ComprobarListaLlamadasInstanciada()
        {
            //Arrange y Act
            Centralita c = new Centralita();

            //Assert
            Assert.IsNotNull(c.Llamadas);
        }

    }
}
