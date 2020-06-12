#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<stdexcept>
using namespace std;

class cuckoo
{
    vector<int> arr;
    int filled_bins = 0;//filled capacity
    int total_capacity = 2;
    int maxTries = 5;//maximum times, the swapping is allowed to search for the vacant space
    int hashIndex1(int key);//calculate and return index for first part so that items can be hashed
    int hashIndex2(int key);//calculate and return index for second part so that items can be hashed
    void insertHelper(int key, vector<int> &Arr, bool whoCalled);//if whoCalled = 0, it means normal insertion is taking place, else if = 1, it means rehashing is taking place.
    void rehash(double times);//rehash in accordance with the load factor
public:
    cuckoo();
    int getSize();//return s current size of the array
    int capacity();//returns total capacity of the array
    float loadFactor();//load factor = n/k, where 'n' is the number of entries occupied in the hash table and 'k' is the number of buckets.
    void insert(int key);//inserts the key
    bool search(int key);//return true if key is found
    void Delete(int key);//deletes teh key
    void print();//prints all keys at their current indeces in the array
    ~cuckoo();
};