#include <iostream>
#include <string>
#include <cctype>   // for islower, isupper, isdigit, etc.

using namespace std;

bool hasLower(const string &s) {
    for (size_t i = 0; i < s.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (islower(c)) return true;
    }
    return false;
}

bool hasUpper(const string &s) {
    for (size_t i = 0; i < s.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (isupper(c)) return true;
    }
    return false;
}

bool hasDigit(const string &s) {
    for (size_t i = 0; i < s.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (isdigit(c)) return true;
    }
    return false;
}

bool hasSpecial(const string &s) {
    const string special = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/";
    for (size_t i = 0; i < s.length(); ++i) {
        if (special.find(s[i]) != string::npos) return true;
    }
    return false;
}

int main() {
    string password;
    cout << "Enter Password: ";
    getline(cin, password);

    int score = 0;

    if (password.length() >= 8) score++;
    if (hasLower(password)) score++;
    if (hasUpper(password)) score++;
    if (hasDigit(password)) score++;
    if (hasSpecial(password)) score++;

    cout << "\nPassword Strength: ";

    if (score == 5)
        cout << "Very Strong\n";
    else if (score == 4)
        cout << "Strong\n";
    else if (score == 3)
        cout << "Medium\n";
    else if (score == 2)
        cout << "Weak\n";
    else
        cout << "Very Weak\n";

    return 0;
}

