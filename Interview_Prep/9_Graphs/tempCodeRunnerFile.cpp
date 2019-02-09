#include <bits/stdc++.h>

using namespace std;

bool visited[10000];
vector<int> adj[10000];

void DFS(int node, long &regionSize){
    regionSize++;
    visited[node] = true;
    for (auto neighbor : adj[node]){
        if (!visited[neighbor]){
            DFS(neighbor, regionSize);
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, m, u, v;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int numOfNodes = n * m;
    // initialize adjacency list
    vector<int> adj[numOfNodes];

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++){
        grid[i].resize(m);
        for (int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // construct adjacency list
    for (int currNode=0; currNode<numOfNodes; currNode++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                // if top row
                if(i == 0){
                    adj[currNode].push_back(grid[i+1][j]);
                    // if top left corner
                    if (j == 0){
                        adj[currNode].push_back(grid[i][j+1]);
                    }
                    // if top right corner
                    else if (j == (m-1)){
                        adj[currNode].push_back(grid[i-1][j]);
                    }
                    // if in top row middle
                    else{
                        adj[currNode].push_back(grid[i][j+1]);
                        adj[currNode].push_back(grid[i][j-1]);
                    }
                }
                // if bottom row
                else if (i == n-1){
                    adj[currNode].push_back(grid[i-1][j]);                    
                    // if bottom left corner
                    if (j == 0){
                        adj[currNode].push_back(grid[i][j+1]);
                    }
                    // if bottom right corner
                    else if (j == (m-1)){
                        adj[currNode].push_back(grid[i][j-1]);
                    }
                    // if in bottom row middle
                    else{
                        adj[currNode].push_back(grid[i][j+1]);
                        adj[currNode].push_back(grid[i][j-1]);
                    }
                }
                // if left column
                if (j == 0){
                    adj[currNode].push_back(grid[i][j+1]);
                    // if left middle column
                    if (i != 0 && i != (n-1)){
                        adj[currNode].push_back(grid[i+1][j]);
                        adj[currNode].push_back(grid[i-1][j]);
                    }
                }
                else if (j == m-1){
                    adj[currNode].push_back(grid[i][j-1]);
                    // if right middle column
                    if (i != 0 && i != (n-1)){
                        adj[currNode].push_back(grid[i+1][j]);
                        adj[currNode].push_back(grid[i-1][j]);
                    }
                }
            }
        }
    }

    // initialize visited bool array
    for (int i = 0; i < numOfNodes; i++){
        visited[i] = false;
    }

    long regionSize = 0;

    // start DFS
    for (int i = 0; i < numOfNodes; i++){
        if (!visited[i]){            
            DFS(i, regionSize);
        }
    }
    cout << "current regionSize is: " << regionSize << endl;

    // long res = DFS(s, regionSize, adj);

    fout << regionSize << "\n";

    fout.close();

    return 0;
}
