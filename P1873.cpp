#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned int n, m;
    cin >> n >> m;
    vector<unsigned int> trees(n);
    for (int i = 0; i < n; i++) {
        cin >> trees.at(i);
    }

    unsigned int min = 1, max = 400001;
}