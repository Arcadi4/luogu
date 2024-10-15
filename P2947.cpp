#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        heights.at(i) = height;
    }

    stack<int> mono;
    vector<int> lookup(n, 0);

    for (int i = 0; i < n; i++) {
        while (!mono.empty() && heights.at(mono.top()) < heights.at(i)) {
            lookup.at(mono.top()) = i + 1;
            mono.pop();
        }
        mono.push(i);
    }

    for (const int& i : lookup) {
        cout << i << endl;
    }
}