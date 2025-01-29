#include <iostream>
#include <cstring> // For strlen
using namespace std;

bool palindrome(int i, int n, char s[]) {
    // Base Condition
    if (i >= n / 2) return true;

    // If the start is not equal to the end, not a palindrome.
    if (s[i] != s[n - i - 1]) return false;

    // Recursively check the next characters.
    return palindrome(i + 1, n, s);
}

int main() {
    char s[100];

    cout << "Enter a string: ";
    cin.getline(s, 100);  // Read the string input

    int n = strlen(s);    // Compute the length of the string once
    cout << boolalpha << palindrome(0, n, s) << endl;

    return 0;
}
