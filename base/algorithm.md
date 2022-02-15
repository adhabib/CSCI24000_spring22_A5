goal: print each given word the given # of times

input: text file containing words and numbers

output: another text file

steps:
. loading data from input
. declare variables
. use getline() to break up input by line (will probably in a for loop or while loop)
. use modulus with if statement to tell program if it is looking at a line of text or numbers
. break each line into separate characters using a special function
. if #, increment some total
. if comma, ignore it
. if it is a letter, save the line, break from my loop
. output into txt file

output file will be created on its own
