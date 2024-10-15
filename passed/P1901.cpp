#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> emitters;
    emitters.resize(n);
    for (int i = 0; i < n; i++) {
        int height, val;
        cin >> height >> val;
        emitters.at(i) = make_pair(height, val);
    }

    stack<int> mono;
    vector<int> nextLarger(n, -1);

    for (int i = 0; i < n; i++) {
        while (!mono.empty() && emitters.at(mono.top()).first < emitters.at(i).first) {
            nextLarger.at(mono.top()) = i;
            mono.pop();
        }
        mono.push(i);
    }

    while (!mono.empty())
        mono.pop();

    vector<int> prevLarger(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!mono.empty() && emitters.at(mono.top()).first < emitters.at(i).first) {
            prevLarger.at(mono.top()) = i;
            mono.pop();
        }
        mono.push(i);
    }

    vector<int> energy(n);

    for (int i = 0; i < n; i++) {
        if (nextLarger.at(i) != -1)
            energy.at(nextLarger.at(i)) += emitters.at(i).second;
        if (prevLarger.at(i) != -1)
            energy.at(prevLarger.at(i)) += emitters.at(i).second;
    }

    int max = 0;

    for (const int& i : energy) {
        max = i > max ? i : max;
    }

    cout << max;
}