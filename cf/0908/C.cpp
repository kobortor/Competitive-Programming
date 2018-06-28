#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
double R;
double xi[MAXN];
double ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N >> R;
    for(int a = 0; a < N; a++){
        cin >> xi[a];

        double highest = R;
        for(int b = 0; b < a; b++){
            double xdiff = abs(xi[a] - xi[b]);
            if(xdiff <= 2 * R){
                //they will collide someday
                highest = max(highest, ans[b] + sqrt(4 * R * R - xdiff * xdiff));
            }
        }
        ans[a] = highest;
        cout << fixed << setprecision(15) << ans[a] << " ";
    }
}