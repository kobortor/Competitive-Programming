#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string S;
int freq[3][3];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;
    for(int a = 0; a < N; a++){
        switch (S[a]) {
            case 'R': freq[a % 3][0]++; break;
            case 'G': freq[a % 3][1]++; break;
            case 'B': freq[a % 3][2]++; break;
        }
    }

    pair<int, vector<int>> best;
    best.first = 1e6;

    vector<int> v = {0, 1, 2};
    do {
        int cost = 0;
        for(int a = 0; a < 3; a++){
            cost += freq[a][0] + freq[a][1] + freq[a][2] - freq[a][v[a]];
        }

        best = min(best, {cost, v});
    } while (next_permutation(allof(v)));

    cout << best.first << "\n";
    for(int a = 0; a < N; a++){
        switch (best.second[a % 3]) {
            case 0: cout << "R"; break;
            case 1: cout << "G"; break;
            case 2: cout << "B"; break;
        }
    }
}
