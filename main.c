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
        int price;
    }Car;   

    Option langs[QUANT_LANGS] = { {1,"PT"}, {2,"ENG"}, {3,"Quit"}};

    //stock de cores
    //id, quantidade, preço, prazo

    int colorStock[4][4] = {
        {1,2,0,10},     //Black hawk
        {2,2,0,10},     //Atlantic blue
        {3,2,0,10},     //Polar white
        {4,0,1000,10}   //Apex green
    };
    //stock de jantes
    int rimStock[3][4] = {
        {1,2,0,25},  //Default
        {2,2,0,25},  //Launch edition    
        {3,2,700,25}  //japan racing
    };
        //stock de janelas
    int windowStock[2][4] = {
        {1,2,0,30},    //Regular
        {2,2,500,30}  //Tinted
    };   

     int currentSelection = 0;


     int checkStock(Car car){
        
        int deliveryTime = 10;
        int finalPrice = car.price;

        //Matriz do stock
        //id 0, quantidade 1, preço 2, prazo 3

        if(colorStock[car.color.id-1][1] < 1){deliveryTime = deliveryTime + colorStock[car.color.id-1][3];};
        finalPrice = finalPrice + colorStock[car.color.id-1][2];

        if(rimStock[car.rims.id-1][1] < 1){deliveryTime = deliveryTime + colorStock[car.rims.id-1][3];}
        finalPrice = finalPrice + rimStock[car.rims.id-1][2];

        if(windowStock[car.windows.id-1][1] < 1){deliveryTime = deliveryTime + colorStock[car.windows.id-1][3];}
        finalPrice = finalPrice + windowStock[car.windows.id-1][2];


        printf("delivery time is %d days\n ",deliveryTime);
        printf("price is %d$\n",finalPrice);

        _getch();
     }

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

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    bool isEng = true;

   int selectLanguage = menu("Welcome to APX, please select the language",langs,QUANT_LANGS);
   
   switch (selectLanguage)
   {
   case 0:
    isEng = false;
    break;
   case 1: 
   isEng = true;
   break;
   case 2:
   return 0;

   default:
    break;
   }
   

    currentSelection = 0; 
    system("cls");

    Option modelos[QUANT_MODELOS] = {{1,"Classe A"},{2, isEng ?"In development":"Em desenvolvimento"}};
    
    Option exterior[QUANT_OPT_EXTERIOR] = {
    {1,isEng ? "Color" : "Cor"},
    {2,isEng ? "Rims" : "Jantes"},
    {3,isEng ? "Windows" : "Janelas"},
    {4,isEng ? "Next" : "Próximo"}
};
    Option colors[QUANT_COLORS] = {
    {1,isEng ? "Black hawk" : "Falcão negro"},
    {2,isEng ? "Atlantic blue" : "Azul atlântico"},
    {3,isEng ? "Polar white" : "Branco polar"},
    {4,isEng ? "Apex green (Limited)" : "Verde predador (Limitada)"}
};

 Option rims[QUANT_RIMS] = {
    {1,isEng ? "Default" : "Origem"},
    {2,isEng ? "Launch Edition (Limited) +700€" : "Edição de lançamento (Limitadas) +700€"},
    {3,isEng ? "Japan Racing +1000€" : "Japan Racing +1000€"}
};
    Option windows[QUANT_WINDOWS] = {
    {1,isEng ? "Regular" : "Normais"},
    {2,isEng ? "Tinted" : "Escurecidas"}
};


 if (isEng){
        printf("Welcome to the configurator!\n");
        printf("Press any key to continue...\n");
       
    }else{
        printf("Bem vindo ao configurador\n");
        printf("Prime qualquer tecla para continuar...\n");

    }

    int c = _getch();
   
    while(1){
    system("cls");
   int selectModel = menu(isEng ? "Select the model":"Seleciona o modelo",modelos,QUANT_MODELOS);
    if(currentSelection == 1){
        system("cls");
        printf(isEng ? "Stay tuned for updates soon\n":"Fica atento para novidades em breve\n");
        printf(isEng ? "Press any key to go back\n":"Prime qualquer tecla para voltar atrás\n");
        int c = _getch();
    }else{
    strcpy(newCar.model, modelos[currentSelection].option);
    newCar.price = 40000;
    currentSelection = 0;
    system("cls");
    break;
    }
    }
   
    while(1){
        system("cls");
       int selectExteriorOption = menu(isEng ? "Okay let's start with the exterior":"Okay vamos começar pelo exterior",exterior,QUANT_OPT_EXTERIOR); 
        system("cls");
        switch (currentSelection)
    {
    case 0:       
       int selectColor = menu(isEng ? "Color Selection":"Escolha da cor",colors,QUANT_COLORS);
        newCar.color = colors[currentSelection];
        currentSelection = 0;
        break;
    case 1:
        currentSelection = 0;
        int selectRim = menu(isEng ? "Rim Selection":"Escolha as jantes",rims,QUANT_RIMS);
        newCar.rims = rims[currentSelection];
        currentSelection = 1;
        break;
    case 2:
        currentSelection = 0;
       int selectWindows = menu(isEng ? "Window Selection":"Escolha as janelas",windows,QUANT_WINDOWS);
       newCar.windows = windows[currentSelection];
       currentSelection = 2;
        break;

        case 3:

        break;
    
    default:
        break;
    }

    if(currentSelection == 3){

        if(newCar.color.id == 0 || newCar.rims.id == 0 || newCar.windows.id == 0){
            printf("%s\n", isEng ? "Please complete the configuration before proceeding" : "Por favor complete a configuração antes de prosseguir");
            _getch();
        }else{
            break;
        }
            
    }
    }

    system("cls");

    printf("%s %s\n",isEng ? "Model:":"Modelo:", newCar.model);
    printf("%s %s\n",isEng ? "Color:":"Cor:",newCar.color.option);
    printf("%s %s\n",isEng ? "Rims:":"Jantes:",newCar.rims.option);
    printf("%s %s\n",isEng ? "Windows:":"Janelas:",newCar.windows.option);

    checkStock(newCar);
     _getch();
   

    return 0;
}