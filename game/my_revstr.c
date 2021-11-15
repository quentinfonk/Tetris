/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** my_revstr
*/

char *my_strcpy(char *dest, char const *src);

int compte(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_revstr(char *str)
{
    int n = compte(str);
    int a = 0;
    char dest[n];

    n--;
    while (n != -1) {
        dest[a] = str[n];
        a++;
        n--;
    }
    dest[a] = '\0';
    str = my_strcpy(str, dest);
    return (str);
}
