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
    public partial class FrmCentralita : Form
    {
        Centralita c;
        FrmLlamador frmLlamador;
        FrmMostrar frmMostrar;

        public FrmCentralita()
        {
            InitializeComponent();
            this.c = new Centralita();
            frmLlamador = new FrmLlamador(this.c);
            frmMostrar = new FrmMostrar(this.c);
        }

        private void btnGenerarLlamada_Click(object sender, EventArgs e)
        {
            this.frmLlamador.ShowDialog();
        }

        private void btnFacturacionTotal_Click(object sender, EventArgs e)
        {
            this.frmMostrar.TipoLlamadaMostrar = TipoLlamada.Todas;
            this.frmMostrar.ShowDialog();
        }

        private void btnFacturacionLocal_Click(object sender, EventArgs e)
        {
            this.frmMostrar.TipoLlamadaMostrar = TipoLlamada.Local;
            this.frmMostrar.ShowDialog();
        }

        private void btnFacturacionProvincial_Click(object sender, EventArgs e)
        {
            this.frmMostrar.TipoLlamadaMostrar = TipoLlamada.Provincial;
            this.frmMostrar.ShowDialog();
        }

        private void btnSalir_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("¿Desea cerrar este programa?", "Confirme acción", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                this.Close();
            }
        }
    }
}
