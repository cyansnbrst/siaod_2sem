#include <iostream>
#include <vector>

using namespace std;


// функция определения знака числа
int num_sign(int x) {
    int y;
    if (x > 0) {
        y = 0;
    }
    if (x < 0) {
        y = 1;
    }
    return y;
}

// массив оставшихся значений точек после создания треугольника
vector<vector<int> > setdiff(vector<vector<int> > &a, vector<vector<int> > &b, int N) {
    vector<vector<int> > diff;
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

    // присваиваем его координатам данные координаты по очереди
    while (N > 0) {  // до тех пор, пока существуют точки
        bool new_set = true;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    tri[0] = coord[i];
                    tri[1] = coord[j];
                    tri[2] = coord[k];

                    int tri_flag = 0; // смотрим, не лежат ли все оставшиеся точки внутри треугольника,
                    // так мы поймем, подходит он или нет

                    for (auto elem: setdiff(tri, coord,
                                            N)) { // рассматриваем каждую оставшуюся точку из множества
                        if (num_sign((tri[0][0] - elem[0]) * (tri[1][1] - tri[0][1]) -
                                     (tri[1][0] - tri[0][0]) * (tri[0][1] - elem[1])) ==
                            num_sign((tri[1][0] - elem[0]) * (tri[2][1] - tri[1][1]) -
                                     (tri[2][0] - tri[1][0]) * (tri[1][1] - elem[1])) ==
                            num_sign((tri[2][0] - elem[0]) * (tri[0][1] - tri[2][1]) -
                                     (tri[0][0] - tri[2][0]) * (tri[2][1] - elem[1]))) {
                            // если они одного знака - то точка лежит внутри треугольника, иначе не лежит
                            ++tri_flag;
                            break;
                        }
                    }

                    if (tri_flag == 0) {
                        // не нашлось ни одной точки внутри треугольника, значит он существует,
                        // выводим его координаты и удаляем их, чтобы найти оставшиеся треугольники
                        new_set = false;
                        coord = setdiff(tri, coord, N);
                        N -= 3;
                        cout << '(' << tri[0][0] << ", " << tri[0][1] << "), " <<
                             '(' << tri[1][0] << ", " << tri[1][1] << "), " <<
                             '(' << tri[2][0] << ", " << tri[2][1] << ')' << endl;
                    }
                }
                if(!new_set) break;
            }
            if(!new_set) break;
        }
    }
    return 0;
}

/*
для проверки:
9
6 7
8 9
5 4
1 1
2 2
2 3
1 2
5 6
3 8
 */