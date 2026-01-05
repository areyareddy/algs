// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
int fill_random(vector<int>& lis) {
    for (int i = 0; i < 20; i++) {
        lis.push_back(rand()%100000-50000+1);
    }
    return 0; 
}

int print_list(vector<int> new_list) {
    int size_new_list = new_list.size();
    for (int i = 0; i < size_new_list; i++) {
        cout << new_list[i] << " "; 
    }
    return 0; 
}

// SET AMOUNT OF BITS AT A TIME HERE

int bits_at_a_time = 8;
// must be a factor of 32
// don't set it to exactly 32 unless you wanna allocate 4 billion buckets into your RAM

vector<int> sorter(vector<int> list) {
    int size = list.size();
    vector<int> final_list; 
    vector<vector<int>> buckets(pow(2, bits_at_a_time));
    for (int bit_shift = 0; bit_shift < 32/bits_at_a_time; bit_shift++) {
        for (int i = 0; i < size; i++) {
            int num = list[i];
            // num ^ (32 ones bit shifted 31 = 1 and 31 zeroes).  Taking xor we get something that flips the 1st bit. 
            int key = num^(1u << 31);
            // we check in blocks of bits_at_a_time, using & (11111...)to read bits
            buckets[((key >> bits_at_a_time*bit_shift) & ((1 << bits_at_a_time) - 1))].push_back(num); 
        }
        // now read the buckets into final_list
        int size_buckets = buckets.size();
        for (int bucket_index = 0; bucket_index < size_buckets; bucket_index++) {
            int bucket_size = buckets[bucket_index].size();
            for (int bucket_element_index = 0; bucket_element_index < bucket_size; bucket_element_index++) {
                final_list.push_back(buckets[bucket_index][bucket_element_index]);
            }
        }
        list = final_list; 
        // clear the stuff in the buckets, but don't throw away the buckets themselves
        for (auto &b : buckets) b.clear();
        final_list.clear();
    }
    return list;  
   
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
    vector<int> sorted_list = sorter(lis);
    print_list(sorted_list);
    return 0;
}
