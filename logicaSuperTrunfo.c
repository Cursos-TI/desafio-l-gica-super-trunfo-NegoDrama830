#include <stdio.h>

// Função principal
int main() {
    // Declaração das variáveis para as cartas
    char estado1[] = "SP", estado2[] = "RJ";
    char codigo1[] = "SP01", codigo2[] = "RJ02";
    char cidade1[] = "São Paulo", cidade2[] = "Rio de Janeiro";
    int populacao1 = 12300000, populacao2 = 6000000;
    float area1 = 1521.11, area2 = 1182.30;
    float PIB1 = 699.28, PIB2 = 361.04;
    int NPT1 = 50, NPT2 = 40;

    // Cálculo de Densidade Populacional e PIB per capita
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = (PIB1 * 1000000000) / populacao1;
    float pibPerCapita2 = (PIB2 * 1000000000) / populacao2;

    // Exibição dos dados das cartas
    printf("CARTA 1\n");
    printf("Estado: %s\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f Km²\nPIB: %.2f bilhões\n", estado1, codigo1, cidade1, populacao1, area1, PIB1);
    printf("Número de Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per capita: %.2f reais\n\n", NPT1, densidade1, pibPerCapita1);

    printf("CARTA 2\n");
    printf("Estado: %s\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f Km²\nPIB: %.2f bilhões\n", estado2, codigo2, cidade2, populacao2, area2, PIB2);
    printf("Número de Pontos Turísticos: %d\nDensidade Populacional: %.2f hab/km²\nPIB per capita: %.2f reais\n\n", NPT2, densidade2, pibPerCapita2);

    // Menu interativo para escolher os dois atributos de comparação
    int opcao1, opcao2;
    float valor1A, valor2A, valor1B, valor2B;
    char atributo1[50], atributo2[50];

    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Número de Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\nOpção: ");
    scanf("%d", &opcao1);

    do {
        printf("Escolha o segundo atributo para comparar (diferente do primeiro):\n");
        printf("1 - População\n2 - Área\n3 - PIB\n4 - Número de Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per Capita\nOpção: ");
        scanf("%d", &opcao2);
    } while (opcao1 == opcao2);

    // Definir os valores dos atributos escolhidos
    switch (opcao1) {
        case 1: valor1A = populacao1; valor2A = populacao2; sprintf(atributo1, "População"); break;
        case 2: valor1A = area1; valor2A = area2; sprintf(atributo1, "Área"); break;
        case 3: valor1A = PIB1; valor2A = PIB2; sprintf(atributo1, "PIB"); break;
        case 4: valor1A = NPT1; valor2A = NPT2; sprintf(atributo1, "Número de Pontos Turísticos"); break;
        case 5: valor1A = densidade1; valor2A = densidade2; sprintf(atributo1, "Densidade Populacional"); break;
        case 6: valor1A = pibPerCapita1; valor2A = pibPerCapita2; sprintf(atributo1, "PIB per Capita"); break;
    }

    switch (opcao2) {
        case 1: valor1B = populacao1; valor2B = populacao2; sprintf(atributo2, "População"); break;
        case 2: valor1B = area1; valor2B = area2; sprintf(atributo2, "Área"); break;
        case 3: valor1B = PIB1; valor2B = PIB2; sprintf(atributo2, "PIB"); break;
        case 4: valor1B = NPT1; valor2B = NPT2; sprintf(atributo2, "Número de Pontos Turísticos"); break;
        case 5: valor1B = densidade1; valor2B = densidade2; sprintf(atributo2, "Densidade Populacional"); break;
        case 6: valor1B = pibPerCapita1; valor2B = pibPerCapita2; sprintf(atributo2, "PIB per Capita"); break;
    }

    // Comparação dos atributos
    int pontos1 = (opcao1 == 5 ? (valor1A < valor2A) : (valor1A > valor2A)) + 
                  (opcao2 == 5 ? (valor1B < valor2B) : (valor1B > valor2B));
    int pontos2 = 2 - pontos1;

    printf("\nComparação de cartas:\n");
    printf("Atributo 1 - %s: %s: %.2f | %s: %.2f\n", atributo1, cidade1, valor1A, cidade2, valor2A);
    printf("Atributo 2 - %s: %s: %.2f | %s: %.2f\n", atributo2, cidade1, valor1B, cidade2, valor2B);

    printf("Resultado: ");
    if (pontos1 > pontos2) {
        printf("Carta 1 (%s) venceu!\n", cidade1);
    } else if (pontos2 > pontos1) {
        printf("Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
