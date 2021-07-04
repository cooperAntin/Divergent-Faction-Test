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
    public partial class Form1 : Form
    {
        Stopwatch stopWatch = new Stopwatch();
        bool timing = true;
        string[] allTimes = new string[20];
        
        public Form1()
        {
            
            InitializeComponent();

            //function go will start the stopWatch if timing = true, and end the stopWatch if timing = false. 
            //I want the stopwatch to start when the form is initialized, and end when an answer is selected. Accordingly,
            //variable time will start off as 'true', and function 'go' will be called immediatly after initialization. Then, timing 
            //will be set to false, and go will be called again when one of the two buttons representing answers to the question are clicked. 
            //This will give us the amount of time spent on this question. 
            go(timing, stopWatch);
            timing = false;
            
        }

        
        public void go(bool a, Stopwatch clock)
        {
            
            allTimes[0] = "dummyValue";

            //When timing is true, an answer hasn't been clicked yet. When timing is false, function go has 
            //already run once, and function go is being called because an answer was clicked. 
            if (a == true)
            {
                //Begin stopWatch
                clock.Start();
              
            }
            else if (a == false)
            {
                //stopWatch is ended. Difference between the start time and stop time is taken and put into 'toDouble' variable. 
                //For testing reasons, I originally had the answers stored in an array of strings, and kept it that way so that 
                //if in the future I wanted to display all result values for whatever reason I could. But to put the times into the 
                //string array, I had to convert to string values. toString contains the string value after toDouble is converted into a string. 
                double toDouble;
                string toString;

                clock.Stop();
                TimeSpan difference = clock.Elapsed;
                toDouble = difference.TotalMilliseconds;
                toString = toDouble.ToString();

                //Place the time we just took at the earliest empty index in array allTimes. This should be 
                //the nearest index with value null, and can be found by increasing subcount untill it reaches a null value. 
                int subcount = 0;
                while (allTimes[subcount] != null)
                {
                    subcount++;
                }
                allTimes[subcount] = toString;



            }
            else
            {
                //I don't see any immediate logical problems that would cause an error, but just in case one happens anyway. 
                throw new ArgumentException("There was an error somewhere!");
            }
        }
        
    

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Call go function to end the stopWatch and put the value into array allTimes. 
            go(timing, stopWatch);

            //Next form, send array allTimes to the next form so that it can add it's own time to 
            //the array
            Form2 questionTwo = new Form2();
            questionTwo.recieveData(allTimes);
            this.Visible = false;
            
            questionTwo.Show();


        } 

        private void button2_Click(object sender, EventArgs e)
        {
            //Call go function to end the stopWatch and put the value into array allTimes. 
            go(timing, stopWatch);


            //Next form, send array allTimes to the next form so that it can add it's own time to 
            //the array
            Form2 questionTwo = new Form2();
            questionTwo.recieveData(allTimes);
            this.Visible = false;
            questionTwo.Show();

        }

        
    }
}
