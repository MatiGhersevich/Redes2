#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

  char *ip = "192.168.1.3";
  int puerto = 8001;

  int server_sock, cliente_sock;
  struct sockaddr_in server_dir, client_dir;
  socklen_t addr_size;
  char buffer[512];
  int tkn;

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0){
    perror("Socket error");
    exit(1);
  }
  printf("Conexion TCP por medio del socket lograda\n");

  memset(&server_dir, '\0', sizeof(server_dir));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = puerto;
  server_addr.sin_addr.s_addr = inet_addr(ip);

  tkn = bind(server_sock, (struct sockaddr*)&server_dir, sizeof(server_dir));
  if (tkn < 0){
    perror("Error en el enlace");
    exit(1);
  }
  printf("Enlace logrado por el puerto: %d\n", puerto);

  listen(server_sock, 1);
  printf("Esperando\n");

  while(1){
    addr_size = sizeof(cliente_dir);
    cliente_sock = accept(server_sock, (struct sockaddr*)&client_dir, &addr_size);
    printf("Cliente conectado\n");

    bzero(buffer, 512);
    recv(cliente_sock, buffer, sizeof(buffer), 0);
    printf("Cliente: %s\n", buffer);

    bzero(buffer, 512);
    strcpy(buffer, "Mensaje del servidor");
    printf("Servidor: %s\n", buffer);
    send(cliente_sock, buffer, strlen(buffer), 0);

    close(cliente_sock);
    printf("Cliente desconectado\n\n");

  }

  return 0;
}