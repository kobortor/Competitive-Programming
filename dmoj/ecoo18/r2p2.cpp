#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

/*
if same weight, take the later one
*/

void testcase(){
    set<int> avail;
    for(int a = 0; a <= 1000000; a++){
        avail.insert(a);
    }

    vector<pair<double, int>> vec;
    int N;
    cin >> N;
    for(int a = 1; a <= N; a++){
        pair<double, int> p;
        cin >> p.second >> p.first;
        vec.push_back(p);
    }
    sort(allof(vec));
    reverse(allof(vec));

    double ans = 0;
    for(pair<double, int> p : vec){
        auto iter = avail.lower_bound(p.second);
        if(iter == avail.begin()){
            //can't do this
        } else {
            ans += p.first;
            avail.erase(prev(iter));
        }
    }
    cout << fixed << setprecision(4) << ans << endl;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    const int MAX_CASE = 10;
    for(int a = 1; a <= MAX_CASE; a++){
        testcase();
    }
}
