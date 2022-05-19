#include <stdio.h>
#define MAX_VERTICES 20
#define MAX_EDGES 20
#define MAX_LENGTH 20
typedef struct{
	int u,v,w;
}Edge;
typedef struct{
	Edge edges[MAX_EDGES];
	int n,m;
}Graph;
typedef struct{
	int a[MAX_LENGTH];
	int size;
}List;
void initGraph(Graph *G, int n, int m){
 G->m=0;
 G->n=n;
}
void addEdge(Graph *G, int u, int v, int w){
	G->edges[G->m].u=u;
	G->edges[G->m].v=v;
	G->edges[G->m].w=w;
	G->m++;
}
void makeNullL(List *l){
	l->size=0;
}
void pushBack(List *l, int x){
	l->a[l->size]=x;
	l->size++;
}
int elmAt(List *l, int pos){
	return l->a[pos-1];
}
List neighbors(Graph *G, int u){
	int i;
	List l; makeNullL(&l);
	for(i=0; i<G->m; i++){
		if(G->edges[i].u==u){
			pushBack(&l,G->edges[i].v);
		}
	}
	return l;
}
//---------------------
int parent[MAX_VERTICES];

int findRoot(int u){
	if(parent[u]==u) return u;
	else return findRoot(parent[u]);
}
void sortByWeight(Graph *G){
	Edge t;
	int i,j;
	for(i=0; i<G->m-1; i++){
		for(j=G->m-1; j>=i+1; j--){
			if(G->edges[j].w < G->edges[j-1].w){
				t=G->edges[j];
				G->edges[j]=G->edges[j-1];
				G->edges[j-1]=t;
			}
		}
	}
}

int krusal(Graph *G, Graph *T){
		int i;
	//sort by weight up
	sortByWeight(G);
	//khoi tao t rong
	initGraph(T,G->n,G->m);

	for(i=1; i<=G->n; i++){
		parent[i]=i;
	}
	int sumW=0;
	//duyet qua cac cung cua G
	for(i=0; i<G->m; i++){
		int u = G->edges[i].u;
		int v = G->edges[i].v;
		int w = G->edges[i].w;
		int rootU=findRoot(u);
		int rootV=findRoot(v);
		if(rootU!=rootV){
			addEdge(T,u,v,w);
			parent[rootV] = rootU;
			sumW += w;
		}
	}
	return sumW;
}
int main(){
	int n,m,u,v,i,w;
	FILE * f = freopen("Kruskal.txt","r",stdin);
	scanf("%d%d",&n,&m); Graph G; initGraph(&G,n,m);
	for(i=0; i<m; i++){
		scanf("%d%d%d",&u,&v,&w);
		addEdge(&G,u,v,w);
	}
	Graph T;
	printf("%d\n",krusal(&G,&T));
	
	for(i=0; i<T.m; i++){
		if(T.edges[i].u<T.edges[i].v)
			printf("%d %d %d\n",T.edges[i].u, T.edges[i].v, T.edges[i].w);
		else printf("%d %d %d\n",T.edges[i].v, T.edges[i].u, T.edges[i].w);
	}
}
