/* Passed */

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

    vector<int> nextHigher(n, 0);
    stack<int> mono;

    for (int i = 0; i < n; i++) {
        while (!mono.empty() && heights.at(mono.top()) <= heights.at(i)) {
            nextHigher.at(mono.top()) = i;
            mono.pop();
        }
        mono.push(i);
    }

    long long seenCows = 0;

    for (int i = 0; i < n; i++) {
        if (nextHigher.at(i) == 0) {
            seenCows += (n - 1) - i;
        } else {
            seenCows += (nextHigher.at(i) - 1) - i;
        }
    }

    cout << seenCows;
}