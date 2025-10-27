#include<iostream>
#include<vector>
using namespace std;

class graph{
    int vertices;
    vector<vector <int>> adj_list;

public: 
    graph(int vertices){
        this->vertices = vertices;
        adj_list.resize(vertices+1);
    };

    void addEdge_undirected(int v1 , int v2){
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }

    void display(){
        for(int i=1;i<=vertices;i++){
            cout<<i<<" -> ";
            for(int j=0;j<adj_list[i].size();j++){
                cout<<adj_list[i][j]<<" ";
            }
            cout<<endl;
        }
       
    }
};

int main(){
    int vertices;
    int edges;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;

    graph g1(vertices);

    for(int i=0;i<edges;i++){
        cout<<"Enter the source and destination nodes: ";
        int v1,v2;
        cin>>v1>>v2;
        g1.addEdge_undirected(v1 , v2);
    }
    g1.display();
}