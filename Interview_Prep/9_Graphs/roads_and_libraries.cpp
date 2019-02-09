#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);
vector<int> neighbors[100005];

// Use DFS to find out how many nodes are in one cluster
void clusterSizeDFS(int currentNode, long &clusterSize, bool visited[])
{
    clusterSize++;
    visited[currentNode] = true;
    for (auto neighbor : neighbors[currentNode])
    {
        if (!visited[neighbor])
        {
            clusterSizeDFS(neighbor, clusterSize, visited);
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {   
        int n, m, fromCity, toCity;
        long c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;

        bool *visited = new bool(n);
        for (int i = 0; i <= n; i++){
            neighbors[i].clear();
            visited[i] = false;
        }

        for (int i = 0; i < m; i++)
        {
            cin >> fromCity >> toCity;
            neighbors[fromCity].push_back(toCity);
            neighbors[toCity].push_back(fromCity);
        }

        long totalCost = 0;

        for (int currentNode = 1; currentNode <= n; currentNode++)
        {
            if (!visited[currentNode])
            {
                long clusterSize = 0;
                clusterSizeDFS(currentNode, clusterSize, visited);
                totalCost += c_lib;
                if (c_lib < c_road)
                {
                    totalCost += (c_lib * (clusterSize - 1));
                }
                else
                {
                    totalCost += (c_road * (clusterSize - 1));
                }
            }
        }

        fout << totalCost << "\n";
    }

    fout.close();

    return 0;
}

