# Mr. Robot - Holberton School :robot:


## Synopsis :thought_balloon:
This is a humble and simple implementation of a UNIX command line interpreter.

## Description :speech_balloon:
Custom version UNIX command language interpreter built as a project for Holberton School. This mini shell reads commands from either interactive  mode and non-interactive mode.


## Requeriments :bookmark_tabs:

* Allowed editors: ```vi```, ```vim```, ```emacs```
* Programs and functions will be compiled with ```gcc 4.8.4``` using the flags ```-Wall``` ```-Werror``` ```-Wextra``` ```and -pedantic```
* All files should end with a new line
* Code should use the ```Betty``` style. it will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style\
.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to
* Authorized functions and system calls:
  * ```access``` (```man 2 access```)
  * ```chdir``` (```man 2 chdir```)
  * ```close``` (```man 2 close```)
  * ```closedir``` (```man 3 closedir```)
  * ```execve``` (```man 2 execve```)
  * ```exit``` (```man 3 exit```)
  * ```fork``` (```man 2 fork```)
  * ```free``` (```man 3 free```)
  * ```stat``` (```__xstat```)(```man 2 stat```)
  * ```lstat``` (```__lxstat```)(```man 2 lstat```)
  * ```fstat``` (```__fxstat)(```man 2 fstat```)
  * ```getcwd``` (```man 3 getcwd```)
  * ```getline``` (```man 3 getline```)
  * ```kill``` (```man 2 kill```)
  * ```malloc``` (```man 3 malloc```)
  * ```open``` (```man 2 open```)
  * ```opendir``` (```man 3 opendir```)
  * ```perror``` (```man 3 perror```)
  * ```read``` (```man 2 read```)
  * ```readdir``` (```man 3 readdir```)
  * ```signal``` (```man 2 signal```)
  * ```strtok``` (```man 3 strtok```)
  * ```wait``` (```man 2 wait```)
  * ```waitpid``` (```man 2 waitpid```)
  * ```wait3``` (```man 2 wait3```)
  * ```wait4``` (```man 2 wait4```)
  * ```write``` (```man 2 write```)
  * ```_exit``` (```man 2 _exit```)
  * ```isatty``` (```man 3 isatty```)
  * ```fflush``` (```man 3 fflush```)

## Flowchart :pushpin:
Below you can see all the process flow in general terms that was taken into account at the time of making the code. 

![flowchar mr robot](https://user-images.githubusercontent.com/60367519/79517219-2adbc000-8013-11ea-9835-30bf7c59a41e.jpg)

## Quick start :runner:
Git clone the repository:

```
git clone https://github.com/cbarros7/simple_shell.git 
```

## Usage :computer:
All the files are to be compiled on an Ubuntu 14.04 LTS machine with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

Once compiled, to start the program, run:
```./hsh```
  
To exit the program, run:
```$ exit```
  
The **Mr. Robot** supports most shell commands, such as ```cat```, ```pwd```, ```ls -la``` and more.


## List of functions :page_facing_up:

| Function Name | Description |
|---------------- | -----------|
|[func_exit](https://github.com/cbarros7/simple_shell/blob/master/built-ins.c)    | Exit the shell.|
|[func_printenv](https://github.com/cbarros7/simple_shell/blob/master/built-ins.c) | Prints the current environment.|
|[read_input](https://github.com/cbarros7/simple_shell/blob/master/loop_functions.c) | Stores whatever is passed to it as standard input. |
|[sparse_str](https://github.com/cbarros7/simple_shell/blob/master/loop_functions.c) | Devides a string into and array of strings. |
|[execute](https://github.com/cbarros7/simple_shell/blob/master/loop_functions.c) | Executes a command that is passed to it as the first aguement. |
|[prompt](https://github.com/cbarros7/simple_shell/blob/master/loop_functions.c) | Prints '$' and waits for a user's input. |
|[_getenv](https://github.com/cbarros7/simple_shell/blob/master/loop_sub_functions.c) | Provides the value of the environment passed to it as arguement. |
|[_which](https://github.com/cbarros7/simple_shell/blob/master/loop_sub_functions.c) | Identifies the path of the command(\*args) that is being passed. |
|[child_process](https://github.com/cbarros7/simple_shell/blob/master/loop_sub_functions.c) | Executes a command if the path of it is an executable file. |
|[search_func](https://github.com/cbarros7/simple_shell/blob/master/loop_sub_functions.c) | Search directory. |
|[_realloc](https://github.com/cbarros7/simple_shell/blob/master/memory.c) | Reallocates a space in memory. |
|[_count_point](https://github.com/cbarros7/simple_shell/blob/master/memory.c) | Memory buffer. |
|[handle_signal](https://github.com/cbarros7/simple_shell/blob/master/signals.c) | Prints new line and prompt when CTRL + C is passed as input. |
|[_stat](https://github.com/cbarros7/simple_shell/blob/master/signals.c) | Displays file or file system status. |
|[_strstr](https://github.com/cbarros7/simple_shell/blob/master/str_func.c) | Locates a substring. |
|[_strlen](https://github.com/cbarros7/simple_shell/blob/master/str_func.c) | Returns a string. |
|[_strcpy](https://github.com/cbarros7/simple_shell/blob/master/str_func.c) | Copies a string pointed to by src to dest. |
|[_strcat](https://github.com/cbarros7/simple_shell/blob/master/str_func.c) | Concatenates two strings. |
|[_strcmp](https://github.com/cbarros7/simple_shell/blob/master/str_func.c) | Compare two strings. |
|[_strdup](https://github.com/cbarros7/simple_shell/blob/master/str_func_2.c) | Copies a string to another. |


## Syntax :notebook_with_decorative_cover:
**Mr. Robot** the user can have the experience in an interactive and non-interactive way. On the one hand, if it is invoked with a standard input that is not connected to the terminal, *Mr. Robot* reads and executes the received commands in order.

To use the **Mr. Robot** interactive mode use isatty(3). Immediately the user will see a warning $ indicating that our shell is ready to read the command.

On the other hand, in non-interactive mode the user will enter command line arguments, so **Mr. Robot** treats the first argument as a file from which to read the commands.
In interactive mode, you can type commands from the keyboard:

Example:
```
$ ./hsh
$ /bin/ls
```
In non-interactive mode, you can pipe commands into the program using echo or cat:

Non-interactive:

Example:
```
$ echo "/bin/ls" | ./hsh
$ cat file_name | ./hsh
```

You can use the same syntax for running commands in other shells:
```
<command> <flags or options> <argument 1> <argument 2> ...
```

In non-interactive mode:
```
<command> | ./hsh
```

## Built-Ins  :hammer:
The following built-ins are supported by the *Mr. Robot*:
  
+ ```env``` - Print the current environment
+ ```exit``` - exit program sucessfully

## Return :clap:

**Mr. Robot** returns zero indicating success and non-zero indicanting failure.

## Bugs :loudspeaker:
No known bugs.

## Annotations :loudspeaker:
We have written an [**article**](https://www.linkedin.com/pulse/ls-l-command-understanding-what-happens-shell-carlos-barros/) in which we deepen the internal processes within the shell by typing the command "ls -l". We talk about fundamental elements such as the PATH, and conclude with the permission structure with some examples. 

## Authors :black_nib:
* **Carlos Barros** [Github](https://github.com/cbarros7)
* **Andrew Kalil** [Github](https://github.com/AndrewKalil)

## Acknowledgements :pray:
Thanks to all the software engineers, peers from different cohorts of the Holberton School, for all the learning that we have been able to acquire in this academic period culminating in this shell emulation. 

For more information about Holberton, visit this [link](https://www.holbertonschool.com/).

<p align="center">
<img src="http://www.holbertonschool.com/holberton-logo.png" alt="Holberton School logo">
</p>
