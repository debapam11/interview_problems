//The Following problem is about printing all the possible permutations of a string, recursively.
//p.s. -> i was asked for the same in an interview of mine :)

#include<bits/stdc++.h>
using namespace std;

//the following function to print all permuation of the string s, takes the string itself, the starting index 
// as l, and the last index as n
void perm(string s, int l, int n){    
    if(l==n)    //base condition, if all permuatations have been made for the current string combination,
                //then print the current string representing one of the permutations
        cout<<s<<"\t";

    else{
        
        for(int i=l;i<=n;i++){
            swap(s[l],s[i]);    //swapping first element with corresponding elements and then recursively
            perm(s,l+1,n);      //finding permutations for the remaining string 
            swap(s[i],s[l]);    //backtracking to the previous state. Note: try without this line and see ;)
        }
    }
    
}

int main(){
    string s="abcd";        //input string to print all permutations of. Change the input string as per 
    int l=s.length()-1;     //your convenience.
    perm(s,0,l);            //function call to print all permutations separated by a space
    return 0;
}