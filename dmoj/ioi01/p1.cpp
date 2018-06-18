#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1030;

int S;
int BIT[MAXN][MAXN];

void update(int X, int Y, int A){
    while(X <= S){
        int _Y = Y;
        while(_Y <= S){
            BIT[X][_Y] += A;
            _Y += _Y & -_Y;
        }
        X += X & -X;
    }
}

int query(int X, int Y){
    int ans = 0;
    while(X){
        int _Y = Y;
        while(_Y){
            ans += BIT[X][_Y];
            _Y -= _Y & -_Y;
        }
        X -= X & -X;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    while(true){
        int tp;
        cin >> tp;
        if(tp == 0){
            cin >> S;
        } else if (tp == 1){
            int X, Y, A;
            cin >> X >> Y >> A;
            update(X + 1, Y + 1, A);
        } else if (tp == 2){
            int L, B, R, T;
            cin >> L >> B >> R >> T;

            R++;
            T++;

            cout << query(R, T) - query(L, T) - query(R, B) + query(L, B) << "\n";
        } else if (tp == 3){
            break;
        }
    }
}
