#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n, m; // n ����� ������, m ����� ����
    cout << "���������� ������ � ����: ";
    cin >> n >> m;
    vector<vector<int>> Vhodrebra(n); // ��������� ����
    vector<vector<int>> Vihodddd(n);  // �������� ����
    cout << "���� �����(������ ����):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        Vhodrebra[from].push_back(to); // ����� ��������� �����
        Vihodddd[to].push_back(from);  // ����� �������� �����
    }
}