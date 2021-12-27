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
- [X] [Bài 2- Lý thuyết đồ thị - Duyệt đồ thị theo chiều sâu (Thuật toán DFS) - Phần 1/6](https://youtu.be/Ej1Vc0fUXPM?list=PLQR5IJqntFProvKkCOpoNOdkal-nh6yqB)
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
### Hàm
```

```