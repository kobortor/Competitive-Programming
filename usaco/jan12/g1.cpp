#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 22;

int N, K;
string combos[MAXN];

int trie_cnt = 1;
struct {
    int child[3] = {-1, -1, -1};
    int score = 0;
    int id = -1;
} trie[MAXN * MAXN];

void insert_substr(string substr, int id, bool score){
    reverse(allof(substr));

    int cur = 0;

    for(char c : substr){
        int nxt = c - 'A';
        if(trie[cur].child[nxt] == -1){
            trie[cur].child[nxt] = trie_cnt++;
        }

        cur = trie[cur].child[nxt];
    }

    trie[cur].id = id;

    if(score){
        trie[cur].score++;
    }
}

//<longest substr, added score>
pii search_trie(string substr){
    reverse(allof(substr));

    int best = 0;
    int score = 0;

    int cur = 0;
    for(char c : substr){
        int nxt = c - 'A';

        if(trie[cur].child[nxt] == -1){
            return {best, score};
        }

        cur = trie[cur].child[nxt];
        score += trie[cur].score;

        if(trie[cur].id != -1){
            best = trie[cur].id;
        }
    }

    return {best, score};
}

vector<pii> adj[MAXN * MAXN];
int dp[2][MAXN * MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 0; a < N; a++){
        cin >> combos[a];

        for(int b = 0; b < (int)combos[a].size(); b++){
            int id = a * MAXN + b + 1;
            string substr = combos[a].substr(0, b + 1);

            insert_substr(substr, id, b + 1 == (int)combos[a].size());
        }
    }

    for(int a = 0; a < N; a++){
        for(int b = 0; b < (int)combos[a].size(); b++){
            int id = a * MAXN + b + 1;
            string tmp = combos[a].substr(0, b + 1);

            for(char nxt_ch = 'A'; nxt_ch <= 'C'; nxt_ch++){
                adj[id].push_back(search_trie(tmp + nxt_ch));
            }
        }
    }

    adj[0].push_back(search_trie("A"));
    adj[0].push_back(search_trie("B"));
    adj[0].push_back(search_trie("C"));

    memset(dp, 0xaf, sizeof dp);
    int cur = 0;

    dp[0][0] = 0;

    while(K--){
        for(int a = 0; a < MAXN * MAXN; a++){
            dp[!cur][a] = 0xafafafaf;
        }

        for(int a = 0 ; a < MAXN * MAXN; a++){
            for(pii p : adj[a]){
                dp[!cur][p.first] = max(dp[!cur][p.first], dp[cur][a] + p.second);
            }
        }

        cur ^= 1;
    }

    cout << *max_element(dp[cur], dp[cur] + MAXN * MAXN) << "\n";
}
