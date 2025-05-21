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
    int A, B; // Удаление ребра A -> B
    cout << "Какое ребро удалить(от куда до куда ребро): ";
    cin >> A >> B;
    return 0;
    for (auto it = Vhodrebra[A].begin(); it != Vhodrebra[A].end(); ) { // Удаление из исходящих рёбер A
    if (*it == B) {
        it = Vhodrebra[A].erase(it);
        break; // Так как рёбра ориентированные, можно прервать после первого найденного
    }
    else ++it;
    }
    for (auto it = Vihodddd[B].begin(); it != Vihodddd[B].end(); ) {  // Удаление из входящих рёбер B
        if (*it == A) {
            it = Vihodddd[B].erase(it);
            break;
        }
        else ++it;
    }    
    for (int i = 0; i < n; ++i) { // Вывод графа после удаления
        cout << i;
        for (int neighbor : Vhodrebra[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    
    return 0;

}
