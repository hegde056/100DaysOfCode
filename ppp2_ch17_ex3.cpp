/* PPP2 Chapte 17 Ex.3 */
#include <iostream>

void to_lower(char* s)
{
	while(*s != '\0')
	{
		if (int(*s) > 65 && int(*s) < 97)
		{
			*s = *s + 32;
		}
		s++;
	}
}

int main()
{
	char str[50] = "HeLLo WorLd!";

	std::cout << "Before :: "<< str << std::endl;
	
	to_lower(str);

	std::cout << "After :: " << str << std::endl;

	return 0;
}
