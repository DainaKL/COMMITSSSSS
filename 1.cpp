#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m; // n ÷èñëî âåðøèí, m ÷èñëî ð¸áåð
    cout << "Êîëè÷åñòâî âåðøèí è ð¸áåð: ";
    cin >> n >> m;
    vector<vector<int>> Vhodrebra(n); // èñõîäÿùèå ð¸áðà
    vector<vector<int>> Vihodddd(n);  // Âõîäÿùèå ð¸áðà
    cout << "Ââîä ðåáåð(îòêóäà êóäà):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        Vhodrebra[from].push_back(to); // Äîáàâ èñõîäÿùåå ðåáðî
        Vihodddd[to].push_back(from);  // Äîáàâ âõîäÿùåå ðåáðî
    }
    int v;
    cout << "Введите вершину v: ";
    cin >> v;
    unordered_set<int> Spissmesh;
}
