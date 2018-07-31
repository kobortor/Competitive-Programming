#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string S, T;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S >> T;

    vector<int> soln;
    for(int a = N - 1; a >= 0; a--){
        int idx = S.find_last_of(T[a]);
        if(idx == -1){
            cout << -1;
            return 0;
        }

        while(idx < a){
            swap(S[idx], S[idx + 1]);
            soln.push_back(++idx);
        }
        S.pop_back();
    }

    cout << soln.size() << "\n";
    for(int i : soln){
        cout << i << " ";
    }
}
