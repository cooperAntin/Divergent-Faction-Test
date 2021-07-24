// awareness5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <map>
#include <iterator>
#include <Windows.h>
#include <thread>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
FUNCTION TABLE OF CONTENTS (in order of appearance):

variableName-A function to assess whether a given char is a valid variable name ..........................................
numberValue-A function to assess whether a given char is a single-digit number............................................
operatorCharacter-A function to assess whether a given char is a valid operator...........................................
checkType-A function that returns whether an indicated variable is an int or a bool.......................................
matchVariable-A function that returns the actual variable associated with the variable written in text file...............
returnIntValue-A function that returns the value of an actual variable associated with text file variable.................
solveInt-A function that solves expressions related to int values.........................................................
boolSolve-A function that solves boolean expressions......................................................................
displayAll-A function that displays the values of all active variables....................................................
soulFunction-A function that randomly switches two variables in the text file.............................................
execute-A function that facilitates the solving of expressions and modifying of variables.................................
compare-A function that solves condition statements.......................................................................
abstraction-A function to translate the variables written in the text document to actual variables in the program.........
process-A function to translate the text file into a series of symbols....................................................
humanOverlord-A function to allow the user to end program at any time by hitting 'k' followed by enter....................
main-Main function........................................................................................................

*/

//Function to check if a char being compared is a viable variable name (for example, not a number)
bool variableName(char c) {

    if ((c == 'a') || (c == 'b') || (c == 'c') || (c == 'd') || (c == 'e') || (c == 'f')) {
        return true;
    }
    else if ((c == 'g') || (c == 'h') || (c == 'i') || (c == 'j') || (c == 'k') || (c == 'l')) {
        return true;
    }
    else if ((c == 'm') || (c == 'n') || (c == 'o') || (c == 'p') || (c == 'q') || (c == 'r')) {
        return true;
    }
    else if ((c == 's') || (c == 't') || (c == 'u') || (c == 'v') || (c == 'w') || (c == 'x')) {
        return true;
    }
    else if ((c == 'y') || (c == 'z')) {
        return true;
    }
    else {
        return false;
    }
}


bool numberValue(char c) {

    if ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5')) {
        return true;
    }
    else if ((c == '6') || (c == '7') || (c == '8') || (c == '9')) {
        return true;
    }
    else {
        return false;
    }
}

bool operatorCharacter(char c) {

    if ((c == '+') || (c == '-') || (c == '*') || (c == '/')) {
        return true;
    }
    else {
        return false;
    }

}

string checkType(string examine) {
    string type;
    if ((examine == "a") || (examine == "b") || (examine == "c") || (examine == "d") || (examine == "e")) {
        type = "int";
        return type;
    }
    if ((examine == "f") || (examine == "g") || (examine == "h") || (examine == "i") || (examine == "j")) {
        type = "bool";
        return type;
    }
}

char matchVariable(map<char, string> variableAssociations, string textVariableName) {
    
    string intendedValue;
    char match = 'x';
    char checkThis = textVariableName[0];
    bool isVariable = variableName(checkThis);
    if (isVariable == true) {
        if (variableAssociations.find('a') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('a')->second;
            if (intendedValue == textVariableName) {
                match = 'a';
                return match;
            }
        }
        if (variableAssociations.find('b') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('b')->second;
            if (intendedValue == textVariableName) {
                match = 'b';
                return match;
            }
        }
        if (variableAssociations.find('c') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('c')->second;
            if (intendedValue == textVariableName) {
                match = 'c';
                return match;
            }
        }
        if (variableAssociations.find('c') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('c')->second;
            if (intendedValue == textVariableName) {
                match = 'c';
                return match;
            }
        }
        if (variableAssociations.find('d') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('d')->second;
            if (intendedValue == textVariableName) {
                match = 'd';
                return match;
            }
        }
        if (variableAssociations.find('e') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('e')->second;
            if (intendedValue == textVariableName) {
                match = 'e';
                return match;
            }
        }
        if (variableAssociations.find('f') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('f')->second;
            if (intendedValue == textVariableName) {
                match = 'f';
                return match;
            }
        }
        if (variableAssociations.find('g') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('g')->second;
            if (intendedValue == textVariableName) {
                match = 'g';
                return match;
            }
        }
        if (variableAssociations.find('h') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('h')->second;
            if (intendedValue == textVariableName) {
                match = 'h';
                return match;
            }
        }
        if (variableAssociations.find('i') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('i')->second;
            if (intendedValue == textVariableName) {
                match = 'i';
                return match;
            }
        }
        if (variableAssociations.find('j') != variableAssociations.end()) {
            intendedValue = variableAssociations.find('j')->second;
            if (intendedValue == textVariableName) {
                match = 'j';
                return match;
            }
        }
    }
    else {
        match = 'z';
        return match;
    }
    

}
//Returns value of actual variable associated with variable from the text file
int returnIntValue(map<char, string> variableAssociations, string name, int a, int b, int c, int d, int e, bool f, bool g, bool h, bool i, bool j) {

    char varName= matchVariable(variableAssociations, name);
    char possibleIntName = name[0];
    int possibleIntValue = 0;
    bool isIntNumber = false;

    
    isIntNumber = numberValue(possibleIntName);
    if (isIntNumber==true) {
        possibleIntName = stoi(name);
        return possibleIntName;
    }
    else {
        if (varName == 'a') {
            return a;
        }
        else if (varName == 'b') {
            return b;
        }
        else if (varName == 'c') {
            return c;
        }
        else if (varName == 'd') {
            return d;
        }
        else if (varName == 'e') {
            return e;
        }
    }
}
//Solve integer expressions
int solveInt(string symbols[], map<char, string> variableAssociations, int position, int a, int b, int c, int d, int e, bool f, bool g, bool h, bool i, bool j) {
    //
    int leftOperator = 0;
    int rightOperator = 0;
    int answer = 0;
    int firstVarPosition = position + 1;
    int secondVarPosition = position + 3;

    string firstVarName = symbols[firstVarPosition];
    string secondVarName = symbols[secondVarPosition];
    
    leftOperator = returnIntValue(variableAssociations, firstVarName, a, b, c, d, e, f, g, h, i, j);
    rightOperator= returnIntValue(variableAssociations, secondVarName, a, b, c, d, e, f, g, h, i, j);
    int operatorPosition = position + 2;
    string check = symbols[operatorPosition];
    if (check == "+") {
        answer = leftOperator + rightOperator;
    }
    else if (check == "-") {
        answer = leftOperator - rightOperator;
    }
    else if (check == "*") {
        answer = leftOperator * rightOperator;
    }
    else if (check == "/") {
        answer = leftOperator / rightOperator;
    }
    return answer;
}

//Solve bool expressions
bool boolSolve(string symbols[], map<char, string> variableAssociations, int position, int a, int b, int c, int d, int e, bool f, bool g, bool h, bool i, bool j) {
    
    position = position + 2;

    string changeTo = symbols[position];
    
    char varName = matchVariable(variableAssociations, changeTo);
    if (changeTo == "true") {
        return true;
    }
    else if (changeTo == "false") {
        return false;
    }
    else if (varName == 'f') {
        return f;
       
    }
    else if (varName == 'g') {
        return g;
    }
    else if (varName == 'h') {
        return h;
    }
    else if (varName == 'i') {
        return i;
    }
    else if (varName == 'j') {
        return j;
    }

}

//When all all actual code has been executed drawn from the text file (because of the sequence this function will be in the program not an if loop)
//Display the values of all variables in usage. 
void displayAll(map<char, string> variableAssociations, int a, int b, int c, int d, int e, bool f, bool g, bool h, bool i, bool j) {
    string showVar;

    cout << "\n" << "\n" << "Variable Values: ";
    if (variableAssociations.find('a') != variableAssociations.end()) {
        showVar = variableAssociations.find('a')->second;
        cout << "\n" << showVar << ": " << a;
    }
    if (variableAssociations.find('b') != variableAssociations.end()) {
        showVar = variableAssociations.find('b')->second;
        cout << "\n" << showVar << ": " << b;
    }
    if (variableAssociations.find('c') != variableAssociations.end()) {
        showVar = variableAssociations.find('c')->second;
        cout << "\n" << showVar << ": " << c;
    }
    if (variableAssociations.find('d') != variableAssociations.end()) {
        showVar = variableAssociations.find('d')->second;
        cout << "\n" << showVar << ": " << d;
    }
    if (variableAssociations.find('e') != variableAssociations.end()) {
        showVar = variableAssociations.find('e')->second;
        cout << "\n" << showVar << ": " << e;
    }
    if (variableAssociations.find('f') != variableAssociations.end()) {
        showVar = variableAssociations.find('f')->second;
        cout << "\n" << showVar << ": " << boolalpha << f;
    }
    if (variableAssociations.find('g') != variableAssociations.end()) {
        showVar = variableAssociations.find('g')->second;
        cout << "\n" << showVar << ": " << boolalpha << g;
    }
    if (variableAssociations.find('h') != variableAssociations.end()) {
        showVar = variableAssociations.find('h')->second;
        cout << "\n" << showVar << ": " << boolalpha << h;
    }
    if (variableAssociations.find('i') != variableAssociations.end()) {
        showVar = variableAssociations.find('i')->second;
        cout << "\n" << showVar << ": " << boolalpha << i;
    }
    if (variableAssociations.find('j') != variableAssociations.end()) {
        showVar = variableAssociations.find('j')->second;
        cout << "\n" << showVar << ": " << boolalpha << j;
    }
    cout << "\n" << "\n";
    
}


//Randomly switches two variables in the text file
void soulfunction(string symbols[]) {

    string activeVars[] = { "x", "x", "x", "x", "x", "x", "x", "x", "x", "x"};
    int arrayLen = 10;
    int positionArray = 0;

    int iterate = 0;
  
    int phantomit = 0;
    
    string candidate;
    string candidateAccepted;
    string replaceCandidate;
    string replacedBy;



    string checkToken;

    bool acceptableMatch = false;
    while (iterate < 147) {
        checkToken = symbols[iterate];
        if (checkToken == "int") {
            phantomit = iterate + 1;
            activeVars[positionArray] = symbols[phantomit];
            positionArray++;
        }
        else if (checkToken == "bool") {
            phantomit = iterate + 1;
            activeVars[positionArray] = symbols[phantomit];
            positionArray++;
        }
        iterate++;
    }
    //This to test to make sure it was listing active variables
    /*
    cout << "\n" << "ACTIVE: ";
    for (int i=0; i < 10; i++) {
        cout << " " << activeVars[i];
    }
    */
    int choose = rand() % arrayLen + 0;
    bool found = false;
    candidate = activeVars[choose];
    while (found == false) {

        if (candidate != "x") {
            candidateAccepted = candidate;
            found = true;
            //When we decide which variable will replace it, we don't want it to replace itself!
            activeVars[choose] = "x";
        }
        else {
            choose = rand() % arrayLen + 0;
            candidate = activeVars[choose];

        }
    }


    while (acceptableMatch == false) {
        
        bool found2 = false;

        int choose2 = rand() % arrayLen + 0;
        replaceCandidate = activeVars[choose2];
        while (found2 == false) {
            if (replaceCandidate != "x") {
                replacedBy = replaceCandidate;
                found2 = true;
                //When we decide which variable will replace it, we don't want it to replace itself!
                activeVars[choose2] = "x";
            }
            else {
                choose2 = rand() % arrayLen + 0;
                replaceCandidate = activeVars[choose2];
            }
        }
     
        //Here it needs to check to make sure the variables it picked are of the same type, otherwise they can't be switched
        string type1 = "nothing";
        string type2 = "nothing";
        int ind = 0;
        int i2 = 0;
        while((type1 == "nothing")&&(ind<150)){
           if (symbols[ind] == candidateAccepted) {
               
               i2 = ind - 1;
               type1 = symbols[i2];
               
               
           }
           ind++;
        }
        ind = 0;
        i2 = 0;
        while ((type2 == "nothing") && (ind < 150)) {
            if (symbols[ind] == replacedBy) {
               
                i2 = ind - 1;
                type2 = symbols[i2];
            }
            ind++;
        }
       
        if (type1 == type2) {
            acceptableMatch = true;

        
        }
        //This was just to check that the types are matching
        //cout << type1 << " " << type2 << " " << boolalpha << acceptableMatch;
        
    }
    acceptableMatch = false;
 
   //Another test here to make sure it was selecting the things to be switched correctly
   // cout << "AI has chosen: " << candidateAccepted << " To be replaced by: " << replacedBy;
    
    fstream commandfile("Instructions.txt");
    fstream revisedfile("draftInstructions.txt");
    string str;
    int stringIndex = 0;
    int forward = 0;
    int backward = 0;
    int stringLength;

    bool initialized = false;
  
    char canidateChar = candidateAccepted[0];
    char replacedChar = replacedBy[0];
    while (getline(commandfile, str)) {
       
        stringLength = (str.length());
        stringIndex = 0;
        while (stringIndex < stringLength) {
            if ((str[stringIndex] == canidateChar) || (str[stringIndex] == replacedChar)) {
                forward = stringIndex + 1;
                if (forward < stringLength) {
                    if (str[forward] == ' ') {
                        backward = stringIndex - 1;
                        if (backward > 0) {
                            if (str[backward] == ' ') {
                                if ((initialized == false) && (str[stringIndex] == canidateChar)) {
                                    str[stringIndex] = replacedChar;
                                    initialized = true;
                                }
                                else if ((initialized == false) && (str[stringIndex] == replacedChar)) {
                                    str[stringIndex] = canidateChar;

                                }
                                else if (initialized == true) {
                                    if (str[backward - 1] == 't') {
                                        if (str[backward - 2] == 'n') {
                                            if (str[backward - 3] == 'i') {
                                                if (str[stringIndex] == canidateChar) {
                                                    str[stringIndex] = replacedChar;
                                                }
                                                else if (str[stringIndex] == replacedChar) {
                                                    str[stringIndex] = canidateChar;
                                                }
                                            }
                                        }
                                    }
                                    else if (str[backward - 1] == 'l') {
                                        if (str[backward - 2] == 'o') {
                                            if (str[backward - 3] == 'o') {
                                                if (str[backward - 4] == 'b') {
                                                    if (str[stringIndex] == canidateChar) {
                                                        str[stringIndex] = replacedChar;
                                                    }
                                                    else if (str[stringIndex] == replacedChar) {
                                                        str[stringIndex] = canidateChar;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    else {
                                        if (str[stringIndex] == canidateChar) {
                                            str[stringIndex] = replacedChar;
                                        }
                                    }

                                }
                                
                            }
                        }  
                    }
                }    
            }
         
            stringIndex++;
        }
       
        revisedfile << str << "\n";
        
    }
    stringIndex = 0;
    
    revisedfile.close();
    commandfile.close();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //This is the part where it now "rewrites" its code. The program will override file "instructions" with file "draftInstructions",
    //which will translate to the program's actions latter when it goes through the process again of reading and reacting based on the 
    //instructions file. 
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    fstream editCommandFile("Instructions.txt");
    fstream fromFile("draftInstructions.txt");
    while (getline(fromFile, str)) {

        editCommandFile << str << "\n";

    }
    editCommandFile.close();
    fromFile.close();
    
}




//Solves and modifies variables
void execute(string symbols[], int len, map<char, string> variableAssociations, int a, int b, int c, int d, int e, bool f, bool g, bool h, bool i, bool j, int *aloc, int *bloc, int *cloc, int *dloc, int *eloc, bool *floc, bool *gloc, bool *hloc, bool *iloc, bool *jloc) {
    


    int boolCount = 0;


    int intCount = 0;

    int count = 0;
    int count3 = 0;
    while (count < len) {
        if (symbols[count] == "if") {
            //Skip forward past paranthesis, at this point the condition has been evaluated
            int count2 = count + 2;
            if (symbols[count2] == "conditionTrue") {
                //This will move this variable to indicate past the condition values, paranthesis and { between
            //'if' and the first part of the expression if the if is true. 
                count3 = count + 7;
                int modifiedValue;
                string setVariable;
                
                setVariable = symbols[count3];
                char  matchedName = setVariable[0];
                string type = checkType(setVariable);
                if (type == "int") {
                    
                    //This here should actually be a variable name, coming after variable type in 'symbols'
                    setVariable = symbols[count3];
                    count3++;
                    //Find out what 'real' variable the variable represented in 'symbols' is associated with. 
                    matchedName = matchVariable(variableAssociations, setVariable);
                    // Now this gets a bit trickier. We know from the grammar that operations for integer variables will be set up using the format:
                    // variable = (variable||number) (operator) (variable||number)
                    //We now know what variable we're operating on, indicated by matchVariable, now we just need to set it to a value. 
                    //To do this, we will solve the righthand side of the '=' sign then return it back to function 'execute' as an integer value
                    modifiedValue = solveInt(symbols, variableAssociations, count3, a, b, c, d, e, f, g, h, i, j);

         
                    if (matchedName == 'a') {
                        a = modifiedValue;
                        *aloc = c;
                    }
                    else if (matchedName == 'b') {
                        b = modifiedValue;
                        *bloc = b;
                    }
                    else if (matchedName == 'c') {
                        c = modifiedValue;
                        *cloc = c;
                    }
                    else if (matchedName == 'd') {
                        d = modifiedValue;
                        *dloc = d;
                    }
                    else if (matchedName == 'e') {
                        e = modifiedValue;
                        *eloc = e;
                    }
                }
                else if (type == "bool") {
                    
                    matchedName = matchVariable(variableAssociations, setVariable);
            
                    bool boolAnswer = boolSolve(symbols, variableAssociations, count3, a, b, c, d, e, f, g, h, i, j);

                    if (matchedName == 'f') {
                        f = boolAnswer;
                        *floc = f;
                    }
                    else if (matchedName == 'g') {
                        g = boolAnswer;
                        *gloc = g;
                    }
                    else if (matchedName == 'h') {
                        h = boolAnswer;
                        *hloc = h;
                    }
                    else if (matchedName == 'i') {
                        i = boolAnswer;
                        *iloc = i;
                    }
                    else if (matchedName == 'j') {
                        j = boolAnswer;
                        *jloc = j;
                    }
                    
                }

                string kill = symbols[count3];
                while (kill != "}") {
                    count3++;
                    kill = symbols[count3];
                }
                count = count3;
            }
            else if (symbols[count2] == "conditionFalse") {
        
                while (symbols[count] != "else") {
                    count++;
                   
                }
             
                //Once we arrive at "else", we need to move past the associated '{' to the actual variable name:
                count3 = count + 3;
                int modifiedValue;
                string setVariable;

                setVariable = symbols[count3];
                
                char  matchedName = setVariable[0];
                string type = checkType(setVariable);
                if (type == "int") {

                    //This here should actually be a variable name, coming after variable type in 'symbols'
                    setVariable = symbols[count3];
                    count3++;
                    //Find out what 'real' variable the variable represented in 'symbols' is associated with. 
                    matchedName = matchVariable(variableAssociations, setVariable);
                    // Now this gets a bit trickier. We know from the grammar that operations for integer variables will be set up using the format:
                    // variable = (variable||number) (operator) (variable||number)
                    //We now know what variable we're operating on, indicated by matchVariable, now we just need to set it to a value. 
                    //To do this, we will solve the righthand side of the '=' sign then return it back to function 'execute' as an integer value
                    modifiedValue = solveInt(symbols, variableAssociations, count3, a, b, c, d, e, f, g, h, i, j);


                    if (matchedName == 'a') {
                        a = modifiedValue;
                        *aloc = a;
                    }
                    else if (matchedName == 'b') {
                        b = modifiedValue;
                        *bloc = b;
                    }
                    else if (matchedName == 'c') {
                        c = modifiedValue;
                        *cloc = c;
                    }
                    else if (matchedName == 'd') {
                        d = modifiedValue;
                        *dloc = d;
                    }
                    else if (matchedName == 'e') {
                        e = modifiedValue;
                        *eloc = e;
                    }
                }
                else if (type == "bool") {

                    matchedName = matchVariable(variableAssociations, setVariable);

                    bool boolAnswer = boolSolve(symbols, variableAssociations, count3, a, b, c, d, e, f, g, h, i, j);
                    if (matchedName == 'f') {
                        f = boolAnswer;
                        *floc = f;
                    }
                    else if (matchedName == 'g') {
                        g = boolAnswer;
                        *gloc = g;
                    }
                    else if (matchedName == 'h') {
                        h = boolAnswer;
                        *hloc = h;
                    }
                    else if (matchedName == 'i') {
                        i = boolAnswer;
                        *iloc = i;
                    }
                    else if (matchedName == 'j') {
                        j = boolAnswer;
                        *jloc = j;
                    }


                }










                string kill = symbols[count3];
                while (kill != "}") {
                    count3++;
                    kill = symbols[count3];
                }
                count = count3;           
            }
        }
        




        count++;
    }
    
}





//In this massively clunky function, we will be solving the condtion statements 
bool compare(map<char, string> variableAssociations, string val1, int intval2, bool boolval2, string type, int a, int b, int c, int d, int e, bool f, bool g, bool h, bool i, bool j) {

    string x;

    //This whole thing collapses if there is no 'a' key to check. I had to look up how to check if a key exists in a C++ map, and this appears to be
    //how you do it
    if(variableAssociations.find('a') != variableAssociations.end()) {
        x = variableAssociations.find('a')->second;

        //val1 represents the leftside of the comparison, in this case d. If val1 == x, therefore, then the key 'a' is storing a value equivalent
        //to val1. In other words, the varibale 'a' is associated with d. 
        if (val1 == x) {
            //Then left side of expression is 'a'

            //How the expression is evaluated where depend on whether we are comparing to an integer or a bool. 
            //Either way, answer will be set to 'true' if the comparison is correct and 'false' if it is incorrect

            if (type == "int") {
                if (a == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (a == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }

            }
        }
    }

    if (variableAssociations.find('b') != variableAssociations.end()) {
        //Solve if leftside value is represented by b
        x = variableAssociations.find('b')->second;
        if (val1 == x) {
            if (type == "int") {
                if (b == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (b == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }

            }
        }
    }

    if (variableAssociations.find('c') != variableAssociations.end()) {
        //Solve if leftside value is represented by c
        x = variableAssociations.find('c')->second;
        if (val1 == x) {
            if (type == "int") {
                if (c == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (c == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }

            }
        }
    }

    if (variableAssociations.find('d') != variableAssociations.end()) {
    //Solve if leftside value is represented by d
    x = variableAssociations.find('d')->second;
        if (val1 == x) {
            if (type == "int") {
                if (d == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (d == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }
            }
        }
    }

    if (variableAssociations.find('e') != variableAssociations.end()) {
    //Solve if leftside value is represented by e
    x = variableAssociations.find('e')->second;
        if (val1 == x) {
            if (type == "int") {
                if (e == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (e == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }
            }
        }
    }

    if (variableAssociations.find('f') != variableAssociations.end()) {
    //Solve if leftside value is represented by f
    x = variableAssociations.find('f')->second;
        if (val1 == x) {
            if (type == "int") {
                if (f == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (f == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }
            }
        }
    }

    if (variableAssociations.find('g') != variableAssociations.end()) {
        //Solve if leftside value is represented by g
        x = variableAssociations.find('g')->second;
        if (val1 == x) {
            if (type == "int") {
                if (g == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (g == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }
            }
        }
    }

    if (variableAssociations.find('h') != variableAssociations.end()) {
        //Solve if leftside value is represented by h
        x = variableAssociations.find('h')->second;
        if (val1 == x) {
            if (type == "int") {
                if (h == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (h == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }
            }
        }
    }

    if (variableAssociations.find('i') != variableAssociations.end()) {
        //Solve if leftside value is represented by i
        x = variableAssociations.find('i')->second;
        if (val1 == x) {
            if (type == "int") {
                if (i == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (i == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }
            }
        }
    }

    if (variableAssociations.find('j') != variableAssociations.end()) {
        //Solve if leftside value is represented by j
        x = variableAssociations.find('j')->second;
        if (val1 == x) {
            if (type == "int") {
                if (j == intval2) {
                    return true;
                }
                else {
                    return false;
                }
            }
            if (type == "bool") {
                if (j == boolval2) {
                    return  true;
                }
                else {
                    return false;
                }
            }
        }
    }

}

//The primary purpose of this function is to match the informaiton in the text file to actual variables in the function, and to 
//call other functions related to evaluating the conditions of if statements (the function called 'compare') and executing instructions
//the function called 'execute'. 

void abstraction(string symbols[], int len) {

    //This will be used to travel through array symbols
    int count = 0;
    //This will be used just to confirm that the variable is assigned
    int checkCount = 2;

    //This will be used to actually assign the value
    int takeValue = 3;
    
    int intAssigned = 0;
    int boolAssigned = 0;

    map<char, string> variableAssociations;


    //A total of 10 variables may be used for this program. 5 int, 5 bool. 
    //Whatever variables are represented in the tokens array will be represented here./////////////////////////////////////////////////////////////
    int a = 0;
    int b = 0;
    int c = 0; 
    int d = 0; 
    int e = 0;
   

    bool f = false;
    bool g = false;
    bool h = false;
    bool i = false;
    bool j = false;
    //End of variable representation//////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //Pointer variables so that future evaluations in latter functions can change the "real" variables here in the abstraction function

    int *aloc;
    int *bloc;
    int *cloc;
    int *dloc;
    int *eloc;

    bool *floc;
    bool *gloc;
    bool *hloc;
    bool *iloc;
    bool *jloc;


    aloc = &a;
    bloc = &b;
    cloc = &c;
    dloc = &d;
    eloc = &e;

    floc = &f;
    gloc = &g;
    hloc = &h;
    iloc = &i;
    jloc = &j;
    
    //End pointer variable initilization



    //Will need to convert string values from tokens (symbols) array to actual in values for ints
    int x = 0;
    //Will pull individual string values out from tokens before converting into integers
    string y = "y";

    //Will need to convert string values representing bool values in tokens (symbols) into actual bool values
    bool z = false;
    //Assign variables that were initiliazed in the text document to the variables above. /////////

    while (count < len) {

        if ((symbols[count] == "int") && (symbols[checkCount]=="=")) {
            y = symbols[takeValue];
            x = stoi(y);

            if (intAssigned == 0) {
                a = x;

                //This little bloc here will be significant latter. We need to associate the names of the real variables above
                //with the names of the variables in the text document (now in the array Tokens) so that we can do calculations latter. 
                //This will be achieved using map. 
                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('a', nameString));
                intAssigned++;
            }
            else if (intAssigned == 1) {
                b = x;

                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('b', nameString));
                intAssigned++;
            }
            else if (intAssigned == 2) {
                c = x;

                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('c', nameString));
                intAssigned++;
            }
            else if (intAssigned == 3) {
                d = x;
                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('d', nameString));
                intAssigned++;
            }
            else if (intAssigned == 4) {
                e = x;
                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('e', nameString));
                intAssigned++;
            }
        }
        else if ((symbols[count] == "bool") && (symbols[checkCount] == "=")) {

            y = symbols[takeValue];


            //Set z to true or false depending on the first letter of y
            if (y[0] == 't') {
                z = true;
            }
            else if (y[0] == 'f') {
                z = false;
            }



            if (boolAssigned == 0) {
                f = z;

                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('f', nameString));
                boolAssigned++;
            }
            else if (boolAssigned == 1) {
                g = z;

                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('g', nameString));
                boolAssigned++;
            }
            else if (boolAssigned == 2) {
                h = z;

                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('h', nameString));
                boolAssigned++;
            }
            else if (boolAssigned == 3) {
                i = z;

                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('i', nameString));
                boolAssigned++;
            }
            else if (boolAssigned == 4) {
                j = z;

                int name = count + 1;
                string nameString = symbols[name];
                variableAssociations.insert(pair<char, string>('j', nameString));
                boolAssigned++;
            }
        }



        count++;
        checkCount++;
        takeValue++;
    }
   
    
//This block of commented-out code here was mostly copied from https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/ to output
//The map so I can check to see if it's mapped correctly. Not an actual part of the program, but a part of testing
    /*
    map<char, string>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = variableAssociations.begin(); itr != variableAssociations.end(); ++itr) {
        cout << '\t' << itr->first
            << '\t' << itr->second << '\n';
    }
    cout << endl;
    */

   


    int conditionPosition = 0;
    count = 0;
    checkCount = 1;
    int nameCount = 2;
    while (count < len) {
        if ((symbols[count] == "if") && (symbols[checkCount] == "(")) {

            map<char, string>::iterator countMap;
            int nameCountOne = (checkCount + 1);
            int nameCountTwo = (checkCount + 3);
            string val1 = symbols[nameCountOne];
            string sval2 = symbols[nameCountTwo];

            char val2 = sval2[0];
            sval2 = val2;
            int intval2 = 0;
            bool boolval2 = false;
            string type = "nonsenseType";

            if (numberValue(val2)) {
                intval2 = stoi(sval2);
                type = "int";
           } 
            else if (val2 == 't') {
                boolval2 = true;
                type = "bool";
            }
            else if (val2 == 'f') {
                boolval2 = false;
                type = "bool";
            }
            
            
            if (compare(variableAssociations, val1, intval2, boolval2, type, a, b, c, d, e, f, g, h, i, j) == true) {
                symbols[checkCount + 1] = "conditionTrue";
                symbols[checkCount + 2] = "conditionTrue";
                symbols[checkCount + 3] = "conditionTrue";
            }
            if (compare(variableAssociations, val1, intval2, boolval2, type, a, b, c, d, e, f, g, h, i, j) == false) {
                symbols[checkCount + 1] = "conditionFalse";
                symbols[checkCount + 2] = "conditionFalse";
                symbols[checkCount + 3] = "conditionFalse";
                }
                
                
            

        }
        count++;
        checkCount++;
        nameCount++;

    }

    execute(symbols, len, variableAssociations, a, b, c, d, e, f, g, h, i, j, aloc, bloc, cloc, dloc, eloc, floc, gloc, hloc, iloc, jloc);
    displayAll(variableAssociations, a, b, c, d, e, f, g, h, i, j);
    

}






//Process Function, convert text file into tokens///////////////////////////////////////////////////////////////////////////////////////////////////////
void process(string raw[], string symbols[], int rawi, int symi, int len) {
    string compare;

    
    //This 'count' will move us through each line of raw text stored in raw
    int count = 0;
    //This 'subcount' will move us through each character in line stored in compare
    int subcount = 0;
    //This 'sublen' will take the length of the string we are moving through character by character, so that we know when to stop subcount
    //From increasing and stop comparison
    int sublen;
    //Sometimes, we need to "look forward" to see if a series of letters spell out a lexeme. If they don't, then we need to go back and keep
    //moving through string compare with subcount. If, however, there IS a match, phantomCount will be added to subcount, skipping forward
    //to the next character that hasn't been compared
    int phantomCount = 0;
    
    //If a match is found, we want the check to start over for the next character. Otherwise, if the function 'process' checks for one thing, 
    //doesn't find it, moves on to the next thing, finds a match, and then moves on to the next thing it won't catch if the next thing is a march for the 
    //first thing it compared. We have to start over checking it against all the possible tokens each time a match is found to prevent this
    bool match;
    
    //This will be useful latter to send the character we are comparing to other functions to determine if it is a number value or 
    //a variable name
    char c;

    while (count < len) {
        compare = raw[count];
        sublen = compare.length();
        subcount = 0;
        
        while (subcount < sublen)
        {
            c = compare[subcount];
            match = false;
            //Check for 'int' ///////////////////
            if ((compare[subcount] == 'i') && (subcount < sublen) && (match==false)) {
                phantomCount=(subcount+1);
                if ((compare[phantomCount] == 'n') && (phantomCount < sublen)) {
                    phantomCount++;
                    if ((compare[phantomCount] == 't') && (phantomCount < sublen)) {
                        phantomCount++;
                        subcount = phantomCount;
                        symbols[symi] = "int";
                        symi++;
                        match = true;
                    }
                }
                phantomCount = 0;
            }
           
            //End of check for 'int'/////////////////

            //Check for 'bool'///////////////////////

            if ((compare[subcount] == 'b') && (subcount < sublen) && (match == false)) {
                phantomCount = (subcount + 1);
                if ((compare[phantomCount] == 'o') && (phantomCount < sublen)) {
                    phantomCount++;
                    if ((compare[phantomCount] == 'o') && (phantomCount < sublen)) {
                        phantomCount++;
                        if ((compare[phantomCount] == 'l') && (phantomCount < sublen)) {
                            phantomCount++;
                            subcount = phantomCount;
                            symbols[symi] = "bool";
                            symi++;
                            match = true;
                        }
                    }
                }
                phantomCount = 0;
            }
            //End check for 'bool'///////////////////

            //Check for 'if'/////////////////////////
            if ((compare[subcount] == 'i') && (subcount < sublen) && (match == false)) {
                phantomCount = (subcount + 1);
                if ((compare[phantomCount] == 'f') && (phantomCount < sublen)) {
                    phantomCount++;
                    subcount = phantomCount;
                    symbols[symi] = "if";
                    symi++;
                    match = true;
                }
            }
            //End check for 'if'/////////////////////

            //Check for 'else'//////////////////////
            if ((compare[subcount] == 'e') && (subcount < sublen) && (match == false)) {
                phantomCount=(subcount+1);
                if ((compare[phantomCount] == 'l') && (phantomCount < sublen)) {
                    phantomCount++;
                    if ((compare[phantomCount] == 's') && (phantomCount < sublen)) {
                        phantomCount++;
                        if ((compare[phantomCount] == 'e') && (phantomCount < sublen)) {
                            phantomCount++;
                            subcount = phantomCount;
                            symbols[symi] = "else";
                            symi++;
                            match = true;
                        }
                    }
                }
            }
            //End check for 'else'//////////////////

            //Check for '='/////////////////////////

            if ((operatorCharacter(c)) && (subcount < sublen) && (match == false)) {
                phantomCount++;
                subcount = phantomCount;
                string place(1, c);
                symbols[symi] = place;
                symi++;
                match = true;
            }
            //End check for '='/////////////////////

            //Check if variable name. Call variableName function to compare to legal variable names///

            if ( (variableName(c)) && (subcount < sublen) && (match == false)) {
                phantomCount = (subcount + 1);
                if ((compare[phantomCount] == ' ') && (phantomCount < sublen)) {
                    phantomCount++;
                    subcount = phantomCount;
                    string place(1, c);
                    symbols[symi] = place;
                    symi++;
                    match = true;
                }
            }
            //End of check for variable names////////

            //Check for number values////////////////

            if ((numberValue(c)) && (subcount < sublen) && (match == false)) {
                phantomCount = (subcount + 1);
                if ((compare[phantomCount] == ' ') && (phantomCount < sublen)) {
                    phantomCount++;
                    subcount = phantomCount;
                    string place(1, c);
                    symbols[symi] = place;
                    symi++;
                    match = true;
                }
            }
            //End check for variable names////////////

            //Check for 'true' bool value/////////////
            if ((compare[subcount] == 't') && (subcount < sublen) && (match == false)) {
                phantomCount = (subcount + 1);
                if ((compare[phantomCount] == 'r') && (phantomCount < sublen)) {
                    phantomCount++;
                    if ((compare[phantomCount] == 'u') && (phantomCount < sublen)) {
                        phantomCount++;
                        if ((compare[phantomCount] == 'e') && (phantomCount < sublen)) {
                            phantomCount++;
                            subcount = phantomCount;
                            symbols[symi] = "true";
                            symi++;
                            match = true;
                        }
                    }
                }
            }
            //End check for 'true' bool value////////////

            //Check for 'false' bool value///////////////
            if ((compare[subcount] == 'f') && (subcount < sublen) && (match == false)) {
                phantomCount = (subcount + 1);
                if ((compare[phantomCount] == 'a') && (phantomCount < sublen)) {
                    phantomCount++;
                    if ((compare[phantomCount] == 'l') && (phantomCount < sublen)) {
                        phantomCount++;
                        if ((compare[phantomCount] == 's') && (phantomCount < sublen)) {
                            phantomCount++;
                            if ((compare[phantomCount] == 'e') && (phantomCount < sublen)) {
                                phantomCount++;
                                subcount = phantomCount;
                                symbols[symi] = "false";
                                symi++;
                                match = true;
                            }
                        }
                    }
                }
            }
            //End check for 'false' bool value/////////////

            //Check if '=' (set equal to) or '==' (if is equal///////
            if ((compare[subcount] == '=') && (subcount < sublen) && (match == false)) {
                phantomCount = (subcount + 1);
                if ((compare[phantomCount] == '=') && (phantomCount < sublen)) {
                    phantomCount++;
                    subcount = phantomCount;
                    symbols[symi] = "==";
                    symi++;
                    match = true;
                }
                else if ((compare[phantomCount] == ' ') && (phantomCount < sublen)) {
                    phantomCount++;
                    subcount = phantomCount;
                    symbols[symi] = "=";
                    symi++;
                    match = true;
                }
            }
            //End check for '=' and '=='/////////////////////////////

            //Check for '(' and ')'/////////////////////////////////
            if ((  (c=='(')||(c==')')) && (subcount < sublen) && (match == false)) {
                phantomCount++;
                subcount = phantomCount;
                string place(1, c);
                symbols[symi] = place;
                symi++;
                match = true;
            }
            //End check for '(' and ')'////////////////////////////

            //Check for '{' and '}'///////////////////////////////
            if (((c == '{') || (c == '}')) && (subcount < sublen) && (match == false)) {
                phantomCount++;
                subcount = phantomCount;
                string place(1, c);
                symbols[symi] = place;
                symi++;
                match = true;
            }
            //End check for '{' and '}'//////////////////////////




            //If no matches, move to next character////////////
            if (match == false) {
                subcount++;
                match = true;
            }

            
        }
        count++;

    }

}
//End of Process Function//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//This function here will be a thread, allowing the user at any time to kill the program 
void humanOverlord(bool kill) {

    string command;
    while (kill == false) {
        cin >> command;
        if (command == "k") {
            kill = true;
            exit(0);

        }
        else {
            kill = false;
        }
    }
}

int main()
{
    ///This part allows the user at any time to press 'k' followed by enter...and kill the program. 
    bool humanVeto = false;
    thread humanControl(humanOverlord, humanVeto);
 
    //This will store each line of text from Instructions.txt. Capped out at 50, kind of as an arbitrary number but also potentially as a 
    //potential precaution for how much the program is able to edit if in the future the program were expanded
    string lines[50];
    //This will be used latter, if in the future we want to change the length allowed it can just be changed in these two lines instead
    //of hardcoded everywhere else
    int controlLen = 50;

    //The file will be represented as a series of tokens to make it easier to manipulate latter
    string tokens[150];
    
    //
    string copyOftokens[150];
    
    //tokens index
    int ti;
    //lines index
    int li;

    //Tracks the number of iterations the program has gone through 
    int iteration = 0;

    //str will represent each line in the file one at a time before it is fed into array lines
    string str;
    int index;

    bool kill = false;
    int test = 0;
    while (kill == false) {
        fill(tokens, tokens + 150, 0);
        fill(copyOftokens, copyOftokens + 150, 0);
        fill(lines, lines + controlLen, " ");
        index = 0;
        ti = 0;
        li = 0;
        fstream commandfile("Instructions.txt");

        while (getline(commandfile, str)) {

            lines[index] = str;
            cout << str << "\n";
            index++;

        }

        
        commandfile.close();



        //This will translate the raw text into a series of tokens that can be more efficiently run and latter manipulated
        process(lines, tokens, li, ti, controlLen);
        for (int i = 0; i < 150; i++) {
            copyOftokens[i] = tokens[i];
        }
        abstraction(tokens, controlLen);
     
        soulfunction(copyOftokens);
       
        cout << "\n" << "ITERATION: " << iteration << "\n"<< "\n";
        cout << "_______________________________________________________________________________________________________________" << "\n" << "\n";
        iteration++;
        test++;
     

      //The program can run far too fast for a human observer to keep track of what is happening. So I had it hesistate in order to allow the user to 
      //observe what is happening more easily. 
      Sleep(1500);
        
    }
}
