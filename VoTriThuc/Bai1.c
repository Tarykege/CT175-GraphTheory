#include<stdio.h>
#define Max_Vertices 20
#define Max_length 20
// Tao cau truc do thi: Mang 2 chieu de luu duoi dang ma tran, bien n de luu so luong dinh
typedef struct {
    int data[Max_length];
    int size;
}List;
typedef struct {
    int A[Max_Vertices][Max_Vertices];
    int n;
}Graph;
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
// Ham tinh bac cua dinh
int degree(Graph *G, int x){
    int i,j,deg=0;
    for(i=1; i<=G->n; i++){
        if(G->A[i][x]==1) deg++;
    }
    return deg;
}
// Ham khoi tao list L de luu gia tri lang gieng
void make_nullList(List *L){
    L->size=0;
}
// Ham them dinh lang gieng vao x
void push_back(List *L, int x){
    L->data[L->size]=x;
    L->size++;
}
// Ham luu cac dinh lang gieng cua x vao list
List neighbor(Graph *G, int x){
    int i;
    List L;
    make_nullList(&L);
    for(i=1; i<=G->n; i++){
        if(G->A[i][x]==1) push_back(&L,i);
    }
    return L;
}
int main(){
    Graph G;
    int n,m,i,j,e,u,v;
    FILE *file = freopen("D:\\Code\\CodeBlock\\GraphTheory-CT175\\VoTriThuc\\input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    init_Graph(&G,n);
    //Them cung vao do thi
    for(e=1; e<=m; e++){
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }
    // in ra lang gieng cua cac dinh trong do thi
    for(i=1; i<=G.n; i++){
        List L = neighbor(&G,i);
            printf("Neightbor(%d) =",i);
        for(j=0; j<L.size; j++){
            printf(" %d",L.data[j]);
        }
        printf("\n");
    }
    fclose(file);

}
