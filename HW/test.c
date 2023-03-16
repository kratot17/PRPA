#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// A structure to hold a dynamically allocated array of words
struct Word
{
    char *word;
    int count;
};

// A structure to hold a dynamically allocated array of words
struct WordArray
{
    struct Word *words;
    int size;
};

int main(int argc, char *argv[])
{
    char **slovnik;
    struct Word *words; // struct to store words and their counts
    slovnik = NULL;
    words = NULL;
    slovnik = malloc(sizeof(char *));
    words = malloc(sizeof(struct Word));
    char tmp[100]; // asssume a word has less than 100 letters
    int i = 0, caseSensitive = 0;
    int wordCount = 0; // number of unique words

    if (argc >= 2)
    {
        if (strcmp(argv[1], "-c") == 0)
        {
            caseSensitive = 1;
        }
    }

    while (scanf("%s", tmp) > 0)
    {
        // make input lower-case if necessary
        if (caseSensitive == 0)
        {
            int len = strlen(tmp);
            for (int i = 0; i < len; i++)
            {
                tmp[i] = tolower(tmp[i]);
            }
        }

        // dynamically allocate memory for a new string
        slovnik[i] = malloc(strlen(tmp) + 1);

        // realocate the slovnik
        slovnik = realloc(slovnik, (i + 2) * sizeof(char *));

        // remove punctuation marks from the string
        int j = 0;
        for (int k = 0; tmp[k]; k++)
        {
            if (!ispunct(tmp[k]))
            {
                slovnik[i][j] = tmp[k];
                j++;
            }
        }

        // null-terminate the string
        slovnik[i][j] = '\0';

        // check if the word already exists in the struct
        int found = 0;
        for (int x = 0; x < wordCount; x++)
        {
            if (strcmp(words[x].word, slovnik[i]) == 0)
            {
                // increment the count for this word
                words[x].count++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            // add a new entry to the struct
            words = realloc(words, (wordCount + 1) * sizeof(struct Word));
            words[wordCount].word = slovnik[i];
            words[wordCount].count = 1;
            wordCount++;
        }
        i++;
    }

    // Create two WordArray structures to store the most common and least common words
    struct WordArray mostCommon;
    struct WordArray leastCommon;

    // Initialize the size of each array to 0
    mostCommon.size = 0;
    leastCommon.size = 0;

    // find the most common words
    int maxCount = 0;
    for (int x = 0; x < wordCount; x++)
    {
        if (words[x].count > maxCount)
        {
            // Reallocate the array to store the new word
            mostCommon.words = realloc(mostCommon.words, sizeof(struct Word));
            mostCommon.words[0] = words[x];
            mostCommon.size = 1;
            maxCount = words[x].count;
        }
        else if (words[x].count == maxCount)
        {
            // Reallocate the array to store the new word
            mostCommon.words = realloc(mostCommon.words, (mostCommon.size + 1) * sizeof(struct Word));
            mostCommon.words[mostCommon.size] = words[x];
            mostCommon.size++;
        }
    }

    // find the least common words
    int minCount = words[0].count;
    leastCommon.words = malloc(sizeof(struct Word));
    leastCommon.words[0] = words[0];
    leastCommon.size = 1;

    for (int x = 1; x < wordCount; x++)
    {
        if (words[x].count < minCount)
        {
            // Reallocate the array to store the new word
            leastCommon.words = realloc(leastCommon.words, sizeof(struct Word));
            leastCommon.words[0] = words[x];
            leastCommon.size = 1;
            minCount = words[x].count;
        }
        else if (words[x].count == minCount)
        {
            // Reallocate the array to store the new word
            leastCommon.words = realloc(leastCommon.words, (leastCommon.size + 1) * sizeof(struct Word));
            leastCommon.words[leastCommon.size] = words[x];
            leastCommon.size++;
        }
    }

    printf("Seznam slov:\n");

    // print the frequency of each word
    for (int x = 0; x < wordCount; x++)
    {
        printf("%-21s%d\n", words[x].word, words[x].count);
    }

    // print the number of unique words
    printf("Pocet slov:          %i\n", wordCount);

    // Print the most common words
    printf("Nejcastejsi:         ");
    for (int x = 0; x < mostCommon.size; x++)
    {
        printf("%s", mostCommon.words[x].word);
        if (x < mostCommon.size - 1)
        {
            printf(" ");
        }
    }

    // Print the least common words
    printf("\nNejmene caste:       ");
    for (int x = 0; x < leastCommon.size; x++)
    {
        printf("%s", leastCommon.words[x].word);
        if (x < leastCommon.size - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    // free memory
    for (int i = 0; i < wordCount; i++)
    {
        free(slovnik[i]);
    }
    free(slovnik);
    free(words);
    free(mostCommon.words);
    free(leastCommon.words);

    return 0;
}
