#include <stdio.h> 

typedef struct {
    int f[100][100],c[100][100]; 
    int n; 
} Graph; 

void init_graph(Graph *G, int n) {
    G->n = n;
}
void add_edge(Graph *G, int u, int v, int f, int c) { 
    G->c[u][v] = c;
    G->f[u][v] = f;
} 
typedef struct {
    int a[100]; 
    int dau = 0, cuoi = 0;
}Queue; 
int front(Queue q) {
    return q.a[q.dau]; 
}
void pop(Queue *q) {
    q->dau++;
}
void push(Queue *q, int x) {
    q->a[q->cuoi] = x; 
    q->cuoi++;
}
int parent[100], w[100], mark[100]; 
void bfs(Graph g, int s) {
    Queue q; 
    push(&q,s);
    parent[s] = 0;
    while (q.dau != q.cuoi) {
        int x = front(q);  
        pop(&q); 
        for (int j = 1; j<=g.n; j++) {
            if (g.f[x][j] != 0){
                w[j] += g.f[x][j]; 
                w[x] -= g.f[x][j];  
                if ( mark[j] == 0) {
                    mark[j] = 1;
                    parent[j] = x;
                    push(&q,j);
                }
            } 
        }
    }
}
int main() {    
    freopen("dothi.txt" , "r", stdin); 
    int n , m;
    Graph g;
    scanf("%d %d", &n, &m); 
    init_graph(&g,n);
    for (int i = 1; i<= m; i++) {
        int u,v,c,f;
        scanf("%d %d %d %d ",&u,&v,&c,&f); 
        add_edge(&g,u,v,f,c);
    }
    bfs(g,1); 
    if (w[1]+w[n] != 0) {
        for (int i =2; i<g.n; i++) {
            if (w[i] != 0 ) printf("%d ", i );
        }
    }   else printf("TOT");
  
}