#include<bits/stdc++.h>
using namespace std;

//NOTE: Use memoiztion to save time from exponential O(2^n) to O(length(s)*length(t))
//Dynamic Programming approach to the same will be added soon. Keep trying :)

int LCS(string s, string t, int l, int r){       //recursive function declared. takes the two strings to check
                                                //and l and r the iterators for the two strings respectively
    
    
    if(s[l]=='\0' || t[r]=='\0')      //base condition, i.e. if the "matching check" goes on till the end
        return 0;                     // and no match is found 


    else if(s[l]==t[r])             //if we find matching chars in both strings, we increment the iterators of
        return (1+LCS(s,t,l+1,r+1));    //both the strings to recursively check the string from the following positions


    else                        //in case, we do not get a match, nor have we reached the end of either string,
                                //then it means we need to compare the two string furthers from two progressive
                                //postions recursively. Thus we can compare the strings from the next postion of either
                                // string but to know which one yields the longest subsequence we take the max of 
                                //both comparisons :)
        return max(LCS(s,t,l+1,r),LCS(s,t,l,r+1));  
}

int main(void){
    string s="ecdgi";
    string t="abcdefghij";

    cout<<"Length of longest common subsequence is : "<<LCS(s,t,0,0);

    //answer is 4, because comparing s with t we see that the longest SUBSEQUENT(maintaining order) string
    //turn out to be "cdgi"
    
}