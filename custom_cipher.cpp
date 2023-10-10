#include <iostream>
#include <string>

using namespace std;

// Function to encode the string
string encode(string s, int j) {
    for (int i = j; i < s.length(); i++) {
        if (i % 2 == 0) {
            s[i] += 3;
        }
    }
    return s;
}

// Function to decode the string
string decode(string s, int j) {
    for (int i = j; i < s.length(); i++) {
        if (i % 2 == 0) {
            s[i] -= 3;
        }
    }
    return s;
}

int main() {
    string input;
    int j;

    cout << "Enter a string: ";
    cin >> input;

    cout << "Enter an integer j: ";
    cin >> j;

    // Encode the string
    string encoded = encode(input, j);
    cout << "Encoded string: " << encoded << endl;

    // Decode the string
    string decoded = decode(encoded, j);
    cout << "Decoded string: " << decoded << endl;

    return 0;
}
