#include<bits/stdc++.h>

using namespace std;

void LinearSearch(int ara[],int n,int key)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(ara[i]==key)
        {
            cout << key << " found at position " << i << endl;
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        cout << key << " not found!" << endl;
    }
}

int BinarySearch(int ara[],int lo,int hi,int key)
{

    if(lo >= hi)
        return -1;
    else
    {
        int mid = (lo+hi) / 2;
        if(key == ara[mid])
             return mid;

        else if(key > ara[mid])
            return BinarySearch(ara,mid+1,hi,key);
        else
            return BinarySearch(ara,lo,mid,key);
    }
}

int main()
{
   srand(time(0));
    int n;
    clock_t t;
    int keys[5];
    double time_taken,time_taken_li=0.0,time_taken_bi=0.0;

    // Input the size of the array 10 100 200 500 1000 2000 5000 10000
    cin >> n;
    int arr[n];

    // Populating the array with random integers
    for(int i=0;i<n;i++)
    {
        arr[i] = rand();
    }


   // for(int i = 0;i<n;i++)
     //   cout << arr[i] << endl;

    // Populating the keys array with two of the Array elements and three random integers
   // keys[0] = arr[0];
    //keys[1] = arr[1];
    for(int i=0;i<5;i++)
    {
        keys[i] = rand();
    }

    // Sorting the array
    sort(arr,arr+n);
   // keys[4] = arr[n-1]+10;

    // Executing Linear Search for the five keys

    for(int i = 0;i<5;i++)
    {
        t = clock();
        LinearSearch(arr,n,keys[i]);
        t = clock()- t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        time_taken_li += time_taken;
    }


 //  cout << fixed << time_taken*1000.0/5.0 << setprecision(5) <<endl;
    cout << "Total time in executing Linear Search :" << time_taken_li*1e6 << endl;
  //  cout << time_taken / 5.0 << endl;

    //Executing Binary Search for the five keys

    for(int i = 0;i < 5 ; i++)
    {
        t = clock();
        int idx = BinarySearch(arr,0,n,keys[i]);
        if(idx>=0)
            cout << keys[i] << " found at position "  << idx << endl;
        else
            cout << keys[i] << " not found!" << endl;
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        time_taken_bi += time_taken;
    }

    //double time_taken_bi = ((double)t)/CLOCKS_PER_SEC;
    cout << "Total time in executing Binary Search :" << time_taken_bi*1e6 << endl;

}
