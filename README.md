:::     ::: :::::::::::  ::::::::  :::    :::
:+:     :+:     :+:     :+:    :+: :+:    :+:
+:+     +:+     +:+     +:+        +:+    +:+
+#+     +:+     +#+     +#++:++#++ +#++:++#++
 +#+   +#+      +#+            +#+ +#+    +#+
  #+#+#+#       #+#     #+#    #+# #+#    #+#
    ###     ###########  ########  ###    ###

Um shell simplificado desenvolvido em C, replicando funcionalidades básicas de terminais Unix/Linux.

## Funcionalidades Principais

- `exit [n]` - Encerra o shell com código opcional
- `clr` - Limpa a tela do terminal
- `echo [-e] [-n] [string]` - Exibe mensagens formatadas
- `pwd` - Exibe o diretório atual
- `ls [-l] [-a] [dir]` - Lista conteúdo de diretórios
- `cd [dir]` - Navega entre diretórios
- `touch [file]...` - Cria arquivos vazios
- `cat [file]...` - Exibe conteúdo de arquivos

### Gerenciamento de Processos
- Execução de programas externos (`./programa`)
- Suporte a processos em background (`comando &`)

### Recursos Avançados
- Redirecionamento I/O (`>`, `<`, `>>`, `|`)
- Histórico de comandos (navegação com ↑/↓)
- Tratamento robusto de erros

## Tecnologias e Conceitos Utilizados:

- Linguagem: C (para acesso direto a syscalls como fork(), execvp(), chdir()).
- Bibliotecas: <stdio.h>, <stdlib.h>, <unistd.h>, <string.h>.
- Estruturas de Dados: Manipulação de strings, arrays dinâmicos.

## Objetivos
- Fornecer uma base funcional para um shell customizável, podendo ser expandido com novos comandos, autocompletar, scripts ou até mesmo uma interface gráfica futuramente.

