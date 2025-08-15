#include <stdio.h>

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

int main(void) {

    //***** Questão 1 *****
    int n = 123;
    invert(n);
    printf("\n");

    //***** Questão 2 *****
    int vet[] = {1, 2, 3};
    int t = sizeof(vet) / sizeof(vet[0]);
    int soma = somavet(vet, t);
    printf("Soma do vetor: %d\n", soma);

    // ***** Questão 3 *****
    int x = 5;
    int resultado = soman(x);
    printf("Somatorio de 1 ate %d: %d\n", x, resultado);

    // ***** Questão 4 *****
    int k, m;

    printf("Digite o valor de k (expoente): ");
    scanf("%d", &k);

    printf("Digite o valor de m (base): ");
    scanf("%d", &m);

    int resposta = pot(k, m);
    printf("%d^%d = %d\n", m, k, resposta);

    // ***** Questão 5 *****

    double num[10];

    cria(num, 10);

    inv(num, 0, 9);

    printf("Vetor invertido:\n");
    for (int i = 0; i < 10; i++) {
        printf("num[%d] = %.2f\n", i, num[i]);
    }

    // ***** Questão 6 *****

    int a, b;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);

    printf("Digite o segundo numero: ");
    scanf("%d", &b);

    printf("MDC de %d e %d = %d\n", a, b, mdc(a, b));

    return 0;
}
