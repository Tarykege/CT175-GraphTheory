#include <stdio.h>
#define MAX_VERTICES 20
#define MAX_LENGTH 20
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
typedef struct{
	int data[MAX_LENGTH];
	int size;
}List;
typedef struct{
	int data[MAX_LENGTH];
	int front,rear;
}Queue;
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
void makeNullL(List *l){
	l->size=0;	
}
void pushBack(List *l, int value){
	l->data[l->size]=value;
	l->size++;
}
int elmAt(List *l, int pos){
	return l->data[pos-1];
}
List neighbors(Graph *G, int x){
	int i;
	List l;
	makeNullL(&l);
	for(i=1; i<=G->n; i++){
		if(G->A[i][x]>0) pushBack(&l,i);
	}
	return l;
}
void makeNullQ(Queue *q){
	q->front=0;
	q->rear=-1;
}
void enQ(Queue *q, int value){
	q->rear++;
	q->data[q->rear]=value;
}
void deQ(Queue *q){
	q->front++;
}
int front(Queue *q){
	return q->data[q->front];
}
int empty(Queue *q){
	return q->front>q->rear;
}
//----
int color[MAX_LENGTH];
int mark[MAX_LENGTH];
int isBipartite(Graph *G, int x){
	int i;
	for(i=0; i<MAX_LENGTH; i++){
		color[i]=-1;
		mark[i]=0;
	}
	Queue q; makeNullQ(&q);
	enQ(&q,x);
	color[x]=1;
	mark[x]=1;
	
	while(!empty(&q)){
		int current = front(&q); deQ(&q);
		List adjList = neighbors(G, current);
		for(i=1; i<=adjList.size; i++){
			int k = elmAt(&adjList,i);
			if(mark[k]==0){
				mark[k]=1;
				if(color[current]==1) color[k]=0;
				else if(color[current]==0) color[k]=1;
				enQ(&q,k);
			}
			else if(color[k] == color[current]){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	int i,j,u,v,m,n;
	Graph G;
	FILE *file = freopen("ThucHanh_buoi2_bai7.0.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	if(isBipartite(&G,1)){
		for(i=1; i<=G.n; i++){
			if(color[i]==1) printf("%d ",i);
		}
		printf("\n");
		for(i=1; i<=G.n; i++){
			if(color[i]==0) printf("%d ",i);
		}
	} else printf("IMPOSSIBLE");
	return 0;
}
