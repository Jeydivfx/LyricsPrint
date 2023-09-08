#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>

#define length 20 
#define size 44

void reading_lyrics(char words[size][length], int *index);
printLyrics(char words[size][length], int *index);


int main()
{
    int* index;
    char words[size][length];
    reading_lyrics(words, &index);
    printLyrics(words, &index);
   

    return 0;
}

void reading_lyrics(char words[size][length], int *index)
{
    FILE* fp;
    char buff[20];
    int i = 0;
    fp = fopen("ilyb.txt", "r");
    while (fscanf(fp, "%s", &buff)!= EOF)
    {
        strcpy(words[i],buff);
        i++;
    }

    *index = i;
    fclose(fp);

}

printLyrics(char words[size][length], int *index)
{
    for (int i = 0; i < *index-1; i++)
    {
        if (strcmp(words[i], "EOL") == 0)
        {
            printf("\n");
            i += 1;
            Sleep(300);
        }
        printf("%s ", words[i]);
        Sleep(350);
    }

    printf("\n\n\n\n\n");
}

