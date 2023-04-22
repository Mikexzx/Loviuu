#include <stdio.h>
#include <string.h>

#define maxintentos 6

int main() {
	
 	system("color 57");
	printf("Hola bienvenida al juego, espero que te guste !! \n\n");
	printf("Las cosas son simples, son una frases que debes completar\n");
	printf("Son 5 frases que puedes jugarrr espero no te aburra! \n\n");
	
    char palabras[][40] = {"quieresserminovia", "tequierescasarconmigo","sabesqueteamoo","graciaspor2hermososmeses","laingemashermosaaa"};
    char palabraAdivinar[40];
    char palabraGuiones[40];
    int intentos = 0, i;
    char letra;
    int acertado = 0;


    srand(time(NULL));
    int indice = rand() % 5; //creamos la variable y le damos que elija una palabra del arreglo
    strcpy(palabraAdivinar, palabras[indice]);	//copiamos el contenido de la palabra en una nueva variable dependiendo de la palabra elegida


    for (i = 0; i < strlen(palabraAdivinar); i++) { //creamos lo guiones bajos dependiendo del tamaño de la palabra
        palabraGuiones[i] = '-';
    }
    palabraGuiones[i] = '\0'; //aumentamos lo guiones hasta el final de la cadena


    while (intentos < maxintentos && !acertado) { //mientras que los intentos sean menores que los maximos y sea diferente de los aciertos
        printf("Introduce una letra: \n\n");
        scanf(" %c", &letra);
        int encontrado = 0;
        for (i = 0; i < strlen(palabraAdivinar); i++) { //dependiendo del tamaño de la palabra y si la palabra que fue insertda es igual a la letra 
            if (palabraAdivinar[i] == letra) {			//de la palabra, los guiones van a ser iguales a las entras restantes y se va a aumentar
                palabraGuiones[i] = letra;				//el valor de los encontrados
                encontrado = 1;
            }
        }
        if (!encontrado) { //si la letra es diferente 
            intentos++; //se va aumentar el numero de intentos
            printf("Letra incorrecta, te quedan %d intentos\n", maxintentos - intentos); //se va a restar los intentos contados de los maximos
        } else {
            printf("Has acertado una letra!\n");
        }
        printf("Palabra a adivinar: %s\n", palabraGuiones); //llamamos a la varibale para que imprima los guiones
        if (strcmp(palabraAdivinar, palabraGuiones) == 0) { //comparamos con strcmp dos cadenas y si las dos son iguales a 0	
            acertado = 1;									//entonces el acertado es 1 
        }
    }

    if (acertado==1) { //si el acerdado es 1 se imprime lo siguiente
        printf("Felicidades, has ganado deseoooo que te haya entrenido este pequeño juegoo \n\n");
        printf("Gracias por ser mi noviaaa te amooo ! \n\n");
    } else {
        printf("Lo siento, has perdido! me rompes mi corazonnn \n");
    }

	system("pause");
    return 0;
}

