//
// Created by Mateusz Śliwka on 2019-04-05.
//

#include "Tree.h"
#include <iostream>

using namespace std;

void Tree::printError(string message) {
    cout << "[ERROR] " + message << endl;
}

Tree::Tree() {
    size = 0;
    //Definiowanie strażnika
    sentinel.color = 'B';
    sentinel.parent = &sentinel;
    sentinel.left = &sentinel;
    sentinel.right = &sentinel;
    root = &sentinel;
}

Tree::~Tree() {
    if (root)
        removeAll();
}

void Tree::removeAll() {
    removeElement(root);
    //Definiowanie strażnika
    sentinel.color = 'B';
    sentinel.parent = &sentinel;
    sentinel.left = &sentinel;
    sentinel.right = &sentinel;
    root = &sentinel;
    //Zmiana rozmiaru
    Tree:
    size = 0;
}

void Tree::removeElement(TreeElement *treeElement) {
    //Jeżeli jest strasznikiem to błąd
    if (treeElement == &sentinel)
        Tree::printError("Usuwany element to strażnik");
    else {
        removeElement(treeElement->left);
        removeElement(treeElement->right);
        delete treeElement;
        Tree::size--;
    }
}

void Tree::rotateRight(TreeElement *treeElement) {
    TreeElement *y, *p;
    y = treeElement->left;
    if (y != &sentinel) {
        p = treeElement->parent;
        treeElement->left = y->right;
        if (treeElement->left != &sentinel)
            treeElement->left->parent = treeElement;
        y->right = treeElement;
        y->parent = p;
        treeElement->parent = y;
        if (p != &sentinel) {
            if (p->left == treeElement)
                p->left = y;
            else
                p->right = y;
        } else
            root = y;
    }
}

void Tree::rotateLeft(TreeElement *treeElement) {
    TreeElement *y, *p;
    y = treeElement->right;
    if (y != &sentinel) {
        p = treeElement->parent;
        treeElement->right = y->left;
        if (treeElement->right != &sentinel)
            treeElement->right->parent = treeElement;
        y->left = treeElement;
        y->parent = p;
        treeElement->parent = y;
        if (p != &sentinel) {
            if (p->left == treeElement)
                p->left = y;
            else
                p->right = y;
        } else
            root = y;
    }
}

void Tree::add(int value) {
    TreeElement *x, *y;
    //Tworzenie wezla
    x = new TreeElement;
    x->left = &sentinel;
    x->right = &sentinel;
    x->parent = root;
    x->value = value;
    //Przypisanie korzenia jako X jezeli rodzic to straznik lub zastapienie liscia
    if (x->parent == &sentinel)
        root = x;
    else {
        while (true) {
            if (value < x->parent->value) {
                if (x->parent->left == &sentinel) {
                    x->parent->left = x;
                    break;
                }
                x->parent = x->parent->left;
            } else if (value > x->parent->value) {
                if (x->parent->right == &sentinel) {
                    x->parent->right = x;
                    break;
                }
                x->parent = x->parent->right;
            } else {
                delete x;
                return;
            }
        }
        x->color = 'R';
        while ((x != root) && (x->parent->color == 'R')) {
            if (x->parent == x->parent->parent->left) {
                y = x->parent->parent->right;
                if (y->color == 'R') {
                    x->parent->color = 'B';
                    y->color = 'B';
                    x->parent->parent->color = 'R';
                    x = x->parent->parent;
                    continue;
                }

                if (x == x->parent->right) {
                    x = x->parent;
                    rotateLeft(x);
                }

                x->parent->color = 'B';
                x->parent->parent->color = 'R';
                rotateRight(x->parent->parent);
                break;
            } else {
                y = x->parent->parent->left;
                if (y->color == 'R') {
                    x->parent->color = 'B';
                    y->color = 'B';
                    x->parent->parent->color = 'R';
                    x = x->parent->parent;
                    continue;
                }

                if (x == x->parent->left) {
                    x = x->parent;
                    rotateRight(x);
                }

                x->parent->color = 'B';
                x->parent->parent->color = 'R';
                rotateLeft(x->parent->parent);
                break;
            }
        }
        root->color = 'B';
        size++;
    }
}

