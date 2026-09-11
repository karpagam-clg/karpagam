#include<bits/stdc++.h>
#define vvi  vector<vector<int>> 
using namespace std;
int moves = INT_MAX;
int n;
vector<vvi> result;
vector<vvi> temp;
bool check2(vvi& c){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(c[i][j]) cnt++;                
        }
    }
    return cnt==1;
}
bool check(vvi & p,vvi & c){
    return p!=c;
}
vvi up(vvi mat){
    for(int i = n-1; i >= 1; i--){
        for(int j =0; j< n;j++){
            if(mat[i][j]==mat[i-1][j]){
                mat[i-1][j] += mat[i][j];
                mat[i][j] = 0; 
            }
        }
    }
    return mat;
}
vvi down(vvi mat){
    for(int i = 0;  i < n-1; i++){
        for(int j =0; j< n;j++){
            if(mat[i][j]==mat[i+1][j]){
                mat[i+1][j] += mat[i][j];
                mat[i][j] = 0; 
            }
        }
    }
        return mat;
}
vvi right(vvi mat){
    for(int j = 0; j < n-1; j++){
        for(int i =0; i< n;i++){
            if(mat[i][j]==mat[i][j+1]){
                mat[i][j+1] += mat[i][j];
                mat[i][j] = 0; 
            }
        }
    }
        return mat;
}
vvi left(vvi mat){
    for(int j = n-1; j >= 1; j--){
        for(int i =0; i< n;i++){
            if(mat[i][j]==mat[i][j-1]){
                mat[i][j-1] += mat[i][j];
                mat[i][j] = 0; 
            }
        }
    }
        return mat;
}


void rec(vvi mat,int move){
    temp.push_back(mat);
    if(check2(mat)){
        if(move < moves){
            moves = move;
            result = temp;
            return;
        }
    }
    vvi u = up(mat);
    vvi d = down(mat);
    vvi r = right(mat);
    vvi l = left(mat);
    if(u!=mat){
        rec(u,move+1);
    }
    if(d!=mat){
        rec(d,move+1);
    }
    if(l!=mat){
        rec(l,move+1);
    }
    if(r!=mat){
        rec(r,move+1);
    }
    temp.pop_back();
}

int main(){
    cout<<"enter the Square Matrix Size"<<endl;
    cin>>n;
    cout<<"enter the Square matrix value line by line"<<endl;
    vector<vector<int>> mat;
    mat.resize(n,vector<int>(n,0));
    cout<<" 0. for empty , 2,4,8"<<endl;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)    cin>>mat[i][j];
    }
    rec(mat,0);
    if(moves == INT_MAX)    cout<<"None of the moves give you the answer";
    else{
            int cnt=0;
            for(vvi a : result){
                cout<<"move :"<<cnt++<<endl;
                for(int i=0;i<n;i++){
                   for(int j=0;j<n;j++)
                        cout<<a[i][j]<<' ';
                cout<<endl;                
            }
            cout<<endl;
            }
    }
    return 0;
}