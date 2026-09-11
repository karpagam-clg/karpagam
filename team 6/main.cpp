#include <iostream>
#include <vector>
using namespace std;
int isPath(vector<vector<int>> &patharr,int n,int m, int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || patharr[i][j]==0){
        return 0;
    }
    if(patharr[i][j] == 3){
        return 1;
    }
    patharr[i][j] = 0;
    int right = isPath(patharr,n,m, i, j+1);
    int down = isPath(patharr,n,m, i+1, j);
    int left = isPath(patharr,n,m, i, j-1);
    int up = isPath(patharr,n,m, i-1, j);
    patharr[i][j] = 1;
    int paths = right + down + left + up;
    return paths;
}


int main() {
    cout << "Enter N (rows) x M (columns) of path"<<endl;
    int n, m;
    cin >> n;
    cin >> m;
    int paths = 0;
    vector<vector<int>> patharr(n, vector<int>(m));
    cout<<"Enter Path"<<endl<< " 2 is start , 1 is path , 0 is wall and 3 is endpoint"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>patharr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(patharr[i][j] == 2) {
                paths = isPath(patharr, n, m, i, j);
                break;
            }
        }
    }

    if(paths!=0){
        cout<<"Path Exists , No of Paths: " << paths;
    }

    else{
        cout<<"Path Doesn't Exist";
    }

    return 0;
}