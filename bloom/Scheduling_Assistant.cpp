#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int D, N;

bool busy[100];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> D >> N;
    for(int a = 1; a <= N; a++){
        cin.ignore();
        string name;
        getline(cin, name);

        int B;
        cin >> B;
        while(B--){
            int S, E;
            cin >> S >> E;
            while(S != E) {
                busy[S++] = true;
            }
        }
    }

    for(int a = 0; a + D - 1 <= 96; a++){
        if(find(busy + a, busy + a + D, true) == busy + a + D){
            cout << a;
            return 0;
        }
    }

    cout << -1;
}
