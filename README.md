Registration id:

717824P332
717824P345
717824P359
721224ITAD32
717824I206
717824I229
717824I136

Logic(Maze Game)

Given an n*m matrix, source, destination.
# represent wall and . represent a path.
The problem is to find the path from source to destination.
Here we using BFS approach to find the shortest path from source to destination.

Approach:

Step 1: Here we start from the source.
Step 2: Push the source into the queue and marked the cell as visited.
Step 3: Check all the adjacent cell whether it has block(#) or way(.) and also check if the adjacent is visited or not.
Step 4: If the adjacent cell is not visited and also it has a way(.) we move to that cell and marked the cell as visited.
Step 5: Repeat Steps 3–4 until the destination is reached or the queue becomes empty.
Step 6: Once we reach the destination return the path.

For Eg:

S . # . .
. . . . .
# . D . .
. # . . .
. . . . #

1.Start from source 's'.
2.Move to (0,1) since the destination is not here we move further.
3.Then move to (1,1)-> (1,2).
4.Now after move down from (1,2) we reached the destination at (2,2).
5.Return the path.