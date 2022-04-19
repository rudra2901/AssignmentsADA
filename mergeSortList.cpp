#include<bits/stdc++.h>
 
#define inp(a, n) for(int i = 0; i < n; i++) cin>>a[i];
#define show(a, n) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
 
using namespace std;

int merge(vector<int>  &a,int i, int j, vector<int> &link) {
    int head;
    int *ptr = &head;

    while((i != -1) && (j != -1)) {
        if(a[i] <= a[j]) {
            *ptr = i;
            ptr = &link[i];
            i = *ptr;
        }
        else {
            *ptr = j;
            ptr = &link[j];
            j = *ptr;
        }
    }
    if(i == -1)
        *ptr = j;
    else
        *ptr = i;

    return head;
}

int mergeSort(vector<int>  &a,int l, int r, vector<int> &link) {
    if(l == r)
        return l;
    
    else if(r - l == 1) {
        link[l] = -1;
        return l;
    }
    else if(r - l == 2) {
        if(a[l] > a[l+1]) {
            link[l+1] = l;
            link[l] = -1;
            return l+1;
        } 
        else {
            link[l] = l+1;
            link[l+1] = -1;
            return l;
        }
    }

    else {
        int mid = (l + r)/2;
        int i = mergeSort(a, l, mid, link);
        int j = mergeSort(a, mid, r, link);

        return merge(a, i, j, link);
    }
}

void showArr(vector<int> &a, vector<int> &link, int n, int start) {
    
    do {
        cout << a[start] << " ";
        start = link[start];
    } while (start != -1);
    cout<<"\n";
}

int main() {
    FILEIO

    int t;
    cin>>t;
    int i = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n), link(n, 0);
        inp(arr, n);

        int start = mergeSort(arr, 0, n, link);

        cout<<"Case "<<i<<" : \n";
        i++;

        showArr(arr, link, n, start);
    }

    return 0;
}