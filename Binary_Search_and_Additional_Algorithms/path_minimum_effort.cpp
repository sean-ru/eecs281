#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(int effort, int i, int j, vector<vector<int> >& heights, vector<vector<bool> > visited);

int main()
{
    vector<vector<int> > heights(3);
    for (int i = 0; i < 3; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        heights[i].push_back(a);
        heights[i].push_back(b);
        heights[i].push_back(c);
    }

    vector<vector<bool> > visited(heights.size(), vector<bool>(heights[0].size()));
    visited[0][0] = true;
    cout << bfs(0, 0, 0, heights, visited) << endl;
}


int bfs(int effort, int i, int j, vector<vector<int> >& heights, vector<vector<bool> > visited)
{
    int M = heights.size();
    int N = heights[0].size();
    int minmaxabsdiff = INT_MAX;
    queue<pair<pair<vector<vector<bool > >, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(visited, effort), make_pair(i, j)));
    while (!q.empty())
    {
        int currmax = q.front().first.second;
        vector<vector<bool> > currvisited = q.front().first.first;
        int curri = q.front().second.first;
        int currj = q.front().second.second;
        if (curri == N - 1 & currj == M - 1)
        {
            minmaxabsdiff = min(minmaxabsdiff, currmax);
        }
        q.pop();
        int dx[4] = { 1, 0, 0, -1 };
        int dy[4] = { 0, 1, -1, 0 };
        for (int a = 0; a < 4; a++)
        {
            int ni = curri + dx[a];
            int nj = currj + dy[a];
            vector<vector<bool> > nvisited = currvisited;
            if (ni >= 0 && nj >= 0 && ni <= N-1 && nj <= M-1 && !currvisited[nj][ni])
            {
                nvisited[nj][ni] = true;
                int neffort = max(currmax, abs(heights[nj][ni] - heights[currj][curri]));
                q.push(make_pair(make_pair(nvisited, neffort),  make_pair(ni, nj)));
            }
        }
    }
    return minmaxabsdiff;
}