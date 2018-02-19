#include <bits/stdc++.h>
#include "../algorithms/sorting/merge_sort.hpp"
using namespace std;
int xrand(int n){
	random_device rand_dev;
	mt19937 generator(rand_dev());
	uniform_int_distribution<int>  distr(0, n - 1);
	return distr(generator);
}

bool comp(int a, int b) {return a <= b;}

int main(){
    vector<int> myvec, dummyvec;
    for(int i = 100; i > 0; i--){
        myvec.push_back(-13000 + xrand(26000));
    }
    //std::random_shuffle(myvec.begin(), myvec.end(), xrand);
    dummyvec = myvec;
    auto begin = chrono::high_resolution_clock::now();
    sort(dummyvec.begin(), dummyvec.end());
    auto end = chrono::high_resolution_clock::now();
    double duration = chrono::duration_cast<chrono::microseconds> (end - begin).count() * pow(10, -6);
    cout << duration << endl;

    begin = chrono::high_resolution_clock::now();
    dsa_implemented::merge_sort(myvec.begin(), myvec.end());
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds> (end - begin).count() * pow(10, -6);
    cout << duration << endl;
    /*for(auto v : myvec){
        cout << v << " ";
    }*/
    cout << ((myvec == dummyvec) ? "True" : "False");
    cout << endl;
}
