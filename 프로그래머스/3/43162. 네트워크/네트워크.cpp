#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visited(200, false);

void dfs(int start, int n, vector<vector<int>> computers)
{
	// Stack Init
	stack<int> st;
	st.push(start);

	while(!st.empty())
	{
		int tar = st.top();
		st.pop();

		for(int i=0; i<n; ++i)
		{
			if(!visited[i] && computers[tar][i])
			{
				visited[i] = true;
				st.push(i);
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

	for(int i=0; i<n; ++i)
	{
		if(!visited[i])
		{
			visited[i] = true;
			dfs(i, n, computers);
			answer++;
		}
	}
    return answer;
}