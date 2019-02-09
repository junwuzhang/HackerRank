#include <bits/stdc++.h>

using namespace std;

// Complete the maxRegion function below.
void DFS(vector<vector<int> > &grid, const int n, const int m, int i, int j, int &regionSize) {
    // mark current cell as visited
    grid[i][j] = -1;
    regionSize++;
    // for each unexplored neighbor, run DFS. For faster DFS, check all eight directions of a cell. 
    // up
    if ((i-1) >= 0 && grid[i-1][j] == 1){
        DFS(grid, n, m, i-1, j, regionSize);
    }
    // down
    if ((i+1) < n && grid[i+1][j] == 1){
        DFS(grid, n, m, i+1, j, regionSize);
    }
    // left
    if ((j-1) >= 0 && grid[i][j-1] == 1){
        DFS(grid, n, m, i, j-1, regionSize);
    }
    // right
    if ((j+1) < m && grid[i][j+1] == 1){
        DFS(grid, n, m, i, j+1, regionSize);
    }
    // up-left
    if ((i-1) >= 0 && (j-1) >= 0 && grid[i-1][j-1] == 1){
        DFS(grid, n, m, i-1, j-1, regionSize);
    }
    // up-right
    if ((i-1) >= 0 && (j+1) < m && grid[i-1][j+1] == 1){
        DFS(grid, n, m, i-1, j+1, regionSize);
    }
    // down-left
    if ((i+1) < n && (j-1) >= 0 && grid[i+1][j-1] == 1){
        DFS(grid, n, m, i+1, j-1, regionSize);
    }
    // down-right
    if ((i+1) < n && (j+1) < m && grid[i+1][j+1] == 1){
        DFS(grid, n, m, i+1, j+1, regionSize);
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int maxSize = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1){
                // run DFS to find max length
                int regionSize = 0;
                DFS(grid, n, m, i, j, regionSize);
                if (maxSize < regionSize) {
                    maxSize = regionSize;
                }
            }
        }

    }

    fout << maxSize << "\n";

    fout.close();

    return 0;
}
