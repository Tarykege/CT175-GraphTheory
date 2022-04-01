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
	G->l[y][x]=z;
}
#define INFINITY 99999
int mark[MAXN];
int pi[MAXN];
int p[MAXN];
void Dijkstra(Graph *G, int s){
	int i,j,it;
	for(i=1; i<=G->n; i++){
		mark[i]=0;
		pi[i]= INFINITY;
	}
	pi[s]=0;
	p[s]=-1; //truoc dinh s khong co dinh nao ca
	
	for(it=1; it<G->n; it++){
		int min_pi = INFINITY;
		for(j=1;j<=G->n; j++){
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
	int path[MAXN];
	int k=0,i;
	int current = u;
	while(current != -1){
		path[k]=current; k++;
		current = p[current];
	}
	for(i=k-1; i>=0; i--) printf("%d",path[i]);
}
int main(){
	Graph G;
	int i,j,m,n,u,v,w,s,t;
	FILE* file = freopen("ThucHanh_buoi3_bai5.0.txt","r",stdin);
	scanf("%d%d",&n,&m);
	G.n=n;
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%d",&w);
			G.l[i][j]=w;
		}
	}
//	initGraph(&G,n);
//	for(i=1; i<=m; i++){
//		scanf("%d%d%d",&u,&v,&w);
//		addEdge(&G,u,v,w);
//	}
//	scanf("%d%d",&s,&t);
//	Dijkstra(&G,s);
//	if(pi[t]==INFINITY) printf("-1"); else printf("%d",pi[t]);
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%d ",G.l[i][j]);
		}
		printf("\n");
	}	
//	for(i=1; i<=G.n; i++){
//		printf("pi[%d]=%d, p[%d] = %d\n",i,pi[i],i,p[i]);
//	}
//	inDuongDi(n);
}
