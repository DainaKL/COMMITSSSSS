#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m; // n число вершин, m число рёбер
    cout << "Количество вершин и рёбер: ";
    cin >> n >> m;
    vector<vector<int>> Vhodrebra(n); // исходящие рёбра
    vector<vector<int>> Vihodddd(n);  // Входящие рёбра
    cout << "Ввод ребер(откуда куда):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        Vhodrebra[from].push_back(to); // Добав исходящее ребро
        Vihodddd[to].push_back(from);  // Добав входящее ребро
    }
}