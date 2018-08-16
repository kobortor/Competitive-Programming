#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B, C;
    cin >> A >> B >> C;

    int AB = abs(A - B);
    int AC = abs(A - C);
    int BC = abs(B - C);

    cout << AB + AC + BC - max(max(AB, AC), BC);
}
