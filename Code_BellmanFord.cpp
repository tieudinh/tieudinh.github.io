#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Cấu trúc để biểu diễn một cạnh của đồ thị
struct Edge {
    int src, dest, weight;
};

// Hàm Bellman-Ford tìm đường đi ngắn nhất từ đỉnh nguồn tới các đỉnh còn lại
void bellmanFord(int vertices, int edgesCount, vector<Edge>& edges, int start) {
    // Khởi tạo khoảng cách từ đỉnh nguồn tới các đỉnh là vô cùng (INT_MAX), riêng đỉnh nguồn có khoảng cách bằng 0
    vector<int> dist(vertices, INT_MAX);
    dist[start] = 0;

    // Lặp lại |V| - 1 lần để cập nhật khoảng cách
    for (int i = 1; i <= vertices - 1; ++i) {
        for (int j = 0; j < edgesCount; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Kiểm tra chu trình âm
    for (int i = 0; i < edgesCount; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Đồ thị có chu trình âm." << endl;
            return;
        }
    }

    // In khoảng cách từ đỉnh nguồn đến các đỉnh khác
    cout << "Khoảng cách từ đỉnh " << start << " đến các đỉnh còn lại:" << endl;
    for (int i = 0; i < vertices; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Đỉnh " << i << " : Không có đường đi" << endl;
        } else {
            cout << "Đỉnh " << i << " : " << dist[i] << endl;
        }
    }
}

int main() {
    int vertices = 5;
    vector<Edge> edges;

    // Thêm các cạnh vào đồ thị
    edges.push_back({0, 1, 1});
    edges.push_back({1, 2, 2});
    edges.push_back({2, 3, 3});
    edges.push_back({3, 4, -3});
    edges.push_back({4, 0, -3});

    // Tìm đường đi ngắn nhất từ đỉnh 0
    bellmanFord(vertices, edges.size(), edges, 0);

    return 0;
}
