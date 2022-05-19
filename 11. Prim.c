#include <stdio.h>
#define MAX_VERTICES 40
#define MAX_LENGTH 40
#define INF 9999
#define NO_EDGE 0
typedef struct{
	int a[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
typedef struct{
	int a[MAX_LENGTH];
	int size;
}List;
void initGraph(Graph *G, int n){
	int i,j;
	G->n=n;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			G->a[i][j]=0;
		}
	}
}
void addEdge(Graph *G, int u, int v, int w){
	G->a[u][v]=w;
	G->a[v][u]=w;
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
	for(i=0; i<G->n; i++){
		if(G->a[u][i] != 0){
			pushBack(&l,i);
		}
	}
	return l;
}
int distanceFrom(int u, List *S, Graph *G){
	int min_dist = INF;
	int min_v =  -1;
	int i;
	for(i=1; i<=S->size; i++){
		int v=elmAt(S,i);
		if(G->a[u][v] != NO_EDGE && min_dist > G->a[u][v]){
			min_dist = G->a[u][v];
			min_v = v;
		}
	}
	return min_v;
}
int mark[MAX_VERTICES];
int Prim(Graph *G, Graph *T){
	initGraph(T,G->n);
	List l;
	makeNullL(&l);
	int i;
	for(i=1; i<=G->n; i++){
		mark[i]=0;
	}
	pushBack(&l,1);
	mark[1]=1;
	
	int sum_w=0;
	for(i=1; i<=G->n; i++){
		int min_dist = INF;
		int min_u;
		int min_v;
		int u;
		for(u=1; u<=G->n; u++){
			if(mark[u]==0){
				int v = distanceFrom(u,&l,G);
				if(v!=-1 && G->a[u][v] < min_dist){
					min_dist = G->a[u][v];
					min_u=u;
					min_v=v;
	
				}
			}
		}
		pushBack(&l,min_u);
		if(mark[min_u]==1) continue;
		mark[min_u] = 1;
		if(mark[min_v] != 0) addEdge(T,min_u,min_v,min_dist);
		sum_w += min_dist;
	}
	return sum_w;
}
int main(){
	int i,j,u,v,w,m,n; Graph G,T;
	FILE *f = freopen("Prim.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=0; i<m; i++){
		scanf("%d%d%d",&u,&v,&w);
		addEdge(&G,u,v,w);
	}
	printf("%d\n",Prim(&G,&T));
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			if(T.a[i][j]!=0 && i<j) printf("%d %d %d\n",i,j,T.a[i][j]);
		}
	}
	return 0;
}
