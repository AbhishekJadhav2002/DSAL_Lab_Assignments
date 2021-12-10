/*
============================================================================
 Name : College_Weighted_Graph.cpp
 Author : 23232_Abhishek Jadhav
 Version : 1.0
 Copyright : Your copyright notice
 Description : DSAL Lab Assignment No. 7
============================================================================
*/
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

        int Prim()
        {
            int current, totalvisited, mincost,i;
            current=0;
            d[current] = 0;
            totalvisited =1;
            visited[current]=1;
            // cout<<endl<<"visited distance and path status is :"<< endl<<"i , visited[i] p[i] , d[i]";
            // for (i=0;i<dept;i++)
            // {
            //     cout<<endl;
            //     //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
            //     cout<< endl<<"for I="<<i;
            //     cout<<"Visited[i]"<<visited[i];
            //     cout<<" p[i]= "<<p[i];
            //     cout<<" d[i]= "<<d[i];
            // }
            while(totalvisited!=dept)
            {
                // cout<<endl<<"total visited="<<totalvisited;
                for (i=0;i<dept;i++)
                {
                    if(Distances[current][i] != 0)
                    {
                        if(visited[i]==0)
                        {
                            if(d[i]>Distances[current][i])
                            {
                                d[i] = Distances[current][i];
                                p[i] = current;
                            }
                        }
                    }
                }
                // cout<<endl<<"visited distance and path status is :"<< endl<<"i , visited[i] p[i] , d[i]";
                // for (i=0;i<dept;i++)
                // { cout<<endl;
                // //cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
                // cout<< endl<<"for I="<<i;
                // cout<<"Visited[i]"<<visited[i];
                // cout<<" p[i]= "<<p[i];
                // cout<<" d[i]= "<<d[i];
                // }
                mincost= 32767;
                // cout<<endl<<"finding minimum cost";
                for (int j=0;j<dept;j++)
                {
                    if(visited[j] == 0)
                    {
                        if (d[j] <mincost)
                        {
                            mincost = d[j];
                            current = j;
                        }
                    }
                }
                // cout<< endl<<"for I="<<i;
                // cout<<"mincost= "<<mincost;
                // cout<<endl<<"current= "<<current<<endl;
                visited[current] = 1;
                totalvisited++;
                // cout<<endl<<"current= "<<current<<" Total Visited== "<<totalvisited;
                //for(int j=0;j<3;j++)
            } /*end of while loop */
            // cout<<endl<<"Minimum span tree is"<<endl;
            mincost =0;
            for (i=1;i<dept;i++)
            { 
                mincost += d[i];
                // cout<<" Edge "<<i<<"-->"<<p[i]<<" Weight= "<<d[i]<<endl;;
            }
            // cout<<"Minimum cost = ";
            return mincost;
            // cout<<endl<<"After Map is visited distance and path status is :";
            // cout<<endl<<"i , visited[i] p[i] , d[i]";
            // for (i=0;i<dept;i++)
            // {
            //     cout<<endl;
            //     cout<<i<<"\t"<<visited[i]<<"\t"<<p[i]<<"\t"<<d[i]<<"\t";
            // } /*end of prim */
        }

        int Kruskal()
        {
            /*
            3 - 2 : 3
            2 - 1 : 5
            3 - 1 : 7
            4 - 3 : 7
            4 - 0 : 8
            3 - 0 : 10
            1 - 0 : 12
            Total =  23
            */
            int adjMat2[dept][dept];
            for(int i=0; i<dept; i++)
            {
                for(int j=0; j<i; j++)
                {
                    adjMat2[i][j] = Distances[i][j];
                    adjMat2[j][i] = Distances[j][i];
                }
            }
            int count = 0, min, wt = 0, t1, t2;
            int father[dept];
            for(int i=0; i<dept; i++)
            {
                father[i] = -1;
            }
            int** res = new int*[dept];
            for(int i=0; i<dept; i++)
            {
                res[i] = new int[dept];
            }
            for(int i=0; i<dept; i++)
            {
                for(int j=0; j<dept; j++)
                {
                    res[i][j] = 0;
                }
            }
            while(count < dept-1)
            {
                min = 999999;
                for(int v1=0; v1<dept; v1++)
                {
                    for(int v2=0; v2<dept; v2++)
                    {
                        if(adjMat2[v1][v2] != 0 && adjMat2[v1][v2] < min)
                        {
                            min = adjMat2[v1][v2];
                            t1  = v1;
                            t2  = v2;
                        }
                    }
                }
                int temp1 = t1, root_temp1;
                int temp2 = t2, root_temp2;
                adjMat2[temp1][temp2] = adjMat2[temp2][temp1] = 0;
                while(t1 >= 0)
                {
                    root_temp1 = t1;
                    t1 = father[t1];
                }
                while(t2 >= 0)
                {
                    root_temp2 = t2;
                    t2 = father[t2];
                }
                if(root_temp1 != root_temp2)
                {
                    res[temp1][temp2] = res[temp2][temp1] = min;
                    wt += res[temp1][temp2];
                    father[root_temp2] = root_temp1;
                    count++;
                }
            }
            // cout<<"\n\t Minimum Spanning Tree : "<<endl;
            // cout<<"\n";
            // for(int i=0; i<dept; i++)
            // {
            //     cout<<"\t\t\t ";
            //     for(int j=0; j<dept; j++)
            //     {
            //         cout<<res[i][j]<<"   ";
            //     }
            //     cout<<endl;
            // }
            return wt;
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
    cout<<"\nMinimum distance to visit every department (using Kruskal's algo) is : "<<MyGraph.Kruskal();
    cout<<"\nMinimum distance to visit every department (using Prims's algo) is : "<<MyGraph.Prim();
}