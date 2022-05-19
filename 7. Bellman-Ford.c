#include <stdio.h>
#define MAXN 100
typedef struct{
	int u,v,w;
}Edge;
typedef struct{
	int n,m;
	Edge edge[MAXN];
}Graph;
void initGraph(Graph *G, int n){
	G->n=n;
	G->m=0;
}
void addEdge(Graph *G, int u, int v, int w){
	G->edge[G->m].u=u;
	G->edge[G->m].v=v;
	G->edge[G->m].w=w;
	G->m++;
}
#define INFINITY 99999
int p[MAXN];
int pi[MAXN];
void BellmanFord(Graph *G, int s){
	int i,step;
	for(i=1; i<=G->n; i++){
		pi[i]=INFINITY;
	}
	pi[s]=0;
	p[s]=-1;
	
	for(step=1; step<G->n; step++){
		for(i=0; i<G->m; i++){
			int u = G->edge[i].u;
			int v = G->edge[i].v;
			int w = G->edge[i].w;
			if(pi[u]+w < pi[v]){
				pi[v] = pi[u]+ w;
				p[v]=u;
			}
		}
	}
	for(i=0; i<G->m; i++){
		int u = G->edge[i].u;
		int v = G->edge[i].v;
		int w = G->edge[i].w;
		if(pi[u]+w < pi[v]){
			break;
		}
	}
}
int main(){
	int i,m,n,u,v,w; Graph G;
 	FILE *file = freopen("BellmanFord.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=0; i<m; i++){
		scanf("%d%d%d",&u,&v,&w);
		addEdge(&G,u,v,w);
	}
	//in do thi
	//for(i=0; i<m; i++){
	//	printf("%d %d %d\n",G.edge[i].u, G.edge[i].v, G.edge[i].w);
	//}
	BellmanFord(&G, 1);
	for(i=1; i<=n; i++){
		printf("pi[%d] = %d, p[%d] = %d\n", i,pi[i],i,p[i]);
	}
}
