#include <stdio.h>
#include <string.h>
  
int main()  
{  
    char s1[50],s2[50],s3[50]={""};  
    int i;  
    scanf("%s",s1);  
    scanf("%s",s2);  
    for(i = 0;i < strlen(s1);i++)  
    {  
        if(s1[i] == s2[i])  
            s3[i] = '1';  
        else  
            s3[i] = '0';  
    }  
    printf("%s\n",s3);  
}