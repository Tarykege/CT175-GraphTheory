#include <stdio.h> 

typedef struct {
    int c[100][100], f[100][100];
    int n;
} Graph; 

typedef struct {
    int dau, pra, sigma; 
} label; 

void init_graph(Graph *g, int n) {
    g->n = n;
}
void add_edge(Graph *g, int u, int v, int w) {
    g->c[u][v] = w;
}
typedef struct{
    int a[100]; 
    int dau; int cuoi; 
} Queue;

void push(int s, Queue *q) {
    q->a[q->cuoi] = s;
    q->cuoi++; 
}
int font(Queue q) {
    return q.a[q.dau];
}
void pop(Queue *q) {
    q->dau++;
}
void print(Queue q) {
    for (int i=q.dau; i<q.cuoi; i++) {
        printf("%d ", q.a[i]); 
    }
    printf("\n");
}
int min(int x, int y) {
    return x < y? x : y;
}
void bfs(Graph g,int s, label a[]) {
    // duyet bfs
    for (int j = 1; j<=g.n; j++) {
        a[j].dau = 0;
    }
    Queue q;
    push(s,&q);
    a[s].dau = 1;
    a[s].pra = -1;
    a[s].sigma = 999999;
    while (q.dau != q.cuoi) {
        int i = font(q);
        pop(&q);
        for (int j = 1; j<=g.n; j++) {
            if (a[j].dau == 0 && g.f[i][j] < g.c[i][j]) {
                a[j].dau = +1; //cung thuan
                a[j].pra = i;
                a[j].sigma = min(a[i].sigma,g.c[i][j] - g.f[i][j]);
                push(j,&q);
            }
            if (a[j].dau == 0 && g.f[j][i] > 0) {
                a[j].dau = -1; //cung nghich
                a[j].pra = i;
                a[j].sigma = min(a[i].sigma,g.f[i][j]);
                push(j,&q);
            }
        }
    }
}
void in_kq(label a[],int n) {
    printf("X0: ");
    int i = 1;
    while (a[i].dau == 1) {
        printf("%d ",i);
        i++; 
    }
    printf("\nY0: ");
    while (i<=n) {
        printf("%d ",i);
        i++; 
    }
}
int dem = 0;
void ford_fullkerson(Graph g,int s, int t) {
    do { 
        // khoi tao label 
        label a[100]; 
        bfs(g,s,a);
        // tang luong
        if (a[t].dau != 0) {
            int k = t;
            while(k != s) {
                int p = a[k].pra;
                if (a[k].dau > 0) g.f[p][k] += a[t].sigma;
                else //giam luong
                    g.f[k][p] -= a[t].sigma;
                k = p;
            }
        } else {
            int sum =0 ;
            for (int i=1; i<=g.n; i++) {
                sum += g.f[i][t];
            }
            printf("Max flow: %d\n",sum);
            in_kq(a,g.n);
            break;
        }
    } while(1); 
}
int main() {
    freopen("LuongMax.txt", "r", stdin); 
    int n,m ;
    Graph g;
    scanf("%d %d", &n, &m);  
    init_graph(&g, n);
    for (int i = 0; i<m; i++) {
        int u,v,w;
        scanf("%d %d %d ",&u,&v,&w);
        add_edge(&g, u,v,w);
    }
    ford_fullkerson(g,1,n);
}
