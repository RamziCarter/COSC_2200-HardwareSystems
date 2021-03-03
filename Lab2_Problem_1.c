#include <stdio.h>
int main() 
	{
		char ch[16];
		printf("Enter string: ");
		scanf("%s", &ch);
	
			int i;
			for(i = 0; i < 16; i++)
			{
			
 				if(ch[i] == 97 || ch[i] == 101 || ch[i] == 105 || ch[i] == 111 || ch[i] == 117)
				{

					printf("%c", ch[i]);
				}
		
				else if(ch[i] == 48 || ch[i] == 50 || ch[i] == 52 || ch[i] == 54  || ch[i] == 56)
				{

					printf("%c", ch[i]);
				}
				else
				{
					printf(NULL);
				}	 
			}
	
	return 0;
	}

	 
//
