#include<bits/stdc++.h>
using namespace std;

void printmatrix(vector<vector<bool>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printv(vector<vector<int>> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool checkScore(int score, int N, int m){
    if((N*N)-m==score){
        return true;
    }
    return false;
}

int main() {
    int N;
    
    int score=0;
    int m;
    cin>>N;
    cin>>m;
    int z=m;

   vector<vector<int>> v(N, vector<int>(N,0));
   vector<vector<bool>> visited(N, vector<bool>(N, true));
    
    while(z--){
        int x,y;
        cin>>x>>y;
        visited[x][y] = false;
        v[x][y] = 0;

    }

    printmatrix(visited);
    cout<<"\n";
    printv(v);

    cout<<"USER INPUT\n";  
    bool flag = true;

    while(flag == true){
        
        if(checkScore(score, N, m)){
            cout<<"YOU WON\n";
            cout<<"SCORE: "<<score<<"\n";
            break;
        }

        cout<<"Enter value between 0 to "<<N-1<<":\n";
        int x,y;
        cin>>x>>y;
        //Edge case handling
        if(x<0 || x>=N || y<0 || y>=N){
            cout<<"INVALID INPUT\n";
            continue;
        }

        if(visited[x][y] != false){
            score++;
            v[x][y] = 1;
           
            cout<<"\n";
            printv(v);
            cout<<score<<"\n";
        }
        
        else {
            cout<<"GAME OVER\n";
            cout<<"SCORE: "<<score<<"\n";
            flag = false;
        }
        

       
        
        
    }

    
    return 0;
}
