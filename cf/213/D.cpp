#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

const double pi = acos(-1);

const double dx1 = 10 * cos(pi / 5);
const double dy1 = 10 * sin(pi / 5);

const double horlen = 2 * dx1;

const double dx2 = 10 * cos(2 * pi / 5);
const double dy2 = 10 * sin(2 * pi / 5);

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    typedef pair<double, double> pdd;
    vector<pdd> points;
    points.push_back(pdd(0, 0));
    for(int a = 0; a < N; a++){
        points.push_back(pdd(a * horlen + dx1, dy1));
        points.push_back(pdd(a * horlen + horlen, 0));
        points.push_back(pdd(a * horlen + dx2 + 10, -dy2));
        points.push_back(pdd(a * horlen + dx2, -dy2));
    }

    cout << points.size() << "\n";
    for(pdd p : points){
        cout << fixed << setprecision(15) << p.first << " " << p.second << "\n";
    }

    cout << "1 2 3 4 5\n";
    for(int a = 1; a < N; a++){
        cout << 4 * (a - 1) + 2 + 1 << " ";
        cout << 4 * a + 1 + 1 << " ";
        cout << 4 * a + 2 + 1 << " ";
        cout << 4 * a + 3 + 1 << " ";
        cout << 4 * a + 4 + 1 << "\n";
    }

    cout << "1 ";
    for(int a = 0; a < N; a++){
        cout << 4 * a + 2 + 1 << " ";
    }

    for(int a = N - 1; a >= 1; a--){
        cout << 4 * a + 4 + 1 << " ";
        cout << 4 * a + 1 + 1 << " ";
        cout << 4 * a + 3 + 1 << " ";
        cout << 4 * (a - 1) + 2 + 1 << " ";
    }
    cout << 4 + 1 << " ";
    cout << 1 + 1 << " ";
    cout << 3 + 1 << " ";
    cout << 1 << "\n";
}
