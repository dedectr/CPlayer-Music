#include <iostream>
#include <SFML/Audio.hpp>
using namespace std;


void tocar(string arquivo){
	sf::Music musica;

	if(!musica.openFromFile(arquivo)){
		cout << "Erro no arquvio" << arquivo << "\n";
	}
	musica.play();
	cout << "Tocando " << arquivo << "\n";
	cin.get();

}


int main(int argc, char const *argv[]){
	string arquivo_dir = argv[1];
	string sair = "casa";
	do {
	tocar(arquivo_dir);
	cout << "Caso queira sair,precione Q \n\n";
	cin >> sair;
	} while(sair == "casa");
	return 0;
}
