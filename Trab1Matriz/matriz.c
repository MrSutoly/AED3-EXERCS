#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

No* criarNo() {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = 0;
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->cima = NULL;
    novo->baixo = NULL;
    return novo;
}

Matriz* alocarMatriz(int linhas, int colunas) {
    Matriz *m = (Matriz*)malloc(sizeof(Matriz));
    m->linhas = linhas;
    m->colunas = colunas;
    m->inicio = NULL;

    if (linhas <= 0 || colunas <= 0)
        return m;

    No *linhaAnterior = NULL;
    No *linhaAtual = NULL;

    for (int i = 0; i < linhas; i++) {
        No *colunaAnterior = NULL;
        No *novo = NULL;

        for (int j = 0; j < colunas; j++) {
            novo = criarNo();

            if (i == 0 && j == 0) {
                m->inicio = novo;
            }

            if (colunaAnterior != NULL) {
                colunaAnterior->direita = novo;
                novo->esquerda = colunaAnterior;
            }

            if (linhaAnterior != NULL) {
                No *acima = linhaAnterior;
                for (int k = 0; k < j; k++) {
                    acima = acima->direita;
                }
                acima->baixo = novo;
                novo->cima = acima;
            }
            colunaAnterior = novo;
        }
        if (i == 0) {
            linhaAnterior = m->inicio;
        } else {
            linhaAnterior = linhaAnterior->baixo;
        }
    }
    return m;
}

void desalocarMatriz(Matriz *m) {
    if (m == NULL || m->inicio == NULL)
        return;

    No *linha = m->inicio;
    while (linha != NULL) {
        No *coluna = linha;
        No *proxLinha = linha->baixo;
        while (coluna != NULL) {
            No *temp = coluna;
            coluna = coluna->direita;
            free(temp);
        }
        linha = proxLinha;
    }
    free(m);
}

No* acessarPosicao(Matriz *m, int x, int y) {
    if (m == NULL || x < 0 || y < 0 || x >= m->linhas || y >= m->colunas)
        return NULL;

    No *atual = m->inicio;
    for (int i = 0; i < x; i++)
        atual = atual->baixo;
    for (int j = 0; j < y; j++)
        atual = atual->direita;

    return atual;
}

void inserirValor(Matriz *m, int x, int y, int valor) {
    No *n = acessarPosicao(m, x, y);
    if (n == NULL) {
        printf("Posição inválida!\n");
        return;
    }
    n->valor = valor;
}

No* buscarValor(Matriz *m, int valor) {
    if (m == NULL) return NULL;

    No *linha = m->inicio;

    while (linha != NULL) {
        No *coluna = linha;
        while (coluna != NULL) {
            if (coluna->valor == valor)
                return coluna;
            coluna = coluna->direita;
        }
        linha = linha->baixo;
    }
    return NULL;
}

void imprimirVizinhos(Matriz *m, int x, int y) {
    No *n = acessarPosicao(m, x, y);
    if (n == NULL) {
        printf("Posição inválida!\n");
        return;
    }

    printf("Vizinhos de (%d,%d):\n", x, y);
    printf("Cima: %d\n", n->cima ? n->cima->valor : -1);
    printf("Baixo: %d\n", n->baixo ? n->baixo->valor : -1);
    printf("Esquerda: %d\n", n->esquerda ? n->esquerda->valor : -1);
    printf("Direita: %d\n", n->direita ? n->direita->valor : -1);
}

void imprimirMatriz(Matriz *m) {
    if (m == NULL || m->inicio == NULL)
        return;

    No *linha = m->inicio;
    while (linha != NULL) {
        No *coluna = linha;
        while (coluna != NULL) {
            printf("%3d ", coluna->valor);
            coluna = coluna->direita;
        }
        printf("\n");
        linha = linha->baixo;
    }
}

No* criarNovoNo() {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        perror("Erro de alocação de memória");
        exit(EXIT_FAILURE);
    }
    // Inicializa o valor e os ponteiros conforme o seu 'criarNo' original
    novo->valor = 0;
    novo->direita = NULL;
    novo->esquerda = NULL;
    novo->cima = NULL;
    novo->baixo = NULL;
    return novo;
}




