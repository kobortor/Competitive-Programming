#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

//reversed, but whatever
int mask(int val){
    int ans = 0;
    while(val){
        if(val % 10 == 4){
            ans = ans * 10 + 4;
        } else if (val % 10 == 7){
            ans = ans * 10 + 7;
        }
        val /= 10;
    }
    return ans;
}

int A, B;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> B;
    while(mask(++A) != mask(B)){}
    cout << A;
}
