📝 Documentação e Implementação: Matriz Dinâmica Encadeada
Este trabalho foi desenvolvido para a disciplina de Estrutura de Dados III, tendo como objetivo a implementação de uma Matriz Dinâmica baseada em Listas Encadeadas Ortogonais (Cross-Linked Lists).

  ### Funções Base (João Pedro)
criarNo() → Cria um nó vazio da matriz com todos os ponteiros (cima, baixo, esquerda, direita) nulos.

alocarMatriz(linhas, colunas) → Aloca uma matriz de tamanho linhas x colunas inicializando todos os nós encadeados.

desalocarMatriz(m) → Desaloca toda a matriz, liberando memória de cada nó.

acessarPosicao(m, x, y) → Retorna o nó localizado na posição (x,y).

inserirValor(m, x, y, valor) → Atualiza o valor do nó na posição (x,y).

lerValor(m, x, y) → Retorna o valor do nó na posição (x,y).

imprimirMatriz(m) → Imprime todos os valores da matriz no console.

imprimirVizinhos(m, x, y) → Imprime os valores dos vizinhos de um nó (cima, baixo, esquerda, direita).

buscarValor(m, valor) → Retorna o primeiro nó que contém o valor informado.

  Funções Extra (João Pedro)
matrizSimetrica(m) → Verifica se a matriz é quadrada e simétrica, comparando cada elemento com seu “espelho” (i,j) ↔ (j,i).


  Funções Extra (Pedro Luca)
Adicionar/Remover Linha: Permite o crescimento/encolhimento vertical da matriz; a remoção reencadeia os nós adjacentes (cima e baixo) para pular a linha removida.

Adicionar/Remover Coluna: Permite o crescimento/encolhimento horizontal; a remoção reencadeia os nós adjacentes (esquerda e direita) para pular a coluna removida.

Transpor Matriz: Realizada in-place, trocando os ponteiros direita pelos baixo e vice-versa, e invertendo as dimensões da matriz.

Girar 90 Graus (Horário e Anti-Horário): Realizada in-place, remapeando ciclicamente os quatro ponteiros (cima, baixo, esquerda, direita) e atualizando o ponto de início (inicio) e as dimensões.

Dificuldades na Rotação 90° Horária

O desafio primário foi o mapeamento lógico dos ponteiros. Inicialmente, a lógica implementada resultava, inadvertidamente, na rotação anti-horária. A correção exigiu o entendimento preciso de que o novo nó superior esquerdo da
matriz rotacionada (o novo m->inicio) é o nó que, na matriz original, estava na última linha e primeira coluna. 
Além disso, foi necessário garantir a troca cíclica correta dos quatro ponteiros (cima, baixo, esquerda, direita) para que as linhas horizontais originais se tornassem colunas verticais na nova estrutura, mantendo o encadeamento lógico da matriz.
