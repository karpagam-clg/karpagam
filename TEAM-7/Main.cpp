#include <bits/stdc++.h>
using namespace std;
vector<int> sample = {1,2,3,4,5,6,7,8,9};
vector<vector<int>> row (9,vector<int>(sample.begin(),sample.end()));
vector<vector<int>> col (9,vector<int>(sample.begin(),sample.end()));
vector<vector<int>> box (9,vector<int>(sample.begin(),sample.end())); 
void possi(vector<vector<int>>& sudo)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            row[i].erase(remove(row[i].begin(),row[i].end(),sudo[i][j]),row[i].end());
            col[j].erase(remove(col[j].begin(), col[j].end(), sudo[i][j]), col[j].end());
            int idx = ((i/3)*3)+(j/3);
            box[idx].erase(remove(box[idx].begin(),box[idx].end(),sudo[i][j]),box[idx].end());
        }
    }
}
bool print()
{
    for(int i=0;i<9;i++)
    {
        if(row[i].size()>0)
        {
            return false;
        }
        if(col[i].size()>0)
        {
            return false;
        }
        if(box[i].size()>0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<vector<int>> sudo = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};
    possi(sudo);
    if(print())
    {
        cout<<"valid";
    }
    else
    {
        cout<<"Invalid";
    }
    return 0;
}
