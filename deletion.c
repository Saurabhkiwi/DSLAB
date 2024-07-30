#include<stdio.h>
#include<string.h>

int main()
{
    int i, j = 0, k = 0,n = 0;
    int flag = 0;

    char str[100], new[100], word[100];

    printf("Enter string: ");
    gets(str);

    printf("\nenter word to be removed :");
    gets(word);

    for(i = 0 ; str[i] != '\0' ; i++)
    {
        k = i;

        while(str[i] == word[j])
        {
            i++,j++;
            if(j == strlen(word))
            {
                flag = 1;
                break;
            }
        }
    j = 0;

    if(flag == 0)
        i = k;
    else
        flag = 0;

    new[n++] = str[i];
    }

    new[n] = '\0';

    printf("\n\n After Removing Word From String: %s",new);
}
