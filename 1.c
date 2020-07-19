#include <stdio.h>
#include <string.h>
void test2() 
{
	printf("Test2\n");
}
void test(char* arg) 
{
	char buf[256];
	strcpy(buf, arg);
	printf("%s\n", buf);
	int a = 0;
	a += 2;
}

int main(int argc, char* argv[])
{
	test(argv[1]);
	return 0;
}
