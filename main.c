#include <stdio.h>
#include <stdlib.h>
#include <string.h>   
#include <conio.h>
#include <locale.h>
#include <windows.h>

#define QUANT_LINGUAS 3
#define QUANT_MODELOS 2
#define QUANT_OPT_EXTERIOR 4
#define QUANT_RIMS 3
#define QUANT_COLORS 4
#define QUANT_WINDOWS 2

int main(void) {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    char language[10] = "";

    const char *opcoes[QUANT_LINGUAS] = { "PT", "ENG", "Quit" };

  

    int selectedModel = 0;
    int selectedLangOP = 0;
    int selectedExteriorOpt = 0;
    int selectedRim = 0;
    int selectedColor = 0;
    int selectedWindows = 0;
    
    
    
    typedef struct{
        char model[50];
        char motor[50];
        char color[50];
        char rims[50];
        char windows[50];
    }Car;

    Car newCar = {0};



    while(1){
        printf("Welcome to APX, select language:\n");
        for (int i = 0; i < QUANT_LINGUAS; i++) {
            printf("%s %s \n", i == selectedLangOP ? ">" : " ", opcoes[i]);
        }

        int c = _getch();

       
        if (c == 224) {
            c = _getch();
            system("cls"); 
            if (c == 72 && selectedLangOP > 0) {
                selectedLangOP--;
            }
             if (c == 80 && selectedLangOP < QUANT_LINGUAS -1) {
                selectedLangOP++; 
            } 
        } 

        else if (c == 13) {
            if (selectedLangOP == 0) {
                strcpy(language,"PT");
                system("cls");
                break;
            } 
            else if (selectedLangOP == 1) {
                strcpy(language,"ENG");
                system("cls");
                break;
                
            } 
            else if (selectedLangOP == 2) {
                return 0;
            }
        }
    }

      

    system("cls");

 if (strcmp(language,"ENG") == 0){
        printf("Welcome to the configurator!\n");
        printf("Press any key to continue...");
       
    }else if (strcmp(language,"PT") == 0){
        printf("Bem vindo ao configurador\n");
        printf("Prime qualquer tecla para continuar...");

    }

    int c = _getch();
    system("cls");

    const char *modelos[QUANT_MODELOS] = {"Classe A",strcmp(language,"ENG") == 0?"In development":"Em desenvolvimento"};

    while(1){
        system("cls");
         printf("Seleciona o modelo\n");
        for (int i = 0; i < QUANT_MODELOS; i++)
        {
     printf("%s %s\n",selectedModel == i ? ">":" ",modelos[i]);
        } 
    int c = _getch();
    system("cls");
    if(c == 224 || c == 0){
        int c = _getch();
        system("cls");
         if(c == 80 && selectedModel < QUANT_MODELOS){
            selectedModel++;
        }else if(c == 72 && selectedModel > 0){
            selectedModel--;
        }
    }else if (c == 13){
            system("cls");
            strcpy(newCar.model, modelos[selectedModel]);
            
            break;
    }

    
    
    }

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
   
    while(1){

        while (1){
        system("cls");    
        strcmp(language,"ENG") == 0 ? printf("Okay let's start with the exterior\n") : printf("Okay vamos começar pelo exterior\n");

         for (int i = 0; i < QUANT_OPT_EXTERIOR; i++)
         {
            printf("%s %s\n", selectedExteriorOpt == i ? ">" : " ", exterior[i]);
         }
         c = _getch();
         if (c == 224 || c == 0){
            c = _getch();
            if(c == 72 && selectedExteriorOpt > 0){
                selectedExteriorOpt--;
            }
            if(c == 80 && selectedExteriorOpt < QUANT_OPT_EXTERIOR-1){
                selectedExteriorOpt++;
            } 
        }else if(c == 13){
            break;
        }



    }

     switch (selectedExteriorOpt)
    {
    case 0:        
        while(1){
            system("cls");
            printf("%s\n",strcmp(language,"ENG") == 0 ? "Color Selection":"Escolha da cor"); 
            for (int i = 0; i < QUANT_COLORS; i++)
            {
                printf("%s %s\n",selectedColor == i ? ">":" ", colors[i]);
            }
            int c = _getch();
            if(c == 224 || c == 0){
                c = _getch();
                if(c == 72 && selectedColor > 0){
                    selectedColor--;
                }
                if(c == 80 && selectedColor < QUANT_COLORS-1){
                    selectedColor++;
                }
            }else if(c == 13){
                    strcpy(newCar.color,colors[selectedColor]);
                    break;
                }
        }
        break;
    case 1:
         while(1){
            system("cls");
            printf("%s\n",strcmp(language,"ENG") == 0 ? "Rim Selection":"Escolha das jantes"); 
            for (int i = 0; i < QUANT_RIMS; i++)
            {
                printf("%s %s\n",selectedRim == i ? ">":" ", rims[i]);
            }
            int c = _getch();
            if(c == 224 || c == 0){
                c = _getch();
                if(c == 72 && selectedRim > 0){
                    selectedRim--;
                }
                if(c == 80 && selectedRim < QUANT_RIMS-1){
                    selectedRim++;
                }
            }else if(c == 13){
                    strcpy(newCar.rims,rims[selectedRim]);
                    break;
                }     
        }
        break;
        case 2:
        while(1){
            system("cls");
            printf("%s\n",strcmp(language,"ENG") == 0 ? "Window Selection":"Escolha das janelas"); 
            for (int i = 0; i < QUANT_WINDOWS; i++)
            {
                printf("%s %s\n",selectedWindows == i ? ">":" ", windows[i]);
            }
            int c = _getch();
            if(c == 224 || c == 0){
                c = _getch();
                if(c == 72 && selectedWindows > 0){
                    selectedWindows--;
                }
                if(c == 80 && selectedWindows < QUANT_WINDOWS-1){
                    selectedWindows++;
                }
            }else if(c == 13){
                    strcpy(newCar.windows,windows[selectedWindows]);
                    break;
                }
                
        }
    break;
        case 3:
        break;
    
    default:
        break;
    }

    if(selectedExteriorOpt == 3){
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