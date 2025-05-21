#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
void obhod(int v, vector<bool>& posetil, const vector<vector<int>>& Vhodrebra) {
    posetil[v] = true;
    for (int sosed : Vhodrebra[v]) {//если на входной позиции есть то класс дойдет так доходя да каждой верш проверяем пока она может кудато свалить
        if (!posetil[sosed]) {
            obhod(sosed, posetil, Vhodrebra);
        }
    }
}

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
    int verka;
    cout << "Какую вершину проверяем на недостижимость?: ";
    cin >> verka;
    vector<bool> posetil(n, false);
    obhod(verka, posetil, Vhodrebra);
    cout << "Недостижимые вершины: ";
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (!posetil[i] && i != verka) {
            cout << i << " ";
            flag = true;
         }
    }
    if (!flag) {
        cout << "все вершины достижимы";
    }
    cout << endl;    
    return 0;
}
