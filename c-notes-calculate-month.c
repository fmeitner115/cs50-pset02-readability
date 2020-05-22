/*
Topics: Strings, pointers
Program that returns the month as a string after being given a number between 1 and 12

Terminology
psz = (p)ointer to (s)tring, (z)ero terminated
strncpy
char *strncpy(char *dest, const char *src, size_t n)
dest: the pointer to the destination array where the content is to be copied
src: the string to be copied
n: the number of characters to be copied from source

%c denotes a Character
%s denotes a String
printf("Character = %c\n", ch);	// %c accepts the variable, not its address
printf("String = %s\n", s);	// %s accepts char* (i.e., the address of the char array
*/
#include <stdio.h>
// For strncpy
#include <string.h>

void calculateMonth(int month, char* pszMonth, int buffersize) 
{
    const char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; // allocated dynamically during the function call. (Can be inefficient with a bad compiler)
    if (!pszMonth || buffersize<1) 
        return; // bad input. Let junk deal with junk data.
    if (month<1 || month>12)
    {
        *pszMonth = '\0'; // return an 'empty' string 
        // OR: strncpy(pszMonth, "Bad Month", buffersize-1);
    }
    else
    {
/* 
char *strncpy(char *dest, const char *src, size_t n)
dest: the pointer to the destination array where the content is to be copied
src: the string to be copied
n: the number of characters to be copied from source
*/
        strncpy(pszMonth, months[month-1], buffersize-1);
    }
    pszMonth[buffersize-1] = '\0'; // ensure a valid terminating zero! Many people forget this!
}

int main()
{
    char month[16]; // 16 bytes allocated here on the stack.
    calculateMonth(2, month, sizeof(month));
    printf("%s", month); // prints "Mar"
}