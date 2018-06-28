#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N;
string S, T;

int offset = 0;
vector<int> opers;
int val[MAXN];

void shift(int x){
    opers.push_back(x);
    reverse(val + N - x, val + N);
    rotate(val, val + N - x, val + N);

    reverse(S.end() - x, S.end());
    rotate(S.begin(), S.end() - x, S.end());
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(val, -1, sizeof val);

    cin >> N >> S >> T;

    for(int a = 0; a < N; a++){
        bool found = false;
        for(int b = 0; b < N; b++){
            if(val[b] == -1 && T[a] == S[b]){
                val[b] = a;
                found = true;
                break;
            }
        }
        if(!found){
            cout << -1;
            return 0;
        }
    }
    for(int a = N - 1; a >= 0; a--){
        int idx = find(val, val + N, a) - val;
        shift(N);
        shift(idx);
        shift(1);
    }
    cout << opers.size() << "\n";

    for(int i : opers){
        cout << i << " ";
    }
}
