# Aula 03 - Tutorial processos - Sistemas Operacionais II

Item | Nota
-----|-----
1.4  |  
2.1  |
3.1  |
Total|

## Objetivos

* Criação de processos com `fork`
* Sincronização de processos com `wait`
* Conceito de processos zumbis
* Execução de programas com `exec`

# Atividade 1 - Explorando a chamada de sistema `fork`

## Passo 1.1 - Experimentos com o programa `duplo.c`

Leia, compile e execute o programa `duplo.c`

Duplique a linha com `fork` e observe as consequências

Repita, mas triplicando

## Passo 1.2 - Diferenciando os processos

Explore `man 2 fork`

Pontos a observar:
* O valor do retorno de `fork`
* Os erros de `fork` (que são improváveis)

Modifique `duplo.c` de forma que os processos imprimam mensagens diferentes

## Passo 1.3 - Consultando processos do sistema

Experimente:
* `ps`
* `ps aux`
* `top`
* `ls /proc`

Referências adicionais:
* `man ps`, no campo *state*
* https://en.wikipedia.org/wiki/Process_state

## Passo 1.4 - Exercício `myleave.c`

Entenda o comando `leave`

`man leave`

Experimente `leave +1`, espere um minuto, e observe

Encerre o processo com `kill -9 <número do processo>` (se não sabe o número, `ps`)

Crie o programa `myleave.c`: 
* Diferentemente de `leave`, só avisa uma vez, e
* usa segundos em vez de minutos, e
* dispensa o `+`
* Use a função C `sleep` de `unistd.h` (`man 3 sleep`)

# Atividade 2 - Explorando a chamada de sistema `wait` e `waitpid`

Programação concorrente: um programa com partes que interferem umas nas outras

Separar + reencontrar (interferir)

Examine `wait`

Pontos a observar:
* `wait` é um caso particular de `waitpid`
* `wait` e `waitpid` usam uma variável para receber o resultado dos processos filhos, e ela deve ser processada com macros
* Os processos filhos retornam resultados através de `exit`
* `waitpid` recebe também flags; a ver no futuro

## Passo 2.1 - Modificando `myleave.c`

Modifique o programa `myleave.c` para que o processo pai espere (através de `waitpid`) o processo que envia a mensagem. O processo deve retornar o número 42. Confirme o valor no recebimento.

## Passo 2.2 - Processos zumbis

Substitua o `waitpid` por um laço infinito. Observe o estado dos processos depois do atraso.

# Atividade 3 - Explorando as funções `execv` e variantes

`execv`, `execve`, `execvp`

Causam a incrível transformação de um processo em outro programa
* As linhas abaixo jamais seriam executadas, a menos de um erro
* `e` indica *environment*, `p`, *path*
* Requerem um array de strings com as chaves e parâmetros

# Passo 3.1 - Programa `lsl.c`

Explore o programa `lsl.c`. Modifique para funcionar com `execv`.