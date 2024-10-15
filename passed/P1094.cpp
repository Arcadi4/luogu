#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int maxPrice, n;
    cin >> maxPrice >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.at(i) = price;
    }
    sort(prices.begin(), prices.end());

    int i = 0, j = n - 1;
    int pairs = 0;

    while (i < j) {
        if (prices.at(i) + prices.at(j) <= maxPrice) {
            pairs++;
            i++;
            j--;
        } else if (prices.at(i) + prices.at(j) > maxPrice) {
            pairs++;
            j--;
        }
    }

    if (i == j) pairs++;

    cout << pairs;
}