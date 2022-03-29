#include <stdio.h>
#include <string.h>

int is_rotation(char *str1, char *str2);

enum
{
	FALSE,
	TRUE
};

int main()
{
	char str1[] = "12345";
	char str2[] = "121234";
	
	int result = 0;
	
	result = is_rotation(str1,str2);
   
	printf("%d\n",result);

	
	
	return 0;
}

int is_rotation(char *str1, char *str2)
{

	const char ch = str2[0];
   	char *ret;  	
   	int ret_length = 0;
	
   	ret = strchr(str1, ch);
   
	if(strlen(str1) != strlen(str2) ||  NULL == ret )
	{
		return FALSE;
	}
		
	ret_length = strlen(ret);
	str2 = str2 + ret_length;
	
	while('\0' != *str2)
	{
		if(*str2 != *str1)
		{
			return FALSE;
		}
		
		++str2;
		++str1;
	}

	return TRUE;
}






