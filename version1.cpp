#include<iostream>
using namespace std;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
char grid[1000][1000];

bool check(int i,int j,int n,int m){
	return (i>=0 && i<n && j>=0 && j<m);
}
void change(int n,int m){
	cout<<"Enter the number of changes:"<<endl;
	int t;
	cin>>t;
	while(t--){
		cout<<"Enter x and y: "<<endl;
		int x,y;
		cin>>x>>y;
		if(!check(x,y,n,m))
		cout<<"Invalid Boundary"<<endl;
		else{
		cout<<"Enter the value: "<<endl;
		char ch;
		cin>>ch;
		grid[x][y]=ch;
		cout<<endl;
		cout<<endl;
     	}
	}
	
}
void print(int n,int m){
	cout<<"-------RESULT-------"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
   	}
   	cout<<"-------END----------"<<endl;
}

void rec(int i,int j,int n,int m){
	int curr = grid[i][j];
	if(curr == 'E')
	{
		grid[i][j]='P';
		print(n, m);
		grid[i][j]='E';
		return;
	}
	grid[i][j]='P';
	for(int k=0;k<4;k++){
		int x=dx[k]+i;
		int y=dy[k]+j;
		if(check(x,y,n,m) && grid[x][y]!='#' && grid[x][y]!='P'){
			rec(x,y,n,m);
		}
	}
	grid[i][j]=curr;	
}
void gamestarts(int n, int m, int sx, int sy){
	while(true){
		cout<<"1. Find Path\n2. Update Grid\n3. Exit"<<endl;
		int x;
		cin>>x;
		cout<<endl;
		switch(x){
		 case 1:{
		 	rec(sx,sy,n,m);
			break;
	     }
		 case 2:{
		 	change(n,m);
			break;
		 }	
		 case 3:{
		 	return ;
		 }
		 default:{
		 	cout<<"Invalid Choice"<<endl;
			break;
		 }
		}
	}
}
int main(){
	int n,m;
	cout<<"Enter row length and column length: "<<endl;
	cin>>n>>m;
	cout<<"Enter the grid: "<<endl;
	int sx=0;
 	int sy=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>grid[i][j];
			if(grid[i][j]=='S'){
				sx=i;
				sy=j;
			}
		}
	}
	gamestarts(n, m, sx, sy);
	
	
	
}
