#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> maps)
{
	// Grid Size
	int n = maps.size();
	int m = maps[0].size();

	// direction
	int dy[4] = { 0, 0, -1, 1 };
	int dx[4] = { -1, 1, 0, 0 };

	// Queue Init
	queue<pair<int, int>> q;
	q.push({ 0,0 });

	// Visited Init
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[0][0] = true;

	// Distance Init
	vector<vector<int>> distance(n, vector<int>(m, -1));
	distance[0][0] = 1;

	// BFS loop
	while(!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for(int i=0; i<4; ++i)
		{
			int ny = y+dy[i];
			int nx = x+dx[i];

			// In Grid
			if(0<=ny && 0<=nx && ny<n && nx<m)
			{
				// Not Wall, Not Visited
				if(maps[ny][nx]==1 && !visited[ny][nx])
				{
					visited[ny][nx] = true;
					q.push({ ny,nx });
					distance[ny][nx] = distance[y][x]+1;
				}
			}
		}
	}

	return distance[n-1][m-1];
}

int solution(vector<vector<int>> maps)
{
	int answer = bfs(maps);

	return answer;
}