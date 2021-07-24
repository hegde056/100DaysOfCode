/* PPP2 Chapte 17 Ex.4 */
#include <iostream>

char* strcopycopy(const char* s)
{
	int n = 0; 

	//find length of s
	while (s[n] != '\0')
	{
		++n;
	}

	char* ret = new char[n+1]; 
	for (int i = 0 ; i <=n;++i)
	{
		ret[i] = s[i];
	}
    
	return ret;
}

int main()
{
	char str1[50] = "Hello World!";
	char* str2 = nullptr;
	std::cout << "str1  :: "<< str1 << std::endl;
	
	str2 = strcopycopy(&str1[0]);

	std::cout << "str2  :: " << str2 << std::endl;

	delete[] str2;
	return 0;
}
