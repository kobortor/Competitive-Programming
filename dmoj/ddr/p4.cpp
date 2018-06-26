#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

int N;

string str[MAXN];

bool solve(int A, int B){
    int diff = 0;
    if(str[A].size() == str[B].size()){
        for(int a = 0; a < (int)str[A].size(); a++){
            diff += str[A][a] != str[B][a];
        }

        return diff <= 1;
    }

    if(str[A].size() > str[B].size()){
        swap(A, B);
    }

    if(abs((int)str[A].size() - (int)str[B].size()) > 1){
        return false;
    }

    int b = 0;
    for(int a = 0; a < (int)str[A].size();){
        if(str[A][a] != str[B][b]){
            if(diff){
                return false;
            }

            diff = 1;
            b++;
        } else {
            a++;
            b++;
        }
    }

    return true;
}

int mat[MAXN][MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(mat, 0x3f, sizeof mat);

    cin >> N;
    for(int a = 1; a <= N; a++){
        mat[a][a] = 0;
        cin >> str[a];

        for(int b = 1; b < a; b++){
            if(solve(a, b)){
                mat[a][b] = 1;
                mat[b][a] = 1;
            }
        }
    }

    for(int k = 1; k <= N; k++){
        for(int a = 1; a <= N; a++){
            for(int b = 1; b <= N; b++){
                mat[a][b] = min(mat[a][b], mat[a][k] + mat[k][b]);
            }
        }
    }

    for(int a = 1; a <= N; a++){
        for(int b = 1; b <= N; b++){
            if(mat[a][b] == 0x3f3f3f3f){
                mat[a][b] = -1;
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int a, b;
        cin >> a >> b;
        cout << mat[a][b] << "\n";
    }
}
