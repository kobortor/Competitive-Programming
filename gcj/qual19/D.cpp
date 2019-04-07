#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1024;

int T;
int N, B, F;
string broken;

int numq = 0;
//pretends the string is size MAXN
string query(string s) {
    numq++;
    assert(numq <= 5);
    string res;
#ifdef DEBUG
    assert((int)s.size() == MAXN);
    for (int i = 0; i < N; i++) {
        if (broken[i] == '0') {
            res += s[i];
        }
    }
#else
    cout << s.substr(0, N) << endl;
    cin >> res;
#endif
    for (int i = N; i < MAXN; i++) {
        res += s[i];
    }
    return res;
}

void answer(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

#ifdef DEBUG
    //do nothing
#else
    int verdict;
    cin >> verdict;
#endif
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> T;

    for (int i = 1; i <= T; i++) {
        numq = 0;
        cin >> N >> B >> F;

#ifdef DEBUG
        cin >> broken;
#endif

        string s;
        for (int a = 0; a < MAXN; a++){
            s += '0' + (a / 16) % 2;
        }

        string res = query(s);
        vector<pii> loc;

        for (int a = 0; a < MAXN; a++) {
            int b = a;
            while (b + 1 < MAXN && res[b] == res[b + 1]){
                b++;
            }

            loc.push_back({a, b});
            a = b;
        }

        vector<string> res2;
        for (int bit = 0; bit < 4; bit++) {
            for (int a = 0; a < MAXN; a++) {
                s[a] = '0' + (a >> bit) % 2;
            }
            res2.push_back(query(s));
        }

        set<int> bad;
        for (int a = 0; a < MAXN; a++) {
            bad.insert(a);
        }

        for (int a = 0; a < (int)loc.size(); a++) {
            int l = loc[a].first;
            int r = loc[a].second;

            for (int i = l; i <= r; i++) {
                int val = a * 16;
                for (int b = 0; b < 4; b++) {
                    if (res2[b][i] == '1') {
                        val |= 1 << b;
                    }
                }
                bad.erase(val);
            }
        }
        for (int i : bad) {
            cout << i << " ";
        }
        cout << endl;

        int verdict;
        cin >> verdict;
    }
}
