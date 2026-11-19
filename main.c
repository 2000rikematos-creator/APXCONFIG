#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <conio.h>
#include <windows.h>

#define QUANT_LANGS 3
#define QUANT_MODELOS 2
#define QUANT_OPT_EXTERIOR 4
#define QUANT_RIMS 3
#define QUANT_COLORS 4
#define QUANT_WINDOWS 2

typedef struct{
        int id;
        const char *option;
    }Option;

 typedef struct{
        char model[50];
        Option color;
        Option rims;
        Option windows;
    }Car;   

    typedef struct{
        int id;
        int quantity;
        float preco;
    }StockItem;


    Option langs[QUANT_LANGS] = { {1,"PT"}, {2,"ENG"}, {3,"Quit"}};

     int currentSelection = 0;

  int menu(const char *title, Option options[], int quantOptions){
   
 while(1){
        system("cls"); 
        printf("%s\n",title);
        for (int i = 0; i < quantOptions; i++) {
            printf("%s %s \n", i == currentSelection ? ">" : " ", options[i].option);
        }

        int c = _getch();
       
        if (c == 224) {
            c = _getch();
            
            if (c == 72 && currentSelection > 0) {
                currentSelection--;
            }
             if (c == 80 && currentSelection < quantOptions -1) {
                currentSelection++; 
            } 
        } 

        else if (c == 13) {
           return currentSelection;
        }
    }
}


int main(void) {
    Car newCar = {0};

    StockItem colorStock[4] = {
        {1, 2, 0.0},
        {2, 2,0.0},
        {3,2,0.0},
        {4,2,0.0}};
    
    StockItem rimStock[3] = {
        {1,2,0.0},
        {2,2,0.0},
        {3,2,0.0}};
        
    StockItem windowStock[2] = {
        {1,2,0.0},
        {2,2,0.0}};   



    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    char language[50] = "";

   int selectLanguage = menu("Welcome to APX, please select the language",langs,QUANT_LANGS);
   
   switch (selectLanguage)
   {
   case 0:
    strcpy(language,"PT");
    break;
   case 1: 
   strcpy(language,"ENG");
   break;
   case 2:
   return 0;

   default:
    break;
   }
   
    currentSelection = 0; 
    system("cls");

    Option modelos[QUANT_MODELOS] = {{1,"Classe A"},{2,strcmp(language,"ENG") == 0?"In development":"Em desenvolvimento"}};
    
    Option exterior[QUANT_OPT_EXTERIOR] = {
    {1,strcmp(language, "ENG") == 0 ? "Color" : "Cor"},
    {2,strcmp(language, "ENG") == 0 ? "Rims" : "Jantes"},
    {3,strcmp(language, "ENG") == 0 ? "Windows" : "Janelas"},
    {4,strcmp(language,"ENG") == 0 ? "Next" : "Próximo"}
};
    Option colors[QUANT_COLORS] = {
    {1,strcmp(language, "ENG") == 0 ? "Black hawk" : "Falcão negro"},
    {2,strcmp(language, "ENG") == 0 ? "Atlantic blue" : "Azul atlântico"},
    {3,strcmp(language, "ENG") == 0 ? "Polar white" : "Branco polar"},
    {4,strcmp(language,"ENG") == 0 ? "Apex green (Limited)" : "Verde predador (Limitada)"}
};

 Option rims[QUANT_RIMS] = {
    {1,strcmp(language, "ENG") == 0 ? "Default" : "Origem"},
    {2,strcmp(language, "ENG") == 0 ? "Launch Edition (Limited) +700€" : "Edição de lançamento (Limitadas) +700€"},
    {3,strcmp(language, "ENG") == 0 ? "Japan Racing +1000€" : "Japan Racing +1000€"}
};
    Option windows[QUANT_WINDOWS] = {
    {1,strcmp(language, "ENG") == 0 ? "Regular" : "Normais"},
    {2,strcmp(language, "ENG") == 0 ? "Tinted" : "Escurecidas"}
};


 if (strcmp(language,"ENG") == 0){
        printf("Welcome to the configurator!\n");
        printf("Press any key to continue...\n");
       
    }else if (strcmp(language,"PT") == 0){
        printf("Bem vindo ao configurador\n");
        printf("Prime qualquer tecla para continuar...\n");

    }

    int c = _getch();
   
    while(1){
    system("cls");
   int selectModel = menu(strcmp(language,"ENG") == 0 ? "Select the model":"Seleciona o modelo",modelos,QUANT_MODELOS);
    if(currentSelection == 1){
        system("cls");
        printf(strcmp(language,"ENG") == 0 ? "Stay tuned for updates soon\n":"Fica atento para novidades em breve\n");
        printf(strcmp(language,"ENG") == 0 ? "Press any key to go back\n":"Prime qualquer tecla para voltar atrás\n");
        int c = _getch();
    }else{
    strcpy(newCar.model, modelos[currentSelection].option);
    currentSelection = 0;
    system("cls");
    break;
    }
   
    }
   

    while(1){
        system("cls");
       int selectExteriorOption = menu(strcmp(language,"ENG") == 0 ? "Okay let's start with the exterior":"Okay vamos começar pelo exterior",exterior,QUANT_OPT_EXTERIOR); 
        system("cls");
        switch (currentSelection)
    {
    case 0:       
       int selectColor = menu(strcmp(language,"ENG") == 0 ? "Color Selection":"Escolha da cor",colors,QUANT_COLORS);
        newCar.color = colors[currentSelection];
        currentSelection = 0;
        break;
    case 1:
        currentSelection = 0;
        int selectRim = menu(strcmp(language,"ENG") == 0 ? "Rim Selection":"Escolha as jantes",rims,QUANT_RIMS);
        newCar.rims = rims[currentSelection];
        currentSelection = 1;
        break;
    case 2:
        currentSelection = 0;
       int selectWindows = menu(strcmp(language,"ENG") == 0 ? "Window Selection":"Escolha as janelas",windows,QUANT_WINDOWS);
       newCar.windows = windows[currentSelection];
       currentSelection = 2;
        break;

        case 3:
        break;
    
    default:
        break;
    }

    if(currentSelection == 3){
        break;
    }
    }

    system("cls");

    printf("%s %s %d\n", strcmp(language,"ENG") == 0 ? "Model:":"Modelo:", newCar.model, 1);
    printf("%s %s %d\n",strcmp(language,"ENG") == 0 ? "Color:":"Cor:",newCar.color.option, newCar.color.id);
    printf("%s %s %d\n",strcmp(language,"ENG") == 0 ? "Rims:":"Jantes:",newCar.rims.option, newCar.rims.id);
    printf("%s %s %d\n",strcmp(language,"ENG") == 0 ? "Windows:":"Janelas:",newCar.windows.option, newCar.windows.id);

     _getch();
   

    return 0;
}