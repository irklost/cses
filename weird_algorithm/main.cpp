#include <iostream>
using namespace std;

void solve() {
    long long int n;
    cin >> n;
    while (n >= 1) {
	if (n == 1) {
	    cout << n << '\n';
	    return;
	}

	cout << n << " ";
	if ((n & 1) == 0) {
	    n /= 2;
	}
	else {
	    n = n * 3 + 1;
	}

    }
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
