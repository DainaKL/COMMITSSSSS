#include <iostream>
#include <string>
using namespace std;

struct tree { //ñòðóêòóðà äåðåâà
    int inf;
    tree* right;
    tree* left;
    tree* parent;
};

tree* node(int x) { //íà÷àëüíûé óçåë
    tree* n = new tree;
    n->inf = x;
    n->left = n->right = NULL;
    n->parent = NULL;
    return n;
}

void insert(tree*& tr, int x) {//âñòàâêà
    tree* n = node(x);
    if (!tr) tr = n; //åñëè äåðåâî ïóñòîå - êîðåíü
    else {
        tree* y = tr;
        while (y) { //èùåì êóäà âñòàâëÿòü
            if (n->inf > y->inf) //ïðàâàÿ âåòêà
                if (y->right)
                    y = y->right;
                else {
                    n->parent = y; //óçåë ñòàíîâèòñÿ ïðàâûì ðåáåíêîì
                    y->right = n;
                    break;
                }
            else if (n->inf < y->inf)//ëåâàÿ âåòêà
                if (y->left)
                    y = y->left;
                else {
                    n->parent = y;//óçåë ñòàíîâèòñÿ ëåâûì ðåáåíêîì
                    y->left = n;
                    break;
                }
        }
    }
}

tree* find(tree* tr, int x) {//ïîèñê
    if (!tr || x == tr->inf)//íàøëè èëè äîøëè äî êîíöà âåòêè
        return tr;
    if (x < tr->inf)
        return find(tr->left, x);//èùåì ïî ëåâîé âåòêå
    else
        return find(tr->right, x);//èùåì ïî ïðàâîé âåòêå
}

void deleteNode(tree*& tr, tree* node) {
    if (!node) return;
    if (!node->left || !node->right) { 
        tree* child = node->left ? node->left : node->right; // Âûáèðàåì ñóùåñòâóþùåãî ðåá¸íêà
        if (node->parent) { // Îáíîâëÿåì ññûëêó ó ðîäèòåëÿ óäàëÿåìîãî óçëà
            if (node->parent->left == node)
                node->parent->left = child; // Åñëè óäàëÿåìûé óçåë áûë ëåâûì ðåá¸íêîì
            else
                node->parent->right = child;
        }
        else {
            tr = child;
        }

        if (child) // Îáíîâëÿåì ðîäèòåëÿ ó ðåá¸íêà
            child->parent = node->parent;

        delete node;
    }
    else {
        tree* preemnik = node->right; // Èùåì ïðååìíèêà ÷òîáû óäàëèòü âñþ ÅÃÎ ÐÎÄÎÑËÎÂÍÓÞ ÎÏßÒÜ
        while (preemnik->left)
            preemnik = preemnik->left;

        node->inf = preemnik->inf; // Êîïèðóåì çíà÷åíèå ïðååìíèêà â óäàëÿåìûé óçåë
        deleteNode(tr, preemnik);  // Ðåêóðñèâíî óäàëÿåì ïðååìíèêà
    }
}

void processPlemyanik(tree*& tr, int x) {
     tree* nodeX = find(tr, x);
 if (!nodeX || !nodeX->parent) { // Если узел не найден или это корень (нет родителя)
     cout << "Нельзя удалить племянников у корня или узла не существует!" << endl;
     return;
 }
 tree* parent = nodeX->parent;
 tree* uncle = (parent->left == nodeX) ? parent->right : parent->left;
 if (!uncle) { // Если нет дяди (а значит, и племянников)
     cout << "Нет дяди (а значит, и племянников)!" << endl;
     return;
 }
 if (uncle->left) { // Если у дяди есть левый племянник - удаляем его
     deleteNode(tr, uncle->left);
     cout << "Левый племянник удалён." << endl;
 }
 else {
     cout << "У дяди нет левого племянника!" << endl;
 }
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
    cout << "Êîëè÷åñòâî ýëåìåíòîâ: ";
    cin >> n;

    tree* tr = nullptr;
    cout << "Ýëåìåíòû(ââîä): ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insert(tr, x);
    }

    cout << "Íà÷àëüíîå äðåâî: " <<endl;
    printTree(tr);

    cout << "Â êàêîì óçëå óäàëèòü? ";
    cin >> x;
    processPlemyanik(tr, x);

    cout << "Äðåâî ïîñëå óäàëåíèÿ: " << endl;
    printTree(tr);

    return 0;
}
