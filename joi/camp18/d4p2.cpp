#include <bits/stdc++.h>
#include "library.h"
using namespace std;

const int MAXN = 205;

void Solve(int N) {
    if(N == 1){
        Answer({1});
        return;
    }

    int cur = -1;
    for(int a = 1; a <= N; a++){
        vector<int> vec(N, 1);
        vec[a - 1] = 0;
        if(Query(vec) == 1){
            cur = a;
            break;
        }
    }

    vector<int> remain;
    for(int a = 1; a <= N; a++){
        if(a != cur){
            remain.push_back(a);
        }
    }

    vector<int> ans;
    ans.push_back(cur);

    for(int a = 2; a <= N; a++){
        vector<int> tmp = remain;
        while((int)tmp.size() > 1){
            vector<int> vec(N, 0);
            int mid = (tmp.size() + 1) / 2;
            for(int a = 0; a < mid; a++){
                vec[tmp[a] - 1] = true;
            }

            int q1 = Query(vec);
            vec[cur - 1] = true;
            int q2 = Query(vec);

            if(q2 <= q1){
                tmp.erase(tmp.begin() + mid, tmp.end());
            } else {
                tmp.erase(tmp.begin(), tmp.begin() + mid);
            }
        }

        int nxt = tmp[0];
        ans.push_back(nxt);
        cur = nxt;

        remain.erase(find(remain.begin(), remain.end(), nxt));
    }
    Answer(ans);
}
