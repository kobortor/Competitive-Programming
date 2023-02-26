#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef pair<double, double> pdd;

int n;

vector<pdd> points;
vector<vector<pdd>> shapes;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<pdd> shape;
        for (int j = 0; j < m; j++) {
            pdd p;
            cin >> p.first >> p.second;
            shape.push_back(p);
            points.push_back(p);
        }
        shapes.push_back(shape);
    }
}
