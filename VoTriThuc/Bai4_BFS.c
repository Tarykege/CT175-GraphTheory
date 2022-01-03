#include<stdio.h>
#define Max_Vertices 20
#define Max_length 20
#define Max_Element 40
typedef struct {
    int A[Max_Vertices][Max_Vertices];
    int n;
}Graph;
typedef struct {
    int data[Max_length];
    int size;
}List;
typedef struct{
	int data[Max_Element];
	int front;
	int rear;
}Queue;
// -------------GRAPH------------------ //
// Ham khoi tao do thi
void init_Graph(Graph *G, int n){
    int i,j;
    G->n=n;
    for(i=1; i<=n ;i++){
        for(j=1; j<=n ;j++){
            G->A[i][j]=0;
        }
    }
}
// Ham them cung vao do thi vo huong 2->3 & 3->2 = 1
void add_edge(Graph *G, int x, int y){
    G->A[x][y]=1;
    G->A[y][x]=1;
}
// Ham kiem tra lang gieng
int adjacent(Graph *G, int x, int y){
    return (G->A[x][y]!=0);
}
// Ham tinh bac cua dinh
int degree(Graph *G, int x){
    int i,deg=0;
    for(i=1; i<=G->n; i++){
        if(G->A[i][x]==1) deg++; //adjacent(G,i,x)
    }
    return deg;
}
// -------------LIST------------------ //
// Khoi tao list de luu dinh lang gieng
void make_nullList(List *L){
    L->size=0;
}
// Them dinh lang gieng x vao list
void push_back(List *L, int x){
    L->data[L->size]=x;
    L->size++;
}
// Tra ve 1 list cac dinh lang gieng cua dinh x
List neighbors(Graph *G, int x){
    int i;
    List L;
    make_nullList(&L);
    for(i=1; i<=G->n; i++){
        if(G->A[i][x]==1) push_back(&L,i); //adjacent(G,i,x)
    }
    return L;
}
// Lay dinh tai vi tri i
int element_at(List *L, int i){
    return L->data[i-1];
}
// -------------QUEUE------------------ //
// lam rong va khoi tao hang doi
void make_nullQueue(Queue *Q){
	Q->front=-1;
	Q->rear=-1;
}
// kiem tra hang doi rong
int empty_Queue(Queue *Q){
	return Q->rear==-1;
}
// kiem tra hang doi day
int full_Queue(Queue *Q){
	return (Q->rear-Q->front+1)%Max_Element==0;	
}
// lay gia tri phan tu thu front
int front(Queue *Q){
	if(empty_Queue(Q)){
		printf("Queue is empty\n");
	}
	else return Q->data[Q->front];
}
// them phan tu vao hang doi
void enQueue(Queue *Q, int x){
	if(!full_Queue(Q)){
		if(empty_Queue(Q)) Q->front=0;
		Q->rear=(Q->rear+1)%Max_Element;
		Q->data[Q->rear]=x;
	} else printf("error\n");
}
// xoa phan tu khoi hang doi
void deQueue(Queue *Q){
	if(!empty_Queue(Q)){
		if(Q->front==Q->rear) make_nullQueue(Q);
		else Q->front=(Q->front+1)%Max_Element;
	} else printf("error\n");
}
// Duyet do thi dinh x theo chieu rong
List BFS(Graph *G, int x, int parent[]){
	List L_BFS;
	make_nullList(&L_BFS);
	Queue Q;
	make_nullQueue(&Q);
	enQueue(&Q,x);
	parent[x]=0;
	int mark[Max_Vertices],i,u;
	for(i=1; i<=G->n; i++){
		mark[i]=0;
	}
	while(!empty_Queue(&Q)){
		u=front(&Q);
		deQueue(&Q);
		if(mark[u]==1){
			continue;
		}
		mark[u]=1;
		push_back(&L_BFS,u);
		List nbor = neighbors(G,u);
		for(i=1; i<=nbor.size; i++){
			int v = element_at(&nbor,i);
			if(mark[v]==0){
				enQueue(&Q,v);
				if(parent[v]==-1){
					parent[v]=u;
				}
			}
		}
	}
	return L_BFS;
}
int main(){
	FILE *file = freopen("input4.txt","r",stdin);
	int n,m,u,v,i,j;
	scanf("%d%d",&n,&m);
	Graph G;
	init_Graph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	int parent[Max_Vertices],mark[Max_Vertices];
	for(i=1; i<=G.n; i++){
		parent[i]=-1;
		mark[i]=0;
	}
	for(i=1; i<=G.n; i++){
		if(mark[i]==0){
			List L_BFS = BFS(&G,i,parent);
			for(j=1; j<=L_BFS.size; j++){
				int v = element_at(&L_BFS,j);
				mark[v]=1;
			}
		}
	}
	for(i=1; i<=G.n; i++){
		printf("Parent(%d) = %d\n",i,parent[i]);
	}
	
	fclose(file);
}
