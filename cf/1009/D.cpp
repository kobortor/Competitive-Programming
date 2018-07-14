#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;

vector<pii> ans;

int gcd(int x, int y){
    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> N >> M;

    if(M < N - 1){
        cout << "Impossible\n";
        return 0;
    }

    for(int a = 2; a <= N; a++){
        ans.push_back({1, a});
    }

    for(int a = 2; a <= N; a++){
        for(int b = 2; b < a && (int)ans.size() < M; b++){
            if(gcd(a, b) == 1){
                ans.push_back({a, b});
            }
        }
    }

    if((int)ans.size() == M){
        cout << "Possible\n";
        for(pii p : ans){
            cout << p.first << " " << p.second << "\n";
        }
    } else {
        cout << "Impossible\n";
    }
}
