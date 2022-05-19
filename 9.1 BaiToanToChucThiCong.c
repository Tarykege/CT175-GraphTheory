#include <stdio.h>
int r[100];
int d[100];

typedef struct {
	int size;
	int A[100];
} List;

typedef struct {
	int A[100][100];
	int n;
} Graph;

typedef struct {
	int t,T;
} congviec;

void makeNull_List(List *L) {
	L->size=0;
}

void pushBack_List(List *L, int x) {
	L->A[L->size++]=x;
}

int element_at(List L1, int i) {
	return L1.A[i];
}

void coppy_List(List *L1, List *L2) {
	int i;
	makeNull_List(L1);
	for(i=0; i<L2->size; i++) {
		pushBack_List(L1,L2->A[i]);
	}
}

void init_graph(Graph *G, int n) {
	G->n=n;
	int i,j;
	for(i=1; i<=G->n; i++)
		for(j=1; j<=G->n; j++)
			G->A[i][j]=0;
}

void add_edge(Graph *G,int u, int v) {
	G->A[u][v]++;
}

List rank(Graph *G) {
	int b[100],u,v;
	for(u=1; u<=G->n; u++) {
		b[u]=0;
		for(v=1; v<=G->n; v++)
			if(G->A[v][u]!=0)
				b[u]++;
	}

	List L1, L2,L;
	makeNull_List(&L1);
	makeNull_List(&L);
	for(u=1; u<=G->n; u++)
		if(b[u]==0)
			pushBack_List(&L1,u);

	int k=0;
	while(L1.size>0) {
		makeNull_List(&L2);
		int i;
		for(i=0; i<L1.size; i++) {
			u=element_at(L1,i);
			r[u]=k;
			pushBack_List(&L,u);

			for(v=1; v<=G->n; v++)
				if(G->A[u][v]!=0) {
					b[v]--;
					if(b[v]==0)
						pushBack_List(&L2,v);
				}
		}
		coppy_List(&L1,&L2);
		k++;
	}
	return L;
}

int bacra(Graph *G, int n, int x) {
	int k=0,i;
	for(i=1; i<=n; i++)
		if(G->A[x][i]!=0) k++;
	return k;
}

int bacvao(Graph *G, int n, int x) {
	int k=0,i;
	for(i=1; i<=n; i++)
		if(G->A[i][x]!=0) k++;
	return k;
}

int min(int x, int y){
	if(x>y) return y;
	return x;
}

int max(int x, int y){
	if(x>y) return x;
	return y;
}

int main() {
	freopen("BaiToanToChucThiCong.txt", "r", stdin);
	Graph G;
	int n, m, u, v, e;
	scanf("%d",&n);
	init_graph(&G,n+2);
	int alpha=n+1,beta=n+2;
	d[alpha]=0;
	for(u=1; u<=n; u++) {
		scanf("%d",&d[u]);
		do {
			scanf("%d ",&v);
			if(v>0)
				add_edge(&G,v,u);
		} while(v>0);
	}

	int i,j,t[100],T[100];
	for(i=1; i<=n; i++) //them cung cho alpha
		if(bacvao(&G,n,i)==0)
			add_edge(&G,alpha,i);

	for(i=1; i<=n; i++) //them cung cho beta
		if(bacra(&G,n,i)==0)
			add_edge(&G,i,beta);

	List L=rank(&G);
	t[alpha]=0;
	for(i=1; i<=L.size; i++) {
		u = element_at(L,i);
		t[u] = -9999;
		for(v=1; v<=G.n; v++)
			if(G.A[v][u] > 0)
				t[u] = max(t[u],t[v]+d[v]);
	}

	T[beta]=t[beta];
	for (j=beta-2; j >= 1; j--) {
		u = element_at(L, j);
		T[u] = 9999; 
		for (v = 1; v <= G.n; v++)
			if (G.A[u][v] > 0)
				T[u] = min(T[u], T[v] - d[u]);
	}
	
	for(i=1;i<=n+2;i++)
		printf("%3d|%5d%5d\n",L.A[i],t[i],T[i]);
}
