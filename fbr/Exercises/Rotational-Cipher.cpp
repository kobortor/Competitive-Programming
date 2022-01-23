#include <bits/stdc++.h>

using namespace std;

string rotationalCipher(string input, int rotationFactor) {
    // Write your code here
    string answer;
    for (char c : input) {
        if ('a' <= c && c <= 'z') {
            answer += (c - 'a' + rotationFactor) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            answer += (c - 'A' + rotationFactor) % 26 + 'A';
        } else if ('0' <= c && c <= '9') {
            answer += (c - '0' + rotationFactor) % 10 + '0';
        } else {
            answer += c;
        }
    }
    return answer;
}
