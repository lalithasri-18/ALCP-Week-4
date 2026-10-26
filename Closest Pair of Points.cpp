#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    double x[100], y[100];
    double minDist = 999999, d;
    int a = 0, b = 0;

    cout << "Enter number of points: ";
    cin >> n;

    if (n < 2 || n > 100) {
        cout << "Enter 2 to 100 points";
        return 0;
    }

    cout << "Enter x and y coordinates:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            d = sqrt(pow(x[i]-x[j], 2) +
                     pow(y[i]-y[j], 2));

            if (d < minDist) {
                minDist = d;
                a = i;
                b = j;
            }
        }
    }

    cout << "Closest pair: ("
         << x[a] << "," << y[a] << ") and ("
         << x[b] << "," << y[b] << ")";

    cout << "\nMinimum distance: " << minDist;

    return 0;
}
