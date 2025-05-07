<img src="assests/logo.png" alt="VISH" width="700" align="center"/>

<br>
<h1>A simplified shell built in C, which replicates the basic UNIX terminal functionalities</h1>
<br>

![Repo Size](https://img.shields.io/github/repo-size/viniXLeite/mini_shell_terminal_C) 
![Last Commit](https://img.shields.io/github/last-commit/viniXLeite/mini_shell_terminal_C)

<span style="font-size:18px; text-align: justify; display: block; width: 100%">The purpose of this project is to work on the analysis of user input, execption handling, memory allocation and security, data structure and the core functionalities of a UNIX SHELL. The working of VISH is based on the principles of REPL (read, parse, print and loop) which was implemented and divided into the files prompt.h, parser.h, executor.h and builtins.h. The Parser is responsible for breaking down user input into tokens while respecting the limits of quotes marks and empty spaces; Once commands have been separated from the original input, the script is added to a queue structure so that it can be analyzed and executed by the Executer.</span>

<span style="font-size:18px; text-align: justify; display: block; width: 100%">PT-BR: O objetivo desse projeto é trabalhar a análise de entradas de usuários, tratamento de exceções, alocação e segurança de memória, estrutura de dados e as principais funcionalidades do UNIX SHELL. O funcionamento do VISH se baseia nos princípios do REPL (read, parse, print and loop) que foi implementado e dividido nos arquivos prompt.h, parser.h, executor.h e builtins.h. O Parser se responsabiliza por quebrar o input do usuário em tokens respeitando os limites das aspas e dos espaços vazios; Uma vez que os comandos foram separados do input original, o scrpit é adicionado à uma estrutura fila para que ele seja análisado e executado pelo Executer.</span>

## Main functionalities

- `exit [n]` - Close the VISH application
- `clr` - Clear the terminal screen
- `echo [string]` - Exhibit a formated message
- `pwd` - Exhibit the current path
- `ls` - List the directory content
- `cd [dir]` - Navigate betwen directories
- `touch [file]...` - Create a file
- `cat [file]...` - Exhibit the content of a file

## Tecnologies and concepts:

- Language: C (In order to a direct acess syscalls as fork(), execvp(), chdir()).
- Libraries: <stdio.h>, <stdlib.h>, <unistd.h>, <string.h>.
- Data structures: strings, dinamyc arrays, queue e list.