void Tree::remove(int value) {
    if (checkIfExists(value)) {
        TreeElement *treeElementToDelete;
        findElement(value, root, treeElementToDelete);
        TreeElement *w, *y, *z;
        if ((treeElementToDelete->left == &sentinel) || (treeElementToDelete->right == &sentinel))
            y = treeElementToDelete;
        else
            y = findNextElement(treeElementToDelete);
        if (y->left != &sentinel)
            z = y->left;
        else
            z = y->right;

        z->parent = y->parent;
        if (y->parent == &sentinel)
            root = z;
        else if (y == y->parent->left)
            y->parent->left = z;
        else
            y->parent->right = z;
        if (y != treeElementToDelete)
            treeElementToDelete->value = y->value;
        if (y->color == 'B') {
            while ((z != root) && (z->color == 'B'))
                if (z == z->parent->left) {
                    w = z->parent->right;
                    if (w->color == 'R') {
                        w->color = 'B';
                        z->parent->color = 'R';
                        rotateLeft(z->parent);
                        w = z->parent->right;
                    }
                    if ((w->left->color == 'B') && (w->right->color == 'B')) {
                        w->color = 'R';
                        z = z->parent;
                        continue;
                    }
                    if (w->right->color == 'B') {
                        w->left->color = 'B';
                        w->color = 'R';
                        rotateRight(w);
                        w = z->parent->right;
                    }
                    w->color = z->parent->color;
                    z->parent->color = 'B';
                    w->right->color = 'B';
                    rotateLeft(z->parent);
                    z = root;
                } else {
                    w = z->parent->left;
                    if (w->color == 'R') {
                        w->color = 'B';
                        z->parent->color = 'R';
                        rotateLeft(z->parent);
                        w = z->parent->left;
                    }
                    if ((w->left->color == 'B') && (w->right->color == 'B')) {
                        w->color = 'R';
                        z = z->parent;
                        continue;
                    }
                    if (w->left->color == 'B') {
                        w->right->color = 'B';
                        w->color = 'R';
                        rotateLeft(w);
                        w = z->parent->left;
                    }
                    w->color = z->parent->color;
                    z->parent->color = 'B';
                    w->left->color = 'B';
                    rotateRight(z->parent);
                    z = root;
                }
        }
        z->color = 'B';
        delete y;
    } else
        printError("Nie ma takiej wartosci w drzewie.");
}

void Tree::findElement(int value, TreeElement *rootElementTree, TreeElement *&elementToFind) {
    if (rootElementTree != &sentinel) {
        if (rootElementTree->value == value) {
            elementToFind = rootElementTree;
            return;
        }
        findElement(value, rootElementTree->left, elementToFind);
        findElement(value, rootElementTree->right, elementToFind);
    }
}

bool Tree::checkIfExists(int value) {
    bool found = false;
    findValue(value, root, found);
    if (found) {
        cout << "Ta wartość występuje w drzewie." << endl;
        return true;
    } else {
        cout << "Nie ma tej wartości w drzewie." << endl;
        return false;
    }

}

void Tree::findValue(int value, TreeElement *rootElementTree, bool &found) {
    if (rootElementTree != &sentinel) {
        if (rootElementTree->value == value) {
            found = true;
            return;
        }
        findValue(value, rootElementTree->left, found);
        findValue(value, rootElementTree->right, found);
    }
}


TreeElement *Tree::findNextElement(TreeElement *p) {
    TreeElement *nextTreeElement;
    if (p != &sentinel) {
        if (p->right != &sentinel)
            return findMinimumElement(p->right);
        else {
            nextTreeElement = p->parent;
            while ((nextTreeElement != &sentinel) && (p == nextTreeElement->right)) {
                p = nextTreeElement;
                nextTreeElement = nextTreeElement->parent;
            }
            return nextTreeElement;
        }
    }
    return &sentinel;
}


TreeElement *Tree::findMinimumElement(TreeElement *p) {
    if (p != &sentinel)
        while (p->left != &sentinel)
            p = p->left;
    return p;
}


void Tree::printRBT(string sp, string sn, TreeElement *p) {
    string cr, cl, cp;
    cr = cl = cp = "  ";
    cr = "┌─";
    cl = "└─";
    cp[0] = '|';

    string t;

    if (p != &sentinel) {
        t = sp;
        if (sn == cr) t[t.length() - 2] = ' ';
        printRBT(t + cp, cr, p->right);

        t = t.substr(0, sp.length() - 2);
        cout << t << sn << p->color << ":" << p->value << endl;

        t = sp;
        if (sn == cl) t[t.length() - 2] = ' ';
        printRBT(t + cp, cl, p->left);
    }
}

void Tree::print() {
    printRBT("", "", root);
}

void Tree::clean() {
    size = 0;
    //Definiowanie strażnika
    sentinel.color = 'B';
    sentinel.parent = &sentinel;
    sentinel.left = &sentinel;
    sentinel.right = &sentinel;
    root = &sentinel;
}