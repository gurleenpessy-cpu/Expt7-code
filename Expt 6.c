#include <stdio.h>
#include <stdlib.h>

// Function to calculate length of a string manually
int strLength(char str[]) {
int len = 0;

while (str[len] != '\0') len++;
return len;
}

// Function to check if pattern matches at position 'pos' in STR
int matchAt(char str[], char pat[], int pos) {
int i = 0;
while (pat[i] != '\0') {
if (str[pos + i] != pat[i])
return 0;
i++;
}
return 1;
}

// Function to perform replacement
void replacePattern(char str[], char pat[], char rep[]) {
char result[500];
int i = 0, j = 0, k = 0, found = 0;
int lenSTR = strLength(str);
int lenPAT = strLength(pat);
int lenREP = strLength(rep);

while (i < lenSTR) {
// If pattern found at position i
if (matchAt(str, pat, i)) {
found = 1;

for (k = 0; k < lenREP; k++)
result[j++] = rep[k];
i += lenPAT; // skip the pattern
} else {
result[j++] = str[i++];
}
}
result[j] = '\0';

if (found)
printf("\nModified String: %s\n", result);
else
printf("\nPattern not found in the main string.\n");
}

int main() {
char str[200], pat[50], rep[50];

printf("Enter the main string (STR): ");
gets(str);

printf("Enter the pattern string (PAT): ");
gets(pat);

printf("Enter the replace string (REP): ");
gets(rep);

replacePattern(str, pat, rep);

return 0;
}