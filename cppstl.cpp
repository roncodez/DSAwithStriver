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

    //insert function 
    vector<int>v(2, 100); // {100, 100} - read as 2 instances of 100
    v.insert(v.begin(), 300); // {300, 100, 100}
    v.insert(v.begin()+1, 2, 10); // {300, 10, 10, 100, 100} read as at posn begin()+1, insert 2 instances of 10

    vector<int> copy(2, 50); // {50, 50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}
    cout << v.size(); // gives the number of elements in the vector 
    v.pop_back(); // pops out/ removes the last element 

    // v1 = {10, 20}
    // v2 = {30, 40}
    v1.swap(v2); // v1 = {30, 40} and v2 = {10, 20}`

    v.clear(); // trims the vector down to an empty vector 
    cout << v.empty(); // returns true or false based on whether the vector is empty or not 
}

// insert operation on a vector is much costlier than push front or insert into a list 
// for a list a doubly linked list is maintained, whereas for a vector a singly linked list is maintained 
void explainList() {
    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}

    ls.push_front(5); // {5,2,4}
    ls.emplace_front(); // {0,5,2,4}

    // rest functions same as vector 
    // begin, end, rbegin, rend, clear, insert, size, swap 
}

void explainDeque() {
    deque<int>dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1,2}
    dq.push_front(4); // {4,1,2}
    dq.emplace_front(3); // {3,4,1,2}

    dq.pop_back(); // {3,4,1}
    dq.pop_front(); // {4,1}

    dq.back(); // returns the last element

    dq.front(); // returns the first element

    // rest functions are same as vector 
    // begin, end, rbegin, rend, clear, insert, size, swap
}

// Stack - LIFO 
// cannot do indexing with stacks 
// only 3 main functions with stack - push, pop, top - O(1) constant time complexity
void explainStack() {
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {1,2}
    st.push(3);
    st.push(3); // {1,2,3,3}
    st.emplace(5); // {1,2,3,3,5}

    cout << st.top(); // prints 5 - just tell me what is at the top
    // Note. st[2] is invalid 
    st.pop(); // {1,2,3,3} - delete 

    cout<<st.top();
    cout << st.size();
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

// Queue - FIFO - First In First Out - all operations happening in constant time 
void explainQueue() {
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5;

    cout << q.back(); // 9

    // q is now {1,2,9}
    cout << q.front(); // 1
    q.pop(); // {2,9}
    cout << q.front(); // 2

    // size, swap, empty same as stack
}

// As the name suggest priority queue - the one who has the largest value stays at the top
// largest integer, largest char (ASCII), string (lexicographically the largest string stays at the top)
void explainPQ() {
    priority_queue<int> pq;
    pq.push(5); // {5}
    pq.push(2); // {2,5}
    pq.push(8); // {2,5,8}
    pq.emplace(10); // {2,5,8,10}
    //internally a tree data structure is maintained 
    cout << pq.top(); // 10
    pq.pop(); // {2,5,8}	    

    cout << pq.top(); // 8
    // the above is known as a Max-heap 

    //size swap empty function same as others 

    // Minimum heap - the smallest element at the top 
    priority_queue<int, vector<int>, greater<int>> pq1; // this is the syntax for a min heap
    pq1.push(5);
    pq1.push(2);
    pq1.push(8);
    pq1.emplace(10);

    cout << pq.top(); // 2

    /*
    push/ pop - O(log n)
    top - O(1)    
    */
}

// Set - sorted order and unique elements - tree is maintained  
void explainSet() {
    // all operations in log n complexity 
    set<int> st;
    st.insert(1); // {1}
    st.emplace(2); // {1,2}
    st.insert(2); // {1,2}
    st.insert(4); // {1,2,4}
    st.insert(3); // {1,2,3,4}

    // Functionality of insert in vector can be used, that only increases efficiency

    //begin(), end(), rbegin(), rend(), clear(), insert(), size(), swap() are same as those above 

    auto it = st.find(3); // returns an iterator to the element if it exists, else returns end() - points to the memory address 

    auto it = st.find(6);

    st.erase(5); // {1,2,3,4} - erases 5 - takes logarithmic time 

    int cnt = st.count(1);

    auto it = st.find(3);
    st.erase(it); 
    /*
    erase can work in 2 ways -> 1. take in the element to be deleted 2. take in the iterator/ memory location to the element to be deleted
    */
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);

    // lower_bound() and upper_bound() function works in the same way as in vector it does 

    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);
}

void explainMultiSet() {
    // Everything is same as set, only difference is that duplicate elements are allowed, only sorted not unique 
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); // {1,1,1}

    ms.erase(1); // all occurences of 1 erased 

    int cnt = ms.count(1);

    // only a single 1 is erased 
    ms.erase(ms.find(1));

    ms.erase(ms.find(1), ms.find(1)+2);
    // rest all functions same as set 
}

// Unordered set - Unique characters, NOT Sorted - all operations in O(1)
// worst case - O(n) linear time 
void explainUSet() {
    unordered_set<int> st;
    /*
    lower_bound and upper_bound function does not work, rest all functions are same as above, it does not 
    store in any particular order, it has better complexity than set in most cases, 
    except when collision happens
    */
}

// Map 
// key value pair 
// keys unique, values can be duplicated 
void explainMap() {
    map<int, int> mpp;
    map<int, pair<int, int>> mpp;
    map<pair<int, int>, int> mpp;

    mpp[1] = 2;
    mpp.emplace({3,1}); 

    mpp.insert({2, 4});

    mpp[{2,3}] = 10;

    for(auto it: mpp) {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5];

    auto it = mpp.find(3);
    cout << *(it).second;
    
    auto it = mpp.find(5);
    // sorted order of KEY not Values 

    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty are same as above 
}

void explainMultiMap() {
    // everything same as map, only it can store multiple keys 
    // only mpp[key] cannot be used here
}

void explainUnorderedMap() {
    // same as set and unordered set ka difference 
}

// ALL CONTAINERS DONE 

// Algorithms 
bool comp(pair<int, int>p1, pair<int, int> p2) {
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // else they are same 
    if(p1.first>p2.first) return true;
    return false; 
}
// in the comparator based on the condition, internal swapping is taking place.

void explainExtra() {
    sort(a, a+n); // array iterator pointers 
    sort(v.begin(), v.end()); // sorting a vector 

    sort(a+2, a+4);
    sort(a, a+n, greater<int>); // sort in descending order - comparator 

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element 
    // if second element is same, 
    // then sort it according to first element but in descending order 

    sort(a, a+n, comp); // self-written comparator 

    int num = 7;
    int cnt = __builtin_popcount(num); // to print the number of set bits of a particular number in binary 

    long long num = 1676767676;
    int cnt = __builtin_popcountll(num);

    string s = "123";
    sort(s.begin(), s.end());

    do {
        cout << s << endl;
    } while(next_permutation(s.begin(), s.end())); // to print all the permutations of a string 

    int maxi = *max_element(a, a+n); // to find the maximum element 
}

int main() {
    

    return 0;
}