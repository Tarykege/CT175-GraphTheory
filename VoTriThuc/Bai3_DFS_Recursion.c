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
typedef struct {
    int data[Max_Element];
    int size;
}Stack;
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
// khoi tao list de luu dinh lang gieng
void make_nullList(List *L){
    L->size=0;
}
// them dinh lang gieng x vao list
void push_back(List *L, int x){
    L->data[L->size]=x;
    L->size++;
}
// tra ve 1 list cac dinh lang gieng cua dinh x
List neighbors(Graph *G, int x){
    int i;
    List L;
    make_nullList(&L);
    for(i=1; i<=G->n; i++){
        if(G->A[i][x]==1) push_back(&L,i); //adjacent(G,i,x)
    }
    return L;
}
// lay dinh tai vi tri i
int element_at(List *L, int i){
    return L->data[i-1];
}
// -------------STACK------------------ //
// khoi tao stack
void make_nullStack(Stack *S){
    S->size=Max_Element;
}
// kiem tra stack rong
int empty_stack(Stack *S){
    return S->size==Max_Element;
}
// them phan tu vao stack
void push(Stack *S, int x){
    if(S->size!=0){
        S->size--;
        S->data[S->size]=x;
    }
}
// lay phan tu ra khoi stack
void pop(Stack *S){
    if(!empty_stack(S)){
        S->size++;
    }
}
// lay gia tri phan tu trong stack
int top(Stack *S){
    return S->data[S->size];
}
// duyet do thi theo chieu sau bang de quy
int mark[Max_Vertices]; // danh dau cac dinh duoc duyet
int parent[Max_Vertices]; // luu parent cua moi dinh
void DFS_Recursion(Graph *G, int u, int p){
	// Kiem tra u duyet chua
	if(mark[u]==1) return;
	// Danh dau u duoc duyet	
	mark[u]=1;
	// Cap nhat cha cua u
	parent[u]=p;
	int i;
	// lay danh sach lang gieng list cua u
	List list = neighbors(G, u);
	for(i=1; i<=list.size; i++){
		int v = element_at(&list,i);
	// goi de quy cac lang gieng v cua u
		DFS_Recursion(G, v, u);
	}
}
int main(){
	Graph G;
	FILE *file = freopen("input3.txt","r",stdin);
	int n,m,u,v,i;
	scanf("%d%d",&n,&m);
	// khoi tao do thi
	init_Graph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		add_edge(&G,u,v);
	}
	// khoi tao list
	for(i=1; i<=G.n; i++){
		mark[i]=0;
		parent[i]=-1;
	}
	// duyet do thi khong lien thong
	for(i=1; i<=G.n; i++){
			if(mark[i]==0){
				DFS_Recursion(&G,i,0);
			}
	}
	// in cac dinh va cha cua dinh trong do thi
	for(i=1; i<=G.n; i++){
		printf("%d %d\n",i,parent[i]);
	}
	fclose(file);
   return 0;
}
