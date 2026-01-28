#include<iostream>
#include<vector>

using namespace std;

// i) Recursive merge sort
vector<double> merge(const vector<double>& left, const vector<double>& right) {
    vector<double> result;
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }
    
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }
    
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }
    
    return result;
}

vector<double> merge_sort_recursive(vector<double> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    
    size_t mid = arr.size() / 2;
    vector<double> left_array;
    vector<double> right_array;
    
    for (size_t i = 0; i < mid; i++) {
        left_array.push_back(arr[i]);
    }
    for (size_t i = mid; i < arr.size(); i++) {
        right_array.push_back(arr[i]);
    }
    
    left_array = merge_sort_recursive(left_array);
    right_array = merge_sort_recursive(right_array);
    
    return merge(left_array, right_array);
}

// ii) Non-Recursive merge sort
void merge_iterative(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> L(n1);
    vector<double> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_iterative(vector<double>& arr) {
    int n = arr.size();
    for (int curr_size = 1; curr_size < n; curr_size = curr_size * 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            
            merge_iterative(arr, left_start, mid, right_end);
        }
    }
}

int main() {
    vector<double> arr = {3, 7, 6, -10, 15, 23.5, 55, -13};
    
    vector<double> arr_recursive = arr;
    
    vector<double> sorted_recursive = merge_sort_recursive(arr_recursive);
    
    cout << "Sorted Array (Recursive): ";
    for (double num : sorted_recursive) {
        cout << num << " ";
    }
    cout << endl;
    
    merge_sort_iterative(arr);
    
    cout << "Sorted Array (Iterative): ";
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}