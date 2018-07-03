#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//O(N^2) solution, but in practice the same speed as O(N^3) due to constants

const int MAXN = 305;

unordered_map<string, int> mp;
int getid(string str){
    return mp.insert({str, mp.size()}).first->second;
}

int N;
int id[MAXN];
int len[MAXN];

int nxt = 1;
struct {
    int dep, len, comp;
    unordered_map<int, int> mp;
    vector<int> vec;
} tr[MAXN * MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        string str;
        cin >> str;
        len[a] = str.size() + len[a - 1] + 1;
        id[a] = getid(str);
    }

    for(int a = 1; a <= N; a++){
        int cur = 0;

        for(int b = a; b <= N; b++){
            if(!tr[cur].mp.count(id[b])){
                tr[cur].mp[id[b]] = nxt;

                tr[nxt].dep = tr[cur].dep + 1;
                tr[nxt].len = b - a + 1;
                tr[nxt].comp = (len[b] - len[a - 1] - 1) - tr[nxt].len;
                nxt++;
            }

            cur = tr[cur].mp[id[b]];

            tr[cur].vec.push_back(a);
        }
    }

    int tot = len[N] - 1;
    int ans = tot;

    for(int a = 1; a < nxt; a++){
        int added = 0;
        int prv = -99999;

        for(int i : tr[a].vec){
            if(prv + tr[a].len <= i){
                prv = i;
                added++;
            }
        }

        if(added >= 2){
            ans = min(ans, tot - added * tr[a].comp);
        }
    }
    cout << ans;
}
