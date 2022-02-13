#include <stdio.h>
#define Max_Vertices 20
#define Max_Edges 500
typedef struct{
	int A[Max_Vertices][Max_Edges];
	int n,m;
}Graph;
void init_Graph(Graph *G, int n, int m){
	int i,j;
	G->n=n;
	G->m=m;
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++){
			G->A[i][j]=0;			
		}
	}
}
void add_edge(Graph *G, int e, int x, int y){
	G->A[x][e]=1;
	G->A[y][e]=1;
}
int adjacent(Graph *G, int x, int y){
	int i,j;
	for(i=1; i<=G->m; i++){
		if(G->A[x][i]==1 && G->A[y][i]==1) return 1;
	}
	return 0;
}
int degree(Graph *G, int x){
	int i,c=0;
	for(i=1; i<=G->m; i++){
		if(G->A[x][i]==1) c++;
	}
	return c;
}
int main(){
	FILE *file = freopen("Matran_Dinh_Cung2.txt","r",stdin);
	int i,j,n,m,u,v;
	Graph G;
	scanf("%d%d",&n,&m);
	init_Graph(&G,n,m);
	
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,i,u,v);
	}
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.m; j++){
			printf("%d ",G.A[i][j]);
		}
		printf("\n");
	}
	for(i=1; i<=n; i++){
		printf("degree(%d) = %d\n",i,degree(&G,i));
	}
}
