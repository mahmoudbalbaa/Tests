#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

extern char **environ;

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen_(c)))

/**###### STRING FUNCTION ######*/

char *_strtok_(char *str, const char *tok);
unsigned int _checkdelim_(char c, const char *str);
char *_strncpy_(char *dest, char *src, int n);
int _strlen_(char *s);
int _putchar_(char c);
int _atoi_(char *s);
void _puts_(char *str);
int _strcmp_(char *s1, char *s2);
int _isalpha_(int c);
void _array_rev_(char *arr, int len);
int _intlen_(int num);
char *_itoa_(unsigned int n);
char *_strcat_(char *dest, char *src);
char *_strcpy_(char *dest, char *src);
char *_strchr_(char *s, char c);
int _strncmp_(const char *s1, const char *s2, size_t n);
char *_strdup_(char *str);

/**###### MEMORIE  MANGMENT ####*/

void _free_env_(char **env);
void *array_fill(void *a, int el, unsigned int len);
char *_memocpy_(char *dest, char *src, unsigned int n);
void *_calloc_(unsigned int size);
void *_realloc_(void *ptr, unsigned int old_size, unsigned int new_size);
void _freeall_(char **input, char *line);

/**###### INPUT Function ######*/

void print_prompt(void);
void sign_handle(int sig);
char *_getline_(void);

/** ###### Command parser and extractor ###*/

int _cmd_path(char **line);
char *_getenv_(char *name);
char **_cmd_prase(char *cmd);
int _builtin_handl(char **cmd, int er);
void _file_read(char *filename, char **argv);
char *_build_(char *token, char *value);
int _bultn_checker(char **cmd);
void _make_env(char **envi);
int _cmd_check(char **tokens, char *line, int count, char **argv);
void _treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_file_bul(char **cmd, char *line, FILE *fd);

/** ####BUL FUNC #####*/

void hashtag_handle(char *buff);
int history(char *input);
int history_dis(char **cmd, int er);
int dis_env(char **cmd, int er);
int change_dir(char **cmd, int er);
int display_help(char **cmd, int er);
int echo_bul(char **cmd, int er);
void  exit_bul(char **cmd, char *input, char **argv, int c);
int print_echo(char **cmd);

/** ####error handle and Printer ####*/
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
