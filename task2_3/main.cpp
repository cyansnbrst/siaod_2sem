#include <iostream>
#include <vector>

using namespace std;

// массив оставшихся значений точек после создания треугольника
vector<vector<int> > setdiff(vector<vector<int> > &a, vector<vector<int> > &b, int N) {
    vector<vector<int> > diff(N - 3, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        int flag = 0;
        for (int j = 0; j < 3; ++j) {
            if (b[i] == a[j]) {
                ++flag;
            }
        }
        if (flag == 0) {
            diff.push_back(b[i]);
        }
    }
    return diff;
}

int main() {

    // ввод N
    int N;
    cin >> N;

    // задаем массив с координатами, заполняем его
    vector<vector<int> > coord(N, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> coord[i][j];
        }
    }

    // создаем массив временного найденного треугольника
    vector<vector<int> > tri(3, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                tri[0] = coord[i];
                tri[1] = coord[j];
                tri[2] = coord[k];
                for (auto elem: setdiff(tri, coord, N)) {
                    if ((tri[0][0] - elem[0]) * (tri[1][1] - tri[0][1]) - (tri[1][0] - tri[0][0]) * (tri[0][1] - elem[1]) &&
                        (tri[1][0] - elem[0]) * (tri[2][1] - tri[1][1]) - (tri[2][0] - tri[1][0]) * (tri[1][1] - elem[1]) &&
                        (tri[2][0] - elem[0]) * (tri[0][1] - tri[2][1]) - (tri[0][0] - tri[2][0]) * (tri[2][1] - elem[1])
                }
            }
        }
    }
    return 0;
}
