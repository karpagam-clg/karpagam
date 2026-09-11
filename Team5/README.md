 2048 Game

A simple console-based implementation of the 2048 game using C++.

The program allows the user to create an N x N board and move the tiles in four directions: left, right, up, and down.

Team Members

717824P306 - Arjun P
717824P328 - Kowshick Kumar R K
717824P336 - Niranjan S
717824Y101 - Abishek R
717824Y130 - Niranjan S
717824Y146 - Shabunath R
717824Y141 - Sabari B
717824Y162 - Vijayaragavan R

Problem Description

The program follows the basic rules of 2048:

* All non-zero tiles move in the selected direction.
* Two equal tiles merge when they collide.
* The merged tile becomes their sum.
* A tile created by a merge cannot merge again in the same move.
* Empty spaces are represented by 0.
* The updated board is displayed after every move.

Example:

2 + 2 = 4
4 + 4 = 8
8 + 8 = 16

Features

* Supports any `N x N` board size
* Move left, right, up, and down
* Handles tile merging correctly
* Prevents multiple merges in a single move
* Displays the board after every move
* Menu-driven console program



Input board:

2 0 2 4
4 4 0 2
0 2 2 0
8 0 0 8

After moving left:

4 4 0 0
8 2 0 0
4 0 0 0
16 0 0 0

 Complexity

For each move:

* Time Complexity: O(N²)
* Extra Space: O(N)

 Technologies Used

* C++
* STL vector
* STL stack
