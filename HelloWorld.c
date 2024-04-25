#include <stdio.h>
#include <string.h>
main()
{
    int k=0,flag=1,i,l,j=0;
    char s[100];
    printf("Enter your name:");
    scanf(" %[^\n]",&s);
    l=strlen(s);
    char a[l];
    for(i=l-1;i>=0;i--)
    {
        if(s[i]==' ')
        {
            flag=0;
            if(k>0)
            {
                a[j]='.';
                j++;
                a[j]=s[i+1];
                j++;

            }
            k=1;
        }
        if(flag==1)
        {
            a[j]=s[i];
            j++;
        }
        if(i==0)
        {
            a[j]='.';
            j++;
            a[j]=s[0];
            j++;

        }
    }
    for(i=j-1;i>=0;i--)
        printf("%c",a[i]);

}