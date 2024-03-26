#include "includes/ft_irc.hpp"

int main(int argc, char **argv)
{
	/*if ( argc != 3 && validArgs(argv) )
		return (1);*/
	(void) argc;
	(void) argv;
	int	sockfd = socket(AF_INET, SOCK_STREAM, 0); // Socket TCP (SOCK_STREAM) IPv4 (AF_INET)
	if (sockfd == -1)
		return (1);
	struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(6667); // Port du serveur
	int status = connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (status == -1) {
        std::cerr << "Erreur lors de la connexion au serveur" << std::endl;
        close(sockfd); // Fermeture du socket en cas d'erreur
        return 1;
	}
	/*struct pollfd	test;
	int n = poll();*/
	return (0);
}
