#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string A, B;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> A >> B;

    int wrong4 = 0, wrong7 = 0;
    for(int a = 0; a < (int)A.size(); a++){
        if(A[a] == '7' && B[a] == '4'){
            wrong7++;
        }
        if(A[a] == '4' && B[a] == '7'){
            wrong4++;
        }
    }
    cout << max(wrong4, wrong7);
}
