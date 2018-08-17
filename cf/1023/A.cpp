#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    if(find(allof(S), '*') == S.end()){
        cout << (S == T ? "YES" : "NO");
        return 0;
    }

    if(N - 1 > M){
        cout << "NO";
        return 0;
    }

    for(int a = 0; a < N; a++){
        if(S[a] == '*'){
            break;
        }

        if(S[a] != T[a]){
            cout << "NO";
            return 0;
        }
    }

    for(int a = 0; a < N; a++){
        if(S[N - a - 1] == '*'){
            break;
        }

        if(S[N - a - 1] != T[M - a - 1]){
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
