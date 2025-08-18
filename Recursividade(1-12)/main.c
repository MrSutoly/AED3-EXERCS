// Alunos que fizeram este exercício:
 // João Pedro Gomes - 2651122
 // Pedro Luca Lacerda Alves - 2651416
#include <stdio.h>
#include <stdlib.h>

/* Questão 1: Dividimos por 10 para pegar o ultimo numero ( resto da divisão)
 e invertemos a ordem numérica utilizando as instâncias da recursão
 ( quando ela voltar e ir resolvendo as instancias, o print voltará invertido) */

void invert(int x) {
    if (x == 0)

        return;

    printf("%d", x % 10);
    invert(x / 10);
}

/*Questão 2: Utilizei uma variável e dei a ela o valor de tamanho do vetor
 , ela usa recursividade até o tamanho do vetor chegar a zero e vai somando os valores
 enquanto isso */


int somavet(int *vet, int t) {

    if (t == 0)
        return 0;

    return vet[0] + somavet(vet + 1, t - 1);
}

/*Questão 3:chamei a recursividade para ele somar todos os numeros
 comecando pelo que ele deu e diminuindo até chegar em um
 */

int soman(int n) {
    if (n == 0) // caso base
        return 0;

    return n + soman(n - 1);
}

/*Questão 4: Função recursiva de potencia básica, sem muito a comentar
 */

int pot(int k, int m) {
    if (k == 0)
        return 1;

    return m * pot(k - 1, m);
}

/*Questão 5: fiz uma função para criar o vetor e outra para inverter, na de criar, multipli
 quei por 1.1 para podermos conferir que funciona em números reais.
 Para a de inverter , criei uma variavel temporária para armazenar o inicio,e após isso tro
 quei seus valores.
 */
void cria(double num[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        num[i] = i * 1.1;
        printf("num[%d] = %.2f\n", i, num[i]);
    }
    printf("\n");
}

// Função recursiva para inverter vetor
void inv(double num[], int ini, int fim) {
    if (ini >= fim) // caso base
        return;

    double temp = num[ini];
    num[ini] = num[fim];
    num[fim] = temp;

    inv(num, ini + 1, fim - 1); // avança e recua
}

/*Questão 6: Lógica da função já foi dada na questão, sem muito o que comentar
 */

int mdc(int a, int b) {
    if (b == 0) return a;
    else return mdc(b, a % b);
}

/*Questão 7: Lógica usada foi de pegar o resto da divisão do K por 10 que sempre será o ultimo número do dividendo
e comparar com o N, se for igual soma 1 e chama a função denovo pegando a divisao de k por 10 que sempre sera o k sem o ultimo número
e faz o mesmo processo.
 */
int ocorrencia(int k, int n){
    if( k == 0) return 0;

    if( k % 10 == n) return 1 + ocorrencia(k / 10, n);

    else return ocorrencia( k / 10, n);
}

/*Questão 8: Lógica usada foi de usar o y como contador de quantas vezes o x se repeta para somar ele mesmo
e diminuir y até 0 pois é o caso base de soma.
 */
int somamult(int x, int y){
    if( y != 0) return  x + somamult(x, y - 1);
    else return 0;
    
}

/*Questão 9: Lógica usada foi de diminuir o número de 2 em 2 até chegar em 0, e quado ele chega em 0 ele printa invertido
e no console fica de forma crescente.
 */
void parcresce(int m){
    if( m == 0) printf(" %d \n", 0);
        else{
        parcresce(m - 2);
        printf("%d \n", m);
    }

}

/*Questão 10: Lógica usada foi quase a mesma da anterior mas agora diminuindo de 1 em 1 e printando antes de chamar a função
pra ficar de forma decrescente.
 */
void imprimeaten(int v){
    if (v == 0) printf("%d \n", 0);
    else{
        printf("%d \n ", v);
        imprimeaten(v - 1);
    }
}

/*Questão 11: Lógica usado foi de diminuir 2 em 2 e printa  antes de chamar a função para ficar de forma decrescente.
 */
void pardecresc(int h){
    if( h == 0) printf(" %d \n", 0);
    else{
        printf("%d \n", h);
        pardecresc(h - 2);
    }
}

/*Questão 12: Lógica usada foi de pegar um número e multiplicar ele por ele mesmo depois de diminuir 2 até chegar em 0 que ele retorno 1 pois é o case base
da multiplicação.
 */
int fatduplo(int u){
    if(u == 0) return 1;
    else return u * fatduplo(u - 2);
}

int main(void) {
    int n, t, soma, x, resultado, k, m, a, b, resposta, i, valor,
    digito,  mult1, mult2, par_cresc, decresc, par_decresc, fat_duplo;

    int vet[] = {1, 2, 3};
    double num[100];
    
    //***** Questão 1 *****
    n = 123;
    printf("Invertido: ");
    invert(n);

    //***** Questão 2 *****
    t = sizeof(vet) / sizeof(vet[0]);
    soma = somavet(vet, t);
    printf("Soma do vetor: %d\n", soma);

    // ***** Questão 3 *****
    x = 5;
    resultado = soman(x);
    printf("Somatorio de 1 ate %d: %d\n", x, resultado);

    // ***** Questão 4 *****
    printf("Digite o valor de k (expoente): ");
    scanf("%d", &k);

    printf("Digite o valor de m (base): ");
    scanf("%d", &m);

    resposta = pot(k, m);
    printf("%d^%d = %d\n", m, k, resposta);

    // ***** Questão 5 *****
    cria(num, 100);
    inv(num, 0, 99);

    printf("Vetor invertido:\n");
    for (i = 0; i < 100; i++) {
        printf("num[%d] = %.2f\n", i, num[i]);
    }

    // ***** Questão 6 *****
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    printf("MDC de %d e %d = %d\n", a, b, mdc(a, b));

    // ***** Questão 7 *****
    printf("Digite um numero para contar ocorrencias de um digito: ");
    scanf("%d", &valor);
    printf("Digite o digito a ser contado: ");
    scanf("%d", &digito);
    printf("O digito %d ocorre %d vezes em %d \n", digito, ocorrencia(valor, digito), valor);

    // ***** Questão 8 *****
    printf("Digite dois numeros para multiplicacao por soma: ");
    scanf("%d %d", &mult1, &mult2);
    printf("%d * %d = %d\n", mult1, mult2, somamult(mult1, mult2));

    // ***** Questão 9 *****
    printf("Digite um numero para impressao crescente de pares: ");
    scanf("%d", &par_cresc);
    if(par_cresc % 2 != 0) {
        printf("O número deve ser par.\n");
        return 1;
    }
    parcresce(par_cresc);

    // ***** Questão 10 *****
    printf("Digite um numero para impressao decrescente: ");
    scanf("%d", &decresc);
    imprimeaten(decresc);

    // ***** Questão 11 *****
    printf("Digite um numero para impressao decrescente de pares: ");
    scanf("%d", &par_decresc);
    if(par_decresc % 2 != 0) {
        printf("O número deve ser par.\n");
        return 1;
    }else{
        pardecresc(par_decresc);
    }

    // ***** Questão 12 *****
    printf("Digite um numero ímpar para fatorial duplo: ");
    scanf("%d", &fat_duplo);
    if(fat_duplo % 2 == 0) {
        printf("O número deve ser ímpar.\n");
        return 1;
    }else{
        printf("Fatorial duplo de %d = %d\n", fat_duplo, fatduplo(fat_duplo));
    }

    return 0;
}
