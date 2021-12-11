#include <bits/stdc++.h>
using namespace std;

class Graph
{
    private :
        int dept;
        int routes;
        int Distances[20][20];
        int visited[20], d[20], p[20];

    public :
        Graph(int v, int e)
        {
            dept = v; routes = e;
            for(int j = 0; j < 20; j++)
            {
                visited[j] = 0;
                for(int i = 0; i < 20; i++)
                {
                    Distances[j][i] = 0;
                }
            }
            d[dept] = INT_MAX;
        };

        void TakeGraph()
        {
            // cout<<"\nEnter Distance of -";
            ifstream file;
            file.open("Distances_Input.txt");
            for(int i = 0; i < routes; i++)
            {
                // cout<<"\n\tRoute No. "<<i+1<<".\tVertex1<->Vertex2 --> Distance : ";
                int v1;
                int v2;
                int w;
                // cin>>v1>>v2>>w;
                if(file.fail()){cout<<"No such file";}
                else
                {
                    file>>v1>>v2>>w;
                }
                Distances[v1-1][v2-1] = w;
                Distances[v2-1][v1-1] = w;
            }
        }

        void DisplayWeightMatrix(string array[])
        {
            cout<<"\n\nAdjacency Matrix of Route Distances -\n\n\t";
            for(int i = 0; i < dept; i++)
            {
                cout<<array[i]<<"\t";
            }
            cout<<"\n\n";
            for(int i = 0; i < dept; i++)
            {
                cout<<array[i]<<"\t";
                for(int j = 0; j < dept; j++)
                {
                    cout<<Distances[i][j]<<"\t";
                }
                cout<<"\n\n";
            }
        }

        int selectMinVertex(vector<int>& value,vector<bool>& processed)
        {
            int minimum = INT_MAX;
            int vertex;
            for(int i=0;i<dept;++i)
            {
                if(processed[i]==false && value[i]<minimum)
                {
                    vertex = i;
                    minimum = value[i];
                }
            }
            return vertex;
        }

        void Dijkstra(int source, int destination)
        {
            int parent[dept];		//Stores Shortest Path Structure
            vector<int> value(dept,INT_MAX);	//Keeps shortest path values to each vertex from source
            vector<bool> processed(dept,false);	//TRUE->Vertex is processed

            //Assuming start point as Node-0
            parent[0] = -1;	//Start node has no parent
            value[0] = 0;	//start node has value=0 to get picked 1st

            //Include (dept-1) edges to cover all dept-vertices
            for(int i=0;i<dept-1;++i)
            {
                //Select best Vertex by applying greedy method
                int U = selectMinVertex(value,processed);
                processed[U] = true;	//Include new Vertex in shortest Path Graph

                //Relax adjacent vertices (not yet included in shortest path graph)
                for(int j=0;j<dept;++j)
                {
                    /* 3 conditions to relax:-
                        1.Edge is present from U to j.
                        2.Vertex j is not included in shortest path graph
                        3.Edge weight is smaller than current edge weight
                    */
                    if(Distances[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX
                    && (value[U]+Distances[U][j] < value[j]))
                    {
                        value[j] = value[U]+Distances[U][j];
                        parent[j] = U;
                    }
                }
            }
            // Print Shortest Path Graph
            cout<<"Shortest distance from "<<source<<" to "<<destination<<" is : ";
            int mincost = 0;
            for(int i=source;i<=destination;++i)
            {
                mincost += Distances[parent[i]][i];
            }
            cout<<mincost;
        //     for(int i=1;i<dept;++i)
        //         cout<<"U->dept: "<<parent[i]<<"->"<<i<<"  wt = "<<Distances[parent[i]][i]<<"\n";
        }
};

int main()
{
    // cout<<"\nEnter -1 to stop...\nEnter names of departments of college : ";
    string dept_name;
    vector<string> dept_array;
    ifstream file("Dept_input.txt");
    while(file>>dept_name)
    {
        if(dept_name == "-1"){break;}
        dept_array.push_back(dept_name);
    }
    cout<<"\nEnter no. of routes : ";
    int edges;
    cin>>edges;
    Graph MyGraph(dept_array.size(), edges);
    MyGraph.TakeGraph();
    MyGraph.DisplayWeightMatrix(&dept_array.front());
    cout<<"\nMinimum distance to visit every department (using Dijkstra's algo) is : ";MyGraph.Dijkstra(0, 2);
}