#include <iostream>
#include <time.h>
#include <vector>
#include <fstream>
#include "Dragon.json"
#include "Pig.json"


/* Code de base :
void DragonAttack(std::vector<int>& PigsHealth, int& PigsDead) { // void pour un tampon de l'action : attaque sur un cochon et vérifiant si il est mort.

	const int maxDamageDragon = 15;
	int sizePigs = 10;

	int randomNumber = rand();
	int randomNumberPig = (randomNumber % (sizePigs));
	int randomDragonDamage = (randomNumber % maxDamageDragon) + 5;
	int NumberPig = randomNumberPig;
	int DragonDamage = randomDragonDamage;
	
	
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
}



void PigsAttack(int& DragonHealth, std::vector<int> PigsHealth) { // void pour un tampon pour l'action : attaque sur un dragon et vérifiant si sa vie est - ou = 0

	const int maxDamagePigs = 4;
	const int sizePigs = 10;

	int randomNumber = rand();
	int randomPigsDamage = (randomNumber % maxDamagePigs) + 1;
	int PigsDamage = randomPigsDamage;
	int sumDamagePigs = 0;
	
	
	for (int i = 0; i < sizePigs; i++) {
		if (PigsHealth[i] > 0) {
			sumDamagePigs += PigsDamage;
		}
	}
	DragonHealth -= sumDamagePigs;
	std::cout << "The pigs attacked the dragon with " << sumDamagePigs << "damage.\n";
	}
*/


int main() {
	srand((time(NULL)));

	/*std::vector <int> PigsHealth{ 10, 10, 10, 10, 10, 10, 10, 10, 10 ,10 };

	int PigsDead = 0;
	int DragonHealth = 100;*/
	int RoundNumber = 1;
	
	char Dragon;
	char Pig;
	int Quantity;

	bool isAlive = true;
	
	std::ifstream infile;
	infile.open("Dragon.json");
	infile.open("Pig.json");

	while (isAlive == true) {
		std::cout << "Round " << RoundNumber << "\n";

		/*DragonAttack(PigsHealth, PigsDead);

		PigsAttack(DragonHealth, PigsHealth);*/

		

		if (Pig["Quantity"] > 0) {
			Pig["Health"] = -Dragon["AttackMin"] || -Dragon["AttackMax"];
			if (Pig["Health"] <= 0)
				Pig["Quantity"]--
		}

		if (Dragon["Health"] > 0) {
			for (int i = 0; i < Pig["Quantity"]; i++) {
				Dragon["Health"] = -Pig["AttackMin"] || -Pig["AttackMax"];
			}
		}

		if (Pig["Quantity"] == 0) {
			std::cout << "All pigs are dead. The dragon has won.\n";

			isAlive = false;
		}
		else if (Dragon["Health"] <= 0) {
			std::cout << "The pigs have slain the dragon. They win.\n";

			isAlive = false;
		}
		RoundNumber++;

		system("pause");
		system("cls");
	}

	infile.close();
	return 0;
}


