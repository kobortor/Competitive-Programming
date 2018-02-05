#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 100;

int N;

int median(vector<int> vec){
    sort(vec.begin(), vec.end());
    return vec[vec.size() / 2];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    vector<int> medians;
    for(int a = 0; a < N; a++){
        vector<int> vals;
        for(int b = 0; b < N; b++){
            int x;
            cin >> x;
            vals.push_back(x);
        }
        medians.push_back(median(vals));
    }
    cout << median(medians);
}
