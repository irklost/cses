#include <iostream>
using namespace std;

void solve() {
    unsigned long long n;
    cin >> n;
    // sum of natural numbers: (n * (n+1))/2
    // 2 -> 1 + 2 = 3
    // 3 -> 1 + 2 + 3 = 6
    unsigned long long want = (n*(n+1))/2;
    while (--n) {
	long long temp;
	cin >> temp;
	want -= temp;
    }
    cout << want << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
