#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<int> vec;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N / 2; a++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(allof(vec));

    int cost1 = 0;
    int cost2 = 0;
    for(int a = 0; a < N / 2; a++){
        cost1 += abs((2 * a + 1) - vec[a]);
    }
    for(int a = 0; a < N / 2; a++){
        cost2 += abs((2 * a + 2) - vec[a]);
    }
    cout << min(cost1, cost2);
}
