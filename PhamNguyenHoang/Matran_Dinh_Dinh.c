#include<stdio.h>
#define MAX_VERTICES 100
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
void init_graph(Graph *G, int n){
	int i,j;
	G->n=n;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++){
			G->A[i][j]=0;
		}
	}
}
// do thi da cung
void add_edge(Graph *G,int x, int y){
	G->A[x][y]+=1;
	G->A[y][x]+=1;
}
//do thi don cung
//void add_edge(Graph *G,int x, int y){
//	G->A[x][y]=1;
//	G->A[y][x]=1;
//}

// do thi co huong
//void add_edge(Graph *G,int x, int y){
//	G->A[x][y]=1;
//}
int adjacent(Graph *G, int x, int y){
	return G->A[x][y]!=0;
}
// ap dung cho ca don cung va da cung
int degree(Graph *G, int x){
	int y,d=0;
	for(y=1; y<=G->n; y++){
		d+=G->A[x][y];
	}
	return d;
}
int main(){
	FILE *file = freopen("Matran_Dinh_Cung2.txt","r",stdin);
	int n,m,u,v,i,j;
	scanf("%d%d",&n,&m);
	Graph G;
	init_graph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++){
			printf("%d ",G.A[i][j]);
		}
		printf("\n");
	}
	for(i=1; i<=G.n; i++){
		printf("degree(%d) = %d\n",i,degree(&G,i));
	}	
	fclose(file);
}
