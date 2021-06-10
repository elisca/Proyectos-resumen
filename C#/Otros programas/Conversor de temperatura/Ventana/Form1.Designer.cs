namespace Ventana
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador requerida.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén utilizando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben eliminar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido del método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.txtFahFah = new System.Windows.Forms.TextBox();
            this.txtFahCel = new System.Windows.Forms.TextBox();
            this.txtFahKel = new System.Windows.Forms.TextBox();
            this.txtInFahrenheit = new System.Windows.Forms.TextBox();
            this.btnFahrenheit = new System.Windows.Forms.Button();
            this.btnCelsius = new System.Windows.Forms.Button();
            this.txtInCelsius = new System.Windows.Forms.TextBox();
            this.txtCelKel = new System.Windows.Forms.TextBox();
            this.txtCelCel = new System.Windows.Forms.TextBox();
            this.txtCelFah = new System.Windows.Forms.TextBox();
            this.btnKelvin = new System.Windows.Forms.Button();
            this.txtInKelvin = new System.Windows.Forms.TextBox();
            this.txtKelKel = new System.Windows.Forms.TextBox();
            this.txtKelCel = new System.Windows.Forms.TextBox();
            this.txtKelFah = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(184, 6);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Fahrenheit";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 34);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(57, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Fahrenheit";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(260, 6);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(40, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Celsius";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(25, 59);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(40, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Celsius";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(331, 6);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(36, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Kelvin";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(29, 86);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(36, 13);
            this.label6.TabIndex = 5;
            this.label6.Text = "Kelvin";
            // 
            // txtFahFah
            // 
            this.txtFahFah.Enabled = false;
            this.txtFahFah.Location = new System.Drawing.Point(181, 32);
            this.txtFahFah.Name = "txtFahFah";
            this.txtFahFah.Size = new System.Drawing.Size(62, 20);
            this.txtFahFah.TabIndex = 6;
            // 
            // txtFahCel
            // 
            this.txtFahCel.Enabled = false;
            this.txtFahCel.Location = new System.Drawing.Point(249, 32);
            this.txtFahCel.Name = "txtFahCel";
            this.txtFahCel.Size = new System.Drawing.Size(62, 20);
            this.txtFahCel.TabIndex = 7;
            // 
            // txtFahKel
            // 
            this.txtFahKel.Enabled = false;
            this.txtFahKel.Location = new System.Drawing.Point(317, 32);
            this.txtFahKel.Name = "txtFahKel";
            this.txtFahKel.Size = new System.Drawing.Size(62, 20);
            this.txtFahKel.TabIndex = 8;
            // 
            // txtInFahrenheit
            // 
            this.txtInFahrenheit.Location = new System.Drawing.Point(71, 31);
            this.txtInFahrenheit.Name = "txtInFahrenheit";
            this.txtInFahrenheit.Size = new System.Drawing.Size(62, 20);
            this.txtInFahrenheit.TabIndex = 9;
            // 
            // btnFahrenheit
            // 
            this.btnFahrenheit.Location = new System.Drawing.Point(139, 31);
            this.btnFahrenheit.Name = "btnFahrenheit";
            this.btnFahrenheit.Size = new System.Drawing.Size(36, 20);
            this.btnFahrenheit.TabIndex = 10;
            this.btnFahrenheit.Text = "->";
            this.btnFahrenheit.UseVisualStyleBackColor = true;
            this.btnFahrenheit.Click += new System.EventHandler(this.btnFahrenheit_Click);
            // 
            // btnCelsius
            // 
            this.btnCelsius.Location = new System.Drawing.Point(139, 57);
            this.btnCelsius.Name = "btnCelsius";
            this.btnCelsius.Size = new System.Drawing.Size(36, 20);
            this.btnCelsius.TabIndex = 15;
            this.btnCelsius.Text = "->";
            this.btnCelsius.UseVisualStyleBackColor = true;
            this.btnCelsius.Click += new System.EventHandler(this.btnCelsius_Click);
            // 
            // txtInCelsius
            // 
            this.txtInCelsius.Location = new System.Drawing.Point(71, 57);
            this.txtInCelsius.Name = "txtInCelsius";
            this.txtInCelsius.Size = new System.Drawing.Size(62, 20);
            this.txtInCelsius.TabIndex = 14;
            // 
            // txtCelKel
            // 
            this.txtCelKel.Enabled = false;
            this.txtCelKel.Location = new System.Drawing.Point(317, 58);
            this.txtCelKel.Name = "txtCelKel";
            this.txtCelKel.Size = new System.Drawing.Size(62, 20);
            this.txtCelKel.TabIndex = 13;
            // 
            // txtCelCel
            // 
            this.txtCelCel.Enabled = false;
            this.txtCelCel.Location = new System.Drawing.Point(249, 58);
            this.txtCelCel.Name = "txtCelCel";
            this.txtCelCel.Size = new System.Drawing.Size(62, 20);
            this.txtCelCel.TabIndex = 12;
            // 
            // txtCelFah
            // 
            this.txtCelFah.Enabled = false;
            this.txtCelFah.Location = new System.Drawing.Point(181, 58);
            this.txtCelFah.Name = "txtCelFah";
            this.txtCelFah.Size = new System.Drawing.Size(62, 20);
            this.txtCelFah.TabIndex = 11;
            // 
            // btnKelvin
            // 
            this.btnKelvin.Location = new System.Drawing.Point(139, 83);
            this.btnKelvin.Name = "btnKelvin";
            this.btnKelvin.Size = new System.Drawing.Size(36, 20);
            this.btnKelvin.TabIndex = 20;
            this.btnKelvin.Text = "->";
            this.btnKelvin.UseVisualStyleBackColor = true;
            this.btnKelvin.Click += new System.EventHandler(this.btnKelvin_Click);
            // 
            // txtInKelvin
            // 
            this.txtInKelvin.Location = new System.Drawing.Point(71, 83);
            this.txtInKelvin.Name = "txtInKelvin";
            this.txtInKelvin.Size = new System.Drawing.Size(62, 20);
            this.txtInKelvin.TabIndex = 19;
            // 
            // txtKelKel
            // 
            this.txtKelKel.Enabled = false;
            this.txtKelKel.Location = new System.Drawing.Point(317, 84);
            this.txtKelKel.Name = "txtKelKel";
            this.txtKelKel.Size = new System.Drawing.Size(62, 20);
            this.txtKelKel.TabIndex = 18;
            // 
            // txtKelCel
            // 
            this.txtKelCel.Enabled = false;
            this.txtKelCel.Location = new System.Drawing.Point(249, 84);
            this.txtKelCel.Name = "txtKelCel";
            this.txtKelCel.Size = new System.Drawing.Size(62, 20);
            this.txtKelCel.TabIndex = 17;
            // 
            // txtKelFah
            // 
            this.txtKelFah.Enabled = false;
            this.txtKelFah.Location = new System.Drawing.Point(181, 84);
            this.txtKelFah.Name = "txtKelFah";
            this.txtKelFah.Size = new System.Drawing.Size(62, 20);
            this.txtKelFah.TabIndex = 16;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(393, 117);
            this.Controls.Add(this.btnKelvin);
            this.Controls.Add(this.txtInKelvin);
            this.Controls.Add(this.txtKelKel);
            this.Controls.Add(this.txtKelCel);
            this.Controls.Add(this.txtKelFah);
            this.Controls.Add(this.btnCelsius);
            this.Controls.Add(this.txtInCelsius);
            this.Controls.Add(this.txtCelKel);
            this.Controls.Add(this.txtCelCel);
            this.Controls.Add(this.txtCelFah);
            this.Controls.Add(this.btnFahrenheit);
            this.Controls.Add(this.txtInFahrenheit);
            this.Controls.Add(this.txtFahKel);
            this.Controls.Add(this.txtFahCel);
            this.Controls.Add(this.txtFahFah);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Conversor de escalas de temperatura";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txtFahFah;
        private System.Windows.Forms.TextBox txtFahCel;
        private System.Windows.Forms.TextBox txtFahKel;
        private System.Windows.Forms.TextBox txtInFahrenheit;
        private System.Windows.Forms.Button btnFahrenheit;
        private System.Windows.Forms.Button btnCelsius;
        private System.Windows.Forms.TextBox txtInCelsius;
        private System.Windows.Forms.TextBox txtCelKel;
        private System.Windows.Forms.TextBox txtCelCel;
        private System.Windows.Forms.TextBox txtCelFah;
        private System.Windows.Forms.Button btnKelvin;
        private System.Windows.Forms.TextBox txtInKelvin;
        private System.Windows.Forms.TextBox txtKelKel;
        private System.Windows.Forms.TextBox txtKelCel;
        private System.Windows.Forms.TextBox txtKelFah;
    }
}

