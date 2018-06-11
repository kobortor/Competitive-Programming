#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

double targ_area = 250.0 * 250.0 / 4.0;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    double x, y;
    cin >> x >> y;

    cout << fixed << setprecision(2);

    if(abs(x + y - 250.0) < 1e-7){
        //on diagonal
        double lft = 250.0 * x / 2.0;
        double rht = 250.0 * y / 2.0;

        if(lft < targ_area){
            double newx = (targ_area - lft) / y * 2;
            cout << newx << " " << 0.0 << "\n";
        } else {
            double newy = (targ_area - rht) / x * 2;
            cout << 0.0 << " " << newy << "\n";
        }
    } else if (x == 0){
        if(y < 250.0 / 2.0){
            double xlen = 250.0 - y;
            double trap = (250.0 + xlen) * y / 2.0;
            double dy = (trap - targ_area) / xlen * 2.0;
            cout << 250.0 - (y - dy) << " " << y - dy << "\n";
        } else {
            double newx = targ_area / y * 2.0;
            cout << newx << " " << 0.0 << "\n";
        }
    } else if (y == 0){
        if(x < 250.0 / 2.0){
            double ylen = 250.0 - x;
            double trap = (250.0 + ylen) * x / 2.0;
            double dx = (trap - targ_area) / ylen * 2.0;
            cout << x - dx << " " << 250.0 - (x - dx) << "\n";
        } else {
            double newy = targ_area / x * 2.0;
            cout << 0.0 << " " << newy << "\n";
        }
    }
}
