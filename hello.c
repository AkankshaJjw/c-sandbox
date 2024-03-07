#include <stdio.h>
#include <string.h>

int main() {
	const char msg[] = "Hello Mera Pyaar";
	int msgArrSize = sizeof(msg)/sizeof(msg[0]);

	char firstWord[50] = {0};
	for (int i= 0; i<msgArrSize; i++)
	{	
		char nextChar;
		if (msg[i] != ' ')
		{
			int len = strlen(firstWord); // Find the current length of firstWord.
        	firstWord[len] = msg[i]; // Set the next character.
			printf("\nnext char: %c",(msg[i]));
        	firstWord[len + 1] = '\0'; // Null-terminate the string.
		}
		else 
		{
			printf("\nbreak time");
			break;
		}
	}
	printf("\nThe first word is: %s", firstWord);
	int a1 = 5;
	int a2 = 5;
	int b;
	int c;
	b = ++a1;
	printf("\nvalue of b: %d, a1: %d", b, a1);
	c = a1++;

	printf("\nvalue of c: %d, a1: %d", c, a1);

	return 0;
}


