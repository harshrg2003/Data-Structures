#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str1[30];
    int freq[26]={0},c=0;
    printf("Enter the string\n");
    scanf("%s",str1);
    int len=strlen(str1);
    for(c=0;str1[c]!='\0';c++)
    {
        freq[tolower(str1[c])-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        {
            printf("The frequency of charecter %c is %d\n", i+'a',freq[i]);
        }
    }
    return 0;
}