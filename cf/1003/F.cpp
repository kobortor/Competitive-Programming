#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 305;
const ll mod = 1e9 + 7;

unordered_map<string, int> mp;
int getid(string str){
    return mp.insert({str, mp.size()}).first->second;
}

int N;
int id[MAXN];
int len[MAXN];
bool good[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        string str;
        cin >> str;
        id[a] = getid(str);

        len[a] = len[a - 1] + str.size() + 1;
    }

    int totlen = len[N] - 1;
    int ans = totlen;

    for(int a = 1; a <= N; a++){
        memset(good, true, sizeof good);

        for(int b = 0; a + b <= N; b++){
            int comp = (len[a + b] - len[a - 1] - 1) - (b + 1);
            for(int c = a; c <= N; c++){
                good[c] &= (c + b <= N) && (id[c + b] == id[a + b]);
            }

            int added = 0;
            int cur = a;
            while(cur <= N){
                if(good[cur]){
                    added++;
                    cur += b;
                }
                cur++;
            }

            if(added >= 2){
                ans = min(ans, totlen - comp * added);
            }
        }
    }

    cout << ans;
}
