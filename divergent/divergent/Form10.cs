﻿using System;
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
    public partial class Form10 : Form
    {

        Stopwatch stopWatch = new Stopwatch();
        bool timing = true;
        string[] allTimes = new string[20];


        public void recieveData(string[] arrayOne)
        {
            int count = 0;


            while (count < arrayOne.Length)
            {
                allTimes[count] = arrayOne[count];
                count++;

            }

        }

       


        public Form10()
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






        private void Form10_Load(object sender, EventArgs e)
        {

        }



        private void button1_Click(object sender, EventArgs e)
        {
            go(timing, stopWatch);

            Form11 questionEleven = new Form11();
            questionEleven.recieveData(allTimes);
            this.Visible = false;

            questionEleven.Show();
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            go(timing, stopWatch);

            Form11 questionEleven = new Form11();
            questionEleven.recieveData(allTimes);
            this.Visible = false;

            questionEleven.Show();
        }

       
    }
}
