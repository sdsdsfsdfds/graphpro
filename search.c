#include "graph.h"

#include "search.h"

int visited[MAXV];						//全局数组
void DFS(AdjGraph *G,int v)				//递归深度优先遍历算法
{
	ArcNode *p;
	visited[v]=1;                   	//置已访问标记
	printf("%3d",v); 					//输出被访问顶点的编号
	p=G->adjlist[v].firstarc;      		//p指向顶点v的第一条弧的弧头结点
	while (p!=NULL)
	{
		if (visited[p->adjvex]==0)		//若p->adjvex顶点未访问,递归访问它
			DFS(G,p->adjvex);
		p=p->nextarc;              		//p指向顶点v的下一条弧的弧头结点
	}
}
void DFS1(AdjGraph *G,int v)		//非递归深度优先遍历算法
{
	ArcNode *p;
	int St[MAXV];
	int top=-1,w,x,i;
    for (i=0;i<G->n;i++)
		visited[i]=0;				//顶点访问标志均置成0
	printf("%3d",v);				//访问顶点v
	visited[v]=1;					//置顶点v已访问
	top++; St[top]=v;				//将顶点v进栈
	while (top>-1)					//栈不空循环
	{
		x=St[top]; 					//取栈顶顶点x作为当前顶点
		p=G->adjlist[x].firstarc;	//找顶点x的第一个相邻点
		while (p!=NULL)
		{
			w=p->adjvex;			//x的相邻点为w
			if (visited[w]==0)		//若顶点w没有访问
			{
				printf("%3d",w);	//访问顶点w
				visited[w]=1;		//置顶点w已访问
				top++;				//将顶点w进栈
				St[top]=w;
				break;				//退出循环，即再处理栈顶的顶点(体现后进先出)
			}
			p=p->nextarc;			//找顶点x的下一个相邻点
		}
		if (p==NULL) top--;			//若顶点x再没有相邻点，将其退栈
	}
	printf("\n");
}
void BFS(AdjGraph *G,int v)					//广度优先遍历算法
{
	ArcNode *p;
	int queue[MAXV],front=0,rear=0;			//定义环形队列并初始化
	int visited[MAXV];            			//定义存放顶点的访问标志的数组
	int w,i;
	for (i=0;i<G->n;i++) visited[i]=0;		//访问标志数组初始化
	printf("%3d",v); 						//输出被访问顶点的编号
	visited[v]=1;              				//置已访问标记
	rear=(rear+1)%MAXV;
	queue[rear]=v;             				//v进队
	while (front!=rear)       				//若队列不空时循环
	{
		front=(front+1)%MAXV;
		w=queue[front];       				//出队并赋给w
		p=G->adjlist[w].firstarc; 			//找顶点w的第一个相邻点
		while (p!=NULL)
		{
			if (visited[p->adjvex]==0) 		//若相邻点未被访问
			{
				printf("%3d",p->adjvex);  	//访问相邻点
				visited[p->adjvex]=1;		//置该顶点已被访问的标志
				rear=(rear+1)%MAXV;			//该顶点进队
				queue[rear]=p->adjvex;
           	}
           	p=p->nextarc;              		//找下一个相邻点
		}
	}
	printf("\n");
}

void Dispath(MatGraph g,int dist[],int path[],int S[],int v) //Dijkstra路径输出
{
    int i,j,k;
    int apath[MAXV],d;
    for(i=0;i<g.n;i++)
    if(S[i]==1&&i!=v)
    {
    printf("从顶点%d到顶点%d的路径长度为:%d\t路径为:",v,i,dist[i]);
    d=0;apath[d]=i;
    k=path[i];
    if(k==-1)
    printf("无路径\n");
    else
    {
    while(k!=v)
    {
    d++;apath[d]=k;
    k=path[k];
    }
    d++;apath[d]=v;
    printf("%d",apath[d]);
    for(j=d-1;j>=0;j--)
    printf(",%d",apath[j]);
    printf("\n");
    }
    }
}
void Dijkstra(MatGraph g,int v) //Dijkstra算法
{
    int dist[MAXV],path[MAXV];
    int S[MAXV];
    int Mindis,i,j,u;
    for(i=0;i<g.n;i++)
    {
    dist[i]=g.edges[v][i];
    S[i]=0;
    if(g.edges[v][i]<INF)
    path[i]=v;
    else
    path[i]=-1;
    }
    S[v]=1;path[v]=0;
    for(i=0;i<g.n-1;i++)
    {
    Mindis=INF;
    for(j=0;j<g.n;j++)
    if(S[j]==0&&dist[j]<Mindis)
    {
    u=j;
    Mindis=dist[j];
    }
    S[u]=1;
    for(j=0;j<g.n;j++)
    if(S[j]==0)
    if(g.edges[u][j]<INF&&dist[u]+g.edges[u][j]<dist[j])
    {
    dist[j]=dist[u]+g.edges[u][j];
    path[j]=u;
    }
    }
    Dispath(g,dist,path,S,v);
}

char* shorttestPath(int u, int v, char algorithm[], char name[])
{

}
