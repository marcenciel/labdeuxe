/* En-tête de programme
   ====================
Programme:		calculNoteFinaleMoy.cpp
Acteur:			Inscrire votre nom
Date de création:	25/01/21
But du programme:	Lire le nom, le prénom et les 5 notes de plusieurs étudiants dans 
			etudiant.txt, qui calculer la note finale pour chacun, l'afficher à 
			l’écran avec son nom, calculer aussi la moyenne du groupe et 
			l'afficher au bas de l’écran*/

/* Directive au pré-processeur
   =========================== */
#include <iostream>
#include <fstream>		//librairie pour la manipulation de fichiers
#include <iomanip>		//librairie pour l'affichage (setw, left)		
using namespace std;

/* Programme principal
   =================== */
void main()
{
	char  	entete[50],		//Entete du fichier
		nom[30],			//Nom de l'étudiant
		prenom[30];		//Prénom de l'étudiant

	float 	note,			//Note lue dans le fichier
		noteFinale,		//Total des 5 notes d'un étudiant
		total = 0,		//Total des notes du groupe
		moyenne;			//Moyenne du groupe

	int   nbEtu = 0;			//Nombre d'étudiants

	//   Mes variables créées

	char meilleurEtu[30];
	int meilleurNote(0);
	char mNom[20];
	char mPrenom[20];
	
	//ifstream fichierNote("etudiant.txt", ios::in); 	//Notes en entrée
	ifstream fichierNote("etudiant.txt");

	if(!fichierNote.is_open())  	
	{
		cout << "Le fichier etudiants.txt est introuvable." << endl;
		system("pause");
		exit(0);
	}
	
	fichierNote.getline(entete, 50);  		

	if(fichierNote.peek() == EOF)      		//si le fichier est vide
	{
		cout << "Le fichier est vide." << endl;
		fichierNote.close();
		system("pause");
		exit(0);
	}	
	
	//affichage de l'entête dans la console
	cout << left << setw(26) << "Nom" << setw(20) << left << "Notes Finale" << endl
		 << "===================" << setw(19) << right << "============" << endl << endl;

	fichierNote >> nom >> prenom;

	while(fichierNote)		//tant que ce n'est pas la fin du fichier
	{
		noteFinale = 0;

		for (int i = 0; i < 5; i++)	//lecture des 5 notes
		{
			fichierNote >> note;
			noteFinale += note;
			if (meilleurNote < note) {
				meilleurNote = note;
				mPrenom[0] = prenom[0];
				mNom[0]= nom[0];
			}
		}
		noteFinale /= 5;

		cout << std::setprecision(0) << fixed << left << setw(13) << nom << setw(10) << prenom << right << setw(10) << noteFinale << setw(2) << right << " %";

		if (noteFinale < 60)		//affiche EC si échec
			cout << " EC";

		cout << endl;
		
		total += noteFinale;
		nbEtu++;

		fichierNote >> nom >> prenom;
	}
	moyenne = total / nbEtu;

	cout << std::setprecision(1) << endl << setw(20) << right << "Moyenne : " << setw(13) << moyenne << " %" << endl << endl;

	cout << meilleurNote;
	cout << mPrenom;
	cout << mNom;

	fichierNote.close();
	system("pause");
}