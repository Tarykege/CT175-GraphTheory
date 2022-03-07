#include<stdio.h>
#define MAX_ELEMENTS 100
#define MAX_VERTICES 20
#define MAX_EDGES 20
typedef struct{
	int n,m;
	int A[MAX_VERTICES][MAX_EDGES];
}Graph;
typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
	int size;
} List;
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
/* Tao danh sach rong */
void make_null(List* L) {
	L->size = 0;	
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
	L->data[L->size] = x;
	L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1*/
ElementType element_at(List* L, int i) {
return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
return L->size;
}

List neighbors(Graph* G, int x) {
	int y;
	List list;
	make_null(&list);
	for (y = 1; y <= G->n; y++)
	if (G->A[x][y]==1)
	push_back(&list, y);
	return list;
}
int main() {
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
	//liet ke danh sach cac dinh
	for (v = 1; v <= n; v++) {
		List list = neighbors(&G, v);
		printf("Cac dinh ke cua %d: [", v);
		for (i = 1; i <= list.size; i++)
		printf("%d ", element_at(&list, i));
		printf("]\n");
	}
	fclose(file);
	return 0;
}
