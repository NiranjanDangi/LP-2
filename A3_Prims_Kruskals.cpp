#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int v;

public:
    Graph(int n)
    {
        this->v = n;
    }
    void print(vector<vector<int> > &mat)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int find1(vector<string> &cities, string city)
    {
        int index = -1;
        for (int i = 0; i < cities.size(); i++)
        {
            if (cities[i] == city)
            {
                index = i;
                return index;
            }
        }
        return index;
    }

    void kruskalMinCost(vector<vector<int> > &adjMatrix, vector<string> &cities)
    {

        int V = adjMatrix.size();
        int minCost = 0;
        vector<int> parent(V, -1);
        int edgeCount = 0;

        while (edgeCount < V - 1)
        {
            int minWeight = 9999;
            int u, v;

            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (adjMatrix[i][j] != 0)
                    { // remember this
                        int uSet = i;
                        int vSet = j;

                        while (parent[uSet] != -1)
                            uSet = parent[uSet];
                        while (parent[vSet] != -1)
                            vSet = parent[vSet];

                        if (uSet != vSet && adjMatrix[i][j] < minWeight)
                        {
                            minWeight = adjMatrix[i][j];
                            u = i; // here too i and j
                            v = j; // here too i and j
                        }
                    }
                }
            }

            int uSet = u;
            int vSet = v;

            while (parent[uSet] != -1)
                uSet = parent[uSet];
            while (parent[vSet] != -1)
                vSet = parent[vSet];

            if (uSet != vSet)
            {
                cout << cities[u] << " --> " << cities[v] << " : " << minWeight << endl;
                minCost += minWeight;
                parent[uSet] = vSet;
                edgeCount++;
            }

            adjMatrix[u][v] = 0;
        }
        cout << "Minimum cost : " << minCost << endl;
    }

    void primMinCost(vector<vector<int> > &adjMatrix, vector<string> &cities){
        int V = adjMatrix.size();
        vector<bool>visited(V,false);
        vector<int>key(V,9999);
        vector<int>parent(V,-1);

        key[0] = 0;

        for (int count = 0; count < V-1; count++)
        {
            int min = 9999, u = -1;
            for (int i = 0; i < V; i++)
            {
                if(!visited[i] && key[i] < min){
                    min = key[i];
                    u = i;
                }
            }

            visited[u] = true;

            for(int v = 0; v < V; v++){
                if (adjMatrix[u][v] && !visited[v] && adjMatrix[u][v] < key[v]){
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }

        }

        int minCost = 0;
        for (int i = 1; i < V; i++)
        {
            cout << cities[parent[i]] << " --> " << cities[i] << " : " << adjMatrix[parent[i]][i] << endl;
            minCost += adjMatrix[parent[i]][i];
        }
        cout << "Minimum cost : " << minCost << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of cities " << endl;
    cin >> n;
    Graph g(n);

    vector<vector<int> > adjMatrix(n, vector<int>(n, 0));
    vector<string> cities(n);

    for (int i = 0; i < n; i++)
    {
        string city;
        cout << "Enter City [ " << i << " ] : " << endl;
        cin >> city;
        cities[i] = city;
    }

    for (int i = 0; i < n; i++)
    {
        int e;
        cout << "Enter total number of cities connected to " << cities[i] << endl;
        cin >> e;

        if (e >= 0 && e < n)
        {
            for (int j = 1; j <= e; j++)
            {
                string name;
                cout << "Enter city name : " << endl;
                cin >> name;
                int index = g.find1(cities, name);
                if (index != -1)
                {
                    int wt;
                    cout << "Enter cost : " << endl;
                    cin >> wt;
                    adjMatrix[i][index] = wt;
                }
                else
                    cout << "Invalid city.." << endl;
            }
        }
        else
            cout << "Invalid Number.." << endl;
    }

    vector<vector<int> > adjMatrix1copy = adjMatrix;
    vector<vector<int> > adjMatrix2copy = adjMatrix;
    g.print(adjMatrix);
    cout << "Kruskal's MST Algorithm : " << endl;
    g.kruskalMinCost(adjMatrix1copy, cities);
    cout << "Prims's MST Algorithm : " << endl;
    g.primMinCost(adjMatrix2copy, cities);
    return 0;
}