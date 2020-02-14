//Gearoids cpp function to check for a symmetrical word (palindrome)
#include <iostream>
#include <string>

using namespace std;

//Take a string and continually reduce as long as it has symmetrical letters
//When the symmetry is broken return false
//If the string is reduced to the point where symmetry is certain, return true
bool isPalindrome(string in){
    if(in[0] != in[in.length()-1]) 
        return false; //when two symmetric letters do not match
    else if(in.length()<2)
        return true; //when the string is too small for any more comparisons
    else
        return isPalindrome(in.substr(1,in.length()-2)); //if the letters matched but the string still has remaining comparisons
}

int main()
{
    //Two testcases, change to see others
    cout<<"racecar: ";
    cout<<isPalindrome("racecar");
    cout<<"\n";
    cout<<"rakecar: ";
    cout<<isPalindrome("rakecar");
    cout<<"\n";
    cout<<"Empty string: ";
    cout<<isPalindrome("");
    cout<<"\n";
    cout<<"1 : ";
    cout<<isPalindrome("1");
    cout<<"\n";
    return 0;
}
