#include <stdio.h>

/* 
! 🏅 Nível Mestre

No nível Mestre, o desafio se intensifica com a adição de funcionalidades avançadas, como menus dinâmicos e lógica de decisão complexa com operadores ternários.

! 🆕 Diferença em relação ao Nível Aventureiro:
* Escolha de Dois Atributos:** O usuário poderá escolher dois atributos para comparação entre as cartas.
* Lógica de Decisão Complexa:** Implementação de estruturas de decisão aninhadas e encadeadas, além do uso de operadores ternários para determinar a carta vencedora.
* Menus Dinâmicos:** Os menus serão dinâmicos, permitindo uma navegação fluida entre as opções de comparação.

! 🚩 Novas Funcionalidades:
* Comparação de Dois Atributos:** O sistema comparará dois atributos simultaneamente para determinar a carta vencedora.
* Lógica Avançada:** Uso de operadores ternários e lógica aninhada para lidar com comparações complexas.
* Empates:** O sistema será capaz de lidar com empates, exibindo mensagens apropriadas.
* Exibição de Resultados:** Exibição dos resultados das comparações de forma clara e interativa.

---

! 📋 Requisitos Funcionais Comuns
* Cadastro de Cartas:** O sistema deve permitir o cadastro de cartas com as informações necessárias.
* Comparação:** O sistema deve comparar as cartas e determinar a vencedora com base nas regras estabelecidas.
* Exibição de Resultados:** Os resultados devem ser exibidos de forma clara, indicando a carta vencedora.

! 📌 Requisitos Não Funcionais Comuns
* Usabilidade:** A interface do usuário deve ser simples e intuitiva.
* Performance:** O sistema deve executar operações sem atrasos perceptíveis.
* Manutenibilidade:** O código deve ser bem estruturado e documentado.
* Confiabilidade:** O sistema deve ser robusto e capaz de lidar com entradas inválidas de forma adequada.

*/

