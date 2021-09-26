#include <stdio.h>

int main(){
	char s[10];
	char s2[10];
	int i;
	scanf("%[^\n]s", s);
	sscanf(s, "%s %d", s2, &i);
	printf("%s, %s, %d", s, s2, i);

	return 0;
}