package com.kce.infosys;

import java.util.*;

class Pair{
	int[] curr;
	String path;
	Pair(int[] curr,String s){
		this.curr=curr;
		this.path=s;
	}
}

public class MazeGame {

	public static int find(char[][] mat) {
		int n=mat.length,m=mat[0].length;
		Queue<Pair> q=new LinkedList<>();
		boolean[][] visited=new boolean[n][m];
		q.offer(new Pair(new int[] {0,0,0},"(0,0)"));
		visited[0][0]=true;
		int dirs[][]= {{0,-1},{0,1},{-1,0},{1,0}};
		while(!q.isEmpty()) {
			Pair p=q.poll();
			int curr[]=p.curr;
			String path=new String(p.path);
			int i=curr[0],j=curr[1],dist=curr[2];
			if(i==n-1 && j==m-1) {
				System.out.println();
				System.out.println("Path Reach("+(n-1)+","+(m-1)+") is "+path);
				System.out.println();
				return dist;
			}
			for(int d[]:dirs) {
				int x=i+d[0],y=j+d[1];
				if(x<0 || y<0 || x>=n || y>=m || visited[x][y] || mat[x][y]=='#')continue;
				visited[x][y]=true;
				q.offer(new Pair(new int[] {x,y,dist+1},new String(path+"->("+x+","+y+")")));
			}
		}
		System.out.println("No Path Exists");
		return -1;
	}
	
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
//		char mat[][]= {
//		{'.','#','#'},
//		{'.','#','.'},
//		{'.','.','.'}
//};
		System.out.println("Enter n:");
		int n=sc.nextInt();
		System.out.println("Enter m:");
		int m=sc.nextInt();
		char[][] mat=new char[n][m];
		for(int i=0;i<n;i++) {
			System.out.println("Enter :"+(i+1)+"th Row:");
			String s=sc.next();
			for(int j=0;j<m;j++) {
				mat[i][j]=s.charAt(j);
			}
		}
		int cost=find(mat);
		if(cost!=-1)
		System.out.println("Minimum Cost at Reach("+(n-1)+","+(m-1)+") is "+cost);
	}
	
}
