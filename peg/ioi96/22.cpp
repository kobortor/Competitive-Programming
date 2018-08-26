#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int cnt = 1;
struct {
    bool is_end = false;
    int child[26];
} tr[2005];

bool good[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    while(true){
        string P;
        cin >> P;

        if(P == "."){
            break;
        } else {
            int idx = 0;
            for(char c : P){
                if(tr[idx].child[c - 'A'] == 0){
                    tr[idx].child[c - 'A'] = cnt++;
                }
                idx = tr[idx].child[c - 'A'];
            }
            tr[idx].is_end = true;
        }
    }

    string S, tmp;
    while(cin >> tmp){
        S += tmp;
    }

    int ans = 0;
    good[0] = true;
    for(int a = 0; a <= (int)S.size(); a++){
        if(good[a]){
            ans = a;

            int idx = 0;
            for(int b = a; b < (int)S.size(); b++){
                if(tr[idx].child[S[b] - 'A'] == 0){
                    break;
                }
                idx = tr[idx].child[S[b] - 'A'];
                good[b + 1] |= tr[idx].is_end;
            }
        }
    }

    cout << ans;
}
