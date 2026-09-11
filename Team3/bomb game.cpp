#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>data;
vector<vector<char>>usr;

void display(int n){
	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<usr[i][j]<<" ";
			}
			cout<<endl;
	}
}
int main(){
	int n;
	cout<<"Enter the size"<<endl;
	cin>>n;
	data.resize(n,vector<int>(n,0));
	usr.resize(n,vector<char>(n,'?'));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			data[i][j]=1;
		}
	}
	for(int i=0;i<(n*n)/4;i++){
		int x=rand()%n;
		int y=rand()%n;
		while(data[x][y]==0){
			x=rand()%n;
			y=rand()%n;
		}
		data[x][y]=0;
	}
	
	int scr=0;
	while(1){
		display(n);
			cout<<"Current Score: "<<scr<<endl;
		int in;
		cout<<"Enter value from 1 to "<<(n*n)<<endl;
		cin>>in;
		int row=(in-1)/n,col=(in-1)%n;
		
		if(usr[row][col]!='?'){
			cout<<"Already Visited"<<endl;
			continue;
		}
		
		if(data[row][col]==0){
			cout<<"BOOM!!" <<endl;
			cout<<"Score: "<<scr<<endl;
			return 0;
		}
		
		scr+=data[row][col];
		usr[row][col]=data[row][col]+'0';
	
		
	}
	
	
	
	
}
