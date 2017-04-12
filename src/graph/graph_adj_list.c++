#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include "graph_adj_list.h"

/*
 * Adds Edge between nodes provided i.e. u and v
 */
void Graph::addEdge(int u,int v)
{
    adjacency_list[u].push_back(v);
    if(!is_directed)
        adjacency_list[v].push_back(u);
}

/*
 * Iterative BreathFirstSearch Alogrithm
 */
BFSResult* Graph::breadthFirstSearch(int source,bool visited[])
{
   std::queue<int> adj_vtx;
   std::list<int>::iterator itr;
   BFSResult *result = new BFSResult(source,vertices);
   
   adj_vtx.push(source);
   visited[source] = true;
   result->dist_from_origin[source]=0;
   std::cout<<"BFS Traversal"<<std::endl;
   std::cout<<source<<" "<<std::endl;

  
   while(!adj_vtx.empty())
   {
        source = adj_vtx.front();
        adj_vtx.pop();
        for(itr=adjacency_list[source].begin();itr!= adjacency_list[source].end();++itr)
        {
            if(!visited[*itr])
            {
                visited[*itr] = true;
                std::cout<<*itr<<" "<<std::endl;
                adj_vtx.push(*itr);
                result->dist_from_origin[*itr] = result->dist_from_origin[source]+1;
            }
        }
   }

   return result;
   
}

/**
 * This is a public method to call DFS on graph
 * for specific source if any provided
 */
void Graph::depthFirstSearch(int source)
{
    bool *visited = new bool[vertices];

    for(int i=0;i<vertices;i++)
        visited[i] = false;

     DFSRoutine(source,visited);
}

/**
 * This is a public method to call DFS on graph
 * Internelly it call DFSRoutine for each vertex 
 * as there can be some un connected components or not reachable from source but part of graph
 */
void Graph::depthFirstSearch()
{
    bool *visited = new bool[vertices];

    for(int i=0;i<vertices;i++)
        visited[i] = false;

    for(int i=0;i<vertices;i++)
        if(visited[i] != false)
            DFSRoutine(i,visited);
}

 /**
  * Iterative method to traverse the graph in depth first manner 
  * for connected components of graph
  */
void Graph::DFSRoutine(int source,bool visited[])
{
    std::stack<int> adj_vtx;
    std::list<int>::iterator itr = adjacency_list[source].begin();

    adj_vtx.push(source);
    visited[source]=true;

    std::cout<<"DFS Traversal"<<std::endl;
    std::cout<<source<<" "<<std::endl;
    while(!adj_vtx.empty())
    {
        source = adj_vtx.top();
        itr = adjacency_list[source].begin();
        while(itr!= adjacency_list[source].end())
        {
            if(!visited[*itr])
            {
                source = *itr;
                visited[source]=true;
                std::cout<<source<<" "<<std::endl;
                // push current node on stack
                adj_vtx.push(source);
                //start exploring adjacent of current node 
                itr= adjacency_list[source].begin();
                continue;
            }
            ++itr;
        }
        adj_vtx.pop();
    }
}

//TODO: As Topological Sort can only be done on acyclic graph. Cycle detection needs to be done.
/*
 * This fucntion calls @topologicalSortRoutine for each unvisited node
 * iteratively 
 */
void Graph::topologicalSort()
{
    bool *visited = new bool[vertices];
    std::stack<int> mstack;

    for(int i=0;i<vertices;i++)
        visited[i] = false;

    for(int i=0;i<vertices;i++)
        if(visited[i] == false)
            topologicalSortRoutine(i,visited,mstack);

    while(!mstack.empty())
    {
        std::cout<<mstack.top()<<" ";
        mstack.pop();
    }
}

/*
 * Topological ordering of a directed graph is a linear ordering of its vertices such that 
 * for every directed edge uv from vertex u to vertex v, u comes before v in the ordering.
 * A topological ordering is possible if and only if the graph has no directed cycles, that is, if it is a directed acyclic graph (DAG)
 *
 * Recursive Routine which actually sorts the graph vertices in topological order 
 */
void Graph::topologicalSortRoutine(int vertex,bool visited[],std::stack<int> &mstack)
{

    std::list<int>::iterator itr = adjacency_list[vertex].begin();
    visited[vertex] = true;

   for(;itr != adjacency_list[vertex].end();++itr)
   {
        if(!visited[*itr])
        {
            topologicalSortRoutine(*itr,visited,mstack);
        }
   }
    mstack.push(vertex);
}

/*
 * isConnected function returns true or false
 * It uses BFS to traverse the graph. If all the nodes
 * are visited during BFS then graph is connected else it has 
 * disconnected components.
 */ 
bool Graph::isConnected()
{
    bool visited[vertices] ;
    
    for(int i=0;i<vertices;++i)
        visited[i] = false;

    breadthFirstSearch(0,visited);

    for(int i=0;i<vertices;++i)
    {
        if(visited[i]==false)
            return false;
    }
    return true;

}
