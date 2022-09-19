#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int myputs(const char* str)
{   
    int i = 0;
    if (str == NULL)
        return EOF;
    while (str[i] != '\0')
    {
        putchar(str[i]);
        i++;
    }
    if (*(str+i) == '\0')
    {
        putchar('\n');
        return 0;
    }
    else
    {
        return EOF;
    }
}

//===============================================================================

int mystrcmp(const char* lhs, const char* rhs)
{
    int left = lhs[0];
    int right = rhs[0];
    int i = 0;
    if (left == right)
    {
        while (lhs[i] != '\0')
        {
            i++;
            left = lhs[i];
            right = rhs[i];
            if (left > right)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        return 0;
    }
    if (left > right)
    {
        return 1;
    }
    if ( left < right)
    {
        return -1;
    }
}

//======================================================================================

unsigned int mystrlen(const char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

//============================================================================================

char* mystrchr(const char* str, int ch)
{
    int i = 0;
    
    while (str[i] != '\0')
    {
        int s = str[i];
        if (s == ch)
        {
            return (char*)str+i;
        }
        i++;
    }
    return NULL;
}

//========================================================================================

char* mystrcpy(char* str, char* src)
{   
    int i= 0;
    while(*src != '\0')
    {
        *str = *src;
        src++;
        str++;
        i++;
    }

    *str = '\0';

    return (str-i);
}

//======================================================================

char* mystrncpy(char* str, const char* src, int size)
{
    int i = 0;
    while (i != size)
    {
        *str = *src;
        i++;
    }
    return str;
}

//=========================================================================

char* mystrdup(char* src)
{
    char* str = (char *) malloc(mystrlen(src) + 1);

    if (str == NULL)
    {
        return NULL;
    }
    mystrcpy(str, src);
    return str;
}

//=================================================================================



//==========================================================

char* mystrcat(char* destptr, const char* srcptr)
{   
    char* retptr = destptr;
    while ( *destptr != '\0')
        destptr++;

    while (*srcptr != '\0') 
    {
       * destptr = * srcptr;
       destptr++;
       srcptr++;

    }
    *destptr = '\0';
    return retptr;
}


//===========================================================

char* mystrncat(char* destptr, const char* srcptr, size_t num)
{
    int i = 0;
    char* retptr = destptr;
    while (*destptr != '\0')
    {
        destptr++;
        i++;
    }
    while (i < num)
    {
        *destptr = *srcptr;
        i++;
        destptr++;
        srcptr++;
    }

    *destptr = '\0';
    return retptr;
}

//=================================================================

char* myfgets(char* str, int num, FILE* fp)
{

    char ch;
    int i = 0;

    while ((ch = getc (fp)) != EOF && i != num) {

        * (str + i) = ch;
        i++;

    }

    return str;

}

//==============================================

int main()
{
    FILE *fp;
    fp = fopen("str.txt", "r");

    char str [10];
    myfgets (str, 10, stdin);
    puts (str);

    fclose(fp);   
}