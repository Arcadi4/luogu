/* Passed */

#include <__utility/pair.h>
#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<int> heap(1);
size_t insertHead = 0;

void resizeHeap() {
    heap.resize((heap.size() + 1) * 2 - 1);
};

size_t getFather(size_t i) {
    if (i == 0) return 0;
    return (i - 1) >> 2;
}

pair<size_t, size_t> getChildren(size_t i) {
    return make_pair((i << 2) + 1, (i << 2) + 2);
}

void insert(int val) {
    heap.at(insertHead) = val;
    size_t pos = insertHead;
    insertHead++;
    if (insertHead == heap.size())
        resizeHeap();
    while (heap.at(pos) < heap.at(getFather(pos))) {
        swap(heap.at(pos), heap.at(getFather(pos)));
        pos = getFather(pos);
        if (pos == 0) return;
    }
}

int getRoot() {
    return heap.at(0);
}

void delRoot() {
    if (insertHead == 0) return;
    insertHead--;
    if (insertHead == 0) return;
    swap(heap.at(0), heap.at(insertHead - 1));
    size_t pos = 0;
    while ((heap.at(pos) > heap.at(getChildren(pos).first) || heap.at(pos) > heap.at(getChildren(pos).second))) {
        if (heap.at(getChildren(pos).second) < heap.at(getChildren(pos).first)) {
            swap(heap.at(pos), heap.at(getChildren(pos).second));
            pos = getChildren(pos).second;
        } else {
            swap(heap.at(pos), heap.at(getChildren(pos).first));
            pos = getChildren(pos).first;
        }
        if (pos >= heap.size()) return;
    }
}

int main() {
    size_t n;
    cin >> n;

    for (size_t _ = 0; _ < n; _++) {
        int op;
        cin >> op;
        switch (op) {
        case 1:
            int val;
            cin >> val;
            insert(val);
        case 2:
            cout << getRoot() << endl;
        case 3:
            delRoot();
        }
    }
}