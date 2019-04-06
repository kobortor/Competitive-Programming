#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    
    vector<int> odd, even;

    int tot = 0;
    while (n--) {
        int x;
        cin >> x;
        tot += x;

        if (x % 2 == 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }

    sort(allof(odd));
    sort(allof(even));

    reverse(allof(odd));
    reverse(allof(even));

    int minsz = min(odd.size(), even.size());

    int sum1 = 0, sum2 = 0;

    for (int a = 0; a < min(minsz, (int) odd.size()); a++) sum1 += odd[a];
    for (int a = 0; a < min(minsz + 1, (int) even.size()); a++) sum1 += even[a];

    for (int a = 0; a < min(minsz + 1, (int) odd.size()); a++) sum2 += odd[a];
    for (int a = 0; a < min(minsz, (int) even.size()); a++) sum2 += even[a];

    cout << tot - max(sum1, sum2);
}
