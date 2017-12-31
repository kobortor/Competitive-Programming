#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;
    N++;
    cout << (N / 2) * (N - N / 2);
}
