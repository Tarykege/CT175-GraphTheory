#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_ELEMENTS 100
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
typedef int ElementType;
typedef struct {
	ElementType data[MAX_ELEMENTS];
	int size;
} List;
//---------Graph---------//
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
	int i,d=0;
	for(i=1; i<=G->n; i++){
		d+=G->A[x][i];
	}
	return d;
}
//---------List---------//
// Tao danh sach rong
void make_null(List* L) {
	L->size = 0;
}
// Them mot phan tu vao cuoi danh sach
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
// Lay phan tu tai vi tri i
ElementType element_at(List* L, int i) {
	return L->data[i-1];
}
// Tra ve so phan tu cua danh sach
int count_list(List* L) {
	return L->size;
}
//----------------------------------//
List neighbors(Graph *G, int x){
	List l;
	make_null(&l);
	int i;
	for(i=1; i<=G->n; i++){
		if(adjacent(G,x,i)) push_back(&l,i);
	}
	return l;
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
	
	printf("\n");
	for(i=1; i<=G.n; i++){
		printf("degree(%d) = %d\n",i,degree(&G,i));
	}
	
	printf("\n");
	for(i=1; i<=G.n; i++){
		List nbors = neighbors(&G,i);
		printf("neigbors(%d) = ",i);
		if(nbors.size==0) printf("nothing");
		for(j=1; j<=nbors.size; j++){
			printf("%d ",element_at(&nbors,j));
		}
		printf("\n");
	}
	fclose(file);
}
