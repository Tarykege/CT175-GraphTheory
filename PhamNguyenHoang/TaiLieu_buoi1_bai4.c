#include<stdio.h>
#define MAX_VERTICES 20
#define MAX_EDGES 20
typedef struct{
	int n;
	int A[MAX_VERTICES][MAX_VERTICES];
}Graph;
void init_graph(Graph *G,int n){
	int i,j;
	G->n=n;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++){
			G->A[i][j]=0;	
		}
	}
}
void add_edge(Graph *G, int x, int y){
	G->A[x][y]+=1;
	G->A[y][x]+=1;
}
int degree(Graph *G, int x){
	int i,deg=0;
	for(i=1; i<=G->n; i++){
		deg +=G->A[x][i];
	}
	return deg;
}
int main(){
	Graph G;
	int n,m,u,v,i,j;
	FILE* file = fopen("D:\\Study\\Code\\C\\GraphTheory-CT175\\PhamNguyenHoang\\ThucHanh_buoi1_Matran_Dinh_Dinh.txt","r");
	fscanf(file,"%d%d",&n,&m);
	init_graph(&G,n);
	for(i=1; i<=m; i++){
		fscanf(file,"%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(j=1; j<=G.n; j++){
		printf("degree(%d) = %d\n",j,degree(&G,j));
	}
	fclose(file);
}
