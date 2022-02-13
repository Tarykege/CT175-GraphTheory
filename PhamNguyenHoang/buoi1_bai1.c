#include<stdio.h>
#define MAX_VERTICES 20
#define MAX_EDGES 20
typedef struct{
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];
}Graph;
void init_graph(Graph *G,int n, int m){
	G->n=n;
	G->m=m;
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			G->A[i][j]=0;
		}
	}
}
void add_edge(Graph *G,int e,int x,int y){
	G->A[x][e]=1;
	G->A[y][e]=1;
}
int degree(Graph *G, int x){
	int i,j,deg=0;
	for(i=1; i<=G->m;i++){
		if(G->A[x][i]==1) deg++;
	}
	return deg;
}
int main(){
	Graph G;
	int n,m,i;
	n=4,m=5;
	init_graph(&G,n,m);
	add_edge(&G,1,1,2);
	add_edge(&G,2,1,3);
	add_edge(&G,3,1,3);
	add_edge(&G,4,3,4);
	add_edge(&G,5,1,4);
	for(i=1; i<=G.n; i++){
		printf("degree(%d) = %d\n",i,degree(&G,i));
	}
}
