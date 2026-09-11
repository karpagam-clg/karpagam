Maze Game:
	
	In this game we are given a n*m Matrix 
		'.' represents Safe to move 
		'#' represents wall Not safe to move
		You can start at (0,0) and you have to reach to (n-1,m-1) 
		Start at (0,0) and goal is (n-1,m-1) 
		if path is available return min cost and its path
		if not return -1

	For this problem we have used BFS to find whether there exisits a path or not
	
	Sample Input:
		Enter n:
		4
		Enter m:
		4
		Enter :1th Row:
		.###
		Enter :2th Row:
		....
		Enter :3th Row:
		###.
		Enter :4th Row:
		##..

	Sample Output:

		Path Reach(3,3) is (0,0)->(1,0)->(1,1)->(1,2)->(1,3)->(2,3)->(3,3)

		Minimum Cost at Reach(3,3) is 6


Team Members:
	Ajay R (721224ECAD05)
	Deepak K S (721224ECAD17)
    Nithish R (721224ECBD43)
	Tharunvarshan T (721224ECCD46)
	Santhosh M 717824P249