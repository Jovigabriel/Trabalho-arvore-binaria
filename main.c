int main(void) {
  FILE *arq = fopen("teste2.txt", "r");
  int opcaoDeImprimir;
  int teste = 0;

  char continua[5] = "sim";
  int opcao;

  while (strcmp(continua, "sim") == 0 || strcmp(continua, "Sim") == 0 ||
         strcmp(continua, "SIM") == 0 || strcmp(continua, "s") == 0 ||
         strcmp(continua, "S") == 0) {

    printf("Escolha uma das seguintes opcoes:\n\n1 - Ler uma árvore de um arquivo fornecido*;"
      "\n2 - Imprimir a árvore;"
      "\n3 - Verificar se um elemento x existe ou não na árvore; "
      "\n4 - Contar o número de elementos da árvore;"
      "\n5 - Imprimir nós folha da árvore;"
      "\n6 - Verificar se a árvore está balanceada;"
      "\n7 - Verificar se árvore é cheia;"
      "\n8 - Imprimir o nivel de um nó x; \n9 - Sair\n\n");

    scanf("%d", &opcao);
    printf("\n");


    switch (opcao) {
    case (1):
      printf("Árvore foi lida do arquivo... ");
      arvore *arvoreDoArq = lerArvore(arq);

      if (arvoreDoArq != NULL) {
        teste = 1;
      } else {
        teste = 0;
      }

      break;

    case (2):

      printf("Escolha a forma que quer imprimir a árvore:"
        "\n1 - Pré-Ordem;"
        "\n2 - Em ordem;"
        "\n3 - Pós-Ordem;"
        "\n4 - Em largura.\n\n");
      
      scanf("%d", &opcaoDeImprimir);
      printf("\n");


      switch (opcaoDeImprimir) {
      case (1):
        printf("Imprimindo a árvore (pré-ordem):\n\n");
        preOrdem(arvoreDoArq);
        break;
      case (2):
        printf("Imprimindo a árvore (em ordem):\n\n");
        emOrdem(arvoreDoArq);
        break;
      case (3):
        printf("Imprimindo a árvore (pós-ordem):\n\n");
        posOrdem(arvoreDoArq);
        break;
      case (4):
        printf("Imprimindo a árvore (em largura):\n\n");

        int h = altura(arvoreDoArq);
        largura(arvoreDoArq, h, 0);
        break;
      }
      break;

    case (3):
      printf("Verificando se elemento existe na árvore:\n\n");

      int x;
      printf(
          "Insira o elemento (int) que quer verificar se existe na árvore:\n");
      scanf("%d", &x);
      puts("\n");

      if (existe(arvoreDoArq, x) == 1)
        printf("O elemento %d EXISTE na árvore!!", x);
      else
        printf("O elemento %d NÃO existe na árvore!!", x);

      break;

    case (4):
      printf("Contando número de elementos da árvore: \n\n");

      printf("A árvore possui %d elementos!",         
      contarElementos(arvoreDoArq));

      break;

    case (5):
      printf("Imprimindo os nós folha da árvore:\n\n");

      nofolha(arvoreDoArq);

      break;

    case (6):
      printf("Verificando se a árvore está balanceada:\n\n");

      if (balanceado(arvoreDoArq) == 1)
        printf("A árvore ESTÁ balanceada!!\n");
      else
        printf("A a árvore NÃO está balanceada!!\n");

      break;

    case (7):
      printf("Verificando se a árvore é cheia:\n\n");

      if (cheia(arvoreDoArq) == 1)
        printf("A árvore É cheia!!");
      else
        printf("A ávore NÃO é cheia!!");

      break;

    case (8):
      printf("Insira o nó para que seu nível seja impresso:\n\n");
      int y;
      scanf("%d", &y);
      printf("\n\nO nível do nó %d da árvore é: ", y);
      nivelDoNo(arvoreDoArq, y, 0);
      printf("!!");

      break;

    case (9):

      if (teste == 1) {
        freearvore(arvoreDoArq);
        printf("\n\nÁrvore liberada da memoria!");
      }

      printf("\n\nObrigado por utilizar nosso programa!");
      strcpy(continua, "nao");

      break;

    default:
      printf("Opção inválida");
    }

    if (opcao != 9) {
      printf("\n\nDeseja continuar?\n\n");
      scanf("%s", continua);
      puts("\n");

    }
  }

  if (opcao != 9) {
    printf("\n\nObrigado por utilizar nosso programa!");
  }

  fclose(arq);
}