int addRow(Matriz *matriz, int linha) {
    // 1. Verificações de entrada e ajuste do índice 'linha' (1-based)
    if (matriz == NULL || linha < 1) {
        return 0;
    }
    if (linha > matriz->linhas + 1) {
        linha = matriz->linhas + 1; // Insere no final se o índice for muito grande
    }

    // Matriz vazia ou sem colunas
    if (matriz->inicio == NULL || matriz->colunas == 0) {
        return 0;
    }

    // 2. Navegação para encontrar as linhas adjacentes
    No *linhaAnterior = NULL; // Ponteiro para a linha que ficará acima da nova
    No *linhaAbaixo = matriz->inicio; // Ponteiro para a linha que ficará abaixo da nova

    // Se a inserção não for na primeira linha, navegue até a linha anterior
    if (linha > 1) {
        linhaAnterior = matriz->inicio;
        for (int i = 0; i < linha - 2; i++) {
            linhaAnterior = linhaAnterior->baixo;
        }
        linhaAbaixo = linhaAnterior->baixo;
    }
    // Se a inserção for no final, linhaAnterior aponta para a última linha
    if (linha == matriz->linhas + 1) {
        linhaAnterior = matriz->inicio;
        for (int i = 0; i < matriz->linhas - 1; i++) {
            linhaAnterior = linhaAnterior->baixo;
        }
        linhaAbaixo = NULL; // Não há linha abaixo
    }

    // 3. Loop de criação da nova linha
    No *novoNoAnterior = NULL; // Rastreia o nó anterior na nova linha

    for (int j = 0; j < matriz->colunas; j++) {
        No *novoNo = criarNo();

        // 3a. Encadeamento Horizontal (esquerda/direita)
        if (novoNoAnterior != NULL) {
            novoNoAnterior->direita = novoNo;
            novoNo->esquerda = novoNoAnterior;
        }

        // 3b. Encadeamento Vertical (cima/baixo)

        // Ligar com a linha de CIMA (linhaAnterior)
        if (linhaAnterior != NULL) {
            linhaAnterior->baixo = novoNo;
            novoNo->cima = linhaAnterior;
        }

        // Ligar com a linha de BAIXO (linhaAbaixo)
        if (linhaAbaixo != NULL) {
            linhaAbaixo->cima = novoNo;
            novoNo->baixo = linhaAbaixo;
        }

        // 3c. Atualização do Ponteiro 'inicio' da Matriz
        if (linha == 1 && j == 0) {
            matriz->inicio = novoNo;
        }

        // 4. Avançar os ponteiros
        novoNoAnterior = novoNo;
        if (linhaAnterior != NULL) linhaAnterior = linhaAnterior->direita;
        if (linhaAbaixo != NULL) linhaAbaixo = linhaAbaixo->direita;
    }

    // 5. Atualizar as dimensões
    matriz->linhas += 1;
    return 1;
}

int addColumn(Matriz *matriz, int coluna) {
    // 1. Verificações de entrada e ajuste do índice 'coluna' (1-based)
    if (matriz == NULL || coluna < 1) {
        return 0;
    }
    if (coluna > matriz->colunas + 1) {
        coluna = matriz->colunas + 1; // Insere no final
    }

    if (matriz->inicio == NULL || matriz->linhas == 0) {
        return 0;
    }

    // 2. Navegação para encontrar as colunas adjacentes
    No *colunaEsquerda = NULL; // Ponteiro para a coluna que ficará à esquerda da nova
    No *colunaDireita = matriz->inicio; // Ponteiro para a coluna que ficará à direita da nova

    // Se a inserção não for na primeira coluna, navegue até a coluna anterior
    if (coluna > 1) {
        colunaEsquerda = matriz->inicio;
        for (int i = 0; i < coluna - 2; i++) {
            colunaEsquerda = colunaEsquerda->direita;
        }
        colunaDireita = colunaEsquerda->direita;
    }
    // Se a inserção for no final, colunaEsquerda aponta para a última coluna
    if (coluna == matriz->colunas + 1) {
        colunaEsquerda = matriz->inicio;
        for (int i = 0; i < matriz->colunas - 1; i++) {
            colunaEsquerda = colunaEsquerda->direita;
        }
        colunaDireita = NULL; // Não há coluna à direita
    }

    // 3. Loop de criação da nova coluna
    No *novoNoAcima = NULL; // Rastreia o nó anterior (acima) na nova coluna

    for (int i = 0; i < matriz->linhas; i++) {
        No *novoNo = criarNo();

        // 3a. Encadeamento Vertical (cima/baixo)
        if (novoNoAcima != NULL) {
            novoNoAcima->baixo = novoNo;
            novoNo->cima = novoNoAcima;
        }

        // 3b. Encadeamento Horizontal (esquerda/direita)

        // Ligar com a coluna da ESQUERDA (colunaEsquerda)
        if (colunaEsquerda != NULL) {
            colunaEsquerda->direita = novoNo;
            novoNo->esquerda = colunaEsquerda;
        }

        // Ligar com a coluna da DIREITA (colunaDireita)
        if (colunaDireita != NULL) {
            colunaDireita->esquerda = novoNo;
            novoNo->direita = colunaDireita;
        }

        // 3c. Atualização do Ponteiro 'inicio' da Matriz
        if (coluna == 1 && i == 0) {
            matriz->inicio = novoNo;
        }

        // 4. Avançar os ponteiros
        novoNoAcima = novoNo;
        if (colunaEsquerda != NULL) colunaEsquerda = colunaEsquerda->baixo;
        if (colunaDireita != NULL) colunaDireita = colunaDireita->baixo;
    }

    // 5. Atualizar as dimensões
    matriz->colunas += 1;
    return 1;
}



