#include<stdio.h>
#define MAX_VERTICES 20
#define MAX_LENGTH 20
int mark[MAX_VERTICES];
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
void makeNullQueue(Queue *q){
	q->front=0;
	q->rear=-1;
}
void enQueue(Queue *q, int value){
	q->rear++;
	q->data[q->rear]=value;
}
void deQueue(Queue *q){
	q->front++;
}
int front(Queue *q){
	return q->data[q->front];
}
int empty(Queue *q){
	return q->front>q->rear;
}
void bfs(Graph *G, int x){
	Queue q;
	makeNullQueue(&q);
	int i;

	enQueue(&q,x);
	while(!empty(&q)){
		int t = front(&q); deQueue(&q);
		if(mark[t]==1) continue;
		mark[t]=1;
		List l = neighbors(G,t);
		for(i=1; i<=l.size; i++){
			int y = elementAt(&l,i);
			if(mark[y]==0){
				enQueue(&q,y);
			}
		}
	}
}

int main(){
	int i,u,v,m,n;
	Graph G;
	FILE *file = freopen("D:\\Study\\Code\\C\\GraphTheory-CT175\\PhamNguyenHoang\\ThucHanh_buoi2_bai3.0.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	for(i=1; i<=G.n; i++){
		mark[i]=0;
	}
	bfs(&G,1);
	int check=1;
	for(i=1; i<=G.n; i++){
		if(mark[i]==0){
			check=0;
		}
	}
	if(check) printf("YES"); else printf("NO");
	return 0;
}
