#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> guests[300];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int sz = (1 + sqrt(1 + 8 * N)) / 2;

/*
    K * (K - 1) / 2 = N
    K ^ 2 - K - 2N = 0
    K = (1 + sqrt(1 + 8N)) / 2
*/

    cout << sz << "\n";

    int id = 1;
    for(int a = 1; a <= sz; a++){
        for(int b = a + 1; b <= sz; b++){
            guests[a].push_back(id);
            guests[b].push_back(id);
            id++;
        }
    }

    for(int a = 1; a <= sz; a++){
        for(int i : guests[a]){
            cout << i << " ";
        }
        cout << "\n";
    }
}