int removeRow(Matriz *matriz, int linha) {
    // 1. Verificações de entrada e ajuste do índice 'linha' (1-based)
    if (matriz == NULL || matriz->inicio == NULL || linha < 1 || linha > matriz->linhas) {
        return 0;
    }

    // Caso especial: Remover a única linha
    if (matriz->linhas == 1) {
        // Desaloca a única linha de nós
        No *col = matriz->inicio;
        while(col != NULL) {
            No *temp = col;
            col = col->direita;
            free(temp);
        }
        matriz->inicio = NULL;
        matriz->linhas = 0;
        return 1;
    }

    // 2. Navegar até o início da linha a ser removida
    No *linhaRemover = matriz->inicio;
    for (int i = 0; i < linha - 1; i++) {
        linhaRemover = linhaRemover->baixo;
    }

    // 3. Ponteiros das linhas adjacentes
    No *linhaAnterior = linhaRemover->cima;
    No *linhaAbaixo = linhaRemover->baixo;

    // Se estiver removendo a primeira linha, ajusta matriz->inicio
    if (linha == 1) {
        matriz->inicio = linhaAbaixo;
    }

    // 4. Loop de remoção e reencadeamento (coluna por coluna)
    No *col = linhaRemover;
    while (col != NULL) {
        No *temp = col; // Nó a ser liberado
        col = col->direita; // Avança para o próximo nó antes de desalocar

        // 4a. Reencadeamento Vertical (costurar a linha de cima com a de baixo)
        // Usa os ponteiros rastreadores (linhaAnterior e linhaAbaixo) para reencadear
        if (linhaAnterior != NULL) {
            linhaAnterior->baixo = linhaAbaixo;
        }
        if (linhaAbaixo != NULL) {
            linhaAbaixo->cima = linhaAnterior;
        }

        // 5. Desalocar o nó
        free(temp);

        // 6. Avançar os ponteiros de reencadeamento para a próxima coluna
        if (linhaAnterior != NULL) linhaAnterior = linhaAnterior->direita;
        if (linhaAbaixo != NULL) linhaAbaixo = linhaAbaixo->direita;
    }

    // 7. Atualizar as dimensões
    matriz->linhas -= 1;
    return 1;
}

int removeColumn(Matriz *matriz, int coluna) {
    // 1. Verificações de entrada e ajuste do índice 'coluna' (1-based)
    if (matriz == NULL || matriz->inicio == NULL || coluna < 1 || coluna > matriz->colunas) {
        return 0;
    }

    // Caso especial: Remover a única coluna
    if (matriz->colunas == 1) {
        // Desaloca a única coluna de nós
        No *row = matriz->inicio;
        while(row != NULL) {
            No *temp = row;
            row = row->baixo;
            free(temp);
        }
        matriz->inicio = NULL;
        matriz->colunas = 0;
        return 1;
    }

    // 2. Navegar até o início da coluna a ser removida (primeiro nó da coluna)
    No *colunaRemover = matriz->inicio;
    for (int j = 0; j < coluna - 1; j++) {
        colunaRemover = colunaRemover->direita;
    }

    // 3. Ponteiros das colunas adjacentes
    No *colunaEsquerda = colunaRemover->esquerda;
    No *colunaDireita = colunaRemover->direita;

    // Se estiver removendo a primeira coluna, ajusta matriz->inicio
    if (coluna == 1) {
        matriz->inicio = colunaDireita;
    }

    // 4. Loop de remoção e reencadeamento (linha por linha)
    No *row = colunaRemover;
    while (row != NULL) {
        No *temp = row; // Nó a ser liberado
        row = row->baixo; // Avança para o próximo nó antes de desalocar

        // 4a. Reencadeamento Horizontal (costurar a coluna da esquerda com a da direita)
        // Usa os ponteiros rastreadores (colunaEsquerda e colunaDireita) para reencadear
        if (colunaEsquerda != NULL) {
            colunaEsquerda->direita = colunaDireita;
        }
        if (colunaDireita != NULL) {
            colunaDireita->esquerda = colunaEsquerda;
        }

        // 5. Desalocar o nó
        free(temp);

        // 6. Avançar os ponteiros de reencadeamento para a próxima linha
        if (colunaEsquerda != NULL) colunaEsquerda = colunaEsquerda->baixo;
        if (colunaDireita != NULL) colunaDireita = colunaDireita->baixo;
    }

    // 7. Atualizar as dimensões
    matriz->colunas -= 1;
    return 1;
}

void transporMatriz(Matriz *m) {
    if (m == NULL || m->inicio == NULL) {
        return;
    }

    // A. Trocar as dimensões da matriz
    int temp = m->linhas;
    m->linhas = m->colunas;
    m->colunas = temp;

    No *linhaAtual = m->inicio;

    // A iteração deve ser baseada nos *ponteiros originais* antes de serem trocados.
    while (linhaAtual != NULL) {
        No *colunaAtual = linhaAtual;

        // Ponteiro para o INÍCIO da próxima LINHA (usa o ponteiro original ->direita)
        No *proximaLinha = linhaAtual->direita;

        while (colunaAtual != NULL) {

            // Ponteiro para o PRÓXIMO NÓ na COLUNA ATUAL (usa o ponteiro original ->baixo)
            No *proximaColuna = colunaAtual->baixo;

            // 1. TROCA DE PONTEIROS PRINCIPAIS (direita <-> baixo)
            // Usa 'baixo' como TEMP para evitar sobrescrever antes de usar
            No *temp_baixo = colunaAtual->baixo;

            colunaAtual->baixo = colunaAtual->direita; // Novo BAIXO é o antigo DIREITA
            colunaAtual->direita = temp_baixo;        // Novo DIREITA é o antigo BAIXO

            // 2. TROCA DE PONTEIROS INVERSOS (esquerda <-> cima)
            No *temp_cima = colunaAtual->cima;

            colunaAtual->cima = colunaAtual->esquerda; // Novo CIMA é o antigo ESQUERDA
            colunaAtual->esquerda = temp_cima;         // Novo ESQUERDA é o antigo CIMA

            // Avança para o próximo nó na COLUNA ATUAL (usa o ponteiro original ->baixo)
            colunaAtual = proximaColuna;
        }

        // Avança para o próximo início de LINHA (usa o ponteiro original ->direita)
        linhaAtual = proximaLinha;
    }
}

void rotacionar90GrausAntiHoraria(Matriz *m) {
    if (m == NULL || m->inicio == NULL) {
        return;
    }

    No *inicioOriginal = m->inicio;

    // 1. LOCALIZAÇÃO DO NOVO INÍCIO PARA ROTAÇÃO ANTI-HORÁRIA
    // O novo (0,0) é o nó na PRIMEIRA LINHA (0) e ÚLTIMA COLUNA (C-1) da matriz original.
    No *novoInicio = inicioOriginal;
    for (int j = 0; j < m->colunas - 1; j++) {
        novoInicio = novoInicio->direita;
    }

    // 2. TROCA DE DIMENSÕES
    int linhasOriginais = m->linhas;
    m->linhas = m->colunas;
    m->colunas = linhasOriginais;

    // 3. TRAVESSIA E TROCA DE PONTEIROS (Lógica que resultou no Anti-Horário)
    No *linhaAtual = inicioOriginal;

    while (linhaAtual != NULL) {
        No *colunaAtual = linhaAtual;

        No *proximaLinha = linhaAtual->direita;

        while (colunaAtual != NULL) {

            No *proximaColuna = colunaAtual->baixo;

            No *temp_dir = colunaAtual->direita;
            No *temp_baixo = colunaAtual->baixo;
            No *temp_esq = colunaAtual->esquerda;
            No *temp_cima = colunaAtual->cima;

            // Mapeamento que funciona para o Anti-Horário (embora a troca seja a do horário)
            colunaAtual->direita = temp_baixo;
            colunaAtual->baixo = temp_esq;
            colunaAtual->esquerda = temp_cima;
            colunaAtual->cima = temp_dir;

            colunaAtual = proximaColuna;
        }

        linhaAtual = proximaLinha;
    }

    // 4. ATUALIZAÇÃO DO INÍCIO
    m->inicio = novoInicio;
}



void rotacionar90GrausHoraria(Matriz *m) {
    if (m == NULL || m->inicio == NULL) {
        return;
    }

    No *inicioOriginal = m->inicio;
    int linhasOriginais = m->linhas;

    // 1. LOCALIZAÇÃO DO NOVO INÍCIO (ÚLTIMA LINHA, PRIMEIRA COLUNA ORIGINAL)
    No *novoInicio = inicioOriginal;
    for (int i = 0; i < linhasOriginais - 1; i++) {
        novoInicio = novoInicio->baixo;
    }

    // 2. TROCA DE DIMENSÕES
    m->linhas = m->colunas;
    m->colunas = linhasOriginais;

    // 3. TRAVESSIA E TROCA DE PONTEIROS
    No *linhaAtual = inicioOriginal;

    while (linhaAtual != NULL) {
        No *colunaAtual = linhaAtual;

        No *proximaLinha = linhaAtual->direita;

        while (colunaAtual != NULL) {

            No *proximaColuna = colunaAtual->baixo;

            No *temp_dir = colunaAtual->direita;
            No *temp_baixo = colunaAtual->baixo;
            No *temp_esq = colunaAtual->esquerda;
            No *temp_cima = colunaAtual->cima;

            // Mapeamento para ROTAÇÃO HORÁRIA (90°):
            // Novo DIREITA = Antigo CIMA
            colunaAtual->direita = temp_cima;
            // Novo BAIXO = Antigo DIREITA
            colunaAtual->baixo = temp_dir;
            // Novo ESQUERDA = Antigo BAIXO
            colunaAtual->esquerda = temp_baixo;
            // Novo CIMA = Antigo ESQUERDA
            colunaAtual->cima = temp_esq;

            colunaAtual = proximaColuna;
        }

        linhaAtual = proximaLinha;
    }

    // 4. ATUALIZAÇÃO DO INÍCIO
    m->inicio = novoInicio;
}

int lerValor(Matriz *m, int linha, int coluna) {
    if (m == NULL || m->inicio == NULL || linha < 0 || coluna < 0 || linha >= m->linhas || coluna >= m->colunas) {
        return -99999; // Valor de erro/indicação de posição inválida
    }

    No *atual = m->inicio;

    // 1. Navegar até a linha correta
    for (int i = 0; i < linha; i++) {
        if (atual == NULL) return -99999;
        atual = atual->baixo;
    }

    // 2. Navegar até a coluna correta
    for (int j = 0; j < coluna; j++) {
        if (atual == NULL) return -99999;
        atual = atual->direita;
    }

    // 3. Retornar o valor
    if (atual != NULL) {
        return atual->valor;
    }

    return -99999; // Nó não encontrado (erro de lógica)
}

int matrizSimetrica(Matriz *m) {
    // verifica se a matriz existe e se é quadrada
    if (m == NULL || m->inicio == NULL || m->linhas != m->colunas) {
        return 0; // não é simétrica
    }

    // percorre todas as posições da matriz
    for (int i = 0; i < m->linhas; i++) {
        for (int j = 0; j < m->colunas; j++) {
            // lê o valor em (i,j)
            int a = lerValor(m, i, j);
            // lê o valor em (j,i) — o “espelho”
            int b = lerValor(m, j, i);

            // se encontrar uma diferença, já sabe que não é simétrica
            if (a != b) return 0;
        }
    }

    // se passou por todos os elementos sem diferença, é simétrica
    return 1;
}

