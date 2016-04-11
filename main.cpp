#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &A, int target) {
    if (A.size() == 0) {
        return -1;
    }

    int start = 0, end = A.size() - 1, mid = 0;
    while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[start] < A[mid]) {
            if (A[start] <= target && A[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        } else {
            if (A[mid] < target && target <= A[end]){
                start = mid;
            } else {
                end = mid;
            }
        }

        if (A[start] == target) {
            return start;
        }
        if (A[end] == target) {
            return end;
        }
        return -1;
    }

}


int main() {
    cout << "Hello, World!" << endl;
    vector<int> A = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int ret = search(A, target);

    cout<<ret;

    return 0;
}