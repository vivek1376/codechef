/*codechef jewels and stones. changed array size to 128 and solution was accepted

a good approach is to make an array of alphabets and mark those which appear in jewels
and use that array to search stones 
*/

#include <stdio.h>
#include <string.h>

int main()
{
	unsigned int test_cases,jewels_mined;
	char jewels[101],stones[101],jewels_condnsd[101];
	char *pch,*pjewel,*ptr;
	
	scanf("%d",&test_cases);
	
	while(test_cases--)
	{
		jewels_mined=0;	//reset value		
		
		//remove duplicates
		strcpy(jewels_condnsd,"");
		scanf("%s",jewels);
		ptr=jewels;
		pjewel=jewels_condnsd;		
		while(*ptr)
		{
			if(!strchr(jewels_condnsd,*ptr))
			{
				*pjewel=*ptr;
				pjewel++;
				*pjewel='\0';				
			}
			ptr++;
		}
		
		scanf("%s",stones);
		ptr=jewels_condnsd;
		while(*ptr)
		{
			pch=stones;
			while(*pch)
			{
				if(*ptr==*pch++)
					jewels_mined++;
			}
			ptr++;
		}
		printf("%d\n",jewels_mined);
	}
	return 0;
}

