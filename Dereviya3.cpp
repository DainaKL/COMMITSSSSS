#include <iostream>
#include <string>
using namespace std;

struct tree { //структура дерева
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(int x) { //начальный узел
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) {//вставка
    tree* n = node(x);
    if (!tr) tr = n; //если дерево пустое - корень
    else {
        tree* y = tr;
        while (y) { //ищем куда вставлять
            if (n->inf > y->inf) //правая ветка
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; //узел становится правым ребенком
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf)//левая ветка
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y;//узел становится левым ребенком
                    y->left = n;
                    break;
                }
        }
    }
}

tree* find(tree* tr, int x) {//поиск
    if (!tr || x == tr->inf)//нашли или дошли до конца ветки
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);//ищем по левой ветке
    else
        return find(tr->right, x);//ищем по правой ветке
}

void deleteNode(tree*& tr, tree* node) {
    if (!node) return;
    if (!node->left || !node->right) { 
        tree* child = node->left ? node->left : node->right; // Выбираем существующего ребёнка
        if (node->parent) { // Обновляем ссылку у родителя удаляемого узла
            if (node->parent->left == node)
                node->parent->left = child; // Если удаляемый узел был левым ребёнком
            else
                node->parent->right = child;
        }
        else {
            tr = child;
        }

        if (child) // Обновляем родителя у ребёнка
            child->parent = node->parent;

        delete node;
    }
    else {
        tree* preemnik = node->right; // Ищем преемника чтобы удалить всю ЕГО РОДОСЛОВНУЮ ОПЯТЬ
        while (preemnik->left)
            preemnik = preemnik->left;

        node->inf = preemnik->inf; // Копируем значение преемника в удаляемый узел
        deleteNode(tr, preemnik);  // Рекурсивно удаляем преемника
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
    cout << "Количество элементов: ";
    cin >> n;

    tree* tr = nullptr;
    cout << "Элементы(ввод): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }

    cout << "Начальное древо: " <<endl;
    printTree(tr);

    cout << "В каком узле удалить? ";
    cin >> x;
    processPlemyanik(tr, x);

    cout << "Древо после удаления: " << endl;
    printTree(tr);

    return 0;
}