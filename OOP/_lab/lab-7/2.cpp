#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

vector<vector<int>> matrix = {{1, -2, 3}, {-4, 5, -6}, {7, -8, 9}};
int rows_without_negatives = 0;

mutex mtx;
condition_variable cv;

void replace_negatives() {
    unique_lock<mutex> lock(mtx);
    for (vector<int> row : matrix) {
        for (int elem : row) {
            if (elem < 0) {
                elem = elem * elem;
            }
        }
    }
    cv.notify_all();
}

void count_rows_without_negatives() {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock);
    for (vector<int> row : matrix) {
        bool has_negative = false;
        for (int elem : row) {
            if (elem < 0) {
                has_negative = true;
                break;
            }
        }
        if (!has_negative) {
            rows_without_negatives++;
        }
    }
}

int main() {
    thread t1(replace_negatives);
    thread t2(count_rows_without_negatives);

    t1.join();
    t2.join();

    cout << "Matrix after replacing negatives:\n";
    for (vector<int> row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    cout << "Number of rows without negatives: " << rows_without_negatives << endl;

    return 0;
}
