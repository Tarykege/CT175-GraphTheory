#include <stdio.h>
#define MAXN 500
#define MAX_VERTICES 500
#define NO_EDGE 0
typedef struct{
	int n;
	int l[MAXN][MAXN];
}Graph;
typedef struct{
	int data[MAXN];
	int size;
}List;
void makeNullList(List *l){
	l->size=0;	
}
void pushBack(List *l, int value){
	l->data[l->size]=value;
	l->size++;
}
int elementAt(List *l, int pos){
	return l->data[pos-1];
}
void initGraph(Graph *G, int n){
	G->n=n;
	int i,j;
	for(i=1; i<=G->n; i++){
		for(j=1; j<=G->n; j++){
			G->l[i][j] = NO_EDGE;
		}
	}
}
void addEdge(Graph *G, int x, int y){
	G->l[x][y]+=1;
}
void copyList(List *S1, List *S2){
	int i;
	makeNullList(S1);
	for(i=1; i<=S2->size; i++){
		pushBack(S1,elementAt(S2,i));
	}
}
int rank[MAX_VERTICES];
void ranking(Graph *G){
	int d[MAX_VERTICES]; // d[u] la lang gieng cua int dinh
	int x,u;
	// khoi tao mang d (tu 0 -> n) = 0
	for(u=1; u<=G->n; u++){
		d[u]=0;
	}
	// neu dinh x nao huong den u => d[u]++
	for(x=1; x<=G->n; x++)
		for(u=1; u<=G->n; u++)
			if(G->l[x][u]!=0)
				d[u]++;
	
	List S1,S2;
	makeNullList(&S1);
	// neu dinh u khong la lang gieng cua dinh nao tuc la d[u]==0 dua vao List S1;
	for(u = 1; u<=G->n; u++){
		if(d[u] == 0)
			pushBack(&S1,u);
	}
	int k=0 ,i; //Khoi tao rank ban dau (k) = 1
	while(S1.size>0){
		makeNullList(&S2);
		for(i=1; i<=S1.size; i++){
			int u = elementAt(&S1,i); // u giu cac dinh trong list s1
			rank[u]=k; // rank dinh u la k
			int v;
			for(v=1; v<=G->n; v++){
				if(G->l[u][v]!=0){ // dinh u khong muon lam lang gieng cua dinh khac vi da co rank
					d[v]--;
					if(d[v]==0); // neu dinh v khong la lang gieng cua cac dinh khac => dinh goc dua vao list S2
					pushBack(&S2, v);
				}
			}
		}
		copyList(&S1,&S2);
		k++;
	}
}
int main(){
	Graph G;
	int i,m,n,u,v;
	FILE* file = freopen("TopoSort.txt","r",stdin);
	scanf("%d%d",&n,&m);
	initGraph(&G,n);
	for(i=1; i<=m; i++){
		scanf("%d%d",&u,&v);
		addEdge(&G,u,v);
	}
	//	for(i=1; i<=n; i++){
	//		for(j=1; j<=n; j++){
	//			printf("%d ",G.l[i][j]);
	//		}
	//		printf("\n");
	//	}
	ranking(&G);
	for(i=1; i<=n; i++){
	//	printf("rank[%d] = %d\n",i,rank[i]);
		printf("%d\n",rank[i]);
	}
}
