<img src="assests/logo.png" alt="VISH" width="700" align="center"/>

<br>
<br>
<span style="font-size:20px">Um shell simplificado desenvolvido em C, replicando funcionalidades básicas de terminais Unix/Linux.</span>
<br>


![Repo Size](https://img.shields.io/github/repo-size/viniXLeite/mini_shell_terminal_C) 
![Last Commit](https://img.shields.io/github/last-commit/viniXLeite/mini_shell_terminal_C)


## Funcionalidades Principais

- `exit [n]` - Encerra o shell com código opcional
- `clr` - Limpa a tela do terminal
- `echo [string]` - Exibe mensagens formatadas
- `pwd` - Exibe o diretório atual
- `ls` - Lista conteúdo de diretórios
- `cd [dir]` - Navega entre diretórios
- `touch [file]...` - Cria arquivos 
- `cat [file]...` - Exibe conteúdo de arquivos

## Tecnologias e Conceitos Utilizados:

- Linguagem: C (para acesso direto a syscalls como fork(), execvp(), chdir()).
- Bibliotecas: <stdio.h>, <stdlib.h>, <unistd.h>, <string.h>.
- Estruturas de Dados: Manipulação de strings, arrays dinâmicos.

## Objetivos
- Fornecer uma base funcional para um shell customizável, podendo ser expandido com novos comandos, autocompletar, scripts ou até mesmo uma interface gráfica futuramente.
