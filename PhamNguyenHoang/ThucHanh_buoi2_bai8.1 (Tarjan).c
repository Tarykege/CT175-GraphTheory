#include<stdio.h>
#define MAX_VERTICES 100
#define MAX_LENGTH 100
typedef struct{
	int A[MAX_VERTICES][MAX_VERTICES];
	int n;
}Graph;
typedef struct{
	int A[MAX_LENGTH];
	int size;
}List;
typedef struct{
	int A[MAX_LENGTH];
	int size;
}Stack;
void makeNullL(List *l){
	l->size=0;
}
void pushBack(List *l, int x){
	l->A[l->size]=x;
	l->size++;
}
int eleAt(List *l, int pos){
	return l->A[pos-1];
}
void makeNullS(Stack *s){
	s->size=0;
}
int emptyS(Stack *s){
	return s->size==0;
}
void push(Stack *s, int x){
	s->A[s->size]=x;
	s->size++;
}
void pop(Stack *s){
	if(!emptyS(s)) s->size--;
}
int top(Stack *s){
	return s->A[s->size-1];
}
void initGraph(Graph *G, int n){
	G->n=n;
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			G->A[i][j]=0;
		}
	}
}
void addEdge(Graph *G, int x, int y){
	G->A[x][y]=1;
}
List neighbor(Graph *G, int x){
	int i;
	List l;
	makeNullL(&l);
	for(i=1; i<=G->n; i++){
		if(G->A[x][i]==1){
			pushBack(&l,i);
		}
	}
	return l;
}
//-----------//
int num[MAX_LENGTH];
int min_num[MAX_LENGTH];
int on_stack[MAX_LENGTH];
int k;
Stack s;
int min(int x, int y){
	if(x>y) return y;
	else return x;
}
void tarjan(Graph *G, int x){
	num[x] = min_num[x] = k; k++;
	push(&s,x);
	on_stack[x] = 1;
	
	List list = neighbor(G,x);
	int i;
	for(i=1; i<=list.size; i++){
		int y=eleAt(&list, i);
		if(num[y] < 0){
			tarjan(G, y);
			min_num[x] = min(min_num[x], min_num[y]);
		} else if(on_stack[y]){
			min_num[x] = min(min_num[x], num[y]);
		}
	}
	printf("min_num[%d] = %d\n",x,min_num[x]);
	if(num[x] == min_num[x]){
		printf("%d la dinh khop.\n",x);
		int w;
		do{
			w=top(&s);
			pop(&s);
			on_stack[w]=0;
		}while(w!=x);
	}
}
void initTarjan(Graph *G){
	int i;
	for(i=1; i<=G->n; i++){
		num[i]=-1;
		on_stack[i]=0;
	}
	k=1;
	makeNullS(&s);
	for(i=1; i<=G->n; i++){
		if(num[i]==-1)
			tarjan(G,i);
	}
}
int main(){
	FILE *file = freopen("ThucHanh_buoi2_bai8.1.txt","r",stdin);
	int i,u,v,m,n;
	scanf("%d%d",&n,&m);
	Graph G; initGraph(&G, n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	initTarjan(&G);
}
