#include <stdio.h>
#include <string>


bool IsPalindrome(const char* input, std::size_t index = 0)
{
    if(std::tolower(input[index]) != std::tolower(input[strlen(input) - 1 - index]))
    {
        return false;
    }
    if(index < (strlen(input) / 2))
    {
        IsPalindrome(input, ++index);
    }
    else
    {
        return true;
    }
}


bool IsPalindrome(std::string& input, std::size_t index = 0)
{
    if(std::tolower(input[index]) != std::tolower(input[input.length() - 1 - index]))
    {
        return false;
    }
    if(index < (input.length() / 2))
    {
        IsPalindrome(input, ++index);
    }
    else
    {
        return true;
    }
}


int main()
{
    std::string const InputStrings[] =
    {
        "azba"
        , "."
        , "    "
        , "a"
        , "1"
        , "Aba"
        , "b"
        , "cH"
        , "zaa..aaZ"
        , "35231"
        , "&&^$^"
    };

    printf("----------\n\nconst char*\n\n----------\n\n");
    for(std::string input : InputStrings)
    {
        printf("Input: %s\n%s\n\n", input.c_str(), (IsPalindrome(input.c_str()) ? "true" : "false"));
    }

    printf("----------\n\nstd::string\n\n----------\n\n");
    for(std::string input : InputStrings)
    {
        printf("Input: %s\n%s\n\n", input.c_str(), (IsPalindrome(input) ? "true" : "false"));
    }
    return 0;
}