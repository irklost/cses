#include <iostream>
#include <math.h>
using namespace std;

void solve() {
    unsigned long long n;
    cin >> n;
    unsigned long long counter = 0;
    unsigned long long prev = 0;
    while (n--) {
	unsigned long long curr;
	cin >> curr;
	if (curr < prev) {
	    unsigned long long temp;
	    temp = prev-curr;
	    counter += temp;
	    curr += temp;
	}
	prev = curr;
    }
    cout << counter << '\n';
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
