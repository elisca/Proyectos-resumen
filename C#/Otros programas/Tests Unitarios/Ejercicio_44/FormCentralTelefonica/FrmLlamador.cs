using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CentralitaHerencia;

namespace FormCentralTelefonica
{
    public partial class FrmLlamador : Form
    {
        Centralita c;
        Llamada llamada;
        bool llamadaProvincial;

        public FrmLlamador(Centralita centralita)
        {
            InitializeComponent();
            this.c = centralita;

            // Carga
            cmbFranja.DataSource = Enum.GetValues(typeof(Provincial.Franja));
            txtNroDestino_TextChanged(null, null);
        }

        public Centralita CentralTelefonica
        {
            get
            {
                return c;
            }
        }

        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            this.cmbFranja.SelectedIndex = 0;
            this.txtNroOrigen.Text = "";
            this.txtNroDestino.Text = "";
        }

        private void btnNum1_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "1";
        }

        private void btnNum2_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "2";
        }

        private void btnNum3_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "3";
        }

        private void btnNum4_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "4";
        }

        private void btnNum5_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "5";
        }

        private void btnNum6_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "6";
        }

        private void btnNum7_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "7";
        }

        private void btnNum8_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "8";
        }

        private void btnNum9_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "9";
        }

        private void btnNum0_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "0";
        }

        private void btnAst_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "*";
        }

        private void btnNum_Click(object sender, EventArgs e)
        {
            this.txtNroDestino.Text = this.txtNroDestino.Text + "#";
        }

        private void txtNroDestino_TextChanged(object sender, EventArgs e)
        {
            bool esProvincial;

            if (txtNroDestino.Text.Length > 0)
            {
                esProvincial = (txtNroDestino.Text.ElementAt(0) == '#');
            }
            else
            {
                esProvincial = false;
            }

            this.cmbFranja.Enabled = esProvincial;
            this.llamadaProvincial = esProvincial;
        }

        private void btnLlamar_Click(object sender, EventArgs e)
        {
            Random numAleatorio = new Random();

            string nroOrigen;
            string nroDestino;
            int duracionLlamada = numAleatorio.Next(1, 50);
            Provincial.Franja franjas;
            float costoLlamada;

            do
            {
                costoLlamada = (float)(numAleatorio.NextDouble() * 10);
            } while (costoLlamada < 0.5 || costoLlamada > 5.6);

            nroOrigen = txtNroOrigen.Text;
            nroDestino = txtNroDestino.Text;

            if (llamadaProvincial)
            {
                Enum.TryParse<Provincial.Franja>(cmbFranja.SelectedValue.ToString(), out franjas);
                this.llamada = new Provincial(nroOrigen, franjas, duracionLlamada, nroDestino);
            }
            else
            {
                this.llamada = new Local(nroOrigen, duracionLlamada, nroDestino, costoLlamada);
            }

            try
            {
                this.c = this.c + llamada;
            }
            catch (CentralitaException ce)
            {
                MessageBox.Show(ce.Message, "Clase: " + ce.NombreClase + " Método: " + ce.NombreMetodo, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            { }
        }

        private void btnSalir_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
