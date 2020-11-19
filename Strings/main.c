#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isUpper(char var);
bool isLower(char var);
void changeCase(char *string);
int wordCounter(char *string);
int length(char *string);
bool isVowel(char var);
bool isConsonant(char var);
int countVowels(char *string);
int countConsonant(char *string);
bool isLetter(char var);
bool isDigit(char var);
bool isEspecial(char var);
bool validateString(char *string);
char *reverse_1(char *var);
void reverse_2(char *var);
void swap(char *v1, char *v2);
void toLower(char *string);
void toUpper(char *string);
bool compareString(const char *first, const char *second);
bool isPalindrom(const char *string);
void findDuplicateHT(char *string);
bool areAnagram(const char *first, const char *second);

int main(void)
{
	//String declarations
	//char x[5] = {'a', 'b', 'c', 'd', 'e'};		  //Array de caractres
	//char x_[6] = {'a', 'b', 'c', 'd', 'e', '\0'}; //Strings
	char fname[] = "FerNaNdO5";				 //String
	char *sname = "Uma string para testar "; //String
	char to_validate[] = "Thisisvalid12";
	//===========================================
	if (isUpper(fname[0]))
	{
		fprintf(stdout, "%c is upper\n", fname[0]);
	}
	//==============================================
	if (isLower(fname[2]))
	{
		fprintf(stdout, "%c is lower\n", fname[2]);
	}
	//================================================
	changeCase(fname);
	//================================================
	fprintf(stdout, "%s\n", fname);
	printf("%d\n", wordCounter(sname));
	printf("Length of %s is %d\n", sname, length(sname));
	printf("%s has %d vowels\n", sname, countVowels(sname));
	printf("%s has %d consonants\n", fname, countConsonant(fname));
	//================================================
	if (isConsonant(sname[2]))
	{
		printf("is consonant\n");
	}
	else
	{
		printf("Is vowel\n");
	}
	//================================================
	changeCase(fname);
	printf("%s\n", fname);
	//================================================
	if (validateString(to_validate))
	{
		printf("String is valid\n");
	}
	else
	{
		printf("String is invalid\n");
	}
	//================================================
	char *reversed = reverse_1(fname);
	printf("Reversed string: %s\n", reversed);
	//================================================
	toUpper(fname);
	reverse_2(fname);
	printf("Reversed string: %s\n", fname);
	toLower(fname);
	printf("%s\n", fname);
	//================================================
	if (compareString("Teste", "Fernando"))
	{
		printf("Equals\n");
	}
	else
	{
		printf("Not equal\n");
	}
	//================================================
	if (isPalindrom("madam"))
	{
		printf("Palindrom\n");
	}
	else
	{
		printf("Not Palindrom\n");
	}
	//================================================
	findDuplicateHT(sname);
	//===================================
	if (areAnagram("ngola", "lango"))
	{
		printf("Anagram\n");
	}
	else
	{
		printf("Not Anagram\n");
	}
	//================================================
	return 0;
}

//====================================================
bool isUpper(char var)
{
	if (var >= 'A' && var <= 'Z')
	{
		return true;
	}
	return false;
}
//====================================================

bool isLower(char var)
{
	if (var >= 97 && var <= 122)
	{
		return true;
	}
	return false;
}
//====================================================
void changeCase(char *string)
{
	for (int i = 0; string[i] != '\0'; ++i)
	{
		if (isUpper(string[i]))
		{
			string[i] += 32;
		}
		else if (isLower(string[i]))
		{
			string[i] -= 32;
		}
	}
}
//====================================================
int wordCounter(char *string)
{
	int words = 1;
	for (int i = 1; string[i] != '\0'; ++i)
	{
		if (string[i] == 32 && string[i - 1] != 32)
		{
			words += 1;
		}
	}
	return words;
}
//====================================================
int length(char *string)
{
	int i = 0;
	for (i = 0; string[i] != '\0'; ++i)
		;
	return i;
}
//====================================================
bool isVowel(char var)
{
	if (var == 'a' || var == 'e' || var == 'i' || var == 'o' || var == 'u' ||
		var == 'A' || var == 'E' || var == 'I' || var == 'O' || var == 'U')
	{
		return true;
	}
	return false;
}
//====================================================
bool isConsonant(char var)
{
	if ((!isVowel(var)) && ((var >= 'A' && var <= 'Z') || (var >= 'a' && var <= 'z')))
	{
		return true;
	}
	return false;
}
//====================================================
int countVowels(char *string)
{
	int vowel = 0;
	for (int i = 0; string[i] != '\0'; ++i)
	{
		if (isVowel(string[i]))
		{
			vowel += 1;
		}
	}
	return vowel;
}
////==================================================
int countConsonant(char *string)
{
	int consonant = 0;
	for (int i = 0; string[i] != '\0'; ++i)
	{
		if (isConsonant(string[i]))
		{
			consonant += 1;
		}
	}

	return consonant;
}
//====================================================
bool validateString(char *string)
{
	for (int i = 0; string[i] != '\0'; ++i)
	{
		if (!isLetter(string[i]) && !isDigit(string[i]))
		{
			break;
		}
	}
	return true;
}
//====================================================
bool isLetter(char var)
{
	if ((var >= 65 && var <= 90) || (var >= 97 && var <= 122))
	{
		return true;
	}
	return false;
}
//====================================================
bool isDigit(char var)
{
	if (var >= 48 && var <= 57)
	{
		return true;
	}
	return false;
}
//====================================================
bool isEspecial(char var)
{
	if ((var >= 33 && var <= 47) || (var >= 58 && var <= 64) || (var >= 91 && var <= 96))
	{
		return true;
	}
	return false;
}
//====================================================
char *reverse_1(char *var)
{
	int i, j;
	for (i = 0; var[i] != '\0'; ++i)
		;
	char *temp = malloc(i * sizeof(char));
	i -= 1;
	for (j = 0; i >= 0; i--, ++j)
	{
		temp[j] = var[i];
	}
	return temp;
}

//====================================================
void reverse_2(char *var)
{
	int i, j;
	for (i = 0; var[i] != '\0'; ++i)
		;
	for (i = 0; j < i; --i, j++)
	{
		swap(&var[i], &var[j]);
		// char tmp = var[j];
		// var[j] = var[i];
		// var[i] = tmp;
	}
}
//====================================================
void swap(char *v1, char *v2)
{
	char temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}
//====================================================
void toLower(char *string)
{
	for (int i = 0; string[i] != '\0'; ++i)
	{
		if (string[i] >= 65 && string[i] <= 90)
		{
			string[i] += 32;
		}
	}
}
//====================================================
void toUpper(char *string)
{
	for (int i = 0; string[i] != '\0'; ++i)
	{
		if (string[i] >= 97 && string[i] <= 122)
		{
			string[i] -= 32;
		}
	}
}
//====================================================
bool compareString(const char *first, const char *second)
{
	int i, j;
	for (i = 0, j = 0; first[i] != '\0' &&
					   second[i] != '\0';
		 j++, ++i)
	{
		if (first[i] != second[j])
		{
			break;
		}
	}
	if (first[i] == second[i])
	{
		return true;
	}
	return false;
}
//====================================================
bool isPalindrom(const char *string)
{
	int i, j;
	for (j = 0; string[j] != '\0'; ++j)
		;
	j -= 1;
	for (i = 0; i < j; ++i, j--)
	{
		if (string[i] != string[j])
		{
			return false;
		}
	}
	return true;
}
//====================================================
void findDuplicateHT(char *string)
{
	int H[26] = {[0] = 0}, i;

	for (i = 0; string[i] != '\0'; ++i)
	{
		H[string[i] - 97] += 1;
	}
	for (i = 0; i < 26; ++i)
	{
		if (H[i] > 1)
		{
			printf("%c appear %d times\n", (i + 97), H[i]);
		}
	}
}
//====================================================
bool areAnagram(const char *first, const char *second)
{
	int Alf[26] = {[0] = 0}, i;
	for (i = 0; first[i] != '\0'; ++i)
	{
		Alf[first[i] - 97]++;
	}
	for (i = 0; second[i] != '\0'; ++i)
	{
		Alf[second[i] - 97]--;
		if (Alf[second[i] - 97] < 0)
		{
			return false;
		}
	}
	return true;
}
//=======================================================