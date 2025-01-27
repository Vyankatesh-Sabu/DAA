#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> singers;
    for (int i = 0; i < n; i++) {
        int lower_bound, upper_bound;
        cin >> lower_bound >> upper_bound;
        singers[lower_bound] = i;
    }

    int scores[n];
    int position = 0;
    for (const auto& singer : singers) {
        scores[singer.second] = 2 *(n-1-position);
        position++;
    }

    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}
