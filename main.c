#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <conio.h>
#include <windows.h>

// Define as constantes para a quantidade de opções disponíveis para cada categoria de configuração do carro
#define QUANT_LINGUAS 3
#define QUANT_MODELOS 2
#define QUANT_OPT_EXTERIOR 4
#define QUANT_RIMS 3
#define QUANT_COLORS 4
#define QUANT_WINDOWS 2
#define QUANT_OPT_INTERIOR 4 
#define QUANT_SEATS 3
#define QUANT_RADIO 3
#define QUANT_DASHBOARD 2
#define QUANT_OPT_EXTRAS 3
#define QUANT_KIT 2
#define QUANT_MOTOR 3

const char *opcoes[QUANT_LINGUAS] = { "PT", "ENG", "Quit" };
 
// Define a estrutura Car para armazenar as informações do carro configurado
 typedef struct{
        char model[50];
        char color[50];
        char rims[50];
        char windows[50];
        char seats[50];
        char radio[50];
        char dashboard[50];
        char kit[50];
        char motor[50];
    }Car;


     int currentSelection = 0;
  
  // Função para exibir o menu e capturar a seleção do usuário
  int menu(const char *title, const char *options[], int quantOptions){
 
 // Loop infinito para exibir o menu e capturar a seleção do usuário
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
           return currentSelection;
        }
    }
}


int main(void) {
    Car newCar = {0};
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    char language[10] = "";

   int selectLanguage = menu("Welcome to APX, please select the language",opcoes,QUANT_LINGUAS);
    switch (selectLanguage)
    {case 0:
        strcpy(language,"PT");
        break;
    case 1:
        strcpy(language, "ENG");
        break;
    case 2:
        return 0;
    }
     
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
    strcmp(language, "ENG") == 0 ? "Launch Edition (Limited) +700€" : "Edição de lançamento (Limitadas) +700€",
    strcmp(language, "ENG") == 0 ? "Japan Racing +1000€" : "Japan Racing +1000€"
};

const char *windows[QUANT_WINDOWS] = {
    strcmp(language, "ENG") == 0 ? "Regular" : "Normais",
    strcmp(language, "ENG") == 0 ? "Tinted" : "Escurecidas"
};


const char *interior[QUANT_OPT_INTERIOR] = {
    strcmp(language, "ENG") == 0 ? "Seats" : "Bancos",
    strcmp(language, "ENG") == 0 ? "Radio" : "Rádio",
    strcmp(language,"ENG") == 0 ? "Dashboard" : "Mostrador",
    strcmp(language,"ENG") == 0 ? "Next" : "Próximo"
};

const char *seats[QUANT_SEATS] = {
    strcmp(language, "ENG") == 0 ? "Default" : "Originais",
    strcmp(language, "ENG") == 0 ? "Leather seats +200€" : "Bancos de couro +200€",
    strcmp(language, "ENG") == 0 ? "Alcantara Bucket seats +1000€" : "Bancos baquet de Alcantara +1000€"
};

const char *radio[QUANT_RADIO] = {
    strcmp(language, "ENG") == 0 ? "Default" : "Original",
    strcmp(language, "ENG") == 0 ? "2DIN Radio +100€" : "2DIN Rádio +100€",
    strcmp(language, "ENG") == 0 ? "Android Auto/CarPlay +300€" : "Android Auto/CarPlay +300€"
};

const char *dashboard[QUANT_DASHBOARD] = {
    strcmp(language, "ENG") == 0 ? "Default" : "Original",
    strcmp(language, "ENG") == 0 ? "Sport +1000€" : "Desportivo +1000€"
};

const char *extras[QUANT_OPT_EXTRAS] = {
    strcmp(language, "ENG") == 0 ? "Bodykit" : "Kit de carroçaria",
    strcmp(language, "ENG") == 0 ? "Engine" : "Motor",
    strcmp(language,"ENG") == 0 ? "Next" : "Próximo"
};

const char *kit[QUANT_KIT] = {
    strcmp(language, "ENG") == 0 ? "Default" : "Original",
    strcmp(language, "ENG") == 0 ? "Sport Package +1000€" : "Pacote desportivo +1000€"
};

