//Biblioteca
#include <stdio.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL,"");
    int opçao;

printf("Selecione (1-3):\n");
scanf("%d", &opçao);

switch(opçao) {
case 1:
printf("Voce escolheu o check in:\n");
break;

case 2:
printf("Voce escolheu serviço de quarto:\n");
break;

case 3:
printf("Voce escolheu fazer pedido:\n");
break;

return 1;
}
return 0;
}