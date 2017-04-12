
#include <list>
#include <stack>
#include <queue>
/*
 * This is a sample code to implement graph with adjeceny list
 * In this type of representation list is maintained to 
 * know the adjecent nodes for each node
 * This graph class store Undirected Graph (UDG)
 * This class provides BFS travers algo and also
 * checks if graph prepared is connected or not
 */

class AdjacentVertex
{
    int weight;
    int vertex;

public:
    explicit AdjacentVertex(int vrtx,int wt)
                :vertex(vrtx),
                weight(wt)
            {}

    int getVertex() { return vertex; }
    int getWeight() { return weight; } 
};

class Graph
{
private:
    int vertices;
    std::list<AdjacentVertex> *adjacency_list;
    bool is_directed;

public:
    Graph(int _v,bool directed = false)
            :vertices(_v),
            is_directed(directed)
    {
       adjacency_list = new std::list<AdjacentVertex>[_v];
    }

    ~Graph()
    {
        delete[] adjacency_list;
    }

    void addEdge(int u,int v,int wt);

    bool isConnected();

    void breadthFirstSearch(int source,bool visited[]);

     
    void depthFirstSearch(int source);

    void depthFirstSearch();

    void topologicalSort();

    void shortestPathByTopoSort(int source);

    int size() {return vertices;}

    void shortestPathByDijakshtra(int source);

    bool isCyclic();
    
private:

    Graph(const Graph &graph);

    Graph operator=(const Graph &graph);

    bool areAdjacentNodes(int u,int v);

    void DFSRoutine(int source,bool visited[]);

    void topologicalSortRoutine(int vertex,bool visited[],std::stack<int> &sortstack);

};
