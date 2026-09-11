Team Number :  1<br>
team Members :<br>
1. Mithulesh  717824F334<br>
2. Umanathan Muthukumaran 717824P159<br>
3. Kavin Senthil 717824Y119<br>
4. Prasanna S 717824E142<br>
5. Praveen V 717824Y136<br>
6. Arun K  717824P107<br>

PS:<br>
to create a 2048 console game<br>
INPUT<br>
 1. size of the Square matrix eg . 3<br>
 2. Enter the matrix  [0,0,0][0,0,0][0,2,2]<br>
OUTPUT:<br>
Move 0 :<br>
[2,2,2][2,2,2][2,2,2]<br>
......<br>
move 1<br>
[0,0,0][0,0,0][0,0,4]<br><br>
IDEA :<br>
Initial thought:<br>
    DP(wont work): because when we reach already calculated state, by that time the internal state would be different from what we previuosly calculated.<br>
<br>

Final Idea after polishing:<br>
    Using DFS<br>
    Valid branch :A branch gives answer only if the grid has only one element left<br>
    Invalid branch : The branch is invalid if there is no more move can be applied and it has more than 1 element left <br>
    For each grid perform 4 opp ((up , down , left ,right))<br>
    Each time pass the new calculated grid and number of moves required to attain that grid as parameters.<br>
    If the branch is valid then, if the no.of moves is less than the global move that is requird to attain the assumed ans, we will update the move and ans.<br>    
