#include <bits/stdc++.h>
using namespace std;

void CalcPrefix(string pattern,vector<int>& pi) {
int len = pattern.length();

    int ptr =0 , i = 1;
    while (i < len){

        if(pattern[ptr] == pattern[i])
            pi[i++] = ++ptr;
       else
       {
           if(ptr == 0)
               pi[i++] = 0 ;
           else /// return to parent
               ptr = pi[ptr - 1];
        }
    }
}

 void KMP(string text , string pattern){
    int n = text.length();
    int m = pattern.length();
    if(m > n ){
        cout<< "Pattern not found\n";
    return ;
    }
    vector<int> pi(m, 0);
    CalcPrefix(pattern, pi);

    bool found = false;
     int i = 0, j = 0;
     while (i< n )
     {
         if (text[i] == pattern[j])
         {
             i++, j++;
             //match all the pattern
             if (j == m) {
                 cout << "The pattern occurs at " << i - m << endl;
                found = true;
             }
         }
         //does not match -> move to its parent
         else if(i < n && pattern[j] != text[i]){
             if (j > 0)
             j = pi[j - 1];
             else
                 i++;
         }
     }
     if(!found )
         cout<< "Pattern not found\n";
 }

int main() {
    pair<string, string > test[7]= {
            {"mississippi", "issip"},    //The pattern occurs at 5
            {"you","thankyou"},     //Pattern not found
            {"youAreGood", "you"},  //The pattern occurs at 0
            {"meatYouSoon", "you"},  //Pattern not found
            {"meatYouSoonYou","You"},//The pattern occurs at 4 ,The pattern occurs at 11
            {"thankyou", "think"},   //Pattern not found
            {"THANKYOU", "thank"}    //Pattern not found

    };

    for(auto it : test){
        KMP(it.first, it.second);
    }

    return 0;
}
