                                          //PEQUEÑO GESTOR DE PROCESOS EN C++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>


void listar_procesos(){
printf("Listando procesos activos: \n");
system("ps-e");
}

void matar_proceso(pid_t pid) {
    if (kill(pid, SIGKILL) == 0){
        printf("Proceso %d terminado correctamente.\n ");  
}
else{
        perror("Error al matar el proceso\n");
}

void ejecutar_proceso(char *programa){
    pid_t pdi = fork();
    if(pid ==0){
        execlp(prgrama, programa, NULL); 
        perror("Error al ejecutar el programa");
        exit(EXIT_FAILURE);
}

else if (pid > 0) {
    printf("proceso %d ejecutandose: %s \n, pid, programa");
}
else{
    perror("Error al crear el proceso %d", pid);
    
} 

pid_t pid;
char programa[256];

while (1){
printf("\n Gestor de procesos\n");
printf("1. Listar procesos \n");
printf("2. Matar proceso\n");
printf("3.Ejecutar un proceso\n");
printf("4. Salir\n")
printf("5.Seleccione una opcion:");
scanf("%d, &opcion");

switch(opcion){


    case 1:
    listar_procesos();
    break;

    case 2:
    printf("Ingrese el PID del proceso a matar\n");
    scanf("%d", &pid);
    matar_proceso(pid);
    break;

    case 3:
    printf("Ingresa el nombre del programa a ejecutar");
    scanf("%s", programa);
    ejecutar_proceso(programa);

    case 4:
    printf("saliendo...");
    exit

    default:
    printf("opcion no valida\n");
}

return 0;


}



