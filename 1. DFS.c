#include<stdio.h>
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
	int size;
}Stack;
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
	int i,d=0;
	for(i=1; i<=G->n; i++){
		d+=G->A[x][i];
	}
	return d;
}
void makeNullList(List *L){
	L->size=0;
}
void pushBack(List *L, int x){
	L->data[L->size]=x;
	L->size++;
}
int elmAt(List L, int pos){
	return L.data[pos-1];
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
void makeNullStack(Stack *s){
	s->size=0;
}
void pushStack(Stack *s, int x){
	s->data[s->size]=x;
	s->size++;
}
void popStack(Stack *s){
	s->size--;
}
int emptyStack(Stack s){
	return s.size==0;
}
int top(Stack s){
	return s.data[s.size-1];
}
int mark[MAX_VERTICES];
int parent[MAX_VERTICES];
void DFS(Graph *G, int x){
	Stack s;
	makeNullStack(&s);
	pushStack(&s,x);
	parent[x]=0;
	
	while(!emptyStack(s)){
		int t = top(s); popStack(&s);
		if(mark[t]!=0) continue;
		
		mark[t]=1;
		List t_neighbor = neighbors(G,t);
		int i;
		for(i=1; i<=t_neighbor.size; i++){
			int y=elmAt(t_neighbor,i);
			if(mark[y]==0){
				pushStack(&s,y);
				parent[y]=t;
			}	
		}
	}
}
//Duong di cua dinh goc -> dinh x
// void Path(int x){
// 	List P; makeNullList(&P);
// 	while(x!=0){
// 		pushBack(&P,x);
// 		x=parent[x];	
// 	}
// 	int i;
// 	printf("%d",elmAt(P,P.size));
// 	for(i=P.size-1; i>=1; i--){
// 		printf(" -> %d",elmAt(P,i));
// 	}
// }
int main(){
	int i,u,v,m,n;
	Graph G;
 	FILE *f = freopen("DFS.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=0; i<m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	for(i=1; i<=G.n; i++){
		mark[i]=0;
		parent[i]=-1;
	}
	//Neu nhu dinh khong bat dau tu dinh 1
	DFS(&G,1);
	for(i=1; i<=G.n; i++){
		if(mark[i]==0){
			DFS(&G,i);
		}
	}
	for(i=1; i<=G.n; i++){
    	    printf("%d %d\n",i,parent[i]);
	}
}

