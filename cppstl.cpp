#include <bits/stdc++.h>
using namespace std;
/*
container, algorithm, iterators, functions 

*/

void explainPair() {
    // pair lies inside the utility library
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> p2 = {1, {3,4}};
    cout << p.first << " " << p2.second.second << " " << p2.second.first;

    pair<int, int> arr[] = { {1,2}, {2,5}, {5,1}};
    cout << arr[1].second;
}

void explainVector() {
    vector<int> v; // creates an empty container 
    v.push_back(1);
    v.emplace_back(2); // emplace_back is faster than push_back, tbough both do the same thing

    vector<pair<int, int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2); // curly braces in emplace_back can be omitted, it automatically assumes it to be a pair 

    vector<int> v(5, 100); // declares a vector with 5 values, all 5 instances of the value 100
    vector<int> v(5); // declares vector v with 5 -  0 values or garbage values, size can still be increased 

    vector<int> v1(5, 20); // with 5 instances of 20 
    vector<int> v2(v1); // creates another container with the same values - 5 instances of 20 

    // to access elements of a vector is similar to arrays 
    // v[0], v[1] or v.at(0), though at is not used very often 

    // iterators 
    vector<int>::iterator it = v.begin(); // points to the memory address not to the element itself 
    it++;
    cout << *(it) << " ";

    it = it + 2;
    cout << *(it) << " ";

    vector<int>:: iterator it = v.end(); // points to one location after the last element 
    vector<int>:: iterator it = v.rend(); // reverse ka end, so if vector is {10,20,30,40}, it points to one location after 10 (reverse)
    vector<int>:: iterator it = v.rbegin(); // reverse ka beginning the very first element i.e. 40 

    cout << v.back() << " "; // back points to the last element 
    
    // iterating through a vector - normal for loop - indexes 
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    // for each loop 
    for(auto it : v) {
        cout << it << " ";
    }
    auto a = 5; // data type automatically assigned based on the data 
    auto a = "ronit";

    // delete from a vector 
    v.erase(v.begin()+1); // deletes the element at index 1
    // you can also give start, end, but this should be given in such a manner that we give the end index to be the one after the element till which we want to delete [start, end)

}

int main() {
    

    return 0;
}