/*
    The Maze of Mysteries - Finding Paths  with Treasures
    0: Pathway.
    1: Wall.
    2: Exit.
    3: Treasure.
*/
#include <bits/stdc++.h>
using namespace std;
int maze[5][5] = {0, 1, 0, 0, 2,
                  0, 0, 0, 1, 0,
                  0, 3, 1, 0, 0,
                  0, 1, 0, 1, 0,
                  0, 0, 0, 0, 0};

int visited[5][5] = {0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0};

queue<int> r;
queue<int> c;

void dfs(int row, int col)
{
    //check boundary 
    if (row < 0 || row > 4 || col < 0 || col > 4)
        return;

    cout << row << "," << col <<endl;

    if (maze[row][col] == 2){
        cout << "We are in the exit!"<<endl;
    }
    // color for visited
    visited[row][col] = 1;
    if(maze[row][col] == 3)
    {
        cout<<"Found the Treasure!"<<endl;
    }
    // → move to right
    if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
    {
        dfs(row, col + 1);
    }
    // ← move to left
    if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
    {
        dfs(row, col - 1);
    }
    // ↓ move to down
    if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
    {
        dfs(row + 1, col);
    }
    // ↑ move to up
    if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
    {
        dfs(row - 1, col);
    }
    visited[row][col] = 0;
}

void bfs(int row, int col)
{
    r.push(row);
    c.push(col);
    int moveCount = 0;
    while (!r.empty())
    {
        row = r.front();
        col = c.front();
        r.pop();
        c.pop();
        // Check the Boundary of maze
        if (row < 0 || row > 4 || col < 0 || col > 4)
            continue;
        // Check if visited
        if (visited[row][col] == 1)
            continue;

        cout << row << " , " << col << endl;

        if(maze[row][col] == 3)
    {
        cout<<"found the Treasure!"<<endl;
    }

        // color for visited
        visited[row][col] = 1;

        if (maze[row][col] == 2){
            cout << "We are in the exit!" << endl;
            visited[row][col] = 0;
        }
        // → move to right
        if (maze[row][col + 1] != 1 && visited[row][col + 1] == 0)
        {
            // cout << "right ";
            r.push(row);
            c.push(col + 1);
            moveCount++;
        }
        // ← move to left
        if (maze[row][col - 1] != 1 && visited[row][col - 1] == 0)
        {
            // cout << "left ";
            r.push(row);
            c.push(col - 1);
            moveCount++;
        }
        // ↓ move to down
        if (maze[row + 1][col] != 1 && visited[row + 1][col] == 0)
        {
            // cout << "down ";
            r.push(row + 1);
            c.push(col);
            moveCount++;
        }
        // ↑ move to up
        if (maze[row - 1][col] != 1 && visited[row - 1][col] == 0)
        {
            // cout << "up ";
            r.push(row - 1);
            c.push(col);
            moveCount++;
        }
    }
    cout<<moveCount;
}

int main()
{
    cout << "DFS" << endl;
    dfs(1, 0);
    cout << "\n"
         << "=============================" << endl;
    cout << "BFS" << endl;
    bfs(1, 0);

    return 0;
}