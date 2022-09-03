#include <bits/stdc++.h>
using namespace std;
int recursion(int a[],int index){
//base cases
if (index==0)
{
    return a[0];//coz i don't have any previos case of incluin or not includong it just have to include it alone
}
if (index==1)
{
    return max(a[0],a[1]);//agar 1 include ->0 th nhi l sakta and if nhi kiya to to sirf 0th le sakta hu

}
//recursons 
int c=a[index]+recursion(a,index-2);//including->add that and add the result fiven by i-2th aftter doinf tge same
int d=recursion(a,index-1);//not incl that index->i will ask i-1th to find it'sa nswe

//samll calculation
return max(c,d);
}

int main()
{
    int N;
    cout<< "Enter size of array" <<endl;
    cin>>N;
    int *arr=new int[N];
    cout<< "Enter the values of array"<<endl;
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
  int result=  recursion(arr,N);
    cout<<"Max sum till"<<"\t"<<N<<"\t"<<"is "<<"\t"<<result<<endl;
    
    return 0;
}