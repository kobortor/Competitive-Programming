#include <bits/stdc++.h>

using namespace std;

string findEncryptedWord(string s) {
    if (s.empty()) return "";

    int mid = (s.size() - 1) / 2;
    return string(1, s[mid]) 
         + findEncryptedWord(s.substr(0, mid))
         + findEncryptedWord(s.substr(mid + 1, string::npos));
}

