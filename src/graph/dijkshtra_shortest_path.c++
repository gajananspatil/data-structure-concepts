#include <climits>
#include "graph_adj_list_aug.h"

#ifndef  INF
#define INF INT_MAX
#endif

Dijakshtra(const Graph &graph,int source)
{
    int vertices = graph.size();    
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;

    int *dist = new int[vertices];
    std::vector<int> shortestPathSet;

    for(int i=0; i <  vertices; ++i)
        dist[i] = INF;

    dist[source] = 0;

    for( int i=0; i < vertices; ++i ) 
    {
        if(dist[i] != INF)
         estimateAdjacentDist(graph,dist,i);
    
    }
    

    

}
