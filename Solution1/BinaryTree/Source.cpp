//#include<iostream>
//#include <ctime>
//#include <fstream>
//#include <iomanip>
//#include <string>
//using namespace std;
//
//struct Node {
//	int info;
//	struct Node* pLeft;
//	struct Node* pRight;
//};
//typedef struct Node NODE;
//typedef NODE* Tree;
////ham khoi tao cay nhi phan
//void Init(Tree& t) {
//	t = NULL;
// }
////ham kiem tra cay nhi phan rong
//bool IsEmpty(Tree t) {
//	if (t == NULL) return 1;
//	return 0;
//}
//// tao node cho cay nhi phan
//Node* GetNode(int x) {
//	Node* p = new Node;
//	if (p == NULL) return NULL;
//	p->info = x;
//	p->pLeft = NULL;
//	p->pRight = NULL;
//	return p;
//}
////them ngau nhien gia tri vao cay nhi phan
//int InsertNode(Tree& t, int x) {
//	if (t != NULL) {
//		if (x > t->info)
//			return InsertNode(t->pRight, x);
//		else
//			return InsertNode(t->pLeft, x);
//	}
//	t = GetNode(x);
//	if (t == NULL)
//		return -1;
//	return 1;
//}
////nhap du lieu cho cay nhi phan tu file
//int Nhap(Tree &t, string filename) {
//	ifstream fi(filename);
//	if (fi.fail() == true) return 0;
//	int n, x;
//	fi >> n;
//	Init(t);
//	for (int i = 1; i <= n; i++) {
//		fi >> x;
//		InsertNode(t, x);
//	}
//	return 1;
//}
////xuat cay theo LNR
//void XuatLNR(Tree t){
//	if (t == NULL)
//		return;
//	XuatLNR(t->pLeft);
//	cout << t->info<<" ";
//	XuatLNR(t->pRight);
//}
////dem so luong node trong cay nhi phan
//int DemNode(Tree t) {
//	if (t == NULL)
//		return 0;
//	int a = DemNode(t->pLeft);
//	int b = DemNode(t->pRight);
//	return a + b + 1;
//}
////xuat cay nhi phan cac so nguyen ra file
////int Xuat(Tree t, string filename) {
////	ofstream fo(filename);
////	if (fo.fail() == true)
////		return 0;
////	fo << setw(6) << DemNode(t) << endl;
////	return Xuat(t, fo);
////}
////int Xuat(Tree t, ofstream& fo) {
////	if (t == NULL)
////		return 0;
////	Xuat(t->pLeft, fo);
////	fo << setw(6) << t->info;
////	Xuat(t->pRight, fo);
////}
//// Tinh Chieu Cao Cua Cay
//int tinhChieuCao(Tree t) {
//	if (t != NULL) {
//		return 1 + max(tinhChieuCao(t->pLeft), tinhChieuCao(t->pRight));
//	}
//	return 0;
//}
//// Xuat Cay Theo Muc 
//void XuatTheoMuc(Tree t, int k)
//{
//	if (t == NULL)
//		return;
//	if (k == 0)
//		cout << t->info << " ";
//	else {
//		XuatTheoMuc(t->pLeft, k - 1);
//		XuatTheoMuc(t->pRight, k - 1);
//	}
//}
//// 
//int main() {
//	Tree t;
//	Init(t);
//	Nhap(t, "input.txt");
//	//XuatLNR(t);
//	//cout<<tinhChieuCao(t);
//
//	XuatTheoMuc(t, 1);
//	return 0;
//}

#include <iostream>
#include <limits.h>

// Số đỉnh trong đồ thị
#define V 6

// Hàm tìm đỉnh có giá trị khoảng cách nhỏ nhất từ tập các đỉnh chưa được bao gồm trong cây đường đi ngắn nhất
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Hàm in ra mảng khoảng cách đã được xây dựng
void printSolution(int dist[])
{
    std::cout << "Dinh \t\t Khoang cach tu nguon\n";
    for (int i = 0; i < V; i++)
        std::cout << i << "\t\t\t" << dist[i] << "\n";
}

// Hàm thực hiện thuật toán tìm đường đi ngắn nhất Dijkstra từ một đỉnh nguồn
void dijkstra(int graph[V][V], int src)
{
    int dist[V];     // Mảng kết quả. dist[i] sẽ chứa khoảng cách ngắn nhất từ nguồn tới đỉnh i

    bool sptSet[V];  //sptSet[i] sẽ là true nếu đỉnh i đã được bao gồm trong cây đường đi ngắn nhất hoặc
    //khoảng cách ngắn nhất từ nguồn tới i đã được xác định

// Khởi tạo tất cả khoảng cách với giá trị VÔ CÙNG và sptSet[] là false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Khoảng cách từ đỉnh nguồn tới chính nó luôn là 0
    dist[src] = 0;

    // Tìm đường đi ngắn nhất cho tất cả các đỉnh
    for (int count = 0; count < V - 1; count++) {
        // Chọn đỉnh có khoảng cách nhỏ nhất từ tập các đỉnh chưa được xử lý
        // u luôn bằng src trong lần lặp đầu tiên
        int u = minDistance(dist, sptSet);

        // Đánh dấu đỉnh đã chọn là đã xử lý
        sptSet[u] = true;

        // Cập nhật khoảng cách các đỉnh kề với đỉnh đã chọn
        for (int v = 0; v < V; v++)
            // Cập nhật dist[v] chỉ khi v chưa được bao gồm trong sptSet,
            // có cạnh từ u đến v và tổng trọng số đường đi từ nguồn tới v thông qua u nhỏ hơn giá trị hiện tại của dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // In ra mảng khoảng cách đã xây dựng
    printSolution(dist);
}

int main()
{
    // Đồ thị ví dụ được biểu diễn bằng ma trận kề
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0 },
                        { 4, 0, 8, 0, 0, 0 },
                        { 0, 8, 0, 7, 0, 4 },
                        { 0, 0, 7, 0, 9, 14 },
                        { 0, 0, 0, 9, 0, 10 },
                        { 0, 0, 4, 14, 10, 0 } };

    dijkstra(graph, 0); // Tìm đường đi ngắn nhất từ đỉnh 0

    return 0;
}