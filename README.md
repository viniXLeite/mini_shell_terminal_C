                                                                                              :::     ::: :::::::::::  ::::::::  :::    :::
                                                                                              :+:     :+:     :+:     :+:    :+: :+:    :+:
                                                                                              +:+     +:+     +:+     +:+        +:+    +:+
                                                                                              +#+     +:+     +#+     +#++:++#++ +#++:++#++
                                                                                               +#+   +#+      +#+            +#+ +#+    +#+
                                                                                                #+#+#+#       #+#     #+#    #+# #+#    #+#
                                                                                                  ###     ###########  ########  ###    ###


##Este projeto consiste em um terminal shell simplificado, desenvolvido para executar comandos básicos em um ambiente Unix/Linux. Inspirado em shells como Bash, ele oferece uma interface interativa onde o usuário pode digitar comandos e receber saídas em tempo real, além de suportar operações essenciais de manipulação de arquivos, diretórios e processos.
Funcionalidades Implementadas:

✅ Comandos Internos:

    exit → Encerra o shell.

    clr → Limpa a tela do terminal.

    echo → Exibe mensagens na saída padrão.

    pwd → Mostra o diretório atual.

    ls → Lista arquivos e diretórios.

    cd → Navega entre diretórios.

    touch → Cria arquivos vazios.

    cat → Exibe o conteúdo de arquivos.

Tecnologias e Conceitos Utilizados:

    Linguagem: C (para acesso direto a syscalls como fork(), execvp(), chdir()).

    Bibliotecas: <stdio.h>, <stdlib.h>, <unistd.h>, <string.h>.

    Estruturas de Dados: Manipulação de strings, arrays dinâmicos.

Objetivo:

Fornecer uma base funcional para um shell customizável, podendo ser expandido com novos comandos, autocompletar, scripts ou até mesmo uma interface gráfica futuramente.

Código Fonte: GitHub (link fictício para exemplo).
