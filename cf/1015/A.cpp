#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
vector<pii> segs;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    while(N--){
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    vector<int> points;
    for(int a = 1; a <= M; a++){
        bool good = true;
        for(pii p : segs){
            good &= !(p.first <= a && a <= p.second);
        }

        if(good){
            points.push_back(a);
        }
    }

    cout << points.size() << "\n";
    for(int i : points){
        cout << i << " ";
    }
}
