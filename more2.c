#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encode(const char *src)
{
    if (src == NULL)
    {
        return NULL;
    }

    char *result = malloc(strlen(src));

    if (result != NULL)
    {
        strcpy(result, src);
        char *current_char = result;

        while (*current_char != '\0')
        {
            // Only increment alphabet characters
            if ((*current_char >= 97 && *current_char <= 122) || (*current_char >= 65 && *current_char <= 90))
            {
                if (*current_char > 109 || (*current_char > 77 && *current_char < 91))
                {
                    // Characters that wrap around to the start of the alphabet
                    *current_char -= 13;
                }
                else
                {
                    // Characters that can be safely incremented
                    *current_char += 13;
                }
            }
            current_char++;
        }
    }
    return result;
}

int main(void)
{
    char *flag_buff = malloc(24 * sizeof(char));
    FILE *fp = fopen("./flag2.txt", "r");
    fscanf(fp, "%s", flag_buff);

    flag_buff = encode(flag_buff);
    printf("Your flag is %s\n", flag_buff);
}
