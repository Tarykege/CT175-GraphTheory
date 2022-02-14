#include <stdio.h>
#define MAX_VERTICES 200
#define MAX_LENGTH 200
typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph *G, int n){
	G->n=n;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			G->A[i][j]=0;
		}
	}
}
void add_edge(Graph *G, int u, int v){
	G->A[u][v]+=1;
	G->A[v][u]+=1;
}
int degree(Graph *G, int x){
	int i,deg=0;
	for(i=1;i<=G->n;i++){
		deg+=G->A[x][i];
	}
	return deg;
}
int main(){
	FILE* file = freopen("D:\\Study\\Code\\C\\GraphTheory-CT175\\PhamNguyenHoang\\ThucHanh_buoi1_bai4.txt","r",stdin);
	int n,m,u,v,i,j;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
		for(i=1; i<=n; i++){
	    	for(j=1; j<=n; j++){
	        	printf("%d ",G.A[i][j]);
	    }
	    printf("\n");
	}
	fclose(file);
}
