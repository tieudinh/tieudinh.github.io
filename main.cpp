#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm để in kết quả tô màu của các đỉnh
void printColors(const vector<int>& colors) {
    for (int i = 0; i < colors.size(); i++) {
        cout << "Đỉnh " << i << " được tô màu: " << colors[i] << endl;
    }
}

// Hàm tô màu đồ thị
void graphColoring(vector<vector<int>>& graph, int V) {
    vector<int> colors(V, -1); // Lưu màu của các đỉnh (-1 nghĩa là chưa được tô)
    colors[0] = 0; // Bắt đầu tô màu đỉnh đầu tiên

    vector<bool> availableColors(V, false); // Mảng đánh dấu màu có sẵn để sử dụng

    // Bắt đầu duyệt từng đỉnh và tô màu
    for (int u = 1; u < V; u++) {
        // Đánh dấu các màu của các đỉnh kề với đỉnh u
        for (int i = 0; i < graph[u].size(); i++) {
            int adjVertex = graph[u][i];
            if (colors[adjVertex] != -1) {
                availableColors[colors[adjVertex]] = true;
            }
        }

        // Tìm màu đầu tiên có thể sử dụng
        int color;
        for (color = 0; color < V; color++) {
            if (!availableColors[color]) {
                break;
            }
        }

        colors[u] = color; // Tô màu cho đỉnh u

        // Đặt lại trạng thái của các màu
        for (int i = 0; i < graph[u].size(); i++) {
            int adjVertex = graph[u][i];
            if (colors[adjVertex] != -1) {
                availableColors[colors[adjVertex]] = false;
            }
        }
    }

    // In kết quả tô màu
    printColors(colors);
}

int main() {
    int V = 5; // Số đỉnh trong đồ thị
    vector<vector<int>> graph(V);

    // Danh sách các cạnh của đồ thị
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 3, 4};
    graph[3] = {1, 2, 4};
    graph[4] = {2, 3};

    cout << "Kết quả tô màu cho đồ thị là:\n";
    graphColoring(graph, V);

    return 0;
}
