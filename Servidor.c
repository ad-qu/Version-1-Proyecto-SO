#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	int sock_conn, sock_listen, ret, i;
	struct sockaddr_in serv_adr;
	char buff[512];
	char buff2[512];
	
	// INICIALITZACIONS
	
	//INICIAR BASE
	
	MYSQL *conn;
	
	conn = mysql_init(NULL); //Creamos una conexion al servidor MYSQL. 
	if (conn==NULL) 
	{
		printf ("Error al crear la conexion: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "juego" ,0, NULL, 0); //Inicializar la conexion.
	
	if (conn==NULL) 
	{
		printf ("Error al inicializar la conexion: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//INICIAR SOCKET
	
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) //Abrimos el socket.
	{
		printf("Error creando el socket.");
	}
	
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0) //Hacemos bind al puerto.
	{
		printf("Error creando el socket.");
	}
	
	memset(&serv_adr, 0, sizeof(serv_adr)); //Inicialitza el zero serv_addr.
	serv_adr.sin_family = AF_INET;
	
	//Asocia el socket a cualquiera de las IP de la maquina. 
	//htonl formatea el numero que recibe al formato necesario.
	
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	serv_adr.sin_port = htons(9060); //Escuchamos en el port 9050
	
	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
	{
		printf ("Error en el bind.");
	}
	
	if (listen(sock_listen, 2) < 0) //La cola de peticiones pendientes no podra ser superior a 4.
	{
		printf("Error en el Listen.");
	}
	
	for(;;i++)
	{
		printf("Escuchando...\n");
		
		sock_conn = accept(sock_listen, NULL, NULL);
		
		printf("Conexion recibida.\n");
		
		ret = read(sock_conn,buff, sizeof(buff)); //Ahora recibimos su mensaje, que dejamos en buff.
		printf ("Recibido.\n");
		
		buff[ret] = '\0'; //Tenemos que añadirle la marca de fin de string para que no escriba lo que hay despues en el buffer.
		
		printf ("Se ha conectado: %s\n", buff); //Escribimos el nombre en la consola.
		
		char *p = strtok(buff, "/");
		int codigo =  atoi (p);
		
		if (codigo == 0)
		{
			//Desconectar.
		}
		
		if (codigo == 1)
		{
			//Iniciar sesion.
			
			MYSQL_ROW row;
			MYSQL_RES *resultado;
			char consulta[100], respuesta[25];
			
			char usuario[20];
			char contra[20];
			
			p = strtok(NULL, "/");
			
			strcpy(usuario,p);
			
			while (p != NULL)
			{
				strcpy(contra, p);
				p = strtok(NULL,"/");
			}
			
			sprintf(consulta, "SELECT usuario FROM jugador WHERE usuario = '%s' AND contrasena = '%s';", usuario, contra);
			
			printf("%s\n",consulta);
			
			int err = mysql_query (conn, consulta);
			
			if (err!=0) {
				
				printf ("Error al consultar la base de datos. %u %s\n", mysql_errno(conn), mysql_error(conn));

				exit (1);
			}
			
			resultado = mysql_store_result(conn);
			row = mysql_fetch_row(resultado);
			
			if(row == NULL)
			{
				sprintf(respuesta, "0");
			}
			else{
				sprintf(respuesta, "1");
				printf("%s conectado.", usuario);
			}
			
			write (sock_conn, respuesta, strlen(respuesta)); //Enviamos.
		}
		
		if (codigo == 2)
		{
			//Registrarse.
			
			char usuario[20];
			char contra[20];
			char consulta[100];
			
			p = strtok(NULL, "/");
			strcpy(usuario,p);

			p = strtok(NULL,"/");
			strcpy(contra, p);

			printf("Se va a registrar: %s %s \n", usuario, contra);
			
			sprintf (consulta, "INSERT INTO jugador(usuario, contrasena, ganadas) VALUES('%s', '%s', '%d')", usuario, contra, 0);
			mysql_query (conn, consulta);
		}
		
		if (codigo == 3)
		{
			//Partida mas rapida.
			
			MYSQL_ROW row;
			MYSQL_RES *resultado;
			
			int err = mysql_query (conn, "SELECT duracion FROM partida WHERE duracion = (SELECT MIN(duracion) FROM partida)");
			
			if (err!=0)
			{
				printf ("Error al consultar datos de la base %u %s\n", mysql_errno(conn), mysql_error(conn));
				exit (1);
			}
			
			resultado = mysql_store_result(conn);
			row = mysql_fetch_row (resultado);
			
			if(row == NULL)
			{
				printf("No se han obtenido los datos de la consulta \n");
			}
			
			else
			{
				printf("El tiempo de la partida mas rapida es %s \n", row[0]);
			}
						
			write (sock_conn, row[0], strlen(row[0])); //Enviamos.
		}
		
		if (codigo == 4)
		{
			//Decir ganador de una partida.
			
			int id;
			MYSQL_ROW row;
			MYSQL_RES *resultado;
			
			int p2 = atoi(p = strtok(NULL, "/"));
			id = p2;
			
			char consulta[80];
			
			sprintf (consulta,"SELECT partida.ganador FROM partida WHERE partida.ID = '%d'", id);
			
			int err = mysql_query (conn, consulta);
			
			if (err!=0)
			{
				printf ("Error al consultar datos de la base %u %s\n", mysql_errno(conn), mysql_error(conn));
				exit (1);
			}
			
			resultado = mysql_store_result(conn);
			row = mysql_fetch_row (resultado);
			
			if(row == NULL)
			{
				printf("No se han obtenido los datos de la consulta \n");
			}
			
			else
			{
				printf("El tiempo de la partida mas rapida es %s \n", row[0]);
			}
			
			write (sock_conn, row[0], strlen(row[0])); //Enviamos.
		}
		
		if (codigo == 5)
		{
			//Quien haya ganado mas partidas.
			
			MYSQL_ROW row;
			MYSQL_RES *resultado;
			
			char usuario[25];
			char consulta[255];
			
			p = strtok(NULL, "/");
			
			strcpy (usuario, p);
			
			// Ya tenemos el nombre
			printf ("Codigo: %d, Usuario: %s\n", codigo, usuario);
			
			sprintf(consulta, "SELECT jugador.ganadas FROM jugador WHERE jugador.usuario = '%s'", usuario);
			
			int err = mysql_query (conn, consulta);
			
			if (err!=0)
			{
				printf ("Error al consultar datos de la base %u %s\n", mysql_errno(conn), mysql_error(conn));
				exit (1);
			}
			
			resultado = mysql_store_result(conn);
			row = mysql_fetch_row (resultado);
			
			if(row == NULL)
			{
				printf("No se han obtenido los datos de la consulta \n");
			}
			
			else
			{
				printf("El tiempo de la partida mas rapida es %s \n", row[0]);
			}
			
			write (sock_conn, row[0], strlen(row[0])); //Enviamos.
		}
		
		if (i == 99)
		{
			i = 0; //Reiniciamos el contador.
		}	
	}
	return 0;
}
