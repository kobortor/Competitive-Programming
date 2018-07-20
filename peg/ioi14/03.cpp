#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<array<pii, 3>> shapes[8];

vector<array<pii, 3>> soln;
void solve(int dep, int X, int Y){
    if(dep < 0){
        return;
    }

    bool px = X >= (1 << dep);
    bool py = Y >= (1 << dep);

    solve(dep - 1, X % (1 << dep), Y % (1 << dep));

    if(px){
        for(array<pii, 3> &arr : soln){
            for(pii &p : arr){
                p.first += 1 << dep;
            }
        }
    }

    if(py){
        for(array<pii, 3> &arr : soln){
            for(pii &p : arr){
                p.second += 1 << dep;
            }
        }
    }

    if(!px && !py){
        for(array<pii, 3> arr : shapes[dep]){
            soln.push_back(arr);
        }
    } else if (px && !py){
        for(array<pii, 3> arr : shapes[dep]){
            for(pii &p : arr){
                p = {(2 << dep) - p.second - 1, p.first};
            }
            soln.push_back(arr);
        }
    } else if (!px && py){
        for(array<pii, 3> arr : shapes[dep]){
            for(pii &p : arr){
                p = {p.second, (2 << dep) - p.first - 1};
            }
            soln.push_back(arr);
        }
    } else if (px && py){
        for(array<pii, 3> arr : shapes[dep]){
            for(pii &p : arr){
                p = {(2 << dep) - p.second - 1, (2 << dep) - p.first - 1};
            }
            soln.push_back(arr);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    shapes[0].push_back({pii(0, 1), pii(1, 0), pii(1, 1)});
    for(int a = 0; a < 7; a++){
        for(array<pii, 3> arr : shapes[a]){
            for(pii &p : arr){
                p.first += 1 << a;
                p.second += 1 << a;
            }
            shapes[a + 1].push_back(arr);
        }

        for(array<pii, 3> arr : shapes[a]){
            for(pii &p : arr){
                p.first += 2 << a;
                p.second += 2 << a;
            }
            shapes[a + 1].push_back(arr);
        }

        for(array<pii, 3> arr : shapes[a]){
            for(pii &p : arr){
                p = {(2 << a) - p.second - 1, p.first + (2 << a)};
            }
            shapes[a + 1].push_back(arr);
        }

        for(array<pii, 3> arr : shapes[a]){
            for(pii &p : arr){
                p = {p.second + (2 << a), (2 << a) - p.first - 1};
            }
            shapes[a + 1].push_back(arr);
        }
    }

    int N, X, Y;
    cin >> N >> X >> Y;

    solve(N - 1, X, Y);

    for(array<pii, 3> arr : soln){
        for(pii p : arr){
            cout << p.first << " " << p.second << " ";
        }
        cout << "\n";
    }
}
