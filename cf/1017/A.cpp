#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N;
int stu[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        stu[a] = x + y + z + w;
    }

    cout << count_if(stu, stu + N, [](int x){ return x > stu[0]; }) + 1;
}
