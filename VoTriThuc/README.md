*[Võ Trí Thức - CTU](https://www.youtube.com/playlist?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)*

## day 1 (22/12/2021)
- [X] [Bài 1: Biểu diễn đơn đồ thị vô hướng bằng "Ma trận Đỉnh - Đỉnh" - Phần 1/2](https://youtu.be/1JTc5TkwXJE?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)

### Lý thuyết
```
- Tập hợp các đỉnh: Vertices (V)
- Tập hợp cung: Edges (E)
- Đơn đồ thị vô hướng
- Không chứa khuyên (a,a)
- Không chứa đa cung
- Tool: https://csacademy.com/app/graph_editor/
```
### Hàm
```
- typdef struct{int A[MAX_VERTICES][MAX_VERTICES]; int n,m}Graph: cấu trúc lưu dữ liệu đồ thị //ví dụ A[2][3] là đường đi từ đỉnh 2 đến đỉnh 3, n so luong dinh, m so luong cung
- init_Graph(Grap *G, int n): khởi tạo đồ thị
- add_edge(Grap *G, int x, int y;): Thêm cung vào đồ thị
- int adjacent(Graph *G, int x, int y): kiểm tra láng giềng
```
## day 2 (25/12/2021)
- [X] [Bài 1: Biểu diễn đơn đồ thị vô hướng bằng "Ma trận Đỉnh - Đỉnh" - Phần 2/2](https://youtu.be/2_zRPi3ryPg?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
### Lý thuyết
```
- Bậc của một đỉnh: số lượng cung nối của đỉnh đó với các đỉnh khác, số bậc tương đương với số đỉnh láng giềng của đỉnh đó
- In các bậc của một đỉnh, in các bậc của từng đỉnh
- Mở/đọc FILE
- Dùng cấu trúc List để quản lý các đỉnh láng giềng (tên và số lượng đỉnh láng giềng của một đỉnh)
```
### Hàm
```
- int degree(Graph *G, int x): tính bậc của một đỉnh
- fopen("path", "retrict format") - fscanf("path", "%kieu_du_lieu",bien)
- freopen("path", "retrict format", stdin) - scanf("%kieu_du_lieu",bien)
- typdef struct(int A[MAX_LENGTH; int n;])List;
- void make_nullList(List *L)
- void push_back(List *L, int x): x là đỉnh láng giềng cần thêm vào
- List neightbor(Graph *G, int x): x là đỉnh cần biết có bao nhiêu đỉnh láng giềng, giá trị trả về list các đỉnh láng giềng
```
## day 3 (27/12/2021)
- [X] [Bài 2- Lý thuyết đồ thị - Duyệt đồ thị theo chiều sâu (Thuật toán DFS - stack) - Phần 1/6](https://youtu.be/Ej1Vc0fUXPM?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
### Lý thuyết
```
- Vai trò của duyệt đồ thị:
	kiểm tra tính liên thông của đồ thị (main)
	Tìm kiếm trạng thái mục tiêu trong bài toán tìm kiếm không gian trạng thái
- Đồ thị liên thông: Giữa hai cặp đỉnh bất kì luôn tìm được đường đi
- Quá trình duyệt hoàn thành, nếu các đỉnh đều được duyệt là đồ thị liên thông (nếu có ít nhất một đỉnh chưa được duyệt thì đồ thị chưa liên thông)
```
### Thuật toán
```
Đưa một đỉnh bất kỳ vào ngăn xếp
While (stack != empty){
	u=pop(stack)
	if(u đã duyệt)
		continue;
	Duyệt u (vd: in u ra màn hình)
	đánh dấu u đã duyệt
	for(các đỉnh kề goi là v của u)
		if(v chưa được duyệt) đưa vào stack
}
```
### day 4 (28/12/2021)
- [X] [Bài 2- Lý thuyết đồ thị - Duyệt đồ thị theo chiều sâu (Thuật toán DFS - stack) - Phần 2/6](https://youtu.be/hBXzdzpTPeA?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
### Lý thuyết
```
- Dùng stack để duyệt
- Dùng list để lưu các đỉnh được duyệt
```
### Hàm
```
	typdef struct{int data[MAX_LENGTH]; int size;}Stack;
	void make_nullStack(Stack *S): khởi tạo stack
	int empty_stack(Stack *S): kiểm tra stack rỗng
	void push_stack(Stack *stack, int x): thêm phần tử vào stack
	int top(Stack *S): lấy giá trị phần tử trong stack
	void pop(Stack *S): xóa phần tử trong stack
	List depth_first_search(Graph *G, int x): duyệt đồ thị theo chiều sâu
		int mark[MAX_VERTICES]: đánh dấu, lưu các đỉnh được duyệt
```
### Important Code
```
// -------------DFS--------------- //
List depth_first_search(Graph *G, int x){
    List list_dfs; // luu cac dinh duoc duyet tu dinh x
    make_nullList(&list_dfs);
    Stack S;
    int u,i;
    make_nullStack(&S);
    push(&S,x);
    // tao list de danh dau dinh duoc duyet
    int mark[Max_Vertices]; //do dai cua mark == so luong dinh
    for(i=1; i<=G->n; i++){//khoi tao cac dinh la chua danh dau
        mark[i]=0;
    }
    // thuc hien duyet do thi
    while(!empty_stack(&S)){
        u=top(&S);
        pop(&S);
        if(mark[u]==1) continue;
        mark[u]=1;
        push_back(&list_dfs,u);
        List u_neightbors=neightbors(G,u); //luu list cac phan tu lang gieng cua u
        for(i=1; i<=u_neightbors.size; i++){
            int v = element_at(&u_neightbors,i);
            if(mark[v]==0) push(&S,v);
        }
    }
    return list_dfs;
}
// -------------MAIN--------------- //
// tao list luu tat ca cac dinh duoc danh dau chua
    List mark_dfs;
    for(i=1; i<G.n; i++){
        mark_dfs.data[i]=0;
    }
    //Duyet tat ca cac dinh ke ca dinh chua duoc danh dau
    for(i = 1; i<=G.n; i++){
        if(mark_dfs.data[i]==0){
            List list_v = depth_first_search(&G,i);
            for(j=1; j<=list_v.size; j++){
                printf("Duyet %d\n",list_v.data[j-1]);
                mark_dfs.data[list_v.data[j-1]]=1;
            }
        }
    }
```
### day 5 (29/12/2021)
- [X] [Bài 2- Lý thuyết đồ thị - Duyệt đồ thị theo chiều sâu (Thuật toán DFS - stack) - Phần 3/6](https://youtu.be/OCCt6u1vR1I?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
### Lý thuyết
```
- Dùng list lưu đỉnh cha của đỉnh được duyệt
```
### Hàm
```
- List depth_first_search(Graph *G, int x, int parent[]): duyệt đồ thị theo chiều sâu
```
### Important Code
```
// -------------DFS--------------- //
List depth_first_search(Graph *G, int x, int parent[]){
    List list_dfs; // luu cac dinh duoc duyet tu dinh x
    make_nullList(&list_dfs);
    Stack S;
    int u,i;
    make_nullStack(&S);
    push(&S,x);
    parent[x]=0;
    // tao list de danh dau dinh duoc duyet
    int mark[Max_Vertices]; //do dai cua mark == so luong dinh
    for(i=1; i<=G->n; i++){//khoi tao cac dinh la chua danh dau
        mark[i]=0;
    }
    // thuc hien duyet do thi
    while(!empty_stack(&S)){
        u=top(&S);
        pop(&S);
        if(mark[u]==1) continue;
        mark[u]=1;
        push_back(&list_dfs,u);
        List u_neightbors=neightbors(G,u); //luu list cac phan tu lang gieng cua u
        for(i=1; i<=u_neightbors.size; i++){
            int v = element_at(&u_neightbors,i);
            if(mark[v]==0){
            	parent[v]=u;
            	push(&S,v);
			}
        }
    }
    return list_dfs;
}
// -------------MAIN--------------- //
int main(){
    FILE *file = freopen("input2.txt","r",stdin);
    int n,m,u,v,i,j;
    scanf("%d%d",&n,&m);
    // khoi tao do thi
    Graph G;
    init_Graph(&G,n);
    for(i=1; i<=m; i++){
        scanf("%d%d",&u,&v);
        add_edge(&G,u,v);
    }
    // tao list luu tat ca cac dinh duoc danh dau chua
    int mark_dfs[Max_Vertices];
    int parent[Max_Vertices];
    for(i=1; i<=G.n; i++){
        mark_dfs[i]=0;
        parent[i]=0;
    }
    
    //Duyet tat ca cac dinh ke ca dinh chua duoc danh dau
    for(i=1; i<=G.n; i++){
        if(mark_dfs[i]==0){
            List list_v = depth_first_search(&G,i,parent);
            for(j=1; j<=list_v.size; j++){
                mark_dfs[list_v.data[j-1]]=1;
            }
        }
    }
    for(i=1; i<=G.n; i++){
        printf("%d %d\n",i,parent[i]);
    }
    fclose(file);
}
```

### day 6 (1/1/2022)
- [X] [Bài 2- Lý thuyết đồ thị - Duyệt đồ thị theo chiều sâu (Thuật toán DFS - recursion) - Phần 4/6](https://youtu.be/5ACSZdTyziM?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
### Lý thuyết
```
int mark[Max_Vertices]; // bien global danh dau cac dinh duoc duyet
int parent[Max_Vertices]; // bien global luu parent cua moi dinh
void DFS_Recurion(Graph *G, int u, int p){
	if(u đã duyệt)
		return;
	Duyệt u
	Đánh dấu u đã duyệt
	Cập nhật tra của u
	List neightbors(u) = {v1, v2,...}
	for(các đỉnh kề v của u){
		DFS_Recursion(G,v,u);
}
```
### Hàm
```
- void DFS_Recurion(Graph *G, int u, int p)
```
### Important Code
```
void DFS_Recursion(Graph *G, int u, int p){
	// Kiem tra u duyet chua
	if(mark[u]==1) return;
	// Danh dau u duoc duyet	
	mark[u]=1;
	// Cap nhat cha cua u
	parent[u]=p;
	int i;
	// lay danh sach lang gieng list cua u
	List list = neighbors(G, u);
	for(i=1; i<=list.size; i++){
		int v = element_at(&list,i);
	// goi de quy cac lang gieng v cua u
		DFS_Recursion(G, v, u);
	}
}

// duyet do thi khong lien thong
for(i=1; i<=G.n; i++){
		if(mark[i]==0){
			DFS_Recursion(&G,i,0);
		}
}
```

### day 7 (3/1/2022)
- [X] [Bài 3- Lý thuyết đồ thị - Duyệt đồ thị theo chiều rộng (Thuật toán BFS) - Phần 1/2](https://youtu.be/Duwqh4gGFbs?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
- [X] [Bài 3- Lý thuyết đồ thị - Duyệt đồ thị theo chiều rộng (Thuật toán BFS) - Phần 2/2](https://youtu.be/1GFWuzYrOYI?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
### Lý thuyết
```
Đưa 1 đỉnh x bất kỳ vào hàng đợi
While(Queue !empty){
	u = front(Queue);
	if(u đã duyệt)	continue;
	Duyệt u;
	Đánh dấu u đã duyệt
	for(các đỉnh kề v của u)
		if(v chưa được duyệt)
			đưa v vào hàng đợi
}
```
### Hàm
```
- void make_nullQueue(Queue *Q)
- int empty_Queue(Queue *Q)
- int full_Queue(Queue *Q)
- int front(Queue *Q)
- void enQueue(Queue *Q, int x)
- void deQueue(Queue *Q)
- List BFS(Graph *G, int x, int parent[])
- for(i=1; i<=nbor.size; i++){
			int v = element_at(&nbor,i);
			if(mark[v]==0){
				enQueue(&Q,v);
				if(parent[v]==-1){
					parent[v]=u;
				}
			}
		}
```
### Important Code
```
// -------------QUEUE--------------- //
// lam rong va khoi tao hang doi
void make_nullQueue(Queue *Q){
	Q->front=-1;
	Q->rear=-1;
}
// kiem tra hang doi rong
int empty_Queue(Queue *Q){
	return Q->rear==-1;
}
// kiem tra hang doi day
int full_Queue(Queue *Q){
	return (Q->rear-Q->front+1)%Max_Element==0;	
}
// lay gia tri phan tu thu front
int front(Queue *Q){
	if(empty_Queue(Q)){
		printf("Queue is empty\n");
	}
	else return Q->data[Q->front];
}
// them phan tu vao hang doi
void enQueue(Queue *Q, int x){
	if(!full_Queue(Q)){
		if(empty_Queue(Q)) Q->front=0;
		Q->rear=(Q->rear+1)%Max_Element;
		Q->data[Q->rear]=x;
	} else printf("error\n");
}
// xoa phan tu khoi hang doi
void deQueue(Queue *Q){
	if(!empty_Queue(Q)){
		if(Q->front==Q->rear) make_nullQueue(Q);
		else Q->front=(Q->front+1)%Max_Element;
	} else printf("error\n");
}
// -------------BFS--------------- //
List BFS(Graph *G, int x, int parent[]){
	List L_BFS;
	make_nullList(&L_BFS);
	Queue Q;
	make_nullQueue(&Q);
	enQueue(&Q,x);
	parent[x]=0;
	int mark[Max_Vertices],i,u;
	for(i=1; i<=G->n; i++){
		mark[i]=0;
	}
	while(!empty_Queue(&Q)){
		u=front(&Q);
		deQueue(&Q);
		if(mark[u]==1){
			continue;
		}
		mark[u]=1;
		push_back(&L_BFS,u);
		List nbor = neighbors(G,u);
		for(i=1; i<=nbor.size; i++){
			int v = element_at(&nbor,i);
			if(mark[v]==0){
				enQueue(&Q,v);
				if(parent[v]==-1){
					parent[v]=u;
				}
			}
		}
	}
	return L_BFS;
}
// -------------MAIN--------------- //
int parent[Max_Vertices],mark[Max_Vertices];
	for(i=1; i<=G.n; i++){
		parent[i]=-1;
		mark[i]=0;
	}
	for(i=1; i<=G.n; i++){
		if(mark[i]==0){
			List L_BFS = BFS(&G,i,parent);
			for(j=1; j<=L_BFS.size; j++){
				int v = element_at(&L_BFS,j);
				mark[v]=1;
			}
		}
	}
```
