#include <iostream>
#include <math.h>
using namespace std;

void solve() {
    char c;
    char prev = '\0';
    // min 1
    unsigned long long counter = 1;
    unsigned long long res = 0;
    while (cin >> c) {
	if (c != prev) {
	    res = max(counter,res);
	    counter = 1;
	    prev = c;
	} else {
	    counter++;
	    res = max(counter,res);
	}
    }
    cout << res << '\n';
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
