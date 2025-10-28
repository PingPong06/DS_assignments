#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class graph{
    int vertices;
    vector <vector <int>> adj_list;

public:
    graph(int v){
        vertices = v;
        adj_list.resize(vertices+1);  // As the graph is 1-based
    };

    void addEdge_undirected(int v1, int v2){
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }

    void bfs_traversal(int origin){
        queue <int> q1;
        vector <bool> vis(vertices , false);
        vis[origin] = true;
        q1.push(origin);

        cout<<"bfs traversal :";
        while(!q1.empty()){
            int front_element = q1.front();
            cout<<front_element<<" -> ";
            q1.pop();

            for(int adj_vertices : adj_list[front_element]){
                if(!vis[adj_vertices]){
                    vis[adj_vertices] =true;
                    q1.push(adj_vertices);
                }
            }
        }

    }

};

int main(){
    int vertices , edges;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    cout<<endl;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    cout<<endl;

    graph g1(vertices);

    for(int i=0;i<edges;i++){
        cout<<"Enter source and destination vertices: ";
        int source, destination;
        cin>>source>>destination;
        cout<<endl;
        g1.addEdge_undirected(source , destination);
    }

    cout<<"Enter the starting vertex of your choice: ";
    int origin;
    cin>>origin;
    cout<<endl;

    g1.bfs_traversal(origin);
    cout<<"end";
}