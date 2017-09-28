#include <stdio.h>
#include <string.h>
#define MAX_SIZE 8


int main(int argc, char *argv[])
{
    int i;
    for (i=1;i<argc;i++){
        int n = esNumero(argv[i]);
        if (n==1){
            printf("El string %i es un numero.\n\n",i);
        }else{
            printf("El string %i no es un numero.\n\n",i);
        }
    }
    return 0;
}


int esNumero(char *args)
{
    char buffer[80];
    int ret = 1;

    sprintf(buffer, "%s", args);
    printf("String input: %s \n", args);

    int n = strlen(buffer);
    if (MAX_SIZE<n){
        printf("String demasiado grande. Introduce un string de 8 caracteres o menos para ser evaluado");
        ret = 0;
    }
    else{
        int i;
        for (i = 0; i < n; ++i){
            if('9' < buffer[i] || buffer[i] < '0' ){
                if(!(i == 0 && buffer[i] == '-')){
                    if(buffer[i] != '\0'){
                        printf("Digito no numerico en posicion del string: %i \n", i);
                        //para que pare de buscar
                        i = n;
                        ret = 0;
                    }
                }
            }
        }
    }
    return ret;
}