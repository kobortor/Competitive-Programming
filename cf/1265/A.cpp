#include<bits/stdc++.h>

// Created by kobortor On 01:08:06 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '?') {
                int j = i;
                while (j + 1 < (int)s.size() && s[j + 1] == '?') {
                    j++;
                }

                char c1 = (i == 0 ? 'a' : s[i - 1]);
                char c2 = (j + 1 == (int)s.size() ? 'a' : s[j + 1]);

                pair<char, char> p;
                switch (c2) {
                    case 'a':
                        p = {'b', 'c'};
                        break;
                    case 'b':
                        p = {'a', 'c'};
                        break;
                    case 'c':
                        p = {'a', 'b'};
                        break;
                }
                if (c1 == p.second) swap(p.first, p.second);

                for (int k = i; k <= j; k++) {
                    s[k] = ((k - i) % 2 ? p.first : p.second);
                }

                i = j;
            } else {
                continue;
            }
        }

        bool good = true;
        for (int i = 1; i < (int)s.size(); i++) {
            good &= s[i - 1] != s[i];
        }
        
        if (good) {
            cout << s << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
