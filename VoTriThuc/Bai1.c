#include<stdio.h>
#define Max_Vertices 20
#define Max_length 20
typedef struct {
    int A[Max_Vertices][Max_Vertices];
    int n;
}Graph;
typedef struct {
    int data[Max_length];
    int size;
}List;
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
List neightbors(Graph *G, int x){
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
int main(){
    Graph G;
    FILE *file = freopen("input.txt","r",stdin);
    int n,m,u,v,i,j;
    scanf("%d%d",&n,&m);
    init_Graph(&G,n);

    // them cac cung vao do thi G
    for(i=1; i<=m; i++){
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }

    // in don do thi duoi dang ma tran dinh dinh
    for(i=1; i<=G.n; i++){
        for(j=1; j<=G.n; j++){
            printf("%d ",G.A[i][j]);
        }
        printf("\n");
    }

    // in cac dinh lang giang cua tung dinh trong do thi
    for(i=1; i<=G.n; i++){
        List L = neightbors(&G, i);
        printf("Neighbor(%d):",i);
        for(j=1; j<=L.size; j++){
            printf(" %d",element_at(&L,j));
        }
        printf("\n");
    }

    fclose(file);
}
