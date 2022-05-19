#include<stdio.h>
#define MAX_VERTICES 20
#define MAX_LENGTH 30
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
typedef struct{
	int data[MAX_LENGTH];
	int front,rear;
}Queue;
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
	int i, d=0;
	for(i=1; i<=G->n; i++){
		if(G->A[x][i]>0) d++;
	}
	return d;
}
void makeNullList(List *l){
	l->size=0;
}
void pushBack(List *l, int x){
	l->data[l->size]=x;
	l->size++;
}
int elmAt(List *l, int pos){
	return l->data[pos-1];
}
List neighbors(Graph *G, int x){
	int i;
	List l;
	makeNullList(&l);
	for(i=1; i<=G->n; i++){
		if(G->A[x][i]>0) pushBack(&l,i);
	}
	return l;
}
void makeNullQ(Queue *Q){
	Q->front=0;
	Q->rear=-1;
}
void pushQ(Queue *Q, int x){
	Q->rear++;
	Q->data[Q->rear]=x;
}
void popQ(Queue *Q){
	Q->front++;
}
int top(Queue *Q){
	return Q->data[Q->front];
}
int empty(Queue *Q){
	return Q->front > Q->rear;
}
int mark[MAX_LENGTH];
int parent[MAX_VERTICES];
void BFS(Graph *G, int x){
	Queue Q;
	makeNullQ(&Q);
	parent[x]=0;
	pushQ(&Q,x);
	
	while(!empty(&Q)){
		int t = top(&Q); popQ(&Q);
		if(mark[t]!=0) continue;
		mark[t]=1;
		List l = neighbors(G,t);
		int i;
		for(i=1; i<=l.size; i++){
			int y = elmAt(&l,i);
			if(mark[y]==0){
				pushQ(&Q, y);
				if(parent[y]==-1){
					parent[y]=t;
				}
			}
		}
	}
}
// void Path(int x){
// 	List p; makeNullList(&p);
// 	while(x!=0){
// 		pushBack(&p,x);
// 		x=parent[x];
// 	}
// 	int i;
// 	printf("%d",elmAt(&p,p.size));
// 	for(i=p.size-1; i>=1; i--){
// 		printf(" -> %d",elmAt(&p,i));
// 	}
// }
int main(){
 	FILE *f = freopen("BFS.txt","r",stdin);
	Graph G; int i,m,n,u,v;
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	for(i=1; i<=n; i++){
		mark[i]=0;
		parent[i]=-1;
	}
	BFS(&G, 1);
	for(i=2; i<=n; i++){
		if(mark[i]==0){
			BFS(&G,i);
		}
	}
// 	Path(8);
    for(i=1; i<=G.n; i++){
        printf("%d %d\n",i,parent[i]);
	}
}
