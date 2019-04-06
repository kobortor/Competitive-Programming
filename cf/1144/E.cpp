#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int K;
    string S, T;
    cin >> K >> S >> T;

    vector<int> vec;

    for (int a = 0; a < K; a++) {
        vec.push_back((S[a] - 'a') + (T[a] - 'a'));
    }
    for (int a = K - 1; a >= 1; a--) {
        if (vec[a] >= 26) {
            vec[a] -= 26;
            vec[a - 1]++;
        }
    }

    int carry = 0;
    if (vec[0] >= 26) {
        vec[0] -= 26;
        carry = 26;
    }

    string soln;
    for (int a = 0; a < K; a++) {
        int ch = vec[a] + carry;
        soln += char('a' + ch / 2);

        if (ch % 2 == 1) {
            carry = 26;
        } else {
            carry = 0;
        }
    }

    cout << soln;
}
