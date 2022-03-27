#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

  char *ip = "192.168.1.3";
  int puerto = 8001;

  int socket1;
  struct sockaddr_in direccion;
  socklen_t addr_size;
  char buffer[512];

  socket1 = socket(AF_INET, SOCK_STREAM, 0);
  if (socket1 < 0){
    perror("Error de socket");
    exit(1);
  }
  printf("Socket para conexion TCP  del server creado \n");

  memset(&direccion, '\0', sizeof(direccion));
  addr.sin_family = AF_INET;
  addr.sin_port = puerto;
  addr.sin_addr.s_addr = inet_addr(ip);

  connect(socket1, (struct sockaddr*)&direccion, sizeof(direccion));
  printf("Conectado con el Servidor\n");

  bzero(buffer, 512);
  strcpy(buffer, "Mensaje del cliente");
  printf("Cliente: %s\n", buffer);
  send(socket1, buffer, strlen(buffer), 0);

  bzero(buffer, 512);
  recv(socket1, buffer, sizeof(buffer), 0);
  printf("Servidor: %s\n", buffer);

  close(socket1);
  printf("Desconectado del Servidor\n");

  return 0;

}