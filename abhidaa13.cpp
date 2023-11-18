#include<stdio.h>
#include<string.h>
int main()
{
	
	char s[100];
	printf("enter a string to reverse\n");
	gets(s);
	strrev(s);
	printf("reverse of the string:%s\n",s);
	return 0;
}
