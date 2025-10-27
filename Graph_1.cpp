#include<iostream>
#include<vector>
using namespace std;

class graph{
    int vertices;
    vector<vector <int>> adjMatrix;

    public:
    graph(int vertices){
        this->vertices = vertices;
        adjMatrix.resize(vertices+1 , vector <int>(vertices+1 , 0));
    };

    void addEdge_undirected(int e1, int e2){
        adjMatrix[e1][e2] = 1;
        adjMatrix[e2][e1] = 1;
    }

    void display(){
        for(int i=1;i<=vertices;i++){
            for(int j=1;j<=vertices;j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }


};

int main(){
    int vertices;
    cout<<"Enter number of vertices: ";
    cin>>vertices;

    graph g1(vertices);

    int no_of_edges;
    cout<<"\nEnter number of edges: ";
    cin>>no_of_edges;

    for(int i=0;i<no_of_edges;i++){
        cout<<"\nEnter the source and destination: ";
        int source,destination;
        cin>>source>>destination;
        g1.addEdge_undirected(source , destination);
    }
    
    g1.display();
}