/**
 *  
 * (C) 2020 Tautvydas Diksas
 *
 */
#include <stdio.h> // fopen, fgets, fclose
#include <stdlib.h> // abort, 
#include <string.h> // strcmp
#include <dirent.h> // opendir readdir closedir
#include <sys/types.h> // opendir closedir
// #include <unistd.h>
// #include <errno.h>
// #include <ftw.h>
// #include <time.h>
// #include <libgen.h>

#include "lib/dynlib.h"

/** Checks given arguments to program.
 * Method checks possible given argument cases.
 * Arguments 2 must be -f and 4 must be 
 */
void hasArguments(int count, char * arguments[]) 
{
    if (count < 5)
    {
        printf("Missing Arguments! Not Enough\n");
        abort();
    }
    else if (count > 5)
    {
        printf("Too many arguments\n");
        abort();
    }
    else if (strcmp(arguments[1], "-f") != 0)
    {
        printf("first operand is -f");
        abort();
    }
    else if (strcmp(arguments[3], "-t") != 0)
    {
        printf("second operand is -t");
        abort();
    }
}

/** Reads file and counts every line which has given string.
 * First, method tries to open file and returns -1 if it does not open.
 * Then method reads lines until end of file and counts lines. While looping
 * a line is checked for given string and if it has the string,
 * counts every case.  
 */
int searchSubString(char *fname, char *str)
{
    FILE *fp;
    int line_num = 1;
    int find_result = 0;
    char temp[512];

    printf("Checking file: %s\n", fname);

    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("I dont want to open\n");
        return -1;
    }

    while (fgets(temp, 512, fp) != NULL)
    {
        if (strstr(temp, str) != NULL)
        {
            find_result++;
            printf("Given text is in line %d.\n", line_num);
        }
        line_num++;  
    }

    // pushname does not work :/
    // if (find_result > 0)
    // {
    //     push(fname);
    // }
    // else
    // {
    //     printf("Didnt find anything within given file.\n\n");
    // }
    
    
    fclose(fp);
    return 0;    
}

/**
 * 
 */
int walkDir(const char * fname, char * text)
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;

    if(!(folder = opendir(fname)))
    {
        perror("Unable to read directory");
        return 1;
    }
    while((entry=readdir(folder)) != NULL)
    {
        files++;
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", fname, entry->d_name);
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        if (entry->d_type == DT_DIR)
        {
            walkDir(path, text);
        }
        else if (entry->d_type == DT_REG)
        {
            printf("\nFile %3d: %s\n", files, entry->d_name);
            searchSubString(path, text);
        }
        // else
        // {
            // printf("Other %3d: %s\n", files, entry->d_name);
        // }
    }
    closedir(folder);
    return 0;
}

int main(int argc, char * argv[]) 
{
    hasArguments(argc, argv);
    walkDir(argv[2], argv[4]);
    printList();

    return 0;
}