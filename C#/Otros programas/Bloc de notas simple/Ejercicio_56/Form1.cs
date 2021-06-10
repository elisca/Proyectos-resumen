using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Ejercicio_56
{
    public partial class Form1 : Form
    {
        StreamWriter sw;
        StreamReader sr;
        string ultimaRuta;
        bool archivoModificado;
        
        public Form1()
        {
            InitializeComponent();
            archivoModificado = false;
        }

        private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "Archivos de texto (*.txt)|*.txt|Todos los archivos (*.*)|*.*";
            openFileDialog1.ShowDialog();
            ultimaRuta = openFileDialog1.FileName;
            if (ultimaRuta != null && ultimaRuta != "")
            {
                using (sr = new StreamReader(ultimaRuta))
                {
                    this.rtb1.Text = sr.ReadToEnd();
                }
                archivoModificado = false;
            }
        }

        private void salirToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (archivoModificado && MessageBox.Show("¿Desea guardar las modificaciones realizadas al archivo antes de salir?", "Confirmar guardar cambios",MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                guardarToolStripMenuItem_Click(sender, e);
            }
            this.Close();
        }

        private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (ultimaRuta != null && ultimaRuta != "")
            {
                using (sw = new StreamWriter(ultimaRuta))
                {
                    sw.Write(this.rtb1.Text);
                    archivoModificado = false;
                }
            }
            else
            {
                guardarComoToolStripMenuItem_Click(sender, e);
            }
        }

        private void guardarComoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.Filter = "Archivos de texto (*.txt)|*.txt|Todos los archivos (*.*)|*.*";
            saveFileDialog1.ShowDialog();
            ultimaRuta = saveFileDialog1.FileName;
            if (ultimaRuta != null && ultimaRuta != "")
            {
                guardarToolStripMenuItem_Click(sender, e);
            }
        }

        private void rtb1_TextChanged(object sender, EventArgs e)
        {
            archivoModificado = true;
        }
    }
}
