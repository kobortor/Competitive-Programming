#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

ll N, X1, X2;
pll val[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X1 >> X2;

    for(int a = 0; a < N; a++){
        cin >> val[a].first;
        val[a].second = a + 1;
    }
    sort(val, val + N);

    ll solve1 = -1, solve2 = -1;
    ll sz1 = 0, sz2 = 0;
    for(ll a = N - 1; a >= 0; a--){
        ll end1 = a - 1 + (X1 + val[a].first - 1) / val[a].first;
        if(end1 < N && solve1 == -1){
            solve1 = a;
            sz1 = end1 - a + 1;
        }
        ll end2 = a - 1 + (X2 + val[a].first - 1) / val[a].first;
        if(end2 < N && solve2 == -1){
            solve2 = a;
            sz2 = end2 - a + 1;
        }

        if(end2 < solve1){
            cout << "Yes\n";
            cout << sz1 << " " << end2 - a + 1 << "\n";
            for(ll i = 0; i < sz1; i++){
                cout << val[solve1 + i].second << " ";
            }
            cout << "\n";
            for(ll i = a; i <= end2; i++){
                cout << val[i].second << " ";
            }
            cout << "\n";
            return 0;
        }
        if(end1 < solve2){
            cout << "Yes\n";
            cout << end1 - a + 1 << " " << sz2 << "\n";
            for(ll i = a; i <= end1; i++){
                cout << val[i].second << " ";
            }
            cout << "\n";
            for(ll i = 0; i < sz2; i++){
                cout << val[solve2 + i].second << " ";
            }
            cout << "\n";
            return 0;
           
        }
    }
    cout << "No";
}
