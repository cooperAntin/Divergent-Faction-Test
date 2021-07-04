using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Windows.Forms;
using System.Diagnostics;

namespace divergent
{
    public partial class Form2 : Form
    {

        Stopwatch stopWatch = new Stopwatch();
        bool timing = true;

        string[] allTimes = new string[20];

        //receive the array allTimes sent by Form1, represented as arrayOne, and make array allTime in this form equivalent
        //to the array received from Form1
        public void recieveData(string[] arrayOne)
        {
            int count = 0;


            while (count < arrayOne.Length)
            {
                allTimes[count] = arrayOne[count];
                count++;

            }

        }


        
        public Form2()
        {
         
            InitializeComponent();
           
            go(timing, stopWatch);
            timing = false;

        }

        public void go(bool a, Stopwatch clock)
        {
            if (a == true)
            {
                clock.Start();

            }
            else if (a == false)
            {

                double toDouble;
                string toString;

                clock.Stop();
                TimeSpan difference = clock.Elapsed;
                toDouble = difference.TotalMilliseconds;
                toString = toDouble.ToString();

                int subcount = 0;
                while (allTimes[subcount] != null)
                {
                    subcount++;
                }
                allTimes[subcount] = toString;


            }
            else
            {
                throw new ArgumentException("There was an error somewhere!");
            }
        }


  





        private void Form2_Load(object sender, EventArgs e)
        {

        }

       

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            go(timing, stopWatch);

            Form3 questionThree = new Form3();
            questionThree.recieveData(allTimes);
            this.Visible = false;

            questionThree.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            go(timing, stopWatch);

            Form3 questionThree = new Form3();
            questionThree.recieveData(allTimes);
            this.Visible = false;

            questionThree.Show();
        }
    }
}
