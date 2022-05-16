#include<bits\stdc++.h>
//order is also important
//base case is to get bc's subsequences
//and then append a with all
//second example-:abcd--->bcd ke saare find a appemd
int subsequences(string str,string output[]){
    if(str.length()==0){
        output[0]="";
        return 1;
    }
    int smallerOutputSize=subsequences(str.substr(1),output);//this is the biultin functio to create subsequences
    for (int i = 0; i < smallerOutputSize; i++)
    {
       output[i+smallerOutputSize]=str[0]+output[i];//subsequences me a append
    }
    return 2*smallerOutputSize;//totlal no of subsequences
    
}
int main(){
    string output[100];
    int outputSize=subsequences("abc",output);
    
    return 0;
}