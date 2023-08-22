#include <iostream>
#include <string>

using namespace std;

// Function to perform school method addition
string schoolMethodAddition(const string& a, const string& b, int B) {
    int n = a.size();
    string result;
    int carry = 0;

    for (int i = n - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / B;
        result = char(sum % B + '0') + result;
    }

    if (carry > 0) {
        result = char(carry + '0') + result;
    }

    return result;
}

int main() {
    int B; // Base
    int n; // Number of digits

    cout << "Enter the base (B): ";
    cin >> B;

    cout << "Enter the number of digits (n): ";
    cin >> n;

    string a, b;

    cout << "Enter the digits of the first number (from least to most significant): ";
    cin >> a;

    cout << "Enter the digits of the second number (from least to most significant): ";
    cin >> b;

    // Make sure both input strings have the same length
    while (a.size() < n) {
        a = "0" + a;
    }

    while (b.size() < n) {
        b = "0" + b;
    }

    string result = schoolMethodAddition(a, b, B);

    cout << "Result of addition: " << result << endl;

    return 0;
}
