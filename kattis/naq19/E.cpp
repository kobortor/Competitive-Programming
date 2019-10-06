#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

const ll mod = 1e9 + 7;
const ll cyc1 = 100;
const ll cyc2 = 101;
const int LONG = 200;

bool vowel (char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

struct hashv {
    ll v1, v2;
    hashv () : v1(0), v2(0) {}
    hashv (ll _v1, ll _v2) : v1(_v1), v2(_v2) {}
    hashv operator+ (char c) const  {
        return hashv {
            (v1 * cyc1 + c) % mod,
            (v2 * cyc2 + c) % mod
        };
    }

    bool operator== (const hashv &h) const {
        return v1 == h.v1 && v2 == h.v2;
    }
};

ll cyc1_pow[MAXN];
ll cyc2_pow[MAXN];

hashv hashes[MAXN];

hashv gethsh(int l, int r) {
    return {
        ((hashes[r].v1 - hashes[l - 1].v1 * cyc1_pow[r - l + 1]) % mod + mod) % mod,
        ((hashes[r].v2 - hashes[l - 1].v2 * cyc2_pow[r - l + 1]) % mod + mod) % mod,
    };
}

struct myhash {
    size_t operator() (const hashv &h) const {
        return hash<long long>()(h.v1 ^ (h.v2 << 32ll));
    }
};

string words[MAXN];
int vowel_cnt[MAXN];
unordered_map<hashv, int, myhash> short_words;
vector<pair<hashv, int>> long_words;

int prv[MAXN];
int nvow[MAXN];

void add_jump(int start, int wrd) {
    int l = words[wrd].size() - vowel_cnt[wrd];
    if (prv[start + l] == -1 || nvow[start + l] < nvow[start] + vowel_cnt[wrd]) {
        prv[start + l] = wrd;
        nvow[start + l] = nvow[start] + vowel_cnt[wrd];
    }
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cyc1_pow[0] = 1;
    cyc2_pow[0] = 1;
    for (int a = 1; a < MAXN; a++) {
        cyc1_pow[a] = cyc1_pow[a - 1] * cyc1 % mod;
        cyc2_pow[a] = cyc2_pow[a - 1] * cyc2 % mod;
    }

    int n;
    cin >> n;

    for (int a = 0; a < n; a++) {
        cin >> words[a];

        hashv str_hash;
        string no_vowel;
        for (char c : words[a]) {
            if (!vowel(c)) {
                no_vowel += c;
                str_hash = str_hash + c;
            } else {
                vowel_cnt[a]++;
            }
        }

        if ((int)no_vowel.size() < LONG) {
            auto au = short_words.insert({str_hash, a});
            if (!au.second) {
                if (vowel_cnt[au.first->second] < vowel_cnt[a]) {
                    au.first->second = a;
                }
            }
        } else {
            long_words.push_back({str_hash, a});
        }
    }

    string word;
    cin >> word;

    for (int a = 0; a < (int)word.size(); a++) {
        hashes[a + 1] = hashes[a] + word[a];
    }

    memset(prv, -1, sizeof prv);
    prv[1] = 0;
    for (int a = 1; a <= (int)word.size(); a++) {
        if (prv[a] == -1) continue;

        for (int b = a; b <= (int)word.size() && b - a + 1 < LONG; b++) {
            auto iter = short_words.find(gethsh(a, b));

            if (iter != short_words.end()) {
                add_jump(a, iter->second);
            }
        }

        for (pair<hashv, int> p : long_words) {
            int l = words[p.second].size() - vowel_cnt[p.second];
            if (a + l - 1 <= (int)word.size() && gethsh(a, a + l - 1) == p.first) {
                add_jump(a, p.second);
            }
        }
    }

    vector<string> out;
    int idx = (int)word.size() + 1;
    while (idx != 1) {
        out.push_back(words[prv[idx]]);
        idx -= words[prv[idx]].size() - vowel_cnt[prv[idx]];
    }

    while (!out.empty()) {
        cout << out.back() << " ";
        out.pop_back();
    }
}
