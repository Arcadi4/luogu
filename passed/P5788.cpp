#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> s;
    int n;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    v.reserve(n);
    ans.resize(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 正序遍历递减栈 - 搜索右侧首个更大元素
    // 正序遍历递增栈 - 搜索右侧首个更小元素
    // 逆序遍历递减栈 - 搜索左侧首个更大元素
    // 逆序遍历递增栈 - 搜索左侧首个更小元素

    for (int i = 0; i < n; i++) {
        while (!s.empty() && v.at(s.top()) < v.at(i)) {
            ans.at(s.top()) = i + 1;
            s.pop();
        }
        s.push(i);
    }

    for (const int& i : ans) {
        cout << i << " ";
    }
}