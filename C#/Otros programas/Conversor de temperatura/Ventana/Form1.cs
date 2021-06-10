using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Escalas_Temperatura;

namespace Ventana
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnFahrenheit_Click(object sender, EventArgs e)
        {
            double auxFahrenheit;
            Fahrenheit auxFah = new Fahrenheit();

            if (double.TryParse(txtInFahrenheit.Text, out auxFahrenheit))
            {
                auxFah = auxFahrenheit;
                txtFahFah.Text = auxFah.GetCantidad().ToString();
                txtFahCel.Text = ((Celsius)auxFah).GetCantidad().ToString();
                txtFahKel.Text = ((Kelvin)auxFah).GetCantidad().ToString();
            }
        }

        private void btnCelsius_Click(object sender, EventArgs e)
        {
            double auxCelsius;
            Celsius auxCel = new Celsius();

            if (double.TryParse(txtInCelsius.Text, out auxCelsius))
            {
                auxCel = auxCelsius;
                txtCelFah.Text = ((Fahrenheit)auxCel).GetCantidad().ToString();
                txtCelCel.Text = auxCel.GetCantidad().ToString();
                txtCelKel.Text = ((Kelvin)auxCel).GetCantidad().ToString();
            }
        }

        private void btnKelvin_Click(object sender, EventArgs e)
        {
            double auxKelvin;
            Kelvin auxKel = new Kelvin();

            if (double.TryParse(txtInKelvin.Text, out auxKelvin))
            {
                auxKel = auxKelvin;
                txtKelFah.Text = ((Fahrenheit)auxKel).GetCantidad().ToString();
                txtKelCel.Text = ((Celsius)auxKel).GetCantidad().ToString();
                txtKelKel.Text = auxKel.GetCantidad().ToString();
            }
        }
    }
}
