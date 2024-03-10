#include<bits/stdc++.h>

// Created by kobortor On 18:13:05 on 10-03-2024

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        bool good = false;
        for (int lenA = 1; lenA < (int)s.size(); lenA++) {
            string A = s.substr(0, lenA);
            string B = s.substr(lenA, string::npos);
            if (A[0] != '0' && B[0] != '0' && stoi(A) < stoi(B)) {
                cout << A << " " << B << endl;
                good = true;
                break;
            }
        }
        if (!good) {
            cout << "-1\n";
        }
    }
}
