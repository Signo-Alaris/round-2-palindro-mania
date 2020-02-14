/*
CDRom
Used http://www.palindromelist.net/ for pallindrome examples.
*/

#include <stdio.h>  //ios
#include <stdlib.h> //malloc
#include <string.h> //strlen
#include <ctype.h>  //isalnum

#define RECURSIVE 1

#if RECURSIVE
int isPallindrome(const char* _str, unsigned int _length, unsigned int _pos)
{
	if (_pos >= _length / 2) // If current iteration is at halfway point
		return 1;

	if (_str[_pos] == _str[_length - _pos - 1]) // If pallindrome so far, keep going
		return isPallindrome(_str, _length,_pos + 1);

	else // No longer pallindrome, return false
		return 0;
}
#endif // RECURSIVE

int main(int argc, char** argv)
{
	if (argc <= 1 || strlen(argv[1]) < 1 || argc>2)
	{
		printf("Please provide a single valid string with length of 1.\n");
		return 0;
	}

// STRING CLENSING
	// Count total alpha numeric characters
	char* t;
	int count = 0;	
	for (t = argv[1]; *t != '\0'; t++)
	{
		if(isalnum(*t))
	 		count++;
	}
	count++; // +1 for null string terminator

	// Create appropriatly sized char buffer on the heap
	char* buff = (char*)malloc(count * sizeof(char));

	// Fill new clensed buffer, starting index 0
	count = 0;	
	for (t = argv[1]; *t != '\0'; t++)
	{
		if(isalnum(*t))
	 	{		
			buff[count] = tolower(*t);
			count++;		
		}
	}	
	// Add null string terminator
	buff[count] = '\0';	
// STRING CLENSING END

   int result;
#if RECURSIVE	
    result = isPallindrome(buff, count, 0);
#else
// Iterative attempt
	result = 1;
	unsigned int i = 0;
	while(i < (count/2) && result)
	{
		if(buff[i] == buff[count - i - 1])
		{
			i++;
		}
		else
		{
			result = 0;
			break;
		}
	}
#endif // RECURSIVE
	printf("\nBefore:\n'%s'\n", argv[1]);
	printf("\nAfter:\n'%s'\n\nisPallindrome =  %d\n", buff, result);

	// delete malloc(ed) buffer
	free(buff);
	
	return 0;
}