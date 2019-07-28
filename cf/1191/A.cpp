#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

char ch(int x){
    switch (x % 4) {
        case 1 : return 'A';
        case 3 : return 'B';
        case 2 : return 'C';
        case 0 : return 'D';
        default: return 'Z';
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int x;
    cin >> x;

    pair<char, int> best = {'Z', 0};
    for (int a = 0; a <= 2; a++) {
        best = min(best, {ch(x + a), a});
    }

    cout << best.second << " " << best.first << "\n";
}
