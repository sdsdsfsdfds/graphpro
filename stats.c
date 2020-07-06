#include "stats.h"
#include "graph.h"
#include "search.h"
int numberOfEdges(AdjGraph *G,int v)     //返回图中边的数量
{
    ArcNode *p;
	visited[v]=1;
	int num_edges;
	p=G->adjlist[v].firstarc;            //p指向顶点v的第一条弧的弧头结点
	num_edges = 1;
	while (p!=NULL)
	{
		if (visited[p->adjvex]==0)		//若p->adjvex顶点未访问,递归访问它
			DFS(G,p->adjvex);
		p=p->nextarc;              		//p指向顶点v的下一条弧的弧头结点
		num_edges++;
	}
	return num_edges;
}

int numberOfVertices(char name[]) //返回图中顶点的数量
{

}

float freemanNetworkCentrality(char name[])  //返回图中 Freeman's Network Centrality 值，此时默认图为无向图即可
{

}

float closenessCentrality(char name[], int node) //返回图中 Closeness Centrality 值
{

}

