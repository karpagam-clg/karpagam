#include<bits/stdc++.h>
using namespace std;
bool checkrow(int r,int c,int val,vector<vector<int> >& mat){
	for(int i=0;i<9;i++){
		if(mat[r][i]==val){
			return false;
		}
	}
	return true;
}
bool checkcol(int r,int c,int val,vector<vector<int> >& mat){
	for(int i=0;i<9;i++){
		if(mat[i][c]==val){
			return false;
		}
	}
	return true;
}
bool checksub(int r,int c,int val,vector<vector<int> >& mat){
	int i=0;
	int j=0;
	if((r/3)==0){
		i=0;
	}
	else if((r/3)==1){
		i=3;
	}
	else if((r/3)==2){
		i=6;
	}
	if((c/3)==0){
		j=0;
	}
	else if((c/3)==1){
		j=3;
	}
	else if((c/3)==2){
		j=6;
	}
	for(int p=i;p<i+3;p++){
		for(int q=j;q<j+3;q++){
			if(mat[p][q]==val){
				return false;
			}
		}
	}
	return true;
}
void print(vector<vector<int> >& mat){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
}
int main(){
	vector<vector<int> >matrix(9,vector<int>(9));
	vector<vector<bool> >vis(9,vector<bool>(9,false));
	int wrong=0;
	int cur=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>matrix[i][j];
			if(matrix[i][j]!=0){
				vis[i][j]=true;
				cur=cur+1;
			}
			
		}
	}
	print(matrix);
	while(true){
		if(cur==81){
			cout<<"win!! game over"<<endl;
			print(matrix);
			break;
		}
		if(wrong==5){
			cout<<"lost!! game over"<<endl;
			break;
		}
		
		string op;
		cout<<"update or delete"<<endl;
		cin>>op;
		int r,c;
		cout<<"enter r and c"<<endl;
		cin>>r>>c;
		if(op=="delete"){
			if(matrix[r][c]!=0){
			    matrix[r][c]=0;
			    cur=cur-1;
			}
		}
		else{
			int val;
			cout<<"enter val"<<endl;
		   cin>>val;
		    if(vis[r][c]==true){
			    cout<<"not possible";
		    }
		    else{
		     	bool row=checkrow(r,c,val,matrix);
		        bool col=checkcol(r,c,val,matrix);
		        bool sub=checksub(r,c,val,matrix);
		        if(row && col && sub){
		        	if(matrix[r][c]==0){
					 cur=cur+1;	
					}
		    	    matrix[r][c]=val;
		    	    cout<<"true"<<endl;
			    }
			    else{
			    	wrong=wrong+1;
				    cout<<"false"<<endl;
			    }
		    }
		}
		
		
		
	}
}
