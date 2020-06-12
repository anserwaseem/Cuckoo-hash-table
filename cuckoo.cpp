#include "cuckoo.h"


int cuckoo::hashIndex1(int key)
{
    int index = (static_cast<int>(round(key)) % (total_capacity));//hash function 1
    
    if(index >= (total_capacity/2))//if calculated index gets more than half of size, then subtract size/2
        index -= (total_capacity/2);
    
    return index;
}

int cuckoo::hashIndex2(int key)
{
    int index = ( static_cast<int>(round(key))/total_capacity % (total_capacity) );//hash function 2
    
    if(index < (total_capacity/2))//if calculated index gets lesser than half of size, then add size/2
        index += (total_capacity/2);
    
    return index;
}

//if whoCalled = 0, it means normal insertion is taking place, else if = 1, it means rehashing is taking place.
void cuckoo::insertHelper(int key, vector<int> &Arr, bool whoCalled)
{
    int index1 = hashIndex1(key);
    int index2 = hashIndex2(key);

    if(Arr[index1]==key || Arr[index2]==key)//if key is already placed, do nothing
        return;

    if(Arr[index1]==-1)//if free, place the key
    {
        Arr.at(index1)=key;

        if(whoCalled == 0)//run if it's normal insertion
        {
            cout<<key<<" inserted.\n";
            filled_bins++;
        }
        return;
    }

    else if(Arr[index2]==-1)//if free, place the key
    {
        Arr.at(index2)=key;

        if(whoCalled == 0)//run if it's normal insertion
        {
            cout<<key<<" inserted.\n";
            filled_bins++;
        }
        return;
    }
    else//if both indices are not free, then try swapping for at most maxTries times
        for(int i=0; i<maxTries; i++)
        {
            swap(key, Arr[index1]);

            if(key==-1)//if true, it means there's a vacant space
            {
                if(whoCalled == 0)//run if it's normal insertion
                {
                    cout<<key<<" inserted.\n";
                    filled_bins++;
                }
                return;
            }

            swap(key, Arr[index2]);

            if(key==-1)//if true, it means there's a vacant space
            {
                if(whoCalled == 0)//run if it's normal insertion
                {
                    cout<<key<<" inserted.\n";
                    filled_bins++;
                }
                return;
            }
        }

    rehash(2.0);
    insertHelper(key, Arr, 0);
}

void cuckoo::rehash(double times)
{
    vector<int> new_arr;//make a new integer array of double the size

    int old_capacity = total_capacity;
    int new_capacity = (double)(total_capacity) * times;
    
    total_capacity = new_capacity;

    for(int i=0; i<new_capacity; i++)//initializng every index of new array with -1
        new_arr.push_back(-1);
    
    for(int i=0; i<old_capacity; i++)//zero to old capacity
    {
        if(arr[i] != -1)//if current index is not empty
            insertHelper(arr[i], new_arr, 1);
    }

    this->arr = new_arr;
}


cuckoo::cuckoo()//default constructor
{
    for(int i=0; i<total_capacity; i++)
        arr.push_back(-1);//initializing every index with -1
}

int cuckoo::getSize()
{
    return filled_bins;
}

int cuckoo::capacity()
{
    return total_capacity;
}

float cuckoo::loadFactor()
{
    return ( ((float)(filled_bins)) / ((float)(arr.size())) );
}

void cuckoo::insert(int key)
{
    if(search(key))//if key already exists, return
    {
        cout<<key<<" is already present.\n";
        return;
    }
    
    insertHelper(key, this->arr, 0);

    //if load factor >= 0.75, rehash
    if( ((float)(filled_bins) / (float)(total_capacity)) >= 0.75)
        rehash(2.0);
}

bool cuckoo::search(int key)
{
    int index1 = hashIndex1(key);
    int index2 = hashIndex2(key);

    if(arr[index1] == key || arr[index2] == key)
        return true;

    return false;
}

void cuckoo::Delete(int key)
{
    if(!search(key))
    {
        cout<<key<<" not found.\n";
        return;
    }

    int index1 = hashIndex1(key);
    int index2 = hashIndex2(key);

    if(arr[index1] == key)
        arr[index1] = -1;//re-initialize
    else if(arr[index2] == key)
        arr[index2] = -1;//re-initialize
    
    cout<<key<<" deleted.\n";
    --filled_bins;

    if( (float)(filled_bins) / (float)(total_capacity) < 0.25 )
        rehash(0.5);
}

void cuckoo::print()
{
    for(int i=0; i<total_capacity; i++)
        if(arr[i] != -1)
            cout<<"Key: "<<arr[i]<<" at index "<<i<<endl;
    cout<<endl;
}

cuckoo::~cuckoo() {}