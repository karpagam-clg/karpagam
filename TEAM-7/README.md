# Team 7

## Team Members:
- Mohit S - 717824F335
- Arulkumaran E - 717824f208
- Anil N - 717824f206
- Hendrapandian S - 717824E121
- Dhinagaran M - 717824V116
- Logidth M - 717824V134

## Problem: Sudoku

### Ideas:
- Valid Sudoku
- Sudoku Solver

### What we did: Valid Sudoku

### Methods:
For every cell we check if it is valid or not by checking the rows, columns, and their respective 3x3 matrix.
Before doing that, we created a tracking structure where each row, col, and 3x3 box has its possible element placements (1-9). Then we traverse through all the elements of the input and remove the corresponding element from the row, col, and box trackers.
The index calculation for the box vector is a bit tricky. For an element at sudo[i][j], it needs to be removed from row[i] (as it is placed in the i'th row) and col[j] (as it is placed in the j'th col).
For the box index, the element from (i, j) in the sudoku grid is placed with respect to its 3x3 perspective, since the 9-length columns and rows are divided into groups of 3. Elements with row and column indices from 0-2 (or 1-3) are in the first box, and so on.
To calculate the exact index for the respective 3x3 boxes, we used this formula:
`"Box Index"=(i/3)*3+(j/3)`

After removing the occurred elements during traversal, the row, col, and box matrixes hold whatever possible elements can still be placed. For a valid sudoku matrix, the remaining possibilities shouldn't conflict with the rules. We traverse for every element and return valid if everything checks out. :)
