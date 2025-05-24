#include <iostream>
#include <string>
using namespace std;

struct tree { //��������� ������
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(int x) { //��������� ����
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) {//�������
    tree* n = node(x);
    if (!tr) tr = n; //���� ������ ������ - ������
    else {
        tree* y = tr;
        while (y) { //���� ���� ���������
            if (n->inf > y->inf) //������ �����
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; //���� ���������� ������ ��������
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf)//����� �����
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y;//���� ���������� ����� ��������
                    y->left = n;
                    break;
                }
        }
    }
}

tree* find(tree* tr, int x) {//�����
    if (!tr || x == tr->inf)//����� ��� ����� �� ����� �����
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);//���� �� ����� �����
    else
        return find(tr->right, x);//���� �� ������ �����
}

void deleteNode(tree*& tr, tree* node) {
    if (!node) return;
    if (!node->left || !node->right) { 
        tree* child = node->left ? node->left : node->right; // �������� ������������� ������
        if (node->parent) { // ��������� ������ � �������� ���������� ����
            if (node->parent->left == node)
                node->parent->left = child; // ���� ��������� ���� ��� ����� �������
            else
                node->parent->right = child;
        }
        else {
            tr = child;
        }

        if (child) // ��������� �������� � ������
            child->parent = node->parent;

        delete node;
    }
    else {
        tree* preemnik = node->right; // ���� ��������� ����� ������� ��� ��� ����������� �����
        while (preemnik->left)
            preemnik = preemnik->left;

        node->inf = preemnik->inf; // �������� �������� ��������� � ��������� ����
        deleteNode(tr, preemnik);  // ���������� ������� ���������
    }
}

void processPlemyanik(tree*& tr, int x) {
    tree* nodeX = find(tr, x);
    tree* parent = nodeX->parent;
    tree* uncle = (parent->left == nodeX) ? parent->right : parent->left;
    deleteNode(tr, uncle->left);
}

void printTree(tree* tr, int space = 0) {
    space += 3;
    printTree(tr->right, space);
    for (int i = 3; i < space; i++) cout << " ";
    cout << tr->inf << "\n";
    printTree(tr->left, space);
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n, x;
    cout << "���������� ���������: ";
    cin >> n;

    tree* tr = nullptr;
    cout << "��������(����): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }

    cout << "��������� �����: " <<endl;
    printTree(tr);

    cout << "� ����� ���� �������? ";
    cin >> x;
    processPlemyanik(tr, x);

    cout << "����� ����� ��������: " << endl;
    printTree(tr);

    return 0;
}