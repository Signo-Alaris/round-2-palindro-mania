/// <summary>Use to check if the first & last characters in a String are equal</summary>
/// <param name="strToCheck">String to be Examined</param name>
/// <returns>True if the first & last are equal, else False.</returns>
bool checkFirstLastCharsEqual(std::string strToCheck) {
    return (strToCheck[0] == strToCheck[strToCheck.length() - 1]) ? true : false;
}

/// <summary>Determines if the given string is a Palindrome.  Function operates Recursively</summary>
/// <param name="palinCheck">String to be Examined</param name>
/// <returns>1 if the string is a Palindrome, else 0.</returns>
int isPalindrome(std::string palinCheck) {
    if (palinCheck.length() < 2) {
        return 1;
    } else if (checkFirstLastCharsEqual(palinCheck)) {
        std::string nextPalinCheck = palinCheck.substr(1,(palinCheck.length() - 2));
        return isPalindrome(nextPalinCheck);
    } else return 0;
}