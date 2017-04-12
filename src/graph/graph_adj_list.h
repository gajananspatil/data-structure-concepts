#include <list>
#include <stack>
#include <queue>
/*
 * This is a sample code to implement graph with adjeceny list,
 * list is maintained to know the adjecent nodes for each node.
 * Graph class is Primarily Undirected Graph (UDG)
 * This class provides BFS travers algo and also
 * checks if graph prepared is connected or not
 */

struct BFSResult
{
    int origin;
    int vertices;
    int *dist_from_origin;

    BFSResult(int _start,int _count)
    {
        origin = _start;
        vertices = _count;
        dist_from_origin = new int[_count]();
    }

    ~BFSResult()
    {
        if(dist_from_origin)
            delete[] dist_from_origin;
    }

private:
    BFSResult(const BFSResult &bfs);
    BFSResult operator=(const BFSResult &bfs);
};


class Graph
{
private:
    int vertices;
    std::list<int> *adjacency_list;
    bool is_directed;

public:
    Graph(int _v,bool directed = false)
            :vertices(_v),
            is_directed(directed)
    {
       adjacency_list = new std::list<int>[_v];
    }

    ~Graph()
    {
        delete[] adjacency_list;
    }

    void addEdge(int u,int v);

    bool isConnected();

    BFSResult* breadthFirstSearch(int source,bool visited[]);

     
    void depthFirstSearch(int source);

    void depthFirstSearch();

    void topologicalSort();
    
private:

    Graph(const Graph &graph);

    Graph operator=(const Graph &graph);

    bool areAdjacentNodes(int u,int v);

    void DFSRoutine(int source,bool visited[]);

    void topologicalSortRoutine(int vertex,bool visited[],std::stack<int> &sortstack);

};
