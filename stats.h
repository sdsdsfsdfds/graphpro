#include <stdio.h>
#include "graph.h"

int numberOfEdges(char name[]);     //返回图中边的数量
int numberOfVertices(char name[]); //返回图中顶点的数量
float freemanNetworkCentrality(char name[]);  //返回图中 Freeman's Network Centrality 值，此时默认图为无向图即可
float closenessCentrality(char name[], int node); //返回图中 Closeness Centrality 值

