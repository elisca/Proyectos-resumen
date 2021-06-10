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
    public partial class FrmMostrar : Form
    {
        Centralita c;
        TipoLlamada tipoLlamada;

        public FrmMostrar(Centralita centralita)
        {
            InitializeComponent();
            this.c = centralita;
        }

        public TipoLlamada TipoLlamadaMostrar
        {
            set
            {
                this.tipoLlamada = value;
            }
        }

        public void MostrarDetalle()
        {
            switch (tipoLlamada)
            { 
                case TipoLlamada.Local:
                    this.richTextBox1.Text = "DETALLE DE LLAMADAS LOCALES:\n";
                    break;
                case TipoLlamada.Provincial:
                    this.richTextBox1.Text = "DETALLE DE LLAMADAS PROVINCIALES\n:";
                    break;
                case TipoLlamada.Todas:
                    this.richTextBox1.Text = "DETALLE DE TODAS LAS LLAMADAS:\n";
                    break;
            }

            foreach (Llamada auxLlamada in c.Llamadas)
            {
                if ((auxLlamada is Local && (this.tipoLlamada == TipoLlamada.Local || this.tipoLlamada == TipoLlamada.Todas)) || (auxLlamada is Provincial && (this.tipoLlamada == TipoLlamada.Provincial || this.tipoLlamada == TipoLlamada.Todas)))
                {
                    richTextBox1.Text = richTextBox1.Text + auxLlamada.ToString();
                }
            }
        }

        private void FrmMostrar_Shown(object sender, EventArgs e)
        {
            this.MostrarDetalle();
        }
    }
}
