#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <climits>
using namespace std;

class Graph
{
  private:
    int numOfNodes;
    int weight = 6;
    // vector<int> shortest_reach;
    struct node
    {
        int nodeNumber, weight;
    };
    vector<node> edges[100000];

  public:
    Graph(int n)
    {
        numOfNodes = n;
    }

    void add_edge(int u, int v)
    {
        // equivalent to add neighbors
        edges[u].push_back({v, weight});
        edges[v].push_back({u, weight});
    }

    vector<int> shortest_reach(int start)
    {
        // BFS algorithm here to find shortest path
        // Initialize distances from given source
        vector<int> path;
        for (int i = 0; i < numOfNodes; i++){
            path.push_back(INT_MAX);
        }

        // double ende queue to do BFS.
        deque<int> Q;
        path[start] = 0;
        Q.push_back(start);

        while (!Q.empty())
        {   
            // deque one node from the front of the queue
            int v = Q.front();
            Q.pop_front();

            for (int i = 0; i < edges[v].size(); i++)
            {
                // checking for the optimal distance
                /* for current node v, for each of its neighbor i: 
                    if the path cost from s to i is higher than path cost from s to v plus edge cost from v to that neighbor i:
                         */
                if (path[edges[v][i].nodeNumber] > path[v] + edges[v][i].weight)
                {   
                    // set the path cost from s to i to be equal to the path cost from s to v plus edge cost from v to that neighbor i:
                    path[edges[v][i].nodeNumber] = path[v] + edges[v][i].weight;
                    // add the neighbor into queue
                    Q.push_back(edges[v][i].nodeNumber);
                }
            }
        }

        for (int i=0; i<path.size(); i++){
            if (path[i] == INT_MAX){
                path[i] = -1;
            }
        }

        return path;
    }
};

int main()
{
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++)
    {

        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++)
        {
            if (i != startId)
            {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
