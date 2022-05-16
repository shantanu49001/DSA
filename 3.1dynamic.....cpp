#include<bits/stdc++.h>//it includes all hearder files of gcc
int main(){
    int *p=new int;//heap me int memory p point karega
    *p=10;
    printf("%d",*p);
    double *pd=new double;
    char *c=new char;
    
    printf("Enyer no of elements\n");
    int n;//stack me strored hai
    scanf("%d",&n);
    int *pa = new int[n]; //heap me integer array store hua hai
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&pa[i]);//poitner aaray ke elements store
            //pouner array pointerse bana hai to hume ointer hi store krna padega
    }
    printf("Array accepted\n");
    printf("Now printing max value\n");
    int max=*pa;//first elemnet ki vaue ko max man lo
    printf("%d\n",max);
    for (int i = 1; i < n; i++)
    {
        if(max<pa[i]){
        max=(pa[i]);//max int hai to usme sirf int store higa
        }
    }
    printf("%d",max);
    delete p;//ppiter isn't deleted just the memory block which it was pointing to in heap has been deleted
    delete pa;
    //p and pa pointer can again be used
    return 0;
}
//*pa--> pa[]-->both are same
//static mem-->scope khatam -->memory khatam
//dyanmic-->we must indicate that now release that memeory