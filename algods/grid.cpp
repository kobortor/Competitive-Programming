#include<bits/stdc++.h>

using namespace std;

template<class T>
struct Grid : vector<vector<T>> {
    Grid() {}
    Grid(int n, int m) : vector<vector<T>>(n, vector<T>(m)) {}
    Grid(int n, int m, const T &init) : vector<vector<T>>(n, vector<T>(m, init)) {}
    T& operator[](const pair<int, int> &p) {
        return ((vector<vector<T>>) (*this))[p.first][p.second];
    }

    template<class T2>
    bool contained(const pair<T2, T2> p) const {
        int n = this->size();
        if (0 <= p.first && p.first < n) {
            int m = ((vector<vector<T>>) (*this))[0].size();
            return 0 <= p.second && p.second < m;
        } else {
            return false;
        }
    }

    const static pair<T, T> steps[4];
    const static pair<T, T> diags[4];
};

template<class T>
const pair<T, T> Grid<T>::steps[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

template<class T>
const pair<T, T> Grid<T>::diags[4] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template<class T>
pair<T, T> operator+(const pair<T, T> &p1, const pair<T, T> &p2) {
    return make_pair(p1.first + p2.first, p1.second + p2.second);
}

template<class T>
pair<T, T> operator-(const pair<T, T> &p1, const pair<T, T> &p2) {
    return make_pair(p1.first - p2.first, p1.second - p2.second);
}

template<class T1, class T2>
pair<T2, T2> operator*(const T1 &t1, const pair<T2, T2> &p2) {
    // use the type of the pair so that 2 * (2.5, 3.14) works out
    // it is unlikely someone will actually do 2.5 * (3, 4)
    return make_pair(t1 * p2.first, t1 * p2.first);
}

template<class T>
T dot(const pair<T, T> p1, const pair<T, T> p2) {
    return p1.first * p2.first + p1.second * p2.second;
}

template<class T>
T cross(const pair<T, T> p1, const pair<T, T> p2) {
    return p1.first * p2.second - p1.second * p2.first;
}

