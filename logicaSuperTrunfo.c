#include <stdio.h>

/* 
! 🏅 Nível Novato

No nível Novato, você começará implementando a lógica básica de comparação entre cartas utilizando estruturas de decisão `if` e `if-else`.

! 🚩 Objetivos:
* **Cadastro de Cartas:** O sistema permitirá ao usuário cadastrar cartas de cidades, incluindo informações como estado, código da carta, nome da cidade, população, área, PIB e número de pontos turísticos.
* **Comparação de Cartas:** O sistema comparará os atributos de duas cartas e determinará a vencedora com base em uma propriedade específica (população, área, PIB, etc.), escolhida no código.
* **Exibição de Resultados:** Após a comparação, o sistema exibirá qual carta venceu com base na regra: maior valor vence, exceto em densidade populacional, onde o menor valor é o vencedor.

! 📥 Entrada de Dados:
* Os dados das cartas serão inseridos manualmente via terminal.
* O sistema solicitará interativamente as informações de cada carta.

! 📤 Saída de Dados:
* Após o cadastro, as propriedades da cidade serão exibidas de forma organizada.
* O resultado da comparação será mostrado, indicando a carta vencedora.

*/

int main()
{
    /* Declarando variaveis */
        
    // LIMITE
    int CARTAS_MAX = 2;                             // Quantidade de cartas
    
    // Chars
    char    estado[CARTAS_MAX][3],                  // Estado *Atualizado agora com 2 letras.
    codigoCarta[CARTAS_MAX][4],                     // Codigo da Carta
    nomeCidade[CARTAS_MAX][20];                     // Nome da cidade
    
    // Ints
    unsigned int    numeroHabitantes[CARTAS_MAX],   // Numedo de habitantes
                    comparador;                     // Será usado na hora da comparação para dizer quem venceu
    int numeroPontosTuristicos[CARTAS_MAX];         // Numero de pontos turisticos
    
    // Floats
    float   area[CARTAS_MAX],                       // Area da cidade
    pib[CARTAS_MAX],                                // Pib da cidade
    // Adicionais deste ex
    densidade[CARTAS_MAX],                          // Densidade da população
    pibPerCapta[CARTAS_MAX],                        // PIB per capta
    superPoder[CARTAS_MAX];                         // Super Poder soma de pop, area, PIB, PIB per capta e densidade pop invertida para comp e numeros de pontos turisticos.
    
    
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

    // Comparar PIB

    printf("Carta %d - %s (%s): %.2f\n",1,nomeCidade[0],estado[0],pib[0]);
    printf("Carta %d - %s (%s): %.2f\n\n",2,nomeCidade[1],estado[1],pib[1]);

    // Compara pib cidade index 0 com cidade index 1 
    if (pib[0] > pib[1]) comparador = 0;
    else comparador = 1;

    printf("Resultado: Carta %d (%s) Venceu!",comparador + 1,nomeCidade[comparador]);

    return 0;
}
