// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {

	// cree un objet de type map pour stocker la table de correspondance .
	// map fonctionne en clef , valeur ( char = caractère = A,B,C,D etc... clef et string = le morse = valeur )
	map<char, string> morseTable;

	// ouvrir le fichier" code_morses.txt"
	ifstream file("morse_codes.txt");

	if (file.is_open()) {
		string line; 
		// on declare une variable line , qui va traiter chaque ligne du fichier 

		// Lire le fichier ligne par ligne
		// getline lit une ligne du fichier et la stock dans la variable line 
		while (getline(file, line)) {
			if (line.size() >= 3) {
				// chaque ligne doit être >= à 3 car char : string  ou encore A : morse
				char charactere = line[0];
				// On extrait les caractère a partir de la ligne 0 et on les stock dans la variable charactere
				string morseCode = line.substr(2);
				// On extrait le code morse à partir de la position  2 de la ligne et nous le stockons dans la variable morseCode 

				// on ajoute la correspondance au dictionnaire 
				morseTable[charactere] = morseCode;
				// a chaque charactere de morseTable on un morseCode
			}
		}

		//fermer le fichier après la lecture
		file.close();
	}
	else {
		cerr << "Erreur lors de l'ouverture du fichier code_morses.txt." << endl;
	}
	// Maintenant, morseTable contient la table de correspondance
	// du code Morse chargée depuis le fichier.
	// Maintenant on peut utiliser morseTable pour traduire du texte en morse.
	
	cout << " Entrez le texte que vous souhaitez traduire en morse :";
	string texte;
	getline(cin, texte);
    // getline est une fonction de la bibliothèque C++ utilisée pour lire une ligne de texte depuis un flux d'entrée (ici cin qui représente lentrée standard par le clavier dans la console )

	for (int i = 0; i < texte.length(); i++) {
		char charactere = texte[i];
		string morseChar = "";		
		if (morseTable.find(charactere) != morseTable.end()) {
			// Si le caractère existe dans la table, ajouter son code morse à la chaine
			morseChar += morseTable[charactere] + "";
		}
		else {
			morseChar += "";
		}
		// Afficher le texte en code morse
		cout << "Texte en code Morse : " << morseChar << endl;
	}
	
	return 0;

}
















 
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.









