#include <stdio.h>
#define LEN 8

void itoi (int n, char s[]);
void itob (int n, char s[], int b);

int main()
{

    int x = -12;
    char str[LEN]=" ";

    int y = -254;
    char str16[LEN]=" ";

    int z = 0xFE;
    char str02[LEN]=" ";

    itoi(x, str);

    itob(y, str16, 16);

    itob(z, str02, 2);

    printf("%s\n", str);
    printf("%s\n", str16);
    printf("%s\n", str02);

    return 0;
}

void itoi (int n, char s[])
{
    int sign, i;
    if((sign=n)<0){
        n=-n;
    }

    i=0;
    do{
        s[i++]=n%10+'0';
    }
    while(n/=10);

    if(sign<0){
        s[i++]='-';
    }

    s[i]='\0';


    for(int k=i-1, j=0; k>0 ; ++j,--k)
    {
        char tmp=s[j];
        s[j]=s[k];
        s[k]=tmp;
    }
}

void itob (int n, char s[], int b)
{
    int sign, i, r;
    r = b;
    if((sign=n)<0){
        n=-n;
    }

    i=0;
    do{
        r=n%b;
        s[i++]=(r>9)? r+'A'-10:r+'0';
      }
    while(n/=b);


    if(sign<0){
        s[i++]='-';
    }

    s[i]='\0';

    for(int k=i-1, j=0; k>0 ; ++j,--k)
    {
        char tmp=s[j];
        s[j]=s[k];
        s[k]=tmp;
    }

}