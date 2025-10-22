#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente
{
    char nome [50];
    char CPF [25];
    char telefone [25];
} cliente;

typedef struct Veiculo
{
    char placa [30];
    char modelo [40];
    int ano;
    cliente *dono;
} veiculo;

 typedef struct ordemservico
{
    int status; 
    int idordem;
    veiculo *automovel;
    char dataentrada [15];
    char descricaoproblema [100]; 


} ordemservico;


int buscarcliente (cliente *clientes, int quantidadeclientes, char *cpf);

void adicionarcliente (cliente *clientes, int *quantidadeclientes);

void adicionarveiculo (veiculo *veiculos, int *quantidadeveiculos, cliente *clientes, int quantidadeclientes);

int buscarveiculo (veiculo *veiculos, int quantidadeveiculos, char *placa);

void adicionarordemservico (ordemservico *ordens, int *quantidadeordens, veiculo *veiculos, int quantidadeveiculos);

int buscarveiculo (veiculo *veiculos, int quantidadeveiculos, char *placa);

void listarclientes (cliente *clientes, int quantidadeclientes);

void listarordemservico (ordemservico *ordens, int quantidadeordens);

void listarveiculos (veiculo *veiculos, int quantidadeveiculos);

void modificarveiculo (veiculo *veiculos, int quantidadeveiculos, cliente *clientes, int quantidadeclientes);

void modificarordemservico (ordemservico *ordens, int quantidadeordens);

void modificarcliente (cliente *clientes, int quantidadeclientes);

int buscarOrdemServico (ordemservico *ordens, int quantidadeordens, int idordem);

void removercliente (cliente *clientes, int *quantidadeclientes, veiculo *veiculos, int quantidadeveiculos, ordemservico *ordens, int quantidadeordens);

void removerveiculo (veiculo *veiculos, int *quantidadeveiculos, ordemservico *ordens, int quantidadeordens);

void removerordemservico (ordemservico *ordens, int *quantidadeordens);

int menu();

void escrevermemoria(cliente *clientes, int quantidadeclientes, veiculo *veiculos, int quantidadeveiculos, ordemservico *ordens, int quantidadeordens);

void lermemoria(cliente *clientes, int *quantidadeclientes, veiculo *veiculos, int *quantidadeveiculos, ordemservico *ordens, int *quantidadeordens);

void gerarrelatorio(ordemservico *ordens, int quantidadeordens);


int main () {
    printf("Estruturas com ponteiros em C\n");
    
    cliente *Cliente = (cliente *) malloc (300 *sizeof(cliente)); // vetor dinamico de clientes para 300 clientes
    int quantidade_clientes = 0;
    if (Cliente == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    //adicionar cliente
    //adicionarcliente(Cliente, &quantidade_clientes);



    veiculo *Veiculo = (veiculo *) malloc (300 *sizeof(veiculo)); // vetor dinamico de veiculos para 300 veiculos
    int quantidade_veiculos = 0;
    if (Veiculo == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    //adicionar veiculo
    //adicionarveiculo(Veiculo, &quantidade_veiculos, Cliente, quantidade_clientes);

    ordemservico *Ordem = (ordemservico *) malloc (300 *sizeof(ordemservico)); // vetor dinamico de ordens de servico para 300 ordens
    int quantidade_ordens = 0;
    if (Ordem == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    //adicionar ordem de servico
    //adicionarordemservico(Ordem, &quantidade_ordens, Veiculo, quantidade_veiculos);

    lermemoria(Cliente, &quantidade_clientes, Veiculo, &quantidade_veiculos, Ordem, &quantidade_ordens);

    while (1){
        int op = menu();
        int sair = 0;
        char cpf[15];

        switch (op){
        case 0:
            sair = 1;
            break;
        case 1:
            adicionarcliente(Cliente, &quantidade_clientes);
            break;
        case 2:
            adicionarveiculo(Veiculo, &quantidade_veiculos, Cliente, quantidade_clientes);
            break;
        case 3:
            adicionarordemservico(Ordem, &quantidade_ordens, Veiculo, quantidade_veiculos);
            break;
        case 4:
            listarclientes(Cliente, quantidade_clientes);
            break;
        case 5:
            listarveiculos(Veiculo, quantidade_veiculos);
            break;
        case 6:
            listarordemservico(Ordem, quantidade_ordens);
            break;
        case 7:
            removercliente(Cliente, &quantidade_clientes, Veiculo, quantidade_veiculos, Ordem, quantidade_ordens);
            break;
        case 8:
            removerveiculo(Veiculo, &quantidade_veiculos, Ordem, quantidade_ordens);
            break;
        case 9:
            removerordemservico(Ordem, &quantidade_ordens);
            break;
        case 10:
            modificarcliente(Cliente, quantidade_clientes);
            break;
        case 11:
            modificarveiculo(Veiculo, quantidade_veiculos, Cliente, quantidade_clientes);
            break;
        case 12:
            modificarordemservico(Ordem, quantidade_ordens);
            break;
        }
        if (sair) {
            break;
        }
    }

    escrevermemoria(Cliente, quantidade_clientes, Veiculo, quantidade_veiculos, Ordem, quantidade_ordens);


  return 0;     
}

int menu(){
    printf("==========MENU===========\n");
    printf("0 - sair do programa\n");
    printf("1 - adicionar clientes \n");
    printf("2 - adicionar veiculo\n");
    printf("3 - adicionar ordem de serviço\n");
    printf("4 - listar clientes\n");
    printf("5 - listar veiculos \n");
    printf("6 - listar ordem de serviço\n");
    printf("7 - remover clientes\n");
    printf("8 - remover veiculos\n");
    printf("9 - remover ordem de serviço\n");
    printf("10 - modificar clientes\n");
    printf("11 - modificar veiculo\n");
    printf("12 - modificar ordem de serviço\n");
    printf("13 - gerar relatorio\n");

    int opcao;
    printf("\n Escolha uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}



void listarordemservico (ordemservico *ordens, int quantidadeordens) {
    printf("Lista de Ordens de Servico:\n");
    for (int i = 0; i < quantidadeordens; i++) {
        printf("Ordem de Servico %d:\n", ordens[i].idordem);
        printf("Status: %s\n", ordens[i].status == 0 ? "Pendente" : "Concluido");
        printf("Data de Entrada: %s\n", ordens[i].dataentrada);
        printf("Descricao do Problema: %s\n", ordens[i].descricaoproblema);
        printf("Veiculo:\n");
        printf("  Placa: %s\n", ordens[i].automovel->placa);
        printf("  Modelo: %s\n", ordens[i].automovel->modelo);
        printf("Dono do Veiculo:\n");
        printf("  Nome: %s\n", ordens[i].automovel->dono->nome);
        printf("  CPF: %s\n", ordens[i].automovel->dono->CPF);
        printf("-----------------------\n");
    }
}

void listarveiculos (veiculo *veiculos, int quantidadeveiculos) {
    printf("Lista de Veiculos:\n");
    for (int i = 0; i < quantidadeveiculos; i++) {
        printf("Veiculo %d:\n", i + 1);
        printf("Placa: %s\n", veiculos[i].placa);
        printf("Modelo: %s\n", veiculos[i].modelo);
        printf("Ano: %d\n", veiculos[i].ano);
        printf("Dono do Veiculo:\n");
        printf("  Nome: %s\n", veiculos[i].dono->nome);
        printf("  CPF: %s\n", veiculos[i].dono->CPF);
        printf("-----------------------\n");
    }
}

int buscarcliente (cliente *clientes, int quantidadeclientes, char *cpf) {
    for (int i = 0; i < quantidadeclientes; i++) {
        if (strcmp(clientes[i].CPF, cpf) == 0) {
            return i; // retorna o índice do cliente encontrado
        }
    }
    return -1; // retorna -1 se o cliente não for encontrado
}

void adicionarveiculo (veiculo *veiculos, int *quantidadeveiculos, cliente *clientes, int quantidadeclientes) {
    

    char cpf[25];
    printf("Digite o CPF do dono do veiculo: ");
    scanf("%s", cpf);

    int indicecliente = buscarcliente(clientes, quantidadeclientes, cpf);
    if (indicecliente != -1) {
        veiculos[*quantidadeveiculos].dono = &clientes[indicecliente];
        printf("Digite a placa do veiculo: ");
        scanf("%s", veiculos[*quantidadeveiculos].placa);
        printf ("Digite o modelo do veiculo: ");
        scanf("%s", veiculos[*quantidadeveiculos].modelo);
        printf ("Digite o ano do veiculo: ");
        scanf("%d", &veiculos[*quantidadeveiculos].ano);
        (*quantidadeveiculos)++;
        printf("Veiculo adicionado com sucesso!\n");
    } else {
        printf("Cliente com CPF %s nao encontrado. Veiculo nao adicionado.\n", cpf);
    }
} 

void adicionarcliente (cliente *clientes, int *quantidadeclientes) {
    printf("Digite o nome do cliente: ");
    scanf("%s", clientes[*quantidadeclientes].nome);
    printf ("Digite o CPF do cliente: ");
    scanf("%s", clientes[*quantidadeclientes].CPF);
    printf ("Digite o telefone do cliente: ");
    scanf("%s", clientes[*quantidadeclientes].telefone);
    printf("Cliente %s\nCPF: %s\nTelefone: %s\n", clientes[*quantidadeclientes].nome, clientes[*quantidadeclientes].CPF, clientes[*quantidadeclientes].telefone);

    (*quantidadeclientes)++; 
}

void adicionarordemservico (ordemservico *ordens, int *quantidadeordens, veiculo *veiculos, int quantidadeveiculos) {
    char placa[30];
    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);
    printf("Procurando veiculo com placa %s...\n", placa);
    printf("veiculo 0 placa: %s\n", veiculos[0].placa); // Debug line to check the first vehicle's plate

    int indiceveiculo = buscarveiculo(veiculos, quantidadeveiculos, placa);
    if (indiceveiculo != -1) {
        ordens[*quantidadeordens].automovel = &veiculos[indiceveiculo];
        printf("Digite a data de entrada (DD/MM/AAAA): ");
        scanf("%s", ordens[*quantidadeordens].dataentrada);
        printf("Digite a descricao do problema: ");
        scanf("%s", ordens[*quantidadeordens].descricaoproblema);
        ordens[*quantidadeordens].status = 0; // 0 para pendente
        ordens[*quantidadeordens].idordem = *quantidadeordens + 1; // ID sequencial
        (*quantidadeordens)++;
        printf("Ordem de servico adicionada com sucesso!\n");
    } else {
        printf("Veiculo com placa %s nao encontrado. Ordem de servico nao adicionada.\n", placa);
    }
}

int buscarveiculo (veiculo *veiculos, int quantidadeveiculos, char *placa) {
    for (int i = 0; i < quantidadeveiculos; i++) {
        if (strcmp(veiculos[i].placa, placa) == 0) {
            return i; // retorna o índice do veiculo encontrado
        }
    }
    return -1; // retorna -1 se o veiculo não for encontrado
}

void listarclientes (cliente *clientes, int quantidadeclientes) {
    printf("Lista de Clientes:\n");
    for (int i = 0; i < quantidadeclientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].CPF);
        printf("Telefone: %s\n", clientes[i].telefone);
        printf("-----------------------\n");
    }

}


void modificarcliente (cliente *clientes, int quantidadeclientes) {
    char cpf[25];
    printf("Digite o CPF do cliente a ser modificado: ");
    scanf("%s", cpf);

    int indicecliente = buscarcliente(clientes, quantidadeclientes, cpf);
    if (indicecliente != -1) {
        printf("Modificando dados do cliente %s:\n", clientes[indicecliente].nome);
        printf("Digite o novo nome (atual: %s): ", clientes[indicecliente].nome);
        scanf("%s", clientes[indicecliente].nome);
        printf("Digite o novo telefone (atual: %s): ", clientes[indicecliente].telefone);
        scanf("%s", clientes[indicecliente].telefone);
        printf("Cliente modificado com sucesso!\n");
    } else {
        printf("Cliente com CPF %s nao encontrado.\n", cpf);
    }
}

void modificarveiculo (veiculo *veiculos, int quantidadeveiculos, cliente *clientes, int quantidadeclientes) {
    char placa[30];
    printf("Digite a placa do veiculo a ser modificado: ");
    scanf("%s", placa);

    int indiceveiculo = buscarveiculo(veiculos, quantidadeveiculos, placa);
    if (indiceveiculo != -1) {
        printf("Modificando dados do veiculo %s:\n", veiculos[indiceveiculo].placa);
        printf("Digite o novo modelo (atual: %s): ", veiculos[indiceveiculo].modelo);
        scanf("%s", veiculos[indiceveiculo].modelo);
        printf("Digite o novo ano (atual: %d): ", veiculos[indiceveiculo].ano);
        scanf("%d", &veiculos[indiceveiculo].ano);
        printf("Veiculo modificado com sucesso!\n");
    } else {
        printf("Veiculo com placa %s nao encontrado.\n", placa);
    }

    printf("Deseja modificar o dono do veiculo?\n");
    char opcao;
    printf("Digite 's' para sim ou 'n' para nao: ");
    scanf(" %c", &opcao);
    if (opcao == 's' || opcao == 'S') {
        char cpf[25];
        printf("Digite o CPF do novo dono do veiculo: ");
        scanf("%s", cpf);

        int indicecliente = buscarcliente(clientes, quantidadeclientes, cpf);
        if (indicecliente != -1) {
            veiculos[indiceveiculo].dono = &clientes[indicecliente];
            printf("Dono do veiculo modificado com sucesso!\n");
        } else {
            printf("Cliente com CPF %s nao encontrado. Dono do veiculo nao modificado.\n", cpf);
        }
    }
}

void modificarordemservico (ordemservico *ordens, int quantidadeordens) {
    int idordem;
    printf("Digite o ID da ordem de servico a ser modificada: ");
    scanf("%d", &idordem);

    int indiceordem = -1;
    for (int i = 0; i < quantidadeordens; i++) {
        if (ordens[i].idordem == idordem) {
            indiceordem = i;
            break;
        }
    }

    if (indiceordem != -1) {
        printf("Modificando dados da ordem de servico %d:\n", ordens[indiceordem].idordem);
        printf("Digite a nova descricao do problema (atual: %s): ", ordens[indiceordem].descricaoproblema);
        scanf("%s", ordens[indiceordem].descricaoproblema);
        printf("Digite o novo status (0 para pendente, 1 para concluido, atual: %d): ", ordens[indiceordem].status);
        scanf("%d", &ordens[indiceordem].status);
        printf("Ordem de servico modificada com sucesso!\n");
    } else {
        printf("Ordem de servico com ID %d nao encontrada.\n", idordem);
    }
}

int buscarOrdemServico (ordemservico *ordens, int quantidadeordens, int idordem) {
    for (int i = 0; i < quantidadeordens; i++) {
        if (ordens[i].idordem == idordem) {
            return i; // retorna o índice da ordem de servico encontrada
        }
    }
    return -1; // retorna -1 se a ordem de servico não for encontrada
}

void removercliente (cliente *clientes, int *quantidadeclientes, veiculo *veiculos, int quantidadeveiculos, ordemservico *ordens, int quantidadeordens) {
    char cpf[25];
    printf("Digite o CPF do cliente a ser removido: ");
    scanf("%s", cpf);

    int indicecliente = buscarcliente(clientes, *quantidadeclientes, cpf);
    // removendo os veiculos associados ao cliente
    if(indicecliente != -1) {
        for (int i = 0; i < quantidadeveiculos; i++) {
            if (veiculos[i].dono != NULL && strcmp(veiculos[i].dono->CPF, cpf) == 0) {
                // Shift veiculos para remover o veiculo associado
                for (int j = i; j < quantidadeveiculos - 1; j++) {
                    veiculos[j] = veiculos[j + 1];
                }
                quantidadeveiculos--;
                i--; // Ajusta o índice para verificar o próximo veiculo
            }
        }
    }
    // removendo as ordens de servico associadas ao cliente
    if(indicecliente != -1) {
        for (int i = 0; i < quantidadeordens; i++) {
            if (ordens[i].automovel != NULL && ordens[i].automovel->dono != NULL && strcmp(ordens[i].automovel->dono->CPF, cpf) == 0) {
                // Shift ordens para remover a ordem associada
                for (int j = i; j < quantidadeordens - 1; j++) {
                    ordens[j] = ordens[j + 1];
                }
                quantidadeordens--;
                i--; // Ajusta o índice para verificar a próxima ordem
            }
        }
    }
    if (indicecliente != -1) {
        for (int i = indicecliente; i < *quantidadeclientes - 1; i++) {
            clientes[i] = clientes[i + 1];
        }
        (*quantidadeclientes)--;
        printf("Cliente com CPF %s removido com sucesso!\n", cpf);
    } else {
        printf("Cliente com CPF %s nao encontrado.\n", cpf);
    }
}

void removerveiculo (veiculo *veiculos, int *quantidadeveiculos, ordemservico *ordens, int quantidadeordens) {
    char placa[30];
    printf("Digite a placa do veiculo a ser removido: ");
    scanf("%s", placa);

    int indiceveiculo = buscarveiculo(veiculos, *quantidadeveiculos, placa);

    // removendo as ordens de servico associadas ao veiculo
    if(indiceveiculo != -1) {
        for (int i = 0; i < quantidadeordens; i++) {
            if (ordens[i].automovel != NULL && strcmp(ordens[i].automovel->placa, placa) == 0) {
                // Shift ordens para remover a ordem associada
                for (int j = i; j < quantidadeordens - 1; j++) {
                    ordens[j] = ordens[j + 1];
                }
                quantidadeordens--;
                i--; // Ajusta o índice para verificar a próxima ordem
            }
        }
    }
    if (indiceveiculo != -1) {
        for (int i = indiceveiculo; i < *quantidadeveiculos - 1; i++) {
            veiculos[i] = veiculos[i + 1];
        }
        (*quantidadeveiculos)--;
        printf("Veiculo com placa %s removido com sucesso!\n", placa);
    } else {
        printf("Veiculo com placa %s nao encontrado.\n", placa);
    }
}

void removerordemservico (ordemservico *ordens, int *quantidadeordens) {
    int idordem;
    printf("Digite o ID da ordem de servico a ser removida: ");
    scanf("%d", &idordem);

    int indiceordem = buscarOrdemServico(ordens, *quantidadeordens, idordem);
    if (indiceordem != -1) {
        for (int i = indiceordem; i < *quantidadeordens - 1; i++) {
            ordens[i] = ordens[i + 1];
        }
        (*quantidadeordens)--;
        printf("Ordem de servico com ID %d removida com sucesso!\n", idordem);
    } else {
        printf("Ordem de servico com ID %d nao encontrada.\n", idordem);
    }
}

void escrevermemoria(cliente *clientes, int quantidadeclientes, veiculo *veiculos, int quantidadeveiculos, ordemservico *ordens, int quantidadeordens) {
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escrever clientes
    fprintf(arquivo, "Clientes %d\n", quantidadeclientes);
    for (int i = 0; i < quantidadeclientes; i++) {
        fprintf(arquivo, "%s %s %s\n", clientes[i].nome, clientes[i].CPF, clientes[i].telefone);
    }

    // Escrever veiculos
    fprintf(arquivo, "Veiculos %d\n", quantidadeveiculos);
    for (int i = 0; i < quantidadeveiculos; i++) {
        fprintf(arquivo, "%s %s %d %s\n", veiculos[i].placa, veiculos[i].modelo, veiculos[i].ano, veiculos[i].dono->CPF);
    }

    // Escrever ordens de servico
    fprintf(arquivo, "OrdensDeServico %d\n", quantidadeordens);
    for (int i = 0; i < quantidadeordens; i++) {
        fprintf(arquivo, "%d %s %s %d %s\n", ordens[i].idordem, ordens[i].automovel->placa, ordens[i].dataentrada, ordens[i].status, ordens[i].descricaoproblema);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em dados.txt\n");
}

void lermemoria(cliente *clientes, int *quantidadeclientes, veiculo *veiculos, int *quantidadeveiculos, ordemservico *ordens, int *quantidadeordens) {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    char tipo[20];
    int quantidade;

    // Ler clientes
    fscanf(arquivo, "%s %d\n", tipo, &quantidade);
    if (strcmp(tipo, "Clientes") == 0) {
        for (int i = 0; i < quantidade; i++) {
            fscanf(arquivo, "%s %s %s\n", clientes[i].nome, clientes[i].CPF, clientes[i].telefone);
        }
        *quantidadeclientes = quantidade;
    }

    // Ler veiculos
    fscanf(arquivo, "%s %d\n", tipo, &quantidade);
    if (strcmp(tipo, "Veiculos") == 0) {
        for (int i = 0; i < quantidade; i++) {
            char cpf[25];
            fscanf(arquivo, "%s %s %d %s\n", veiculos[i].placa, veiculos[i].modelo, &veiculos[i].ano, cpf);
            int indicecliente = buscarcliente(clientes, *quantidadeclientes, cpf);
            if (indicecliente != -1) {
                veiculos[i].dono = &clientes[indicecliente];
            } else {
                veiculos[i].dono = NULL; // Cliente não encontrado
            }
        }
        *quantidadeveiculos = quantidade;
    }

    // Ler ordens de servico
    fscanf(arquivo, "%s %d\n", tipo, &quantidade);
    if (strcmp(tipo, "OrdensDeServico") == 0) {
        for (int i = 0; i < quantidade; i++) {
            char placa[30];
            fscanf(arquivo, "%d %s %s %d %s\n", &ordens[i].idordem, placa, ordens[i].dataentrada, &ordens[i].status, ordens[i].descricaoproblema);
            int indiceveiculo = buscarveiculo(veiculos, *quantidadeveiculos, placa);
            if (indiceveiculo != -1 ) {
                ordens[i].automovel = &veiculos[indiceveiculo];
            } else {
                ordens[i].automovel = NULL; // Veiculo não encontrado
            }
        }
        *quantidadeordens = quantidade;
    }
    fclose(arquivo);
    printf("Dados carregados com sucesso de dados.txt\n");
}

void gerarrelatorio(ordemservico *ordens, int quantidadeordens) {
    int pendentes = 0, concluidos = 0;
    for (int i = 0; i < quantidadeordens; i++) {
        if (ordens[i].status == 0) {
            pendentes++;
        } else if (ordens[i].status == 1) {
            concluidos++;
        }
    }
    printf("Relatorio de Ordens de Servico:\n");
    printf("Total de Ordens: %d\n", quantidadeordens);
    printf("Ordens Pendentes: %d\n", pendentes);
    printf("Ordens Concluidas: %d\n", concluidos);
    if (quantidadeordens > 0) {
        printf("Percentual de Conclusao: %.2f%%\n", (concluidos / (float)quantidadeordens) * 100);
    } else {
        printf("Percentual de Conclusao: N/A\n");
    }
}
