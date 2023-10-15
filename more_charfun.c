#include "main.h"

/**
 * _strcmp_ - Compare Two String
 * @s1:String 1
 * @s2:String 2
 * Return: 0 If Identical Otherwise How Much Diffrent
 */
int _strcmp_(char *s1, char *s2)
{
int cmp = 0, i, len1, len2;
len1 = _strlen_(s1);
len2 = _strlen_(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);
	if (len1 != len2)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * _isalpha_ - Check if Alphabtic
 *@c: Character
 * Return: 1 If True 0 If Not
 */
int _isalpha_(int c)
{
if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _itoa_ - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa_(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = _intlen_(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	_array_rev_(s, len);
	s[i + 1] = '\0';
	return (s);
}
/**
 *  _array_rev_ - Reverse Array
 * @arr:Array To Reverse
 * @len:Length Of Array
 * Return: Void(Reverse Array)
 */
void _array_rev_(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
/**
 * _intlen_ - Determine Length Of Int
 * @num: Given Int
 * Return: Length Of Int
 */
int _intlen_(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
