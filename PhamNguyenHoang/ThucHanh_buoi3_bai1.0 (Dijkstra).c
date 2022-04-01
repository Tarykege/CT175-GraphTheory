#include <stdio.h>
#define MAXN 500
#define NO_EDGE 0
typedef struct{
	int n;
	int l[MAXN][MAXN];
}Graph;

void initGraph(Graph *G, int n){
	G->n=n;
	int i,j;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++){
			G->l[i][j] = NO_EDGE;
		}
	}
}
void addEdge(Graph *G, int x, int y, int z){
	G->l[x][y]=z;
}
#define INFINITY 99999
int mark[MAXN];
int pi[MAXN]; //pi[i] do dai duong di ngan nhat tu s -> i
int p[MAXN];  //p[i] dinh lien truoc dinh i tren duong di ngan nhat tu s -> i
void Dijkstra(Graph *G, int s){
	int i,j,it;
	for(i=1; i<=G->n; i++){
		mark[i]=0;
		pi[i]=INFINITY;
	}
	pi[s]=0; //duong di ngan nhat tu s den s la 0
	p[s]=-1; //truoc dinh s khong co dinh nao ca
	
	for(it=1; it<G->n; it++){
		int min_pi = INFINITY;
		for(j=1; j<=G->n; j++){
			if(mark[j]==0 && pi[j]<min_pi){
				min_pi = pi[j];
				i = j;
			}
		}
		mark[i]=1;
		for(j=1; j<=G->n; j++){
			if(G->l[i][j] != NO_EDGE && mark[j]==0){
				if(pi[i]+G->l[i][j]<pi[j]){
					pi[j]=pi[i]+G->l[i][j];
					p[j]=i;
				}
			}
		}
	}
}
void inDuongDi(int u){
	int path[MAXN], k=0, i;
	int current = u;
	while(current != -1){
		path[k] = current; k++;
		current = p[current];
	}
	for(i=k-1; i>=0; i--) printf("%d ",path[i]);
}
int main(){
	Graph G;
	int i,m,n,u,v,w,j;
	FILE* file = freopen("ThucHanh_buoi3_bai1.0.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d%d",&u,&v,&w);
		addEdge(&G,u,v,w);
	}
//	in do thi dang ma tran
	for(i=1; i<=G.n; i++){
		for(j=1; j<=G.n; j++){
			printf("%d ",G.l[i][j]);
		}
		printf("\n");
	}
	Dijkstra(&G,1);
	inDuongDi(n);
//	for(i=1; i<=G.n; i++){
//		printf("pi[%d]=%d, p[%d] = %d\n",i,pi[i],i,p[i]);
//	}
// duong di tu dinh 1 den dinh n
//	if(pi[n]==INFINITY) printf("-1"); else printf("%d",pi[n]);
}
