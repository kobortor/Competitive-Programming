#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll seedA = 101;
const ll seedB = 2;
const ll mod = 1e9 + 7;

const int MAXN = 2e5 + 5;

int N, M;

string str;
set<int> st[26];
ll hshA[26][MAXN];
ll hshB[26][MAXN];

ll qpowA[MAXN];
ll qpowB[MAXN];

pll hash_over(ll l, ll r, int tp){
    pll ans;
    ans.first = hshA[tp][r] - hshA[tp][l - 1] * qpowA[r - l + 1];
    ans.second = hshB[tp][r] - hshB[tp][l - 1] * qpowB[r - l + 1];

    ans.first %= mod;
    ans.second %= mod;
    
    if(ans.first < 0) ans.first += mod;
    if(ans.second < 0) ans.second += mod;

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    qpowA[0] = 1;
    qpowB[0] = 1;

    for(int a = 1; a < MAXN; a++){
        qpowA[a] = qpowA[a-1] * seedA % mod;
        qpowB[a] = qpowB[a-1] * seedB % mod;
    }

    cin >> N >> M;
    cin >> str;
    str = "$" + str;

    for(int a = 1; a <= N; a++){
        for(int b = 0; b < 26; b++){
            hshA[b][a] = hshA[b][a - 1] * seedA;
            hshB[b][a] = hshB[b][a - 1] * seedB;

            hshA[b][a] %= mod;
            hshB[b][a] %= mod;
        }

        st[str[a] - 'a'].insert(a);
        hshA[str[a] - 'a'][a]++;
        hshB[str[a] - 'a'][a]++;

        hshA[str[a] - 'a'][a] %= mod;
        hshB[str[a] - 'a'][a] %= mod;
    }

    while(M--){
        int x, y, len;
        cin >> x >> y >> len;

        bool good = true;
        for(int a = 0; a < 26; a++){
            auto xit = st[a].lower_bound(x);
            if(xit == st[a].end() || *xit - x >= len){
                continue;
            }
            int ytp = str[y + (*xit - x)] - 'a';

            pll hash1 = hash_over(x, x + len - 1, a);
            pll hash2 = hash_over(y, y + len - 1, ytp);

            if(hash1 != hash2){
                good = false;
                break;
            }
        }

        cout << (good ? "YES\n" : "NO\n");
    }
}
