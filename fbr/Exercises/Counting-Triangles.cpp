#include <bits/stdc++.h>

using namespace std;

struct sides {
    long long a;
    long long b;
    long long c;

    void self_sort() {
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
    }
};

bool operator==(const sides &s1, const sides &s2) {
    return s1.a == s2.a && s1.b == s2.b && s1.c == s2.c;
}

bool operator<(const sides &s1, const sides &s2) {
    if (s1.a != s2.a) return s1.a < s2.a;
    if (s1.b != s2.b) return s1.b < s2.b;
    return s1.c < s2.c;
}

int countDistinctTriangles(vector <sides> arr) {
    for (sides &s : arr) s.self_sort();

    sort(arr.begin(), arr.end());

    return unique(arr.begin(), arr.end()) - arr.begin();
}
