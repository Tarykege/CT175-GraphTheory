#include<stdio.h>
#define Max_Vertices 20
// Tao cau truc do thi: Mang 2 chieu de luu duoi dang ma tran, bien n de luu so luong dinh
typedef struct {
    int A[Max_Vertices][Max_Vertices];
    int n,m;
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
    for(int i=1; i<=G->n; i++){
        if(G->A[i][x]==1) deg++;
    }
    return deg;
}
int main(){
    Graph G;
    int n,m;
    scanf("%d",&n);
//    FILE *file = fopen("D:\Code\CodeBlock\GraphTheory-CT175\VoTriThuc\input.txt","r");
//    fscanf(file,"%d%d",&n,&m);
//    fclose(file);
//    init_Graph(&G,6);
//    add_edge(&G,2,6);
//    add_edge(&G,6,4);
//    add_edge(&G,5,6);
//    add_edge(&G,1,4);
//    add_edge(&G,1,5);
//    add_edge(&G,2,3);
//    add_edge(&G,2,4);
//    add_edge(&G,4,5);
}
