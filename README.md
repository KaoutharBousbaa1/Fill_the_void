# Fill_the_void
In this project, I have given a set of Tetrominoes, and I have to find a way to assemble them in the smallest possible square. Here is a glance about the way I solving this problem using C language.\

1) - Validating the input :
- Moving the Tetrimino to the top-most left-most positions to find the suitable solution
- Checking every line to check if there is only “.” and “#” character
- If the number of '#' is greater than 4 exit
- Check if there are missed lines between the Tetriminos
- Checking every piece against a list of a valid Tetriminos
- Each array stores a total of 16 parameters (whether a “#” or “.” 
- Before storing the valid block into my linked list, first I shift the block to the top-left corner
- If the list doesn’t match any of the given (valid) lists, then return an error and quit simply
- If we validated the Tetrominoes, we can then put them into a linked list\

3) - Storing the arrays into a linked list:
Then I will store the arrays into a linked a list\

4) – How can I fill it using recursive backtracking algorithm?
- In our problem it’s kind of easy to express the problem recursively
I’m going to give an example for this:
Say we have two pieces:\
                              . . . .\                                     
                              . # # .\
                              . # # .\
                              . . . .\
                              ----LINE----\
                              . . . .\
                              # # # .\
                              . . . #\
                              . . . .\
When my program first started, the first piece is filled in the top left like this:\
                              A A . .\
                              A A . .\
                              . . . .\
                              . . . .\
Still won’t fit? So I will keep shifting the piece through each possible space(left, right, up, down) on the square till it will fit.
- The keys to backtracking here is the choice I make, which is shifting the first Tetriminoe, once I express that I recurse in that decision, if the decision doesn’t work I come back and I undo it and make another choice, we explore, we undo, we made another choice.
- To figure out the efficient solution, we have to find the smallest square to start with, which is : starting size = number of Teteriminoes * 2





