#include "bits/stdc++.h"

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begn(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int MAXN = 4040;

int n; 
string S;
vector<string> of_length[MAXN];
string a[MAXN];
int supersequence_of[MAXN];

int dp[MAXN][MAXN];
int prv[MAXN][MAXN];
int is_ok[MAXN][MAXN];
int compared[MAXN];

bool is_subsequnce(string smaller, string larger) {

  int ptr = 0;
  for (char c : larger) {
    if (ptr < smaller.size() && smaller[ptr] == c) {
      ptr++;
    }
  }

  return (ptr == smaller.size());

}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  cin >> n;
  cin >> S;

  for (int i = 0; i < n; i++) {
    string foo; cin >> foo;
    of_length[foo.size()].push_back(foo);
  }

  int N = 0;
  for (int i = 0; i < MAXN; i++) {
    for (string s : of_length[i]) {
      N++;
      a[N] = s;
      if (!is_subsequnce(s, S)) {
        cout << "impossible\n";
        return 0;
      }
    }
    vector<string>().swap(of_length[i]);
  }

  // for (int i = 0; i <= N; i++) {
  //   cout << "string " << i << " is " << a[i] << endl;
  // }

  for (int i = 1; i <= N; i++) {
    supersequence_of[i] = supersequence_of[i - 1] + is_subsequnce(a[i - 1], a[i]);
  }

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = i + (i > 0); j < N; j++) {
      if (!dp[i][j]) continue;

      if (supersequence_of[j + 1] > supersequence_of[j]) {
        dp[i][j + 1] = 1;
        prv[i][j + 1] = i;
      }

      if (is_ok[i][j + 1] == 0) {
        if (supersequence_of[j + 1] - supersequence_of[i] == j + 1 - i) {
          is_ok[i][j + 1] = 1;
        }
        else {
          is_ok[i][j + 1] = (is_subsequnce(a[i], a[j + 1]) ? 1 : -1);
          assert(compared[j + 1] < 1);
          compared[j + 1]++;
        }
      }

      // cout << i << " -> " << j + 1 << " has value " << is_ok[i][j + 1] << endl;

      if (is_ok[i][j + 1] > 0) {
        dp[j][j + 1] = 1;
        prv[j][j + 1] = i;
      }

    }
  }

  for (int i = 0; i < N; i++) {
    if (dp[i][N]) {

      vector<string> path1, path2;

      int x1 = i, x2 = N;
      while (make_pair(x1, x2) != make_pair(0, 0)) {

        // cout << "at " << x1 << " " << x2 << endl;

        int pstate = prv[min(x1, x2)][max(x1, x2)];

        path2.push_back(a[x2]);
        if (pstate == x1) {
          x2--;
        }
        else {
          swap(path1, path2);
          swap(x1, x2);
          x1 = pstate;
        }

      }

      reverse(path1.begin(), path1.end());
      reverse(path2.begin(), path2.end());

      cout << path1.size() << " " << path2.size() << "\n";
      for (string ss : path1) {
        cout << ss << "\n";
      }
      for (string ss : path2) {
        cout << ss << "\n";
      }

      return 0;

    }
  }

  cout << "impossible\n";

}