int main()
{
    /* Declarando variaveis */
        
    // LIMITE
    int CARTAS_MAX = 2,                             // Quantidade de cartas
        ATRIBUTOS_MAX = 2;

    
    // Chars
    char    estado[CARTAS_MAX][3],                  // Estado *Atualizado agora com 2 letras.
    codigoCarta[CARTAS_MAX][4],                     // Codigo da Carta
    nomeCidade[CARTAS_MAX][20];                     // Nome da cidade
    
    // Ints
    unsigned int    numeroHabitantes[CARTAS_MAX],   // Numedo de habitantes
                    opcao[ATRIBUTOS_MAX],
                    vencedor[ATRIBUTOS_MAX];                     // Será usado na hora da comparação para dizer quem venceu
    int numeroPontosTuristicos[CARTAS_MAX];         // Numero de pontos turisticos
    
    // Floats
    float   area[CARTAS_MAX],                       // Area da cidade
    pib[CARTAS_MAX],                                // Pib da cidade
    // Adicionais deste ex
    densidade[CARTAS_MAX],                          // Densidade da população
    pibPerCapta[CARTAS_MAX],                        // PIB per capta
    superPoder[CARTAS_MAX];                         // Super Poder soma de pop, area, PIB, PIB per capta e densidade pop invertida para comp e numeros de pontos turisticos.
    
    double atributoSoma[ATRIBUTOS_MAX];
    
    /* Entrada de dados */
    
    /* CARTA 01*/
    printf("\nPreenchendo dados da CARTA 01\n\n");
    
    // Entrada do estado LETRA
    printf("Informe o estado, apenas com letras de A até H (Utilizar Somente maiúculo!): \n");
    scanf(" %s", &estado[0]); // Espaço antes do %s para não pegar buffer do enter, se não sai 2 mensagens.
    
    // Entrada do codigo da carta
    printf("Informe o codigo da carta, lembre-se inicia com a letra do estado em MAIÚSCULO seguido de 2 numeros de 01 até 04:\n");
    scanf(" %s", codigoCarta[0]); // Espaço antes do %s para não pegar buffer do enter, se não sai 2 mensagens.
    
    // Entrada nome da cidade (Sem tratamento de erros)
    printf("Nome da cidade sem ESPAÇOS: ");
    scanf(" %s", nomeCidade[0]);
    
    // Entrada numero da população (Sem tratamento de erros)
    printf("Número da população sem VIRGULAS!: ");
    scanf("%u", &numeroHabitantes[0]);
    
    // Entrada area da cidade em m2 (Sem tratamento de erros)
    printf("Numero da área em km² da cidade: ");
    scanf("%f", &area[0]);
    
    // Entrada PIB da cidade
    printf("Numero do PIB da cidade em bilhão(oes): ");
    scanf("%f", &pib[0]);
    
    // Entrada do número de pontos turisticos da cidade
    printf("Número de pontos turisticos da cidade: ");
    scanf("%d", &numeroPontosTuristicos[0]);
    
    // ---------------------------------------------------------------------------------------
    
    /* CARTA 02*/
    printf("\nPreenchendo dados da CARTA 02\n\n");
    
    // Entrada do estado LETRA
    printf("Informe o estado, apenas com letras de A até H (Utilizar Somente maiúculo!): \n");
    scanf(" %s", &estado[1]); // Espaço antes do %c para não pegar buffer do enter, se não sai 2 mensagens.
    
    // Entrada do codigo da carta
    printf("Informe o codigo da carta, lembre-se inicia com a letra do estado em MAIÚSCULO seguido de 2 numeros de 01 até 04:\n");
    scanf(" %s", codigoCarta[1]); // Espaço antes do %s para não pegar buffer do enter, se não sai 2 mensagens.
    
    // Entrada nome da cidade (Sem tratamento de erros)
    printf("Nome da cidade sem ESPAÇOS: ");
    scanf(" %s", nomeCidade[1]);
    
    // Entrada numero da população (Sem tratamento de erros)
    printf("Número da população sem VIRGULAS!: ");
    scanf("%u", &numeroHabitantes[1]);
    
    // Entrada area da cidade em m2 (Sem tratamento de erros)
    printf("Numero da área em Km² da cidade: ");
    scanf("%f", &area[1]);
    
    // Entrada PIB da cidade
    printf("Numero do PIB da cidade em bilhão(oes): ");
    scanf("%f", &pib[1]);
    
    // Entrada do número de pontos turisticos da cidade
    printf("Número de pontos turisticos da cidade: ");
    scanf("%d", &numeroPontosTuristicos[1]);
    
    // -----------------------------------------------------------------------------------------------
    
    /* Realizando os calculos da densidade e pib per capta*/
    
    // Calculo da densidade
    densidade[0] = (float) numeroHabitantes[0] / area[0];
    densidade[1] = (float) numeroHabitantes[1] / area[1];
    
    // Calculo do PIB perCapta | Bilhão = 1000000000 
    pibPerCapta[0] = (pib[0] * 1000000000) / (float) numeroHabitantes[0];
    pibPerCapta[1] = (pib[1] * 1000000000) / (float) numeroHabitantes[1];
    
    // Calculo super poder 
    superPoder[0] = (float) numeroHabitantes[0] + area[0] + pib[0] + (float) numeroPontosTuristicos[0] + pibPerCapta[0] + (1.0 / densidade[0]);
    superPoder[1] = (float) numeroHabitantes[1] + area[1] + pib[1] + (float) numeroPontosTuristicos[1] + pibPerCapta[1] + (1.0 / densidade[1]);
    
    // -----------------------------------------------------------------------------------------------
    
    // Imprimindo resultados conforme pedido
    
    // Carta 1

    printf("\nCarta %d\n",1);
    printf("Estado                          : %s\n", estado[0]);
    printf("Código                          : %s\n", codigoCarta[0]);
    printf("Nome da cidade                  : %s\n", nomeCidade[0]);
    printf("População                       : %u\n", numeroHabitantes[0]);
    printf("Área                            : %.2f km²\n", area[0]);
    printf("PIB                             : %.2f bilhões de reais\n", pib[0]);
    printf("Número de pontos turisticos     : %d\n", numeroPontosTuristicos[0]);
    printf("Densidade Populacional          : %.2f hab/km²\n", densidade[0]);
    printf("PIB per Capita                  : %.2f reais\n", pibPerCapta[0]);
    printf("Super poder                     : %.2f\n", superPoder[0]);

    // Carta 2
    
    printf("\nCarta %d\n",2);
    printf("Estado                          : %s\n", estado[1]);
    printf("Código                          : %s\n", codigoCarta[1]);
    printf("Nome da cidade                  : %s\n", nomeCidade[1]);
    printf("População                       : %u\n", numeroHabitantes[1]);
    printf("Área                            : %.2f km²\n", area[1]);
    printf("PIB                             : %.2f bilhões de reais\n", pib[1]);
    printf("Número de pontos turisticos     : %d\n", numeroPontosTuristicos[1]);
    printf("Densidade Populacional          : %.2f hab/km²\n", densidade[1]);
    printf("PIB per Capita                  : %.2f reais\n", pibPerCapta[1]);
    printf("Super poder                     : %.2f\n", superPoder[1]);

    printf("\n\n");

    // Comparações 

    printf("Comparação de Cartas\n");

    /* // ! Comentado pois aparentemente não sera mais preciso verificar todos os valores.
    printf("População               : Carta 1 venceu (%d)\n", (int) (numeroHabitantes[0] > numeroHabitantes[1]));
    printf("Área                    : Carta 1 venceu (%d)\n", (int) (area[0] > area[1]));
    printf("PIB                     : Carta 1 venceu (%d)\n", (int) (pib[0] > pib[1]));
    printf("Pontos Turísticos       : Carta 1 venceu (%d)\n", (int) (numeroPontosTuristicos[0] > numeroPontosTuristicos[1]));
    printf("Densidade Populacional  : Carta 2 venceu (%d)\n", (int) (densidade[0] > densidade [1]));
    printf("PIB per Capita          : Carta 1 venceu (%d)\n", (int) (pib[0] > pib[1]));
    printf("Super Poder             : Carta 1 venceu (%d)\n", (int) (superPoder[0] > superPoder[1]));
    */

    // Menu interativo

    printf("\nEscolha um dos atributos para comparar: \n");
    printf("1- População\n");
    printf("2- Área\n");
    printf("3- PIB\n");
    printf("4- Numero de pontos turisticos\n");
    printf("5- Densidade demográfica\n");
    printf("Escolha a opção: ");

    scanf("%u", &opcao[0]);

    printf("\n\n");

    /* Aqui ele já verifica qual já foi escolhido e não apresenta a opção!... */
    printf("\nEscolha outro dos atributos para comparar: \n");
    if(opcao[0] != 1) printf("1- População\n");
    if(opcao[0] != 2) printf("2- Área\n");
    if(opcao[0] != 3) printf("3- PIB\n");
    if(opcao[0] != 4) printf("4- Numero de pontos turisticos\n");
    if(opcao[0] != 5) printf("5- Densidade demográfica\n");
    printf("Escolha a opção: ");

    scanf("%u", &opcao[1]);

    printf("\n\n");

    // Tratamento de erros....
    // Caso não atenda os requisitos o programa informa o que aconteceu e já para por aqui...

    if( (opcao[0] == opcao[1]) )
    {
        printf("Você não pode escolher o mesmo atributo para comparar!\n\nSem GRAÇA!!\n");
        return 0;
    }
    else if (   (opcao[0] < 0 && opcao[0] > 5) ||
                (opcao[1] < 0 && opcao[1] > 5))
    {
        printf("Meu deuUUXX, esolheu alguma opção invalida!!!\n\nArrrrghh!!\n");
        return 0;
    }


    // Comparação entre caratas 

    atributoSoma[0] = 0;
    atributoSoma[1] = 0;

    switch (opcao[0])
    {
    case 1:
        printf("Carta %d - %s (%s) população: %u\n",1,nomeCidade[0],estado[0],numeroHabitantes[0]);
        printf("Carta %d - %s (%s) população: %u\n",2,nomeCidade[1],estado[1],numeroHabitantes[1]);
        if (numeroHabitantes[0] == numeroHabitantes[1]) vencedor[0] = 0;
        else if (numeroHabitantes[0] > numeroHabitantes[1]) vencedor[0] = 1; // Maior numero vence
        else vencedor[0] = 2;
        atributoSoma[0] += (double) numeroHabitantes[0];
        atributoSoma[1] += (double) numeroHabitantes[1];
        break;
    case 2:
        printf("Carta %d - %s (%s) Área: %.2f\n",1,nomeCidade[0],estado[0],area[0]);
        printf("Carta %d - %s (%s) Área: %.2f\n",2,nomeCidade[1],estado[1],area[1]);
        if (area[0] == area[1]) vencedor[0] = 0;
        else if (area[0] > area[1]) vencedor[0] = 1; // Maior numero vence
        else vencedor[0] = 2;
        atributoSoma[0] += (double) area[0];
        atributoSoma[1] += (double) area[1];
        break;
    case 3:
        printf("Carta %d - %s (%s) PIB: %.2f\n",1,nomeCidade[0],estado[0],pib[0]);
        printf("Carta %d - %s (%s) PIB: %.2f\n",2,nomeCidade[1],estado[1],pib[1]);
        if (pib[0] == pib[1]) vencedor[0] = 0;
        else if (pib[0] > pib[1]) vencedor[0] = 1; // Maior numero vence
        else vencedor[0] = 2;
        atributoSoma[0] += (double) pib[0];
        atributoSoma[1] += (double) pib[1];
        break;
    case 4:
        printf("Carta %d - %s (%s) pontos turisticos: %d\n",1,nomeCidade[0],estado[0],numeroPontosTuristicos[0]);
        printf("Carta %d - %s (%s) pontos turisticos: %d\n",2,nomeCidade[1],estado[1],numeroPontosTuristicos[1]);
        if (numeroPontosTuristicos[0] == numeroPontosTuristicos[1]) vencedor[0] = 0;
        else if (numeroPontosTuristicos[0] > numeroPontosTuristicos[1]) vencedor[0] = 1; // Maior numero vence
        else vencedor[0] = 2;
        atributoSoma[0] += (double) numeroPontosTuristicos [0];
        atributoSoma[1] += (double) numeroPontosTuristicos [1];
        break;
    case 5:
        printf("Carta %d - %s (%s) densidade demográfica: %.2f\n",1,nomeCidade[0],estado[0],densidade[0]);
        printf("Carta %d - %s (%s) densidade demográfica: %.2f\n",2,nomeCidade[1],estado[1],densidade[1]);
        if (densidade[0] == densidade[1]) vencedor[0] = 0;
        else if (densidade[0] < densidade[1]) vencedor[0] = 1; // Menor numero vence
        else vencedor[0] = 2;
        atributoSoma[0] += (double) densidade[0];
        atributoSoma[1] += (double) densidade[1];
        break;
    
    default:
        printf("Opção Invalida!");
        return 0;
        break;
    }

    // Resultado vencedor
    if(vencedor[0] > 0)
        printf("RESULTADO: Carta %d (%s) Venceu!\n",vencedor[0],nomeCidade[vencedor[0] - 1]);
    else
        printf("Ninguém venceu, deu EMPATE!\n");

    // Como ainda não pode usar for ou while só copiei

    switch (opcao[1])
    {
    case 1:
        printf("Carta %d - %s (%s) população: %u\n",1,nomeCidade[0],estado[0],numeroHabitantes[0]);
        printf("Carta %d - %s (%s) população: %u\n",2,nomeCidade[1],estado[1],numeroHabitantes[1]);
        if (numeroHabitantes[0] == numeroHabitantes[1]) vencedor[1] = 0;
        else if (numeroHabitantes[0] > numeroHabitantes[1]) vencedor[1] = 1; // Maior numero vence
        else vencedor[1] = 2;
        atributoSoma[0] += (double) numeroHabitantes[0];
        atributoSoma[1] += (double) numeroHabitantes[1];
        break;
    case 2:
        printf("Carta %d - %s (%s) Área: %.2f\n",1,nomeCidade[0],estado[0],area[0]);
        printf("Carta %d - %s (%s) Área: %.2f\n",2,nomeCidade[1],estado[1],area[1]);
        if (area[0] == area[1]) vencedor[1] = 0;
        else if (area[0] > area[1]) vencedor[1] = 1; // Maior numero vence
        else vencedor[1] = 2;
        atributoSoma[0] += (double) area[0];
        atributoSoma[1] += (double) area[1];
        break;
    case 3:
        printf("Carta %d - %s (%s) PIB: %.2f\n",1,nomeCidade[0],estado[0],pib[0]);
        printf("Carta %d - %s (%s) PIB: %.2f\n",2,nomeCidade[1],estado[1],pib[1]);
        if (pib[0] == pib[1]) vencedor[1] = 0;
        else if (pib[0] > pib[1]) vencedor[1] = 1; // Maior numero vence
        else vencedor[1] = 2;
        atributoSoma[0] += (double) pib[0];
        atributoSoma[1] += (double) pib[1];
        break;
    case 4:
        printf("Carta %d - %s (%s) pontos turisticos: %d\n",1,nomeCidade[0],estado[0],numeroPontosTuristicos[0]);
        printf("Carta %d - %s (%s) pontos turisticos: %d\n",2,nomeCidade[1],estado[1],numeroPontosTuristicos[1]);
        if (numeroPontosTuristicos[0] == numeroPontosTuristicos[1]) vencedor[1] = 0;
        else if (numeroPontosTuristicos[0] > numeroPontosTuristicos[1]) vencedor[1] = 1; // Maior numero vence
        else vencedor[1] = 2;
        atributoSoma[0] += (double) numeroPontosTuristicos [0];
        atributoSoma[1] += (double) numeroPontosTuristicos [1];
        break;
    case 5:
        printf("Carta %d - %s (%s) densidade demográfica: %.2f\n",1,nomeCidade[0],estado[0],densidade[0]);
        printf("Carta %d - %s (%s) densidade demográfica: %.2f\n",2,nomeCidade[1],estado[1],densidade[1]);
        if (densidade[0] == densidade[1]) vencedor[1] = 0;
        else if (densidade[0] < densidade[1]) vencedor[1] = 1; // Menor numero vence
        else vencedor[1] = 2;
        atributoSoma[0] += (double) densidade[0];
        atributoSoma[1] += (double) densidade[1];
        break;
    
    default:
        printf("Opção Invalida!");
        return 0;
        break;
    }

    // Resultado segundo vencedor
    if(vencedor[1] > 0)
        printf("RESULTADO: Carta %d (%s) Venceu!\n",vencedor[1],nomeCidade[vencedor[1] - 1]);
    else
        printf("Ninguém venceu, deu EMPATE!\n");

    printf("Soma dos atributos: Carta %d (%s) : %.2f\n",1,nomeCidade[0],atributoSoma[0]);
    printf("Soma dos atributos: Carta %d (%s) : %.2f\n",2,nomeCidade[1],atributoSoma[1]);

    if(atributoSoma[0] == atributoSoma[1]) printf("Nos atributos somandos ninguém ganhou! Deu empate!");
    else if(atributoSoma[0] > atributoSoma[1]) printf("RESULTADO: Carta %d (%s) venceu nos atributos somandos!\n",1,nomeCidade[0]);
    else printf("RESULTADO: Carta %d (%s) venceu nos atributos somandos!\n",2,nomeCidade[1]);

    return 0;
}
