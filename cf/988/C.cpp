#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int K;
unordered_map<ll, pll> mp;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> K;
    for(int test = 1; test <= K; test++){
        int N;
        cin >> N;

        ll sum = 0;
        vector<ll> vec(N);
        for(int a = 0; a < N; a++){
            cin >> vec[a];
            sum += vec[a];
        }

        for(int a = 0; a < N; a++){
            auto iter = mp.find(sum - vec[a]);
            if(iter != mp.end()){
                cout << "YES\n";
                cout << iter->second.first << " " << iter->second.second << "\n";
                cout << test << " " << a + 1 << "\n";
                return 0;
            }
        }

        for(int a = 0; a < N; a++){
            mp[sum - vec[a]] = pll(test, a + 1);
        }
    }

    cout << "NO\n";
}
