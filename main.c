#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <conio.h>
#include <windows.h>

#define QUANT_LINGUAS 3
#define QUANT_MODELOS 2
#define QUANT_OPT_EXTERIOR 4
#define QUANT_RIMS 3
#define QUANT_COLORS 4
#define QUANT_WINDOWS 2

const char *opcoes[QUANT_LINGUAS] = { "PT", "ENG", "Quit" };

 typedef struct{
        char model[50];
        char motor[50];
        char color[50];
        char rims[50];
        char windows[50];
    }Car;


     int currentSelection = 0;

  int menu(const char *title, const char *options[], int quantOptions){
   
 while(1){
        printf("%s\n",title);
        for (int i = 0; i < quantOptions; i++) {
            printf("%s %s \n", i == currentSelection ? ">" : " ", options[i]);
        }

        int c = _getch();
       
        if (c == 224) {
            c = _getch();
            system("cls"); 
            if (c == 72 && currentSelection > 0) {
                currentSelection--;
            }
             if (c == 80 && currentSelection < quantOptions -1) {
                currentSelection++; 
            } 
        } 

        else if (c == 13) {
           
            break;
        }
    }
}


int main(void) {
    Car newCar = {0};
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    char language[10] = "";

   menu("Welcome to APX, please select the language",opcoes,QUANT_LINGUAS);
    currentSelection == 0 ? strcpy(language,"PT") : strcpy(language,"ENG");
    currentSelection = 0; 
    system("cls");

    const char *modelos[QUANT_MODELOS] = {"Classe A",strcmp(language,"ENG") == 0?"In development":"Em desenvolvimento"};
    
    const char *exterior[QUANT_OPT_EXTERIOR] = {
    strcmp(language, "ENG") == 0 ? "Color" : "Cor",
    strcmp(language, "ENG") == 0 ? "Rims" : "Jantes",
    strcmp(language, "ENG") == 0 ? "Windows" : "Janelas",
    strcmp(language,"ENG") == 0 ? "Next" : "Próximo"
};
const char *colors[QUANT_COLORS] = {
    strcmp(language, "ENG") == 0 ? "Black hawk" : "Falcão negro",
    strcmp(language, "ENG") == 0 ? "Atlantic blue" : "Azul atlântico",
    strcmp(language, "ENG") == 0 ? "Polar white" : "Branco polar",
    strcmp(language,"ENG") == 0 ? "Apex green (Limited)" : "Verde predador (Limitada)"
};

 const char *rims[QUANT_RIMS] = {
    strcmp(language, "ENG") == 0 ? "Default" : "Origem",
    strcmp(language, "ENG") == 0 ? "Launch Edition (Limited) +700€" : "Launch Edition (Limitadas) +700€",
    strcmp(language, "ENG") == 0 ? "Japan Racing +1000€" : "Japan Racing +1000€"
};
const char *windows[QUANT_WINDOWS] = {
    strcmp(language, "ENG") == 0 ? "Regular" : "Normais",
    strcmp(language, "ENG") == 0 ? "Tinted" : "Escurecidas"
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
    menu((language,"ENG") == 0 ? "Select the model":"Seleciona o modelo",modelos,QUANT_MODELOS);
    if(currentSelection == 1){
        system("cls");
        printf(strcmp(language,"ENG") == 0 ? "Stay tuned for updates soon\n":"Fica atento para novidades em breve\n");
        printf(strcmp(language,"ENG") == 0 ? "Press any key to go back\n":"Prime qualquer tecla para voltar atrás\n");
        int c = _getch();
    }else{
    strcpy(newCar.model, modelos[currentSelection]);
    currentSelection = 0;
    system("cls");
    break;
    }
   
    }
   

    while(1){
        system("cls");
        menu(strcmp(language,"ENG") == 0 ? "Okay let's start with the exterior":"Okay vamos começar pelo exterior",exterior,QUANT_OPT_EXTERIOR); 
        system("cls");
        switch (currentSelection)
    {
    case 0:       
        menu(strcmp(language,"ENG") == 0 ? "Color Selection":"Escolha da cor",colors,QUANT_COLORS);
        strcpy(newCar.color,colors[currentSelection]);
        currentSelection = 0;
        break;
    case 1:
        currentSelection = 0;
        menu(strcmp(language,"ENG") == 0 ? "Rim Selection":"Escolha as jantes",rims,QUANT_RIMS);
        strcpy(newCar.rims,rims[currentSelection]);
        currentSelection = 1;
        break;
    case 2:
        currentSelection = 0;
       menu(strcmp(language,"ENG") == 0 ? "Window Selection":"Escolha as janelas",windows,QUANT_WINDOWS);
        strcpy(newCar.windows,windows[currentSelection]);
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

    printf("%s %s\n", strcmp(language,"ENG") == 0 ? "Model:":"Modelo:", newCar.model);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Color:":"Cor:",newCar.color);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Rims:":"Jantes:",newCar.rims);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Windows:":"Janelas:",newCar.windows);

    c = _getch();
   


    

    return 0;
}