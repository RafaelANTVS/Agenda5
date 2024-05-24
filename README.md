# projeto 5 - Vespertino (CC2632)

# **Agenda de contatos**

## Objetivo


Agenda de contatos permite o usuário registrar seu nome, número e e-mail em um arquivo.
Ele guarda em duas listas a vontade do usuario, sendo uma lista para contatos de trabalho e outra pessoal.
Cada registro numera uma prioridade ao contato, sendo o limite de contatos 255.


## Compilação


Será utilizado um programa que leia arquivos em formato C e por meio do seu terminal o usuário digita "gcc *.c && ./a.out" fazendo o código funcionar.

## Utilização


Um menu aparecerá na tela dando 6 opções ao usuário, cada opção servindo a uma ação para serem digitadas, precisando ser um dos seguintes números:

- 1- Cria um contato na ordem do nome, e-mail e numero de telefone, será dada uma posição na memória desse contato, não podendo repetir o número de telefone com outros e o e-mail tem requisitos para que seja considerado um e-mail. 
- 2- Pede um numero de telefone para deletar, se for encontrado, o contato com o respectivo numero sera apagado.
- 3- Lista todos os contatos com os dados na memória.
- 4- Salva em uma agenda em binário, os dados registrados ao criar o contato dando uma segurança maior porem dificultando sua leitura para programas C.
- 5- Carrega a agenda para o usuário visualizar ou continuar sua agenda da onde parou quando salvou.
- 6- Muda um dos dados a pedido do usuario, tendo as mesmas regras do criar contato, onde não pode repetir telefone e o e-mail possui requisitos.
- 0- Digitando "0" ele sairá do programa.
