#include <iostream>
using namespace std;

void solve() {
    unsigned long long n;
    cin >> n;
    // 1 -> 1
    // 2 -> NO SOLUTION
    // 3 -> NO SOLUTION
    // 4 -> 3 1 4 2
    // 5 -> 4 2 5 3 1 | 5 3 1 4 2
    // two loops -> print odd, print eve -> larger to smaller
    if (n == 2 || n == 3) {
	cout << "NO SOLUTION" << '\n';
	return;
    }
    long long e = n;
    long long o = n-1;
    if ((n & 1) == 1) {
	e = n-1;
	o = n;
    }

    for (long long i = o; i > 0; i-=2) {
	cout << i;
	if (i > 0) {
	    cout << " ";
	}
    }
    for (long long i = e; i > 0; i-=2) {
	cout << i;
	if (i > 0) {
	    cout << " ";
	}
    }

    cout << '\n';
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
