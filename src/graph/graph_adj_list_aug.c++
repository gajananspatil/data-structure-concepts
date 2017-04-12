
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <set>
#include <utility>  
#include "graph_adj_list_aug.h"

#define INF INT_MAX

extern "C" void printpath(std::vector<int> &pi,int source, int destination);

/*
 * Adds Edge between nodes provided i.e. u and v
 */
void Graph::addEdge(int u,int v,int wt)
{
    AdjacentVertex vtx(v,wt) ;
    adjacency_list[u].push_back(vtx);

    if(!is_directed)
    {
        //TODO need to check if this works
        AdjacentVertex vtx(u,wt) ;
        adjacency_list[v].push_back(vtx);
    }
}

/**
  TODO for adjacentvertex class implementation

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
*/

/**
TODO: uncomment after modifing BFS code
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
**/

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
  * Method to traverse the graph in depth first manner 
  * for connected component of graph
  */
void Graph::DFSRoutine(int source,bool visited[])
{
    std::stack<int> adj_vtx;
    std::list<AdjacentVertex>::iterator itr = adjacency_list[source].begin();

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
            if(!visited[itr->getVertex()])
            {
                source = itr->getVertex();
                visited[source]=true;
                std::cout<<source<<" "<<std::endl;
                adj_vtx.push(source);
                itr= adjacency_list[source].begin();
                continue;
            }
            ++itr;
        }
        adj_vtx.pop();
    }
}


/**
 *
 *
 *
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
 * This topological sort alogrithm is based on DFS algorithm
 * It starts on arbitrary node and visits each node in graph
 * and terminates when it visits already visited node.
 *
 * A difference can be noted between two algorithms is that we are pushing it on stack
 * when we have visited all its adjacent node recursively 

 * This alogrithm will sort topologically all the nodes if there is no cycle in graph
 * i.e. for Directed Acyclic Graph (DAG).
 */

void Graph::topologicalSortRoutine(int vertex,bool visited[],std::stack<int> &mstack)
{

    std::list<AdjacentVertex>::iterator itr = adjacency_list[vertex].begin();
    visited[vertex] = true;

   for(;itr != adjacency_list[vertex].end();++itr)
   {
        if(!visited[(*itr).getVertex()])
        {
            topologicalSortRoutine((*itr).getVertex(),visited,mstack);
        }
   }
    mstack.push(vertex);
}


void Graph::shortestPathByTopoSort(int source)
{
    
    bool *visited = new bool[vertices];
    std::stack<int> mstack;
    int dist[vertices];

    for(int i=0;i<vertices;i++)
    {
        visited[i] = false;
        dist[i] = INF;
    }

    for(int i=0;i<vertices;i++)
        if(visited[i] == false)
            topologicalSortRoutine(i,visited,mstack);
    
    
    dist[source] = 0 ; 
    while(!mstack.empty())
    {
        int v = mstack.top();
        mstack.pop();

        std::list<AdjacentVertex>::iterator itr;

        if(dist[v] != INF)
        {
            for(itr = adjacency_list[v].begin();itr != adjacency_list[v].end();++itr)
            {
                if( dist[(*itr).getVertex()] > dist[v] + (*itr).getWeight() )
                    dist[(*itr).getVertex()] = dist[v] + (*itr).getWeight();
            }
        }

    }

    std::cout<<"Shortest Path for all Nodes from source:"<<source<<std::endl;
    for(int i=0;i<vertices;i++)
    {
        (dist[i] == INF) ? std::cout<<"INF " : std::cout<<dist[i] << " " ;
    }

    
}

// This algorithm starts with setting shortest distance for source as 0 and others to infinity
//   Visit adjacent vertices and calculate distances using weights and add these to min heap
//   once all the adjacent vertices of souce are pushed to heap pick the vertex with min weight 
//   and start the same procedure as above
//
// Dijkstra's algorithm doesn't work for graphs with negative weight edges

void Graph::shortestPathByDijakshtra(int source)
{
    std::vector<int> dist( vertices, INF );
    std::vector<int> shortestPathSet;
    //std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    std::vector<int> pi(vertices, -1 );     //this vector to store previous vertex in shortest path

    std::set < std::pair <int,int> >  mindist_set;
    
    /**
    for(int i=0; i <  vertices; ++i)
    {
        dist[i] = INF;
    }
    **/

    dist[source] = 0;
    mindist_set.insert ( std::make_pair ( dist[source] , source ) );
    std::list < AdjacentVertex >::iterator itr ;

    while( !mindist_set.empty() )
    {
       std::pair<int,int> dist_vtx = *mindist_set.begin() ;
       int vtx = dist_vtx.second;
       //int pathdist = dist_vtx.first; 
       
       mindist_set.erase( mindist_set.begin() );  // remove the first element after visiting

       for( itr = adjacency_list[vtx].begin(); itr != adjacency_list[vtx].end(); ++itr )
       {
            int ad_v = (*itr).getVertex() ;
            int ad_wt = (*itr).getWeight();

           if( dist[ad_v]  > dist[vtx] + ad_wt )
           {
                // If this dist is not INF it means its already there in set
                // Hence remove it and then insert new value
                if( dist[ad_v] != INF )
                    mindist_set.erase(mindist_set.begin());

                if(ad_v != source)
                   pi[ad_v] = vtx;

                dist[ad_v] = dist[vtx] + ad_wt ;
                mindist_set.insert( std::make_pair(dist[vtx] + ad_wt,ad_v) );
           }
       }
    }

    std::cout<<"Shortest Path for all Nodes from source "<< source<<" using Dijkstra's Algo:"<<std::endl;
    for(int i=0;i<vertices;i++)
    {
        std::cout << i << " : ";
        if( dist[i] == INF ) 
        {    
            std::cout<<"INF " ;
        }
        else
        {
            std::cout<<dist[i] <<"\tPath=>: ";
            printpath(pi,source,i);
            std::cout<<std::endl;
        }
    }

}

/**
 *
 *
 *
 */
void printpath(std::vector<int> &pi,int source, int destination)
{
   if( source == destination ) 
   {
        std::cout<< destination <<" ";
        return;
   }
    printpath(pi,source,pi[destination]);
    std::cout<< destination << " ";
}
