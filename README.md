<img src="assests/logo.png" alt="VISH" width="700" align="center"/>

<br>
<span style="font-size:20px">Um shell simplificado desenvolvido em C, replicando funcionalidades básicas de terminais Unix/Linux.</span>
<br>
<br>

![Repo Size](https://img.shields.io/github/repo-size/viniXLeite/mini_shell_terminal_C) 
![Last Commit](https://img.shields.io/github/last-commit/viniXLeite/mini_shell_terminal_C)

     
RESVCREVER:
Nesse projeto criamos o nosso próprio bash, em uma escala menor. O propósito dele é nos fazer trabalhar com múltiplos processos, file descriptors, tratamento de entrada do usuário, entre diversos outros desafios menores.
Ao realizar esse projeto ganhamos o conhecimento de como o bash funciona por baixo dos panos, como nosso input é tratado e como os comandos dados a ele são executados.
O Minishell é um projeto muito desafiador, por ser longo e ser o primeiro projeto colaborativo do currículo, forçando não apenas o nosso treinamento técnico, com o código em si, mas também nossas habilidades de comunicação, em todas as trocas com a sua dupla durante todo o processo).
Embora trabalhoso, é um projeto muito divertido e com um retorno de conhecimento e sentimento de realização enormes.
🤓 Um pouco sobre as etapas do código
🔪 PARSER: A primeira coisa a se fazer é separar o input do usuário e tipar cada argumento recebido. Para isso fizemos uma separação de processos, separando os inputs por cada '|' pipe encontrado e depois pelos espaços (tratamento especial quando há aspas). Isso nos deixava cada arumento em um token, onde conseguíamos tipar o que aquele token era: comando simples, argumento, buildin, arquivo, redirecionamento, etc.
📖 EXPANDER: Feito os tokens, o expander rodava eles em busca do '$' e das aspas para a expansão das variáveis de ambiente e remoção das aspas. Caso o expander encontrasse a variável descrida depois do símbulo ($), ele a substituia pelo seu valor (guardado na nossa variável envp), caso contrário, substituia pur vazio (""). Já as aspas, seguindo algumas regras, eram removidas do token.
🏁 EXECUTER: Com os tokens prontos para montar os comandos, o executor os juntavam em um array de strings (formato aceito pela função execve). Verificava a quantidade de processos, checando a quantidade de pipes, e abria processos filhos para lidar com os comandos. Checava o caminho disponível da variável PATH e passava para a função execve. O único caso em que o comando é rodado no processo pai é quando temos apenas um processo/comando e este é um Build-in. Os Build-ins serão descritos no próximo tópico.



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
- Estruturas de Dados: Manipulação de strings, arrays dinâmicos, filas e listas.

## Objetivos
- Fornecer uma base funcional para um shell customizável, podendo ser expandido com novos comandos, autocompletar, scripts ou até mesmo uma interface gráfica futuramente.
