#include <bits/stdc++.h>

#define inp(a, n) for(int i = 0; i < n; i++) cin>>a[i];
#define show(a, n) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

using namespace std;

void swap (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//Partition with middle of three elements
int medianOf3(vector<int> &arr, int l, int r) { 
    int mid = (l + r) / 2;
    if (arr[mid] < arr[l]) 
        swap(arr[mid], arr[l]);
    if (arr[r] < arr[l]) 
        swap(arr[r], arr[l]);
    if (arr[mid] > arr[r]) 
        swap(arr[mid], arr[r]);
    
    swap(arr[mid], arr[r - 1]); 
    return arr[r - 1];
}

//To sort smaller sized arrays
void smallSort(vector<int> &arr, int l, int r) {
    int size = r - l + 1; 
    if (size <= 1)
        return;
        
    if (size == 2) {
        if (arr[r] < arr[l]) 
            swap(arr[l], arr[r]);
        return; 
    }
    else {
        if (arr[r - 1] < arr[l])
            swap(arr[r - 1], arr[l]); 
        if (arr[r] < arr[l])
            swap(arr[r], arr[l]); 
        if (arr[r - 1] > arr[r])
            swap(arr[r - 1], arr[r]);
    } 
}

int partition(vector<int> &a, int l, int r, int pivot) {
    int i = l+1, j = r-2;

    while(i < j) {
        while(a[i] < pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if (i < j)
            swap(a[i], a[j]);
    }
    
    swap(a[i], a[r-1]);
    return i;
}

void quickSort(vector<int> &a, int l, int r) {

    if(r-l < 3)
        smallSort(a, l, r);

    if(l < r) {

        int pivot = medianOf3(a, l, r);
        int part = partition(a, l, r, pivot);
        quickSort(a, l, part-1);
        quickSort(a, part+1, r);
    }
}
int main() {

    FILEIO

    int t;
    cin>>t;
    int i = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        inp(v,n)

        quickSort(v, 0, n-1);
        cout<<"Case "<<i<<" : ";
        i++;
        show(v, n);
        cout<<"\n";
    }
}