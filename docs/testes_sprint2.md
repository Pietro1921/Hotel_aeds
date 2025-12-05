Relatório de Testes – Sprint 2

Projeto: Hotel Descanso Garantido
Sprint: 2
Desenvolvedor: Davi Santana
Data: 04/12/2025

Objetivo da Sprint 2

Implementar as funcionalidades de cadastro com validação de unicidade e persistência em arquivo binário, conforme o Product Backlog:

PB	Descrição
PB06	Cadastrar Cliente (validar código único)
PB07	Cadastrar Funcionário (validar código único)
PB08	Cadastrar Quarto (validar número único + status inicial "desocupado")

Todas as funções foram implementadas com retorno padronizado:

1 → Sucesso

0 → Duplicado

-1 → Erro de arquivo / persistência

Também foi desenvolvido um programa de teste manual (sprint2_test.c) contendo um menu para validar cada cadastro.

Plano de Testes da Sprint 2
Ambiente

Compilador: gcc

Comando utilizado:

gcc src/*.c -I include -o sprint2_test


Arquivos binários gerados em: /data/

Caso de Teste 1 – PB06: Cadastrar Cliente (sucesso)
Entradas:
Código: 1
Nome: João Silva
Endereço: Rua A
Telefone: 319999999

Resultado esperado:
Cliente cadastrado com sucesso.

Resultado obtido:

Cliente cadastrado com sucesso.

Observação:

Arquivo clientes.bin criado e cliente armazenado corretamente.

Caso de Teste 2 – PB06: Cadastrar Cliente (código duplicado)
Pré-condição:

Cliente de código 1 já existe.

Entradas:
Código: 1
Nome: João Teste
Endereço: Rua B
Telefone: 319888888

Resultado esperado:
ERRO: codigo de cliente duplicado.

Resultado obtido:

ERRO: codigo de cliente duplicado.

Observação:

Sistema validou corretamente a duplicidade.

Caso de Teste 3 – PB07: Cadastrar Funcionário (sucesso)
Entradas:
Código: 10
Nome: Maria
Telefone: 319777777
Cargo: Atendente
Salário: 2000

Resultado esperado:
Funcionario cadastrado com sucesso.

Resultado obtido:

Funcionario cadastrado com sucesso.

Caso de Teste 4 – PB07: Funcionário duplicado
Pré-condição:

Funcionário de código 10 já existe.

Entradas:
Código: 10
Nome: Maria Teste
Telefone: 319111111
Cargo: Gerente
Salário: 5000

Resultado esperado:
ERRO: codigo de funcionario duplicado.

Resultado obtido:

ERRO: codigo de funcionario duplicado.

Caso de Teste 5 – PB08: Cadastrar Quarto (sucesso)
Entradas:
Número: 101
Qtd. Hóspedes: 2
Valor diária: 150

Resultado esperado:
Quarto cadastrado com sucesso.

Resultado obtido:

Quarto cadastrado com sucesso.

Observação:

Campo status automaticamente definido como "desocupado" conforme o Backlog.

Caso de Teste 6 – PB08: Quarto duplicado
Pré-condição:

Quarto de número 101 já existe.

Entradas:
Número: 101
Qtd. Hóspedes: 3
Valor diária: 200

Resultado esperado:
ERRO: numero de quarto duplicado.

Resultado obtido:

ERRO: numero de quarto duplicado.

Conclusão da Sprint 2

Todos os itens do backlog foram implementados corretamente:

Persistência funcionando

Validação de unicidade funcionando

Estruturas corretas

Testes de sucesso e erro validados

Binários gerados e atualizados conforme esperado