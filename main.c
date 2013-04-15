#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define m_maxnum 5
#define n_maxnum 5
#define buf_size 1024

struct stack_str {
    char data;
    struct stack_str *prev;
};

struct stack_str *push(char content, struct stack_str *head)
{
    struct stack_str *newhead =
        (struct stack_str *) malloc(sizeof(struct stack_str));
    newhead->data = content;
    newhead->prev = head;
    return newhead;
}

struct stack_str *pop(struct stack_str *head)
{
    struct stack_str *prev_elem;
    if (!head)
        return 0;
    prev_elem = head->prev;
    free(head);
    return prev_elem;
}

char see(struct stack_str *head)
{
    if (!head)
        return 0;
    return head->data;
}

void free_stack(struct stack_str *head)
{
    struct stack_str *current, *next;

    for (current = head; current; current = next) {
        next = current->prev;
        free(current);
    }
}

void check_string(int str_size)
{
    int i, stacksize = 0, exit = 0;
    char c, str[buf_size];
    struct stack_str *stack_head = NULL;
    fgets(str, buf_size, stdin);
    for (i = 0; i < str_size && i < strlen(str); i++) {
        c = str[i];
        if (c == '.' || c == ':' || c == ';')
            break;
        if (c == '(' || c == '[' || c == '{') {
            stack_head = push(c, stack_head);
        }
        if (c == ')') {
            if (see(stack_head) == '(') {
                stack_head = pop(stack_head);
            } else {
                exit = 1;
                break;
            }
        }
        if (c == ']') {
            if (see(stack_head) == '[') {
                stack_head = pop(stack_head);
            } else {
                exit = 1;
                break;
            }
        }
        if (c == '}') {
            if (see(stack_head) == '{') {
                stack_head = pop(stack_head);
            } else {
                exit = 1;
                break;
            }
        }
    }
    if (exit || stack_head) {
        puts("wrong");
    } else {
        puts("correctly");
    }
    free_stack(stack_head);
}

void readme(char *argv[])
{
    if (!strcmp(argv[1], "-h")) {
        printf
            ("Help: \n"
             "1) Enter m (count of strings) and n (count of symbols)\n"
             "2) Enter each string. End of string - : ; .\n"
             "If can't enter more than n symbols, entering of string stop automatically\n");
        exit(0);
    }
}

void input_and_start_check(void)
{
    char m[m_maxnum], n[n_maxnum];
    int i, m_int, n_int;
    puts("Enter m");
    fgets(m, m_maxnum, stdin);
    puts("Enter n");
    fgets(n, n_maxnum, stdin);
    m_int = atoi(m);
    n_int = atoi(n);
    if (!m_int && !n_int) {
        puts("###Error with typed m and n.");
        exit(0);
    }
    for (i = 0; i < m_int; i++) {
        printf("Enter %d string, {. : ;} - end of string\n", i + 1);
        check_string(n_int);
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        readme(argv);
    input_and_start_check();
    return 0;
}
