#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int arr[3], d;
    cin >> arr[0] >> arr[1] >> arr[2] >> d;
    sort(arr, arr + 3);

    cout << max(0, d - (arr[2] - arr[1])) + max(0, d - (arr[1] - arr[0]));
}
