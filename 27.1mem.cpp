// array size and saving location dekhna hai
#include <bits/stdc++.h>
using namespace std;
int memoization(int a[], int index,int b[],int fi)//a me input vales hai answer b se aayega
{
    // recursons
    if (index == 0)
    {
        return a[0]; // coz i don't have any previos case of incluin or not includong it just have to include it alone
    }
    if (index == 1)
    {
        return max(a[0], a[1]); // agar 1 include ->0 th nhi l sakta and if nhi kiya to to sirf 0th le sakta hu
    }
    if (b[index]!=-1)//extra added
    {
        return b[index];
    }
    
    // recursons
    int c = a[index] + memoization(a, index - 2,b,fi); // including->add that and add the result fiven by i-2th aftter doinf tge same
    int d = memoization(a, index - 1,b,fi);            // not incl that index->i will ask i-1th to find it'sa nswe
    int minn=min(c,d);//exta added
    b[index]=minn;//extra added
    // samll calculation
    return max(c,d);//extra added
}
int main()
{
    int N;
    cout << "Enter size of the array" << endl;
    cin >> N;
    int *arr = new int[N];
    cout << "Enter array elements" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int *b=new int[N+1];
    for (int i = 0; i <= N; i++)
    {
        b[i]=-1;
    }
    
  int val=  memoization(arr, N,b,N);
    cout<<val<<endl;
    return 0;
}