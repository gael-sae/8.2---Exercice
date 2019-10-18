#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include "Dragon.json"
#include "Pig.json"

void DragonAttack(std::vector<int>& PigsHealth, int& PigsDead) { // void pour un tampon de l'action : attaque sur un cochon et vérifiant si il est mort.

	const int maxDamageDragon = 15;
	int sizePigs = 10;

	int randomNumber = rand();
	int randomNumberPig = (randomNumber % (sizePigs));
	int randomDragonDamage = (randomNumber % maxDamageDragon) + 5;
	int NumberPig = randomNumberPig;
	int DragonDamage = randomDragonDamage;
	
	std::ifstream infile;
	infile.open("Dragon.json");
	infile.open("Pig.json");
	
	bool isDeadP = true;

	while (isDeadP) {
		if (NumberPig == 10) {
			NumberPig = 0;
		}
		if (PigsHealth[NumberPig] > 0) {
			PigsHealth[NumberPig] -= DragonDamage;
			std::cout << "The dragon attacked the pig " << NumberPig << " with " << DragonDamage << " damages.\n";
			isDeadP = false;
		}
		if (PigsHealth[NumberPig] <= 0) {
			NumberPig++;
		}
	}
	PigsDead = 0;

	for (int i = 0; i < sizePigs; i++) {
		if (PigsHealth[i] <= 0) {
			std::cout << "The pig " << i << " is dead.\n";
			PigsDead++;
		}
	}
	infile.close();
}



void PigsAttack(int& DragonHealth, std::vector<int> PigsHealth) { // void pour un tampon pour l'action : attaque sur un dragon et vérifiant si sa vie est - ou = 0

	const int maxDamagePigs = 4;
	const int sizePigs = 10;

	int randomNumber = rand();
	int randomPigsDamage = (randomNumber % maxDamagePigs) + 1;
	int PigsDamage = randomPigsDamage;
	int sumDamagePigs = 0;
	
	std::ifstream infile;
	infile.open("Dragon.json");
	infile.open("Pig.json");

	for (int i = 0; i < sizePigs; i++) {
		if (PigsHealth[i] > 0) {
			sumDamagePigs += PigsDamage;
		}
	}
	DragonHealth -= sumDamagePigs;
	std::cout << "The pigs attacked the dragon with " << sumDamagePigs << "damage.\n";
	
	infile.close();
}



int main() {
	srand((time(NULL)));


	std::vector <int> PigsHealth{ 10, 10, 10, 10, 10, 10, 10, 10, 10 ,10 }; // list des vie des cochons

	int PigsDead = 0;
	int DragonHealth = 100;
	int RoundNumber = 1;

	bool isAliveP = true;
	bool isAliveD = true;


	while (isAliveD == true && isAliveP == true) {
		std::cout << "Round " << RoundNumber << "\n";

		DragonAttack(PigsHealth, PigsDead);

		PigsAttack(DragonHealth, PigsHealth);

		if (PigsDead == 10) {
			std::cout << "All pigs are dead. The dragon has won.\n";

			isAliveP = false;
		}
		else if (DragonHealth <= 0) {
			std::cout << "The pigs have slain the dragon. They win.\n";

			isAliveD = false;
		}
		RoundNumber++;

		system("pause");
		system("cls");
	}
	return 0;
}


