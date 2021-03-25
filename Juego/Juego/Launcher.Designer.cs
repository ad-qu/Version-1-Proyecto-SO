namespace Juego
{
    partial class Launcher
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Launcher));
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.ganador = new System.Windows.Forms.RadioButton();
            this.rapida = new System.Windows.Forms.RadioButton();
            this.mayor = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.Drag_Pnl = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.Drag_Pnl)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(561, 276);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 0;
            // 
            // ganador
            // 
            this.ganador.AutoSize = true;
            this.ganador.Location = new System.Drawing.Point(561, 319);
            this.ganador.Name = "ganador";
            this.ganador.Size = new System.Drawing.Size(111, 17);
            this.ganador.TabIndex = 1;
            this.ganador.TabStop = true;
            this.ganador.Text = "Dime ganador (ID)";
            this.ganador.UseVisualStyleBackColor = true;
            // 
            // rapida
            // 
            this.rapida.AutoSize = true;
            this.rapida.Location = new System.Drawing.Point(561, 342);
            this.rapida.Name = "rapida";
            this.rapida.Size = new System.Drawing.Size(112, 17);
            this.rapida.TabIndex = 2;
            this.rapida.TabStop = true;
            this.rapida.Text = "Partida más rápida";
            this.rapida.UseVisualStyleBackColor = true;
            // 
            // mayor
            // 
            this.mayor.AutoSize = true;
            this.mayor.Location = new System.Drawing.Point(561, 365);
            this.mayor.Name = "mayor";
            this.mayor.Size = new System.Drawing.Size(107, 17);
            this.mayor.TabIndex = 3;
            this.mayor.TabStop = true;
            this.mayor.Text = "Partidas ganadas";
            this.mayor.UseVisualStyleBackColor = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(561, 405);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 4;
            this.button1.Text = "Enviar";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Drag_Pnl
            // 
            this.Drag_Pnl.BackColor = System.Drawing.Color.Transparent;
            this.Drag_Pnl.Location = new System.Drawing.Point(0, 0);
            this.Drag_Pnl.Name = "Drag_Pnl";
            this.Drag_Pnl.Size = new System.Drawing.Size(1280, 143);
            this.Drag_Pnl.TabIndex = 5;
            this.Drag_Pnl.TabStop = false;
            this.Drag_Pnl.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Drag_Pnl_MouseDown);
            this.Drag_Pnl.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Drag_Pnl_MouseMove);
            this.Drag_Pnl.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Drag_Pnl_MouseUp);
            // 
            // Launcher
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(1280, 720);
            this.Controls.Add(this.Drag_Pnl);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.mayor);
            this.Controls.Add(this.rapida);
            this.Controls.Add(this.ganador);
            this.Controls.Add(this.textBox1);
            this.DoubleBuffered = true;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Launcher";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Launcher";
            ((System.ComponentModel.ISupportInitialize)(this.Drag_Pnl)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.RadioButton ganador;
        private System.Windows.Forms.RadioButton rapida;
        private System.Windows.Forms.RadioButton mayor;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.PictureBox Drag_Pnl;
    }
}