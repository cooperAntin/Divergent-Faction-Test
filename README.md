# awareness5

This is a program that is able to edit itself. 

I feel the need to involve the obvious disclaimer, because this program is effectually able to modify it's own code, there is some degree of danger in taking what I have here and
modifying and especially in integrating it with other programs. Really it's ability to change itself is quite limited and probably benign, but it seems foolish not to remind whoever on the 
internet that might be seeing this that a self-modifying program can be dangerous if used badly. So though I think it is very unlikelythat anything will go wrong, here is the disclaimer!

I thought it would be interesting to make a program that can edit its own code. Both because that just seemed cool, and because such a goal seemed totally attainable!

Here's how it works:

There are four main steps to the program's self-modification. 

A) The program reads a text file containing a series of C++ instructions, named "instructions.txt", but written in text

B) The program translates the text into actionable code, and executes those instructions

C) The program edits the text file "instructions.txt"

D) The edited file now becomes the file that the program translates into code. This cycle continues indefinetly or until user ends 


Thus the program is self-editing. 

At any time, the user may hit the 'k' key followed by enter to end the program. 
Until then, the program will just keep editing itself. Though it can do so incredibly fast, moving through hundreds and hundreds of iterations a minute, I slowed it down considerably so that 
the user can observe. The delay between iterations is artificial, and just so the user can see what is happening. 

