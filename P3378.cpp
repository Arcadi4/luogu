#include <__utility/pair.h>
#include <algorithm>
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
    return (i - 1) >> 1;
}

pair<size_t, size_t> getChildren(size_t i) {
    return make_pair((i << 1) + 1, (i << 1) + 2);
}

void insert(int val) {
    if (insertHead >= heap.size())
        resizeHeap();
    heap.at(insertHead) = val;
    size_t pos = insertHead;
    insertHead++;
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
    swap(heap.at(0), heap.at(insertHead));
    heap.at(insertHead) = 0;
    size_t pos = 0;
    while (pos < heap.size() && pos < min(heap.at(getChildren(pos).first), heap.at(getChildren(pos).second)))
        insertHead--;
}

int main() {
    size_t n;
    cin >> n;

    for (size_t _ = 0; _ < n; _++) {
        for (const int& i : heap) {
            cout << i << " ";
        }
        int op;
        cin >> op;
        switch (op) {
        case 1:
            int val;
            cin >> val;
            insert(val);
            break;
        case 2:
            cout << getRoot() << endl;
            break;
        case 3:
            delRoot();
            break;
        }
    }
}