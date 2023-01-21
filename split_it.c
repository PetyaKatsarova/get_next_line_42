#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSTRINGS 32

// char	**split_it(const char *str, const char *delim)
// {
// 	char	**result = NULL;
// 	size_t	count = 0;
// 	char	*temp = NULL;
// 	char	*temp_str = NULL;
// 	char	*token = NULL;

// 	temp_str = strdup(str);
// 	if (temp_str == NULL)
// 		result (NULL);
// 	temp = temp_str; //why??

// 	while ((token = strsep(&temp, delim) != NULL))
// 	{}
// }

char **split_it(const char *str, const char *delim)
{
	char **result = NULL;
    size_t count = 0;
    char *temp = NULL;
    char *word = NULL;
    char *temp_str = NULL;

    temp_str = strdup(str);
    if (temp_str == NULL) {
        return NULL;
    }
    temp = temp_str;
	while ((word = strsep(&temp, delim)) != NULL)
	{
		if(*word == '\0')
			continue;
		result = realloc(result, sizeof(char *) * ++count);
		if (result == NULL)
		{
			free(temp_str);
			return NULL;
		}
		result[count - 1] = strdup(word);
		if (result[count - 1] == NULL) {
			free(temp_str);
			for (size_t i = 0; i < count -1; i++) {
				free(result[i]);
			}
			free(result);
			return (NULL);
		} 
	}
	free(temp_str);
	result = realloc(result, sizeof(char *) * (count + 1));
	result[count] = 0;
	return (result);
}


int main(void)
{
	char	str[] = "Hello, World, Tra, la, la";
	char	**result = split_it(str, ",");

	for (int i = 0; result[i] != NULL; i++) {
		printf("%s -- ", result[i]);
	}
	return (0);
}

// int main(void)
// {
// 	char str[] = "Hello, World, Tra, la, la";
// 	char *delim = ",";
// 	char *word;
// 	char *temp_str = strdup(str);

// 	word = strsep(&temp_str, delim);
// 	while (word != NULL)
// 	{
// 		printf("%s -- ", word);
// 		word = strsep(&temp_str, delim);
// 	}
// 	free(temp_str);
// 	return (0);
// }