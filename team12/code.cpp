#include<bits/stdc++.h>
using namespace std;
int dr[4][2]={(1,0),(0,1),(-1,0),(0,-1)};
vector<pair<int,int>> findPath(char start,char dest,int m,int n,vector<vector<char>>& maze){
	int si=-1,sj=-1,di=-1,dj=-1;
	for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(maze[i][j]==start){
                si=i;
                sj=j;
            }
            if(maze[i][j]==dest){
                di=i;
            	dj=j;
            }
        }
    }
	queue<pair<int,int>>q;
	vecctor<vector<bool>>visited(m,vector<bool>(n,false));
	q.push({si,sj});
	visited[s1][sj]=true;
	while(!q.empty()){
		char curr=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nr=curr+dr[i][0];
			int nc=curr+dr[i][1];
			if(nr>=0&&nr<m&&nc>=0&&nc<n&&!visited[nr][nc]&&maze[nr][nc]!='#'){
				visited[nr][nc]=true;
				q.push({nr,nc});
			}
		}
	}
}
int main(){
	int m,n;
	cin>>m>>n;
	vector<vector<char>>maze(m,vector<char>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>maze[i][j];
		}
	}
	char start,dest;
	cin>>start>>dest;
	vector<pair<int,int>>path=findPath(start,dest,m,n,maze);
	for(auto &p:path){
		cout<<"("<<p.first<<","<<p.second<<")";
	}
	return 0;
}