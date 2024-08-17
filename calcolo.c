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
    bmr=(float)(10*p+6.25*h-5*eta+5);
  else
    bmr=(float)(10*p+6.25*h-5*eta-161);
  printf("\nMetabolismo basale (secondo Mifflin-St Jeor): %.2fkcal\n",bmr);

  //calcolo del fabbisogno giornaliero
  printf("\nInserisci il tuo livello di attivita'\ns=sedentario (poco o nessun esercizio)\nl=leggermente attivo (esercizio fisico da 1 a 3 giorni alla settimana)\na=moderatamente attivo (esercizio fisico da 3 a 5 giorni alla settimana)\nm=molto attivo (esercizio fisico da 6 a 7 giorni alla settimana)\ne=estremamente attivo (esercizio fisico 2 volte al giorno)\n\nFai la tua scelta: ");
  fflush(stdin);
  scanf("%c",&a);
  while (a!='s' && a!='S' && a!='l' && a!='L' && a!='a' && a!='A' && a!='m' && a!='M' && a!='e' && a!='E')
  {
    printf("L'attivita'  inserita non esiste!\n");
    printf("Inserisci un livello di attivita' esistente: ");
    fflush(stdin);
    scanf("%c",&a);
  }
  if (a=='s' || a=='S')
    tdee=bmr*1.2;
  else if (a=='l' || a=='L')
    tdee=bmr*1.375;
  else if (a=='a' || a=='A')
    tdee=bmr*1.55;
  else if (a=='m' || a=='M')
    tdee=bmr*1.725;
  else 
    tdee=bmr*1.9;
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
