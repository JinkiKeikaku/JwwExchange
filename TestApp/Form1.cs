using System;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace TestApp {
    public partial class Form1 : Form {
        public Form1() {
            InitializeComponent();
        }

        private void btnOpen_Click(object sender, EventArgs e) {
            var f = new OpenFileDialog();
            f.Filter = "Jww Files|*.jww|Jws Files|*.jws|All Files|*.*";
            if (f.ShowDialog() != DialogResult.OK) return;
            OpenFile(f.FileName);
            //ガベコレしないとunmanage側のString関係のオブジェクトでコンソールにメッセージが出るので
            //ここでガベコレしています。メッセージは出ていても問題はないそうですが、
            //デバッグ中のメモリリークの確認のためにここに入れました。無くても構いません。
            GC.Collect();

        }

        private void btnSave_Click(object sender, EventArgs e) {
            SaveFile("d:\\test0.jww");
            //ガベコレしないとunmanage側のString関係のオブジェクトでコンソールにメッセージが出るので
            //ここでガベコレしています。メッセージは出ていても問題はないそうですが、
            //デバッグ中のメモリリークの確認のためにここに入れました。無くても構いません。
            GC.Collect();
        }

        void SaveFile(string path) {
            using var a = new JwwHelper.JwwWriter();

            //JwwHelper.dllと同じフォルダに"template.jww"が必要です。
            //"template.jww"は適当なjwwファイルでそのファイルからjwwファイルのヘッダーをコピーします。
            //Headerをプログラムから設定してもいいのですが、項目が多いので大変です。
            a.InitHeader("template.jww");

            //ヘッダーの変更は初期化後に行います。
            a.Header.m_aStrGLayName[0] = "ABC";
            a.Header.m_aStrGLayName[1] = "日本語";
            //図形オブジェクトを作ってAddData()で書き込む図形を追加します。
            //適当に斜めの線を追加します。
            //var s = new JwwHelper.JwwSen();
            //s.m_start_x = 100.0;
            //s.m_start_y = 100.0;
            //s.m_end_x = -100.0;
            //s.m_end_y = -100.0;
            for (int i = 0; i < 100; i++) {
                var s = new JwwHelper.JwwSen();
                s.m_start_x = 100.0 + i;
                s.m_start_y = 100.0;
                s.m_end_x = -100.0 + i;
                s.m_end_y = -100.0;
                a.AddData(s);
            }
            //Write()で書き込み。
            a.Write(path);
        }

        private void Form1_DragDrop(object sender, DragEventArgs e) {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop, false);
            if (files.Length < 1) return;
            OpenFile(files[0]);
        }

        private void Form1_DragEnter(object sender, DragEventArgs e) {
            if (e.Data.GetDataPresent(DataFormats.FileDrop)) {
                e.Effect = DragDropEffects.All;
            } else {
                e.Effect = DragDropEffects.None;
            }
        }
        void OpenFile(String path) {
            try {
                if (Path.GetExtension(path) == ".jww") {
                    //JwwReaderが読み込み用のクラス。
                    using var reader = new JwwHelper.JwwReader();
                    //Completedは読み込み完了時に実行される関数。
                    reader.Read(path, Completed);
                    var a = reader.Header.m_jwwDataVersion;

                } else if (Path.GetExtension(path) == ".jws") {
                    //jwsも読めますが、このプロジェクトでは確認用のコードがありません。
                    using var a = new JwwHelper.JwsReader();
                    a.Read(path, Completed2);
                }
            } catch (Exception exception) {
                textBox1.Text = "";
                MessageBox.Show(exception.Message, "Error");
            }
        }

        //dllでjwwファイル読み込み完了後に呼ばれます。これは確認用のコードです。
        void Completed(JwwHelper.JwwReader reader) {
            var sb = new StringBuilder();
            var header = reader.Header;
            sb.AppendLine("Paper:" + header.m_nZumen);
            sb.AppendLine("Layers=============================================");
            for (var j = 0; j < 16; j++) {

                sb.AppendLine("Layer group " + j + " Name:" + header.m_aStrGLayName[j] + " Scale:" + header.m_adScale[j]);
                for (var i = 0; i < 16; i++) {
                    if (i % 2 == 1) {
                        sb.AppendLine("  Layer " + i + " Name:" + header.m_aStrLayName[j][i]);
                    } else {
                        sb.Append("  Layer " + i + " Name:" + header.m_aStrLayName[j][i]);
                    }
                }
            }
            sb.AppendLine("Blocks=============================================");
            sb.AppendLine("Size of blocks:" + reader.GetBlockSize());
            //foreach (var s in reader.Blocks) {
            //    sb.AppendLine(s.ToString());
            //}

            sb.AppendLine("Shapes=============================================");
            var dataList = reader.DataList;
            foreach (var s in dataList) {
                sb.Append(s.GetType().Name);
                sb.AppendLine(s.ToString());
            }
            sb.AppendLine("Imagess=============================================");
            var images = reader.Images;
            foreach (var s in images) {
                sb.Append(s.ImageName + "  ");
                sb.AppendLine(s.Size + "bytes");
            }
            textBox1.Text = sb.ToString();


        }
        //dllでjwsファイル読み込み完了後に呼ばれます。確認用のコードは未実装。
        void Completed2(JwwHelper.JwsReader reader) {
            var sb = new StringBuilder();
            var header = reader.Header;
            sb.AppendLine("Bounds=============================================");
            sb.AppendLine($"({header.m_Bounds_Left}, {header.m_Bounds_Bottom}, {header.m_Bounds_Right}, {header.m_Bounds_Top})");
            sb.AppendLine("Origin=============================================");
            sb.AppendLine($"({header.m_Origin_x}, {header.m_Origin_y})");
            sb.AppendLine("Scales=============================================");
            foreach (var s in header.m_Scales) {
                sb.AppendLine(s.ToString());
            }
            sb.AppendLine("Blocks=============================================");
            sb.AppendLine("Size of blocks:" + reader.GetBlockSize());
            sb.AppendLine("Shapes=============================================");
            var dataList = reader.DataList;
            foreach (var s in dataList)
            {
                sb.Append(s.GetType().Name);
                sb.AppendLine(s.ToString());
            }
            textBox1.Text = sb.ToString();
        }

    }
}
