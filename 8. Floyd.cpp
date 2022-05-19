#include <stdio.h>
#define MAXN 100
#define NO_EDGE 0
//hoac gia tri dac biet nao do
typedef struct {
	int n;
	int L[MAXN][MAXN];
} Graph;

void init_graph(Graph* G, int n) {
	G->n = n;
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			G->L[i][j] = NO_EDGE;
}
void add_edge(Graph *G,int x,int y,int w) {
	G->L[x][y] = w;
}
// Floyd - Warshall
#define INFINITY 9999999
int pi[MAXN][MAXN];
int next[MAXN][MAXN];
void Floyd_Warshall(Graph *G) {
    //khoi tao
	for (int i = 1; i<= G->n; i++)
        for (int j = 1; j<= G->n; j++) {
            pi[i][j] = INFINITY;
            next[i][j] = -1;
            if (G->L[i][j] != NO_EDGE) {
                pi[i][j] = G->L[i][j];
                next[i][j] = j;
            }
            if (i == j) pi[i][j] = 0;
        }
    //Duyet
	for (int k=1; k<= G->n; k++)
        for (int u = 1; u<= G->n; u++)
            for (int v = 1; v<= G->n; v++)
                if (pi[u][k] + pi[k][v] < pi[u][v]) {
                    pi[u][v] = pi[u][k] + pi[k][v];
                    next[u][v] = next[u][k];
                }
}
int main() {
	freopen("dt.txt", "r", stdin);
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	Floyd_Warshall(&G);
    for (int i = 1; i<= n; i++) {
        if (pi[i][i] < 0) {
            printf("negative cycle");
            return 0;
        }
    }
    printf("ok");
}
