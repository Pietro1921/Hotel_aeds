Sistema de Gerenciamento de Hotel – AEDs I
Descrição

Este projeto consiste no desenvolvimento de um sistema de gerenciamento de hotel, implementado em linguagem C, utilizando estruturas (struct), arquivos binários para persistência de dados, organização modular em arquivos .c e .h e controle de versão com GitHub.

O sistema simula operações reais de um hotel, como cadastro de clientes, funcionários, quartos, controle de estadias (check-in e check-out), cálculo de valores, fidelidade, estatísticas e geração de relatórios.

Funcionalidades Implementadas
--> Sprint 1

Cadastro de clientes

Persistência em arquivo binário (clientes.bin)

--> Sprint 2

Cadastro de funcionários

Cadastro de quartos

Persistência em arquivos binários

--> Sprint 3

Criação de estadias (check-in)

Encerramento de estadias (check-out)

Controle de ocupação de quartos

Cálculo de diárias e valor total

--> Sprint 4

Sistema de fidelidade (10 pontos por diária)

Pesquisa de clientes

Pesquisa de funcionários

Listagem de estadias por cliente

--> Sprint 5

Estatísticas do sistema:

Total de clientes

Total de funcionários

Total de quartos

Total de estadias

--> Sprint 6

Geração de relatórios em arquivos .txt

Relatório de fidelidade

Ranking de clientes

📁 Estrutura do Projeto
Hotel_aeds/
├── src/
│   ├── cliente.c
│   ├── funcionario.c
│   ├── quarto.c
│   ├── estadia.c
│   ├── persistencia.c
│   ├── data.c
│   ├── estatisticas.c
│   ├── relatorios.c
│   └── main.c
│
├── include/
│   ├── cliente.h
│   ├── funcionario.h
│   ├── quarto.h
│   ├── estadia.h
│   ├── persistencia.h
│   ├── data.h
│   ├── estatisticas.h
│   ├── relatorios.h
│   └── structs.h
│
├── data/        (arquivos binários gerados em execução)
├── relatorios/  (arquivos .txt gerados pelo sistema)
├── README.md
└── .gitignore

Como Compilar

No terminal (VS Code ou CMD):

gcc src/*.c -I include -o hotel.exe

Como Executar
.\hotel.exe

Autores

Davi Santana

Pietro Lage

🔗 Repositório GitHub

https://github.com/Pietro1921/Hotel_aeds.git
