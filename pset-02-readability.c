#include <stdio.h>

// For strncpy
#include <string.h>

// For isalpha()
#include <ctype.h>

// Declare function prototype for count_letters function 
// Function takes in an input of an array of chars and returns an integer
int count_letters(char array_of_text[]);
int count_specific_character(char array_of_text[], char symbol);
// Declare function which rounds a float to the nearest whole number
int round_float(float number);
// When declaring a pointer, you should write the * next to the variable as opposed to writing it next to the type (i.e. avoid char* pszGrade)
void convert_to_grade(int index, char *pszGrade, int buffersize);

// Program does not take in any parameters
// 'void' explicitly states that the function does not expect to receive any parameters from its caller
int main(void)
{
    // Request text from user
    char plaintext_array[1000];
    printf("Text: ");

    /* --- fgets reads a line from the specified stream (plaintext_array). It stops after a maximum of sizeof(plaintext_array) characters and reads the characters from the stdin stream --- */
    fgets(plaintext_array, sizeof(plaintext_array), stdin);
    int length_of_plaintext = strlen(plaintext_array) - 1;
    // Declare variable which stores the result of calling the function count_letters
    int letters = count_letters(plaintext_array);
    // Single quotes '' are used to identify a single character while double quotes create a string literal
    // Counting spaces is the equivalent of counting the words
    int words = count_specific_character(plaintext_array, ' ') + 1;
    int exclamation_marks = count_specific_character(plaintext_array, '!');
    int question_marks = count_specific_character(plaintext_array, '?');
    // Counting periods is the equivalent of counting the sentences
    int periods = count_specific_character(plaintext_array, '.');
    int sentences = exclamation_marks + periods + question_marks;
    // l is the average number of letters per 100 words in the text
    // s is the average number of sentences per 100 words in the text
    float l, s, index;
    int rounded_answer;
    // l = letters * ( 100 / words);
    // (float) is an example of typecasting. Typecasting is converting one datatype into another.
    l =  letters * (100 / (float)words);

    s = sentences * (100 / (float)words);
    index = (0.0588 * l) - (0.296 * s) - 15.8;
    rounded_answer = round_float(index);

    char grade[100];
    convert_to_grade(rounded_answer, grade, sizeof(grade));
}

int count_letters(char array_of_text[])
{
    int count_alpha = 0;

    for (int i = 0; array_of_text[i] != '\0'; i++)
    {
        // The C library function int isalpha(int c) checks if the passed character is alphabetic. It belongs to the ctype library
        if (isalpha(array_of_text[i]))
        {
            count_alpha++;
        }
    }

    return count_alpha;
}

int count_specific_character(char array_of_text[], char symbol) 
{
    int symbol_counter = 0;

    for (int i = 0; array_of_text[i] != '\0'; i++) 
    {
        if (array_of_text[i] == symbol)
        {
            symbol_counter++;
        }
    }

    return symbol_counter;
}

int round_float(float number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

// psz = pointer to string, zero-terminated
void convert_to_grade(int index, char *pszGrade, int buffersize)
{
    if (!pszGrade || buffersize < 1)
    {
        return; // bad input. Let junk deal with junk data
    }
    if (index < 1)
    {
        strncpy(pszGrade, "Before Grade 1", buffersize - 1);
        printf("%s\n", pszGrade);
    }
    else if (index > 15)
    {
        strncpy(pszGrade, "Grade 16+", buffersize - 1);
        printf("%s\n", pszGrade);
    } 
    else
    {
        printf("Grade %i\n", index);
    }
}
