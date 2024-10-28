
namespace TestApp {
    partial class Form1 {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            panel1 = new System.Windows.Forms.Panel();
            btnSave = new System.Windows.Forms.Button();
            btnPaste = new System.Windows.Forms.Button();
            btnOpen = new System.Windows.Forms.Button();
            textBox1 = new System.Windows.Forms.TextBox();
            panel1.SuspendLayout();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.Controls.Add(btnSave);
            panel1.Controls.Add(btnPaste);
            panel1.Controls.Add(btnOpen);
            panel1.Dock = System.Windows.Forms.DockStyle.Top;
            panel1.Location = new System.Drawing.Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new System.Drawing.Size(906, 48);
            panel1.TabIndex = 0;
            // 
            // btnSave
            // 
            btnSave.Location = new System.Drawing.Point(145, 13);
            btnSave.Name = "btnSave";
            btnSave.Size = new System.Drawing.Size(75, 23);
            btnSave.TabIndex = 0;
            btnSave.Text = "Save";
            btnSave.UseVisualStyleBackColor = true;
            btnSave.Click += btnSave_Click;
            // 
            // btnPaste
            // 
            btnPaste.Location = new System.Drawing.Point(273, 12);
            btnPaste.Name = "btnPaste";
            btnPaste.Size = new System.Drawing.Size(75, 23);
            btnPaste.TabIndex = 0;
            btnPaste.Text = "Paste";
            btnPaste.UseVisualStyleBackColor = true;
            btnPaste.Click += btnPaste_Click;
            // 
            // btnOpen
            // 
            btnOpen.Location = new System.Drawing.Point(43, 13);
            btnOpen.Name = "btnOpen";
            btnOpen.Size = new System.Drawing.Size(75, 23);
            btnOpen.TabIndex = 0;
            btnOpen.Text = "Open";
            btnOpen.UseVisualStyleBackColor = true;
            btnOpen.Click += btnOpen_Click;
            // 
            // textBox1
            // 
            textBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            textBox1.Location = new System.Drawing.Point(0, 48);
            textBox1.Multiline = true;
            textBox1.Name = "textBox1";
            textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            textBox1.Size = new System.Drawing.Size(906, 509);
            textBox1.TabIndex = 1;
            // 
            // Form1
            // 
            AllowDrop = true;
            AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            ClientSize = new System.Drawing.Size(906, 557);
            Controls.Add(textBox1);
            Controls.Add(panel1);
            Name = "Form1";
            Text = "Form1";
            DragDrop += Form1_DragDrop;
            DragEnter += Form1_DragEnter;
            panel1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Button btnOpen;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button btnPaste;
    }
}

