#include<stdio.h>
#define MAX_VERTICES 20
#define MAX_LENGTH 20
#define white 0
#define black 1
#define gray 2
int color[MAX_VERTICES];
int cycle;
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
typedef struct{
	int data[MAX_LENGTH];
	int size;
}List;
void initGraph(Graph *G, int n){
	int i,j;
	G->n=n;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			G->A[i][j]=0;
		}
	}
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
void makeNullList(List *l){
	l->size=0;	
}
void pushBack(List *l, int value){
	l->data[l->size]=value;
	l->size++;
}
int elementAt(List *l, int pos){
	return l->data[pos-1];
}
List neighbors(Graph *G, int x){
	int i;
	List l;
	makeNullList(&l);
	for(i=1; i<=G->n; i++){
		if(G->A[i][x]>0) pushBack(&l,i);
	}
	return l;
}
void dfs(Graph *G, int x, int parent){
	color[x]=gray;
	int i;
	List l = neighbors(G,x);
	for(i=1; i<=l.size; i++){
		int t = elementAt(&l,i);
		if(parent==t) continue;
		if(color[t]==gray){
			cycle=1;
			return;
		}
		if(color[t]==white) dfs(G,t,x);
	}
	color[x]=black;
}
int checkCycle(Graph *G){
	int i;
	for(i=1; i<=G->n; i++){
		color[i]=white;
	}
	cycle=0;
	for(i=1; i<=G->n; i++){
		if(color[i]==white){
			dfs(G,i,0);
		}
	}
	return cycle;
}
int main(){
	int i,u,v,m,n;
	Graph G;
	FILE *file = freopen("ThucHanh_buoi2_bai5.0.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	if(checkCycle(&G)) printf("YES"); else printf("NO");
	return 0;
}
