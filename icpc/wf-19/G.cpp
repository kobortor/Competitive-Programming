// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <initializer_list>


// Created by $%U%$ On $%h%$:$%m%$:$%s%$ on $%D%$-$%M%$-$%Y%$

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;
const int MAXK = 22;

const int CUTOFF = 500;

vector<pair<int, char>> children[MAXN];
char initial[MAXN];
int par[MAXN];

const ll ROLL1 = 101;
const ll ROLL2 = 103;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;

ll POW1[MAXN];
ll POW2[MAXN];

struct Hash {
    ll x, y;
    Hash() {
        x = y = 0;
    }
    explicit Hash(char ch) {
        x = ch;
        y = ch;
    }
    explicit Hash(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
    Hash prepend(char ch) {
        ll _x = (x * ROLL1 + ch) % mod1;
        ll _y = (y * ROLL2 + ch) % mod2;
        return Hash{_x, _y};
    }
    Hash append(char ch, ll this_len) {
        ll _x = (x + ch * POW1[this_len]) % mod1;
        ll _y = (y + ch * POW2[this_len]) % mod2;
        return Hash{_x, _y};
    }
    Hash concat(Hash other, ll len) {
        ll _x = (x + other.x * POW1[len]) % mod1;
        ll _y = (y + other.y * POW2[len]) % mod2;
        return Hash{_x, _y};
    }
    ll to_ll() {
        return x * mod2 + y;
    }
};

struct Trie {
    Trie *nxt[26];
    int cnt;
    Trie() {
        cnt = 0;
        fill(nxt, nxt + 26, nullptr);
    }
};

Trie allocated[MAXN];
int alloc_idx = 0;
Trie* get_new_trie() {
    return &allocated[alloc_idx++];
}

Trie* trie_root = get_new_trie();

pair<int, Hash> jmp[MAXN][MAXK];

void pre_dfs(Trie* cur) {
    for (int i = 0; i < 26; i++) {
        if (cur->nxt[i] == nullptr) continue;
        pre_dfs(cur->nxt[i]);
        cur->cnt += cur->nxt[i]->cnt;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    memset(jmp, -1, sizeof jmp);

    POW1[0] = 1;
    POW2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        POW1[i] = POW1[i - 1] * ROLL1 % mod1;
        POW2[i] = POW2[i - 1] * ROLL2 % mod2;
    }
    

    for (int i = 1; i <= n; i++) {
        cin >> initial[i] >> par[i];

        children[par[i]].push_back({i, initial[i]});
        jmp[i][0] = {par[i], Hash(initial[i])};
        for (int k = 1; k < MAXK; k++) {
            int mid = jmp[i][k-1].first;
            Hash mid_hsh = jmp[i][k-1].second;

            jmp[i][k] = {
              jmp[mid][k - 1].first,
              mid_hsh.concat(jmp[mid][k - 1].second, 1 << (k - 1))
            };
            if (jmp[i][k].first == -1) break;
        }
        for (int k = 0; k < MAXK; k++) {
            // cout << i << " jump " << k << " gets " << jmp[i][k].first << " w/ " << jmp[i][k].second.x << " " << jmp[i][k].second.y << endl;
            if (jmp[i][k].first == -1) break;
        }
    }

    unordered_map<ll, Trie*> known_hashes;
    vector<string> queries;

    // build trie for short tries
    for (int i = 0; i < k; i++) {
        string str;
        cin >> str;
        queries.push_back(str);

        Hash hsh(0, 0);
        Trie* ptr = trie_root;
        for (int j = 0; j < str.size(); j++) {
            char ch = str[j];
            if (ptr->nxt[ch - 'A'] == nullptr) {
                ptr->nxt[ch - 'A'] = get_new_trie();
            }
            ptr = ptr->nxt[ch - 'A'];

            hsh = hsh.append(ch, j);
            // cout << str << ": " << hsh.x << ", " << hsh.y << " -> " << ptr << endl;
            known_hashes[hsh.to_ll()] = ptr;
        }
    }

    for (int i = 1; i <= n; i++) {
        // cout << "Lady " << i << endl;
        int idx = i;
        Hash hsh(0, 0);
        int this_len = 0;
        for (int k = MAXK - 1; k >= 0; k--) {
            if (jmp[idx][k].first != -1) {
                Hash nxt_hsh = hsh.concat(jmp[idx][k].second, this_len);
                if (known_hashes.count(nxt_hsh.to_ll())) {
                    this_len += 1 << k;
                    idx = jmp[idx][k].first;
                    hsh = nxt_hsh;
                }
            }
        }

        if (known_hashes.count(hsh.to_ll())) {
            known_hashes[hsh.to_ll()]->cnt++;
        }
    }

    pre_dfs(trie_root);

    for (int i = 0; i < k; i++) {
        const string& str = queries[i];
        // cout << str << ": ";
        Trie *ptr = trie_root;
        for (char ch : str) {
            ptr = ptr->nxt[ch - 'A'];
        }
        cout << ptr->cnt << "\n";
    }
}