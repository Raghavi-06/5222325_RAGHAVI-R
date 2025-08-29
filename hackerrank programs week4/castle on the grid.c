#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Point
 {
    int x,y,moves;
};

bool isValid(int x,int y,int n,const vector<string>& grid,const vector<vector<bool>>& visited)
 {
    return x >=0 && x<n && y >=0 && y<n && grid[x][y] == '.' && !visited[x][y];
}
//function to find the minimum number of moves
int minimumMoves(int n,vector<string> grid,int startX,int startY,int goalX,int goalY)
 {
    if (startX == goalX && startY == goalY) 
    {
        return 0;
    }
    queue<Point> q;
    vector<vector<bool>> visited(n,vector<bool>(n,false));

    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    while (!q.empty())
     {
        Point current = q.front();
        q.pop();
        for (int i = current.x - 1; i >= 0; --i) 
        {
 if (grid[i][current.y] == 'X') break; 
 if (i == goalX && current.y == goalY) return current.moves+1;
    if (!visited[i][current.y])
     {
         q.push({i, current.y, current.moves + 1});
         visited[i][current.y] = true;
     }
 }
    for (int i = current.x + 1; i < n; ++i)
     {
if (grid[i][current.y] == 'X') break;
 if (i == goalX && current.y == goalY) return current.moves+1;
     if (!visited[i][current.y]) 
     {
     q.push({i, current.y, current.moves + 1});
    visited[i][current.y] = true;
            }
 }
    for (int j = current.y - 1; j >= 0; --j)
     {
     if (grid[current.x][j] == 'X') break; 
if (current.x == goalX && j == goalY) return current.moves+1;
    if (!visited[current.x][j])
     {
         q.push({current.x, j, current.moves + 1});
         visited[current.x][j] = true;
  }
}
     for (int j = current.y + 1; j < n; ++j) 
    {
        if (grid[current.x][j] == 'X') break; 
if (current.x == goalX && j == goalY) return current.moves+1;
     if (!visited[current.x][j])
      {
        q.push({current.x, j, current.moves + 1});
        visited[current.x][j] = true;
     }
    }
  }
    return -1;
}
int main()
 {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> grid[i];
    }
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;
 cout << minimumMoves(n, grid, startX, startY, goalX, goalY) << endl;
    return 0;
}