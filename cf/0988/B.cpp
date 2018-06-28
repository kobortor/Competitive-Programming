#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 105;

int N;
string str[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> str[a];
    }
    sort(str, str + N, [](const string &s1, const string &s2){return s1.size() < s2.size();});

    for(int a = 0; a < N - 1; a++){
        if((int)str[a + 1].find(str[a]) == -1){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for(int a = 0; a < N; a++){
        cout << str[a] << "\n";
    }
}
