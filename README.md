## Simple Shell
> In this project, we coded from scratch a simple Unix shell.
> This shell is an interactive commandline interpreter.
> This shell that we created utilizes the command line interface (CLI).
> It allows users to type in a defined set of commands
> (e.g. "env" to print out the environment, "rm" to remove files,
> "ls" to list file in the current directory, etc) and have the operating
> system run the appropriate function. Our shell is a simple version
> that handles memory leaks very well and has basic functionality.
> It allows the user to manipulate folders however they want,
> from writing, reading, etc, print things to the terminal,
> change directories, print where you are in the system, among others.

### Synopsis
> On this Simple Shell repository it holds all the code necessary for
> our custom simple shell to run. Our shell currently handles the executions
> of executables found in the environmental variable PATH.
> Some of the commands that our shell supports include /bin/ls, pwd, env, etc.

#### Some of the allowed functions and system calls
```access```, ```chdir```, ```close```, ```closedir```, ```execve```,```exit```
```_exit```, ```signal```, ```malloc```, ```free```, ```getcwd```, ```wait```, ```write```.

### File Descriptions
* ```AUTHORS```: include the names of the contributors to this repository.
* ```_realloc.c```: contains a function that reallocates then allocated memory and sets all the values to 0.
* ```_strings.c```: contains functions that helps in the manipulation os strings including strcat, strcmp, strcpy, strdup, strlen.
* ```builtin_parser.c```: parses the builtin programs.
* ```cd_handler.c```: include functions that helps to get the current working directory, handles cd when the user does not set any other arguements, navigates to the previous directory when user invokes cd -, and changes the current working directory.
* ```ctrl_exit.c```: contains functions to display prompt, to ignore spaces before command, to ignore the ctrl-C when evoked, and to handl the shell exit.
* ```envset_unset.c```: this file contains functions that handles the environment, setting it and also unsetting it.
* ```execute.c```: this file contains functions to convert sting to token and handles the execution of a file given as input.
* ```holberton.h```: handles all the prototypes used in this repository.
* ```man_1_simple_shell```: This is a manual description of what our shell is and its content and also an example to illustrate how it works.
* ```path_handler.c```: this funtion contains functions to get the path of the command, retrive the environment, and return full command path.
* ```print_char.c```: includes the putchar and a print to help print a string.
* ```read_line.c```: contain functions that reads the characters in standard input.
* ```shell.c```: this is our main function that displays an prompt and waits for the user to type in a command.


### Shell Usage
* Install
```
(your_terminal)$ git clone https://github.com/DennisWanjeri/simple_shell.git
(your_terminal)$ cd simple_shell
```
* Compile
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
* Usage: non-interactive mode
```
echo "/bin/ls" | ./hsh
```
* Usage: interactive mode
```
(your_terminal)$ ./hsh
```

#### Illustration
```
#cisfun$ ls -l
total 80
-rw-rw-r-- 1 root root 158  Apr 14 07:43 AUTHORS
-rw-rw-r-- 1 root root 1913 Apr 14 15:52 README.md
-rw-rw-r-- 1 root root 1008 Apr 15 11:51 _realloc.c
-rw-rw-r-- 1 root root 2219 Apr 15 13:20 _strings.c
#cisfun$ echo "simple shell easy!"
simple shell easy!
#cisfun$ exit 98
(your_terminal)$
```
#### Authors
1. [Dennis Wanjeri](https://github.com/DennisWanjeri)
2. [Jane Ng'ethe](https://github.com/Janengethe)