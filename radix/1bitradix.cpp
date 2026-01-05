// 1 bit radix sort for 32 bit signed ints 
#include <bits/stdc++.h>

using namespace std;
int fill_random(vector<int>& lis) {
    for (int i = 0; i < 20; i++) {
        lis.push_back(rand()%100000-50000+1);
    }
    return 0; 
}

vector<int> sorter(vector<int> list) {
    int size = list.size();
    vector<int> final_list; 
    vector<int> bucket1;
    vector<int> bucket0; 
    for (int bit_shift = 0; bit_shift < 31; bit_shift++) {
        for (int i = 0; i < size; i++) {
            // we check if the xth before last digit is a 1. so starts at 0 (last digit) and proceeds to 31(first digit) 
            if ((list[i] >> bit_shift) & 1) {
                bucket1.push_back(list[i]);
            }
            else {
                bucket0.push_back(list[i]);
            }
        }
        int size_0 = bucket0.size();
        int size_1 = bucket1.size();
        for (int bucket_index = 0; bucket_index < size_0; bucket_index++) {
            final_list.push_back(bucket0[bucket_index]);
        }
        for (int bucket_index = 0; bucket_index < size_1; bucket_index++) {
            final_list.push_back(bucket1[bucket_index]);
        }
        list = final_list; 
        bucket0.clear();
        bucket1.clear();
        final_list.clear();
    }
    // do the exact same thing for the sign bit except now 0 = positive (greater)
    // so flip the 0-1 ordering, and set bit_shift hard at 32. 
    for (int i = 0; i < size; i++) {
        // we check if the xth before last digit is a 1. so starts at 0 (last digit) and proceeds to 31(first digit) 
        if ((list[i] >> 31) & 1) {
            bucket0.push_back(list[i]);
        }
        else {
            bucket1.push_back(list[i]);
        }
    }
    int size_0 = bucket0.size();
    int size_1 = bucket1.size();
    for (int bucket_index = 0; bucket_index < size_0; bucket_index++) {
        final_list.push_back(bucket0[bucket_index]);
    }
    for (int bucket_index = 0; bucket_index < size_1; bucket_index++) {
        final_list.push_back(bucket1[bucket_index]);
    }
    return final_list; 
}

int main() {
    bool read_from_input = true; 
    vector<int> lis;
    if (read_from_input) {
        int input_element;
        while (cin >> input_element) {
            lis.push_back(input_element); 
        }
    }
    else {
        fill_random(lis);
    }
    vector<int> new_list = sorter(lis);
    int size_new_list = new_list.size();
    for (int i = 0; i < size_new_list; i++) {
        cout << new_list[i] << " "; 
    }
    return 0;
}
