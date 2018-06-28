#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    vector<pii> group1, group2;
    
    for(int a = 0; a < N; a++){
        pii p;
        cin >> p.first >> p.second;
        if(p.first < p.second){
            group1.push_back(p);
        } else {
            group2.push_back(p);
        }
    }

    sort(allof(group1), [](pii p1, pii p2){ return p1.first < p2.first; });
    sort(allof(group2), [](pii p1, pii p2){ return p1.second > p2.second; });

    int cur_tm = 0;
    int part_b = 0;

    for(pii p : group1){
        cur_tm += p.first;
        part_b = max(0, part_b - p.first) + p.second;
    }
    for(pii p : group2){
        cur_tm += p.first;
        part_b = max(0, part_b - p.first) + p.second;
    }

    cout << cur_tm + part_b << "\n";
}
