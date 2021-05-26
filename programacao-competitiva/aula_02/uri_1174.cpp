#include <bits/stdc++.h>

using namespace std;

int main() {
    double x;

    cout << fixed << setprecision(1);

    for (int i = 0; i < 100; i++) {
        cin >> x;
        if (x <= 10) {
            cout << "A[" << i << "] = " << x << endl;
        }
    }


    return 0;
}
