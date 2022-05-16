#include <bits\stdc++.h>
//problem with my code-:
//1112->111 only considered 2 left out
//1112->111 ,2->11 1 ->but all possible is not obtained
//recursion qs helps us to find permutations qs easily.
/**
 * a-z==>1-25
 * BASE CASE->either divise drom 0th index aur last index and rest recursion will do
 * 1123
 * 1-123  11-23 two digt no will be greaer than 11 and less than 26
 * 1-23 12-3  2-3 23
 * 2-3 or 23  1-2  12   2-3 or 23
 * like this all combinationa
 * as ssomn as it becomes empty recursive calls end base cases called
 * arushi sharma->for solution
 * second approach
 * 1123->aabc/aaw/alc/kbc/kw
 * 1|123->output=empty
 * 123->recursion pe pass->output='1'=a=>isko har ek further ke saath append
 * ab a ko append kate hue saare print=>uske andar 12 ko append kate hue 123 pr overflow exit
 * second->1123=>output=""
 * 11|23=>output=k 
 * ab k ko append kate hue saare print=>fir 2 ko aapend kate hue saare=next 23 pr apped kate hue=>iske baad break
 * third->112->outflow exit
 * 4123=>check lagana padega start me k 41 ko letter se map kr paa rhe hai ya nhi
 */
int main(){
    
    return 0;
}