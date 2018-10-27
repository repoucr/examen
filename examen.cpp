/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   examen.cpp
 * Author: sistemas2018
 * 
 * Created on October 27, 2018, 8:52 AM
 */

#include "examen.h"
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


using namespace std;

string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void *funcionHilo1Numeros(void*arg);
void *funcionHilo2Letras(void*arg);
void *funcionHilo3Eliminar(void*arg);

void procesosFork(int hijos, int nietos, int bisnietos) {
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < hijos; i++) {
        int result;
        int hijo = getpid();
        int padre = getppid();
        if ((result = fork()) == 0) {
            cout << "Soy el proceso hijo con i = " << i << "con PID " << getpid() << ". El PID de mi padre es= " << getppid() << "\n";
            for (j = 0; j < nietos; j++) {
                int nieto = getpid();
                int resultNieto;
                if ((resultNieto = fork()) == 0) {
                    cout << "Soy el proceso nieto con j = " << j << "con PID " << this.getpid() << ". El PID de mi padre es= " << hijo << "El pid de mi abuelo es" << padre << "\n";
                    for (k = 0; k < bisnietos; k++) {
                        int resultBisnieto;
                        if ((result = fork()) == 0) {
                            cout << "Soy el proceso bisnieto con k = " << k << "con PID " << this.getpid() << ". El PID de mi padre es= " << nieto << "El PID de mi abuelo es" << hijo << "El PID de mi bisabuelo es" << padre << "\n";
                            exit(0);
                        } else
                            if (result > 0) {
                            wait(0);
                        } else {
                            cout << "Ocurrió un error en la creación del nuevo proceso con fork";
                            exit(1);
                        }
                    }
                    exit(0);
                } else
                    if (resultNieto > 0) {
                    wait(0);
                } else {
                    cout << "Ocurrió un error en la creación del nuevo proceso con fork";
                    exit(1);
                }
            }
            exit(0);
        } else
            if (result > 0) {

            cout << "Soy el proceso padre con PID= " << getpid() << "\n";
            wait(0);
        } else {
            cout << "Ocurrió un error en la creación del nuevo proceso con fork";
            exit(1);
        }

    }
}
pthread_t h1, h2, h3;

void hiloAleatorio() {

    pthread_create(&h1, NULL, funcionHilo1Numeros, (void *) 1);
    pthread_create(&h2, NULL, funcionHilo2Letras, (void *) 2);
    pthread_create(&h3, NULL, funcionHilo3Eliminar, (void *) 3);
    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
    pthread_join(h3, NULL);


}

void *funcionHilo1Numeros(void*arg) {

    while (1) {
        int i = 1 + rand() % (100 - 1);
        printf(" %i", i);
        fflush(stdout);
        sleep(1);
    }
}

void *funcionHilo2Letras(void*arg) {
    while (1) {
        int i = 1 + rand() % (27 - 1);
        printf(" %c", letras[i]);
        fflush(stdout);
        sleep(1);
    }
}

void *funcionHilo3Eliminar(void*arg) {

    sleep(5000);
    cout << endl << "Soy el hilo 2 " << "con PID= " << pthread_self() << endl;
    pthread_cancel(h1);
    cout << endl << "He eliminado el hilo 2 " << "con PID= " << endl;
    sleep(10000);
    pthread_cancel(h2);


}

void mutexLectorEscritor() {
    
    

}

void semaforoLectorEscritor() {
}
