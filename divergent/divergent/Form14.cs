using System;
using System.Globalization;
using System.Windows.Forms;
using System.Collections;

namespace divergent
{
    public partial class Form14 : Form
    {

  
        string[] allTimes = new string[20];

        //This variable will represent the attribute in which the quiz-taker scored the highest

        //These variables will represent the attributes that were being tested in each question, in the order that they were being tested in. 
        //'Neutral' represents a question that does not count for the score, for whatever reason. In the first case because it was an exmplanatory 
        //example question, in the second because the question is meant to confuse efforts to manipulate the quiz, and the final because it is a 
        //relativly easy question that is meant to cause the test-taker to feel more confident after dealing with somewhat difficult questions. None of 
        //the 'neutral' questions will count for which faction the quiz-taker is sorted into. 
        double neutralOne;
        double abnegationOne;
        double euraditeOne;
        double amnityOne;
        double dauntlessOne;
        double candorOne;
        double neutralTwo;
        double euraditeTwo;
        double dauntlessTwo;
        double abnegationTwo;
        double candorTwo;
        double amnityTwo;
        double neutralThree;

        //These variables will represent the total amount of time spent solving problems testing each attribute;

        double abnegationTotal;
        double euraditeTotal;
        double amnityTotal;
        double dauntlessTotal;
        double candorTotal;







        //this function checks a against values b, c, d, and e to see if it is the largest number of the five
        public bool checkAgainstAll( double a, double b, double c, double d, double e)
        {
            if(a < b)
            {
                return false;
            }
            else if(a < c)
            {
                return false;
            }
            else if (a < d)
            {
                return false;
            }
            else if ( a < e)
            {
                return false;
            }
            else
            {
                return true;
            }

        }



        public void recieveData(string[] arrayOne)
        {
            
        
            int count = 0;


     
            while (count < arrayOne.Length)
            {
                allTimes[count] = arrayOne[count];
                count++;

            }
        }












        public Form14()
        {
            
           InitializeComponent();



            


           



            
        }

        public void alter()
        {
            //This function will be very clunky. The problem I'm trying to solve here could have been solved more succinctly by just creating an array 
            //of doubles, but it would be less visually obvious what I'm doing and, at least for me, harder to modify in the future if ever I should need to. 
            //Therefore I used a more brutish method of assigning each variable individually. 





            //set intercount to 1, since the first value of allTimes will be a dummy value. 
            int interCount = 1;

            neutralOne = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            abnegationOne = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            euraditeOne = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            amnityOne = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            dauntlessOne = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            candorOne = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            neutralTwo = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            euraditeTwo = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            dauntlessTwo = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            abnegationTwo = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            candorTwo = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            amnityTwo = Convert.ToDouble(allTimes[interCount]);
            interCount++;
            neutralThree = Convert.ToDouble(allTimes[interCount]);


            //Total the attribute values

            abnegationTotal = abnegationOne + abnegationTwo;
            euraditeTotal = euraditeOne + euraditeTwo;
            amnityTotal = amnityOne + amnityTwo;
            dauntlessTotal = dauntlessOne + dauntlessTwo;
            candorTotal = candorOne + candorTwo;


            //This variable will represent the attribute in which the quiz-taker scored the highest
            string factionChoice = "factionless";
            //If the quiz taker receives an equal score in two or more categories, they will eventually be marked as divergent
            //The total time spent on questions testing the first attribute will be compared to the amount of time spent on
            //questions testing the other four attributes. If they spent more time on the first attribute than the others, factionChoice
            //will be set to the name of that faction. 
            double factionsMatched = 0;
            if (checkAgainstAll(abnegationTotal, euraditeTotal, amnityTotal, dauntlessTotal, candorTotal) == true)
            {
                factionChoice = "abnegation";
                factionsMatched++;

            }
            if (checkAgainstAll(euraditeTotal, abnegationTotal, amnityTotal, dauntlessTotal, candorTotal) == true)
            {
                factionChoice = "euradite";
                factionsMatched++;

            }
            if (checkAgainstAll(amnityTotal, abnegationTotal, euraditeTotal, dauntlessTotal, candorTotal) == true)
            {
                factionChoice = "amity";
                factionsMatched++;

            }
            if (checkAgainstAll(dauntlessTotal, abnegationTotal, amnityTotal, euraditeTotal, candorTotal) == true)
            {
                factionChoice = "dauntless";
                factionsMatched++;

            }
            if (checkAgainstAll(candorTotal, abnegationTotal, amnityTotal, dauntlessTotal, euraditeTotal) == true)
            {
                factionChoice = "candor";
                factionsMatched++;

            }
            if (factionsMatched > 1)
            {
                factionChoice = "divergent";
            }

            int counterCount = 0;
            string showAllofIt = " ";
            while (counterCount < allTimes.Length)
            {
                showAllofIt = showAllofIt + " + " + allTimes[counterCount];
                counterCount++;
            }


            //Based on the word stored in 'factionChoice', the user will be taken to a form that will show them their faction
            if (factionChoice == "euradite")
            {
                Form15 euraditeScreen = new Form15();
                this.Visible = false;
                euraditeScreen.Show();

            }
            else if (factionChoice == "abnegation")
            {
                Form16 abnegationScreen = new Form16();
                 this.Visible = false;
                abnegationScreen.Show();

            }
            else if (factionChoice == "amity")
            {
                Form17 amityScreen = new Form17();
                 this.Visible = false;
                amityScreen.Show();

            }
            else if (factionChoice == "candor")
            {
                Form18 candorScreen = new Form18();
                 this.Visible = false;
                candorScreen.Show();

            }
            else if (factionChoice == "dauntless")
            {
                Form19 dauntlessScreen = new Form19();
                 this.Visible = false;
                dauntlessScreen.Show();

            }
            else if (factionChoice == "divergent")
            {
                Form20 divergentScreen = new Form20();
                 this.Visible = false;
                divergentScreen.Show();

            }
            else
            {
                this.Close();
            }
           
        }
      

       

        private void Form14_Load(object sender, EventArgs e)
        {

        }

        //When the load results button is clicked, alter will be called, calculate results, and take the user to the 
        //form represnting their faction
        private void button1_Click(object sender, EventArgs e)
        {
            alter();
        }
    }
}
