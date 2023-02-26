#include <bits/stdc++.h>
using namespace std;
int guess(string s) {
    cout << s << endl;
    string ret;
    getline(cin, ret);
    if (ret == "ACCESS GRANTED") exit(0);
    string num;
    for (int i = 15; '0' <= ret[i] && ret[i] <= '9'; i++) num += ret[i];
    return stoi(num);
}
int main() {
    int len;
    for (int i = 1; i <= 20; i++) {
        string s;
        for (int j = 0; j < i; j++) s += 'a';
        if (guess(s) != 5) {len = i; break;}
    }
    string ans;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < 26; j++) {
            string tmp = ans;
            tmp += (char) ('a' + j);
            string g = tmp;
            while (g.size() < len) g += 'a';
            if (guess(g) != 5 + i * 9) {
                ans = tmp;
                goto outer;
            }
        }
        for (int j = 0; j < 26; j++) {
            string tmp = ans;
            tmp += (char) ('A' + j);
            string g = tmp;
            while (g.size() < len) g += 'a';
            if (guess(g) != 5 + i * 9) {
                ans = tmp;
                goto outer;
            }
        }
        for (int j = 0; j < 10; j++) {
            string tmp = ans;
            tmp += (char) ('0' + j);
            string g = tmp;
            while (g.size() < len) g += 'a';
            if (guess(g) != 5 + i * 9) {
                ans = tmp;
                goto outer;
            }
        }
        abort();
        outer:
        int l = 0;
    }
}