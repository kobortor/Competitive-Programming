#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int M;
    cin >> M;
    int a;
    for(a = 1; M > 0; a++){
        int tmp = a;
        while(tmp % 5 == 0) {
            tmp /= 5;
            M--;
        }
    }
    a--;
    if(M == 0){
        cout << "5\n";
        cout << a + 0 << " ";
        cout << a + 1 << " ";
        cout << a + 2 << " ";
        cout << a + 3 << " ";
        cout << a + 4 << " ";
    } else {
        cout << "0";
    }
}
