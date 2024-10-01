/*
Write a function that, when given a string as its argument,
searches the following array of structures for a matching
command name, then calls the function associated with that name.
*/

#include <stdio.h>
#include <string.h>

void new_cmd(void)
{
    printf("new\n");
}

void open_cmd(void)
{
    printf("open\n");
}

void close_cmd(void)
{
    printf("close\n");
}

void close_all_cmd(void)
{
    printf("close_all\n");
}

void save_cmd(void)
{
    printf("save\n");
}

void save_as_cmd(void)
{
    printf("save_as\n");
}

void save_all_cmd(void)
{
    printf("save_all\n");
}

void print_cmd(void)
{
    printf("print\n");
}

void exit_cmd(void)
{
    printf("exit\n");
}

struct
{
    char *cmd_name;
    void (*cmd_pointer)(void);
} file_cmd[] =
    {
        {"new", new_cmd},
        {"open", open_cmd},
        {"close", close_cmd},
        {"close all", close_all_cmd},
        {"save", save_cmd},
        {"save as", save_as_cmd},
        {"save all", save_all_cmd},
        {"print", print_cmd},
        {"exit", exit_cmd}};

void run_cmd(char *cmd_name)
{
    for (int i = 0; i < (sizeof(file_cmd) / sizeof(file_cmd[0])); i++)
    {
        if (strcmp(cmd_name, file_cmd[i].cmd_name) == 0)
        {
            return file_cmd[i].cmd_pointer();
        }
    }

    printf("Command [%s] not found.\n", cmd_name);
}

int main(void)
{
    run_cmd("new");
    run_cmd("open");
    run_cmd("close");
    run_cmd("close all");
    run_cmd("save");
    run_cmd("save as");
    run_cmd("save all");
    run_cmd("print");
    run_cmd("exit");

    run_cmd("bruh");

    return 0;
}