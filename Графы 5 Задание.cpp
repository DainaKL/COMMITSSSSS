#include <iostream>
#include <unordered_set>
#include <vector>
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
    return 0;
    cout << "Истоки графа: "; // Поиск истоков (вершин с нулевой полустепенью захода)
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (Vihodddd[i].empty()) {  // Если нет входящих рёбер
            cout << i << " ";
            flag = true;
        }
    }
    if (!flag) {
        cout << "иСТОков нет";
    }
    cout << endl;
}
