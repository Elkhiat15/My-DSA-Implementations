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
    for (int i = 0, j = 0; i < n; i++)
     {
         if (text[i] == pattern[j])
         {
             //match all the pattern
             if (++j == m) {
                 cout << "The pattern occurs at " << i - j + 1 << endl;
                found = true;
             }
         }
         //does not match -> move to its parent
         else if (j > 0)
         {
             j = pi[j];
             i--;
         }
     }
     if(!found )
         cout<< "Pattern not found\n";
 }

int main() {
    pair<string, string > test[7]= {
            {"thankyou", "you"},    //The pattern occurs at 5
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