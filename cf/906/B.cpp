#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> test(int N, int M){
    if(N == 1 && M == 1){
        return {{1}};
    }
    if(N == 3 && M == 3){
        return {
            {9,7,5},
            {4,3,1},
            {2,8,6}
        };
    }

    if(N <= 3 && M <= 3){
        return {};
    }

    vector<vector<int>> ans;
    for(int a = 0; a < N; a++){
        vector<int> vec;
        for(int b = 0; b < M; b++){
            vec.push_back(a * M + b + 1);
        }

        if(a % 2 == 1){
            reverse(vec.begin(), vec.end());
        }
        vector<int> front_half, back_half;
        for(int b = 0; b < (M + 1) / 2; b++){
            back_half.push_back(vec.back());
            vec.pop_back();
        }
        for(int b = 0; b < M / 2; b++){
            front_half.push_back(vec.back());
            vec.pop_back();
        }
        reverse(back_half.begin(), back_half.end());
        reverse(front_half.begin(), front_half.end());

        for(int b = 0; b < M / 2; b++){
            vec.push_back(back_half[b]);
            vec.push_back(front_half[b]);
        }
        if(M & 1){
            vec.push_back(back_half.back());
        }

        if(a % 2 == 1 && M % 2 == 1){
            reverse(vec.begin(), vec.end());
        }
        ans.push_back(vec);
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    bool swapped = false;
    if(M < N){
        swap(M, N);
        swapped = true;
    }

    vector<vector<int>> ans = test(N, M);
    if(ans.empty()){
        cout << "NO\n";
        return 0;
    } else {
        cout << "YES\n";
    }

    if(swapped){
        for(int b = 0; b < M; b++){
            for(int a = 0; a < N; a++){
                int x = ans[a][b] - 1;
                int vr = x / M;
                int vc = x % M;

                cout << vc * N + vr + 1 << "\t";
            }
            cout << "\n";
        }
    } else {
        for(int a = 0; a < N; a++){
            for(int b = 0; b < M; b++){
                cout << ans[a][b] << "\t";
            }
            cout << "\n";
        }
    }
}
