/*
============================================================================
 Name : MST_using_Dijkstra.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 8
============================================================================
*/
#include <bits/stdc++.h>
using namespace std;
#define edge pair<int, int>

class Dijkstra
{
    private :
        int dept;
        int routes;
        int Distances[20][20];
        int path[20], parent[20];
        bool visited[20];
        vector<pair<int, edge>> v;

    public :
        Dijkstra(int v, int e)
        {
            dept = v; routes = e;
            for(int j = 0; j < 20; j++)
            {
                path[dept] = INT_MAX;
                visited[j] = false;
                for(int i = 0; i < 20; i++)
                {
                    Distances[j][i] = 0;
                }
            }
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

        void SelectMinRoute(int source)
        {
            visited[source] = true;  //source is marked as visited
            for(int i = 0; i < dept; i++)
            {
                if(Distances[source][i] != 0 && !visited[i])
                {
                    v.push_back(make_pair(Distances[source][i], edge(i, source)));
                    visited[i] = true;
                    parent[i] = source;
                    path[i] = Distances[source][i];
                    // cout<<endl<<parent[i]<<","<<i<<" -> "<<path[i]<<endl;
                }
            }
            sort(v.begin(), v.end());
            for(int i = 0; i < v.size(); i++)
            {
                // cout<<endl<<v.at(i).second.first<<endl;
                int temp = v.at(i).second.first;
                v.erase(v.begin());
                SelectMinRoute(temp);
            }
            return;
        }

        void DijkstraMST(int source)
        {
            //Assuming start point as Node-source
            parent[source] = source;	//Start node has no parent
            path[source] = 0;	//start node has value=0 to get picked 1st
            SelectMinRoute(source);
            int vertex = 0;
            while(vertex != dept)
            {
                if(vertex == source)
                {
                    vertex++;
                    continue;
                }
                cout<<"\n    "<<source<<"     -->     "<<vertex<<"    =    "<<path[parent[vertex]] + Distances[parent[vertex]][vertex]<<endl;
                vertex++;
            }
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
    Dijkstra MyGraph(dept_array.size(), edges);
    MyGraph.TakeGraph();
    MyGraph.DisplayWeightMatrix(&dept_array.front());
    cout<<"\nEnter source vertex : ";
    int source;
    cin>>source;
    cout<<"\nMinimum distance to visit every department (using Dijkstra's algo) is,\n  Source  -->  Vertex  =  Distance";MyGraph.DijkstraMST(source);
}