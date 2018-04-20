#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, A, B;
string str;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B;
    int tot = A + B;
    cin >> str;

    for(int a = 0; a < N;){
        int b = a;
        while(b < N && str[b] == '.'){
            b++;
        }
        int diff = b - a;

        int hi = (diff + 1) / 2;
        int lo = diff / 2;

        if(A < B){
            swap(A, B);
        }
        A = max(0, A - hi);
        B = max(0, B - lo);

        a = b + 1;
    }
    cout << tot - A - B;
}
