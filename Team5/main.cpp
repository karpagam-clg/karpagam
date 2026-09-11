#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>>board;
void right() {
	for(int i=0; i<n; i++) {
		stack<int>st;
		for(int j=n-1; j>=0; j--) {
			int curr=board[i][j];
			if(board[i][j]==0) continue;
			if(!st.empty()&&st.top()==curr) {
				st.pop();
				st.push(-(2*curr));
				continue;
			}
			st.push(curr);
		}
		int a=0;
		while(a<n-st.size()) {
			board[i][a]=0;
			a++;
		}
		while(!st.empty()) {
			board[i][a]=abs(st.top());
			st.pop();
			a++;
		}
	}
}

void left()
{
	for(int i=0; i<n; i++)
	{
		stack<int>st;
		for(int j=0; j<n; j++)
		{
			if(board[i][j]==0)
				continue;
			if(!st.empty() && st.top()==board[i][j])
			{
				st.pop();
				st.push(board[i][j]*-2);
			}
			else
				st.push(board[i][j]);
		}
		for(int j=n-1; j>=0; j--)
		{
			if(st.size()-1!=j)
				board[i][j]=0;
			else {
				board[i][j]=st.top()<0?st.top()*-1:st.top();
				st.pop();
			}

		}
	}
}
void up()
{
	for(int i=0; i<n; i++)
	{
		stack<int>st;

		for(int j=n-1; j>=0; j--)
		{
			if(board[j][i]==0)
				continue;

			if(!st.empty() && st.top()==board[j][i])
			{
				st.pop();
				st.push(board[j][i]*-2);
			}
			else
				st.push(board[j][i]);
		}

		for(int j=0; j<n; j++)
			board[j][i]=0;

		int k=0;

		while(!st.empty())
		{
			board[k][i]=abs(st.top());
			st.pop();
			k++;
		}
	}
}

void down()
{
	for(int i=0; i<n; i++)
	{
		stack<int>st;

		for(int j=0; j<n; j++)
		{
			if(board[j][i]==0)
				continue;

			if(!st.empty() && st.top()==board[j][i])
			{
				st.pop();
				st.push(board[j][i]*-2);
			}
			else
				st.push(board[j][i]);
		}

		for(int j=0; j<n; j++)
			board[j][i]=0;

		int k=n-1;

		while(!st.empty())
		{
			board[k][i]=abs(st.top());
			st.pop();
			k--;
		}
	}
}
void print()
{
	for(auto i:board)
	{
		for(auto j:i)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	cout<<"Enter the size of board \n";
	cin>>n;
	board.resize(n,vector<int>(n,0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>board[i][j];
	print();
	bool flag=true;
	while(true)
	{
		cout<<"Enter 1. left 2. right 3.up  4. down 5. exit\n";
		int choice;
		cin>>choice;
		switch(choice) {
		case 1:
			cout<<"After left :\n";
			left();
			print();
			break;
		case 2:
			cout<<"After right :\n";
			right();
			print();
			break;
		case 3:
			cout<<"After up :\n";
			up();
			print();
			break;
		case 4:
			cout<<"After down :\n";
			down();
			print();
			break;
		case 5:
			flag=false;
		default:
			cout<<"Invalid choice\n ";
		}
		if(!flag)
			break;
	}
	cout<<"Thanks for playing";
	return 0;
}