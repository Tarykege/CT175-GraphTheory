#include<stdio.h>
#define MAX_VERTICES 30
#define MAX_LENGTH 30
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
typedef struct{
	int data[MAX_LENGTH];
	int size;
}List;
void initGraph(Graph *G, int n){
	G->n=n;
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			G->A[i][j]=0;
		}
	}
}
void makeNullList(List *l){
	l->size=0;
}
void addEdge(Graph *G, int x, int y){
	G->A[x][y]+=1;
	G->A[y][x]+=1;
}
int degree(Graph *G, int x){
	int i,deg=0;
	for(i=1; i<=G->n; i++){
		deg+=G->A[i][x];
	}
	return deg;
}
void pushBack(List *l, int x){
	l->data[l->size]=x;
	l->size++;
}
List neighbors(Graph *G, int x){
	List l; int i;
	makeNullList(&l);
	for(i=1; i<=G->n; i++){
		if(G->A[i][x]!=0) pushBack(&l,i);
	}
	return l;
}
int elementAt(List *l, int pos){
	return l->data[pos-1];
}
int color[MAX_VERTICES];
int fail;
void colorize(Graph *G, int x, int c){
	if(color[x]==-1){
		color[x]=c;
		List l = neighbors(G,x);
		int i;
		for(i=1; i<=l.size; i++){
			int t = elementAt(&l,i);
			colorize(G,t,!c);
		}
	} else if(color[x]!=c) fail=1;
}
int isBiGraph(Graph *G){
	int i;
	for(i=1; i<=G->n; i++){
		color[i]=-1;
	}
	fail=0;
	colorize(G, 1, 0);
	return !fail;
}
int main(){
	FILE *file = freopen("D:\\Study\\Code\\C\\GraphTheory-CT175\\PhamNguyenHoang\\ThucHanh_buoi2_bai7.0.txt","r",stdin);
	Graph G; int i,m,n,u,v;
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	if(isBiGraph(&G)){
		for(i=1; i<=n; i++){
			if(color[i]==0) printf("%d ",i);
		}
		printf("\n");
		for(i=1; i<=n; i++){
			if(color[i]==1) printf("%d ",i);
		}
	}
	else printf("IMPOSSIBLE");
}
