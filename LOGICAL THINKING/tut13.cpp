#include <iostream>
using namespace std;

void printPattern(int n) {
    // Total rows
    int totalRows = 2 * n - 1;

    for (int i = 0; i < totalRows; i++) {
        // Decide the current row index (mirroring for lower half)
        int currentRow = (i < n) ? i : totalRows - i - 1;

        // Print left decreasing numbers
        for (int j = n; j > n - currentRow - 1; j--) {
            cout << j;
        }

        // Print middle repeated numbers
        for (int j = 0; j < (2 * (n - currentRow) - 1); j++) {
            cout << n - currentRow;
        }

        // Print right increasing numbers
        for (int j = n - currentRow; j <= n; j++) {
            cout << j;
        }

        cout << endl; // Move to the next line
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    printPattern(n);

    return 0;
}
