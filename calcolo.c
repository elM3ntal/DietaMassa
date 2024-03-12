#include <stdio.h>
#include <stdlib.h>



int main (void)
{
  float p, bmr, tdee, pr, gr, cgr, ccb, cb,kcal;
  int eta, h, sur;
  char s,a;
  printf("Inserisci il tuo peso(kg): ");
  scanf("%f",&p);
  printf("Inserisci la tua altezza(cm): ");
  scanf("%d",&h);
  printf("Inserisci la tua eta': ");
  scanf("%d",&eta);
  printf("Inserisci il tuo sesso(M/F): ");
  fflush(stdin);
  scanf("%c",&s);
  while (s!='M' && s!='m' && s!='F' && s!='f')
  {
    printf("Il sesso inserito non esiste!\n");
    printf("Inserisci il tuo sesso(M/F): ");
    fflush(stdin);
    scanf("%c",&s);
  }

  //calcolo del metabolismo basale
  if (s=='M' || s=='m')
    bmr=(float)((10*p)+(6.25*h)-(5*eta)+5);
  else
    bmr=(float)((10*p)+(6.25*h)-(5*eta)-161);
  printf("\nMetabolismo basale (secondo Harris Benedict): %.2fkcal\n",bmr);

  //calcolo del fabbisogno giornaliero
  printf("\nInserisci il tuo livello di attivita' (s=sedentario, a=moderatamente attivo, m=molto attivo): ");
  fflush(stdin);
  scanf("%c",&a);
  while (a!='s' && a!='S' && a!='a' && a!='A' && a!='m' && a!='M')
  {
    printf("L'attività inserita non esiste!\n");
    printf("Inserisci il tuo livello di attivita' (s=sedentario, a=moderatamente attivo, m=molto attivo): ");
    fflush(stdin);
    scanf("%c",&a);
  }
  if (a=='S' || a=='s')
    tdee=bmr*1.53;
  else if (a=='a' || a=='A')
    tdee=bmr*1.76;
  else
    tdee=bmr*2.25;
  printf("\nTDEE: %.2fkcal\n",tdee);

  printf("Inserisci di quante calorie vuoi che sia il surplus (tra 300 e 500): ");
  scanf("%d",&sur);
  while (sur<300 || sur>500)
  {
    printf("Il valore inserito non rispetta le condizioni date\n");
    printf("Inserisci di quante calorie vuoi che sia il surplus (tra 300 e 500): ");
    scanf("%d",&sur);
  }
  kcal=(float)tdee+sur;
  pr=2*p; //calcolo delle proteine (g)
  cgr=kcal*0.2; //calcolo delle kcalorie dei grassi
  gr=cgr/9; //calcolo dei grassi (g)
  ccb=kcal-(pr*4)-cgr; //calcolo delle kcalorie dei carboidrati
  cb=ccb/4; //calcolo dei carboidrati (g)
  //1g carboidrati = 4kcal

  printf("\nkcal totali= %.2fkcal\n",kcal);
  printf("Proteine: %.2f\n",pr);
  printf("Grassi: %.2f\n",gr);
  printf("Carboidrati: %.2f\n\n",cb);

  system("PAUSE");
  return 0;
}
