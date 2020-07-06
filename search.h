#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "seqlist.h"

void DFS(AdjGraph *G,int v);		//递归深度优先遍历算法

void DFS1(AdjGraph *G,int v);		//非递归深度优先遍历算法

void BFS(AdjGraph *G,int v);		//广度优先遍历算法

void Dijkstra(MatGraph g,int v);   //Dijkstra算法

char* shortestPath(int u, int v, char algorithm[], char name[])`
{

}
