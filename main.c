#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define m_maxnum 5
#define n_maxnum 5

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

void free_stack(struct stack_str *head, int stack_size)
{
    struct stack_str *temp_p;
    for (; stack_size; stack_size--) {
        temp_p = head;
        head = head->prev;
        free(temp_p);
    }
}

void check_string(int str_size)
{
    int i, stacksize = 0, EXIT = 0;
    char c;
    struct stack_str *stack_head =
        (struct stack_str *) malloc(sizeof(struct stack_str));

    for (i = 0; i < str_size && !EXIT; i++) {
        while ((c = getchar()) == '\n');
        if (c == '.' || c == ':' || c == ';')
            break;
        if (c == '(' || c == '[' || c == '{') {
            stack_head = push(c, stack_head);
            stacksize++;
        }
        if (c == ')') {
            if (see(stack_head) == '(') {
                stack_head = pop(stack_head);
                stacksize--;
            } else
                EXIT = 1;
        }
        if (c == ']') {
            if (see(stack_head) == '[') {
                stack_head = pop(stack_head);
                stacksize--;
            } else
                EXIT = 1;
        }
        if (c == '}') {
            if (see(stack_head) == '{') {
                stack_head = pop(stack_head);
                stacksize--;
            } else
                EXIT = 1;
        }
    }
    if (EXIT) {
        puts("wrong");
        return;
    }
    if (!stacksize)
        puts("correctly");
    else
        puts("wrong");
    free_stack(stack_head, stacksize);
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
