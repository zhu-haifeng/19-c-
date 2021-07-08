#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int i,j;
    printf("number:190110716\nsubject no.2\n");
	do
    {
	    printf("please input a small letter:");
        scanf(" %c",&c);
	}while(c<97||c>122);

	c-=32;

	for(i=1;i<=4;i++)
	{
		for(j=8;j;j--)
		{
			printf("%2c",c);

		}
		printf("\n");
		for(j=8;j;j--)
		{
			printf("%-2c",c);

		}
		printf("\n");
	}
	return 0;
}