const char *motor[QUANT_MOTOR] = {
    strcmp(language, "ENG") == 0 ? "Default 1.6L Diesel" : "1.6L Diesel",
    strcmp(language, "ENG") == 0 ? "2.0L Turbo Petrol +2000€" : "2.0L Turbo Gasolina +2000€",
    strcmp(language, "ENG") == 0 ? "3.5L V8 Petrol +4000€" : "3.5L V8 Gasolina +4000€"
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
    strcpy(newCar.model, modelos[currentSelection]);
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
        strcpy(newCar.color,colors[currentSelection]);
        currentSelection = 0;
        break;
    case 1:
        currentSelection = 0;
        int selectRim = menu(strcmp(language,"ENG") == 0 ? "Rim Selection":"Escolha as jantes",rims,QUANT_RIMS);
        strcpy(newCar.rims,rims[currentSelection]);
        currentSelection = 1;
        break;
    case 2:
        currentSelection = 0;
       int selectWindows = menu(strcmp(language,"ENG") == 0 ? "Window Selection":"Escolha as janelas",windows,QUANT_WINDOWS);
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

    printf("%s %s\n", strcmp(language,"ENG") == 0 ? "Model:":"Modelo:", newCar.model);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Color:":"Cor:",newCar.color);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Rims:":"Jantes:",newCar.rims);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Windows:":"Janelas:",newCar.windows);

    c = _getch();

    while (1){
        system("cls");
       int selectInteriorOption = menu(strcmp(language,"ENG") == 0 ? "Now let's move on to the interior":"Agora vamos passar para o interior",interior,QUANT_OPT_INTERIOR); 
        system("cls");
        switch (currentSelection)
    {
    case 0:       
       int selectSeats = menu(strcmp(language,"ENG") == 0 ? "Seat Selection":"Escolha os bancos",seats,QUANT_SEATS);
        strcpy(newCar.seats,seats[currentSelection]);
        currentSelection = 0;
        break;
    case 1:
        currentSelection = 0;
        int selectRadio = menu(strcmp(language,"ENG") == 0 ? "Radio Selection":"Escolha o rádio",radio,QUANT_RADIO);
        strcpy(newCar.radio,radio[currentSelection]);
        currentSelection = 1;
        break;
    case 2:
        currentSelection = 0;
        int selectDashboard = menu(strcmp(language,"ENG") == 0 ? "Dashboard Selection":"Escolha o mostrador",dashboard,QUANT_DASHBOARD);
        strcpy(newCar.dashboard,dashboard[currentSelection]);
        currentSelection = 2;
        break;
    
    case 3:
        break;
    }

    if(currentSelection == 3){
        break;
    }

    }

    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Seats:":"Bancos:", newCar.seats);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Radio:":"Rádio:",newCar.radio);
    printf("%s %s\n",strcmp(language,"ENG") == 0 ? "Dashboard:":"Mostrador:",newCar.dashboard);
    
    c = _getch();

    while (1){
        system("cls");
       int selectExtrasOption = menu(strcmp(language,"ENG") == 0 ? "Now let's move on to the extras":"Agora vamos passar para os extras",extras,QUANT_OPT_EXTRAS); 
        system("cls");
        switch (currentSelection)
    {
    case 0:       
       int selectKit = menu(strcmp(language,"ENG") == 0 ? "Bodykit Selection":"Escolha o kit de carroçaria",kit,QUANT_KIT);
        strcpy(newCar.motor,kit[currentSelection]);
        currentSelection = 0;
        break;
    case 1:
        currentSelection = 0;
        int selectMotor = menu(strcmp(language,"ENG") == 0 ? "Engine Selection":"Escolha o motor",motor,QUANT_MOTOR);
        strcpy(newCar.motor,motor[currentSelection]);
        currentSelection = 1;
        break;
    
    case 2:
        break;
    }
    
    if(currentSelection == 2){
        break;
    }

    }

    printf("%s %s\n",strcmp(language, "ENG") == 0 ? "Seats:":"Bancos:", newCar.kit);
    printf("%s %s\n",strcmp(language, "ENG") == 0 ? "Seats:":"Bancos:", newCar.motor);
    _getch();
    
    return 0;
}