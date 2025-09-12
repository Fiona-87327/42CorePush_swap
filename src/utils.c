#include "push_swap.h"

static size_t my_strlen(const char *s)
{
    size_t n = 0;
    if (!s) return 0;
    while (s[n]) n++;
    return n;
}

void putstr_fd(const char *s, int fd)
{
    if (!s) return;
    (void)!write(fd, s, my_strlen(s));
}

void *xmalloc(size_t size)
{
    void *p = malloc(size);
    if (!p)
        fatal_error();
    return p;
}

int safe_atoi(const char *s, int *out)
{
    long long sign = 1;
    long long res = 0;
    size_t i = 0;
    if (!s || !*s)
        return 0;
    /* skip leading spaces */
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-') sign = -1;
        i++;
    }
    if (!(s[i] >= '0' && s[i] <= '9'))
        return 0;
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + (s[i] - '0');
        if (sign * res > INT_MAX || sign * res < INT_MIN)
            return 0;
        i++;
    }
    /* trailing non-space characters are invalid */
    while (s[i])
    {
        if (!(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
            return 0;
        i++;
    }
    *out = (int)(sign * res);
    return 1;
}

void free_stack(t_node **s)
{
    t_node *cur = s ? *s : NULL;
    while (cur)
    {
        t_node *n = cur->next;
        free(cur);
        cur = n;
    }
    if (s) *s = NULL;
}

void fatal_error(void)
{
    putstr_fd("Error\n", 2);
    exit(1);
}

/*
** Whitespace split
*/
static int is_space(char c)
{
    return (c == ' ' || (c >= 9 && c <= 13));
}

char **ws_split(const char *s)
{
    size_t i = 0, count = 0, len = my_strlen(s);
    /* Count tokens */
    while (i < len)
    {
        while (i < len && is_space(s[i])) i++;
        if (i < len)
        {
            count++;
            while (i < len && !is_space(s[i])) i++;
        }
    }
    char **out = (char **)xmalloc((count + 1) * sizeof(char *));
    out[count] = NULL;
    /* Fill tokens */
    i = 0;
    size_t idx = 0;
    while (i < len)
    {
        while (i < len && is_space(s[i])) i++;
        if (i >= len) break;
        size_t start = i;
        while (i < len && !is_space(s[i])) i++;
        size_t tlen = i - start;
        char *tok = (char *)xmalloc(tlen + 1);
        for (size_t j = 0; j < tlen; ++j)
            tok[j] = s[start + j];
        tok[tlen] = '\0';
        out[idx++] = tok;
    }
    return out;
}

void free_split(char **v)
{
    if (!v) return;
    for (int i = 0; v[i]; ++i)
        free(v[i]);
    free(v);
}