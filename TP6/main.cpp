#include <QApplication>
#include <QMessageBox>
#include "king.hpp"
#include "kingException.hpp"
#include "board.hpp"
#include <iostream>
#include <QSize>



void displayErrorBox() {
	// pour l'exercise 2 du Tp6
	try
	{
		chess::King r1(chess::Color::White);
		chess::King r2(chess::Color::White);
		chess::King r3(chess::Color::White);



	}
	catch (const chess::KingException& e)
	{
		QMessageBox::critical(nullptr, "Error", e.what());

	}
}



/*Il y a des problème de compilation non résolue de la librairie gtest dans test.cpp
* Vous pourrez mettre test.cpp en commentaire pour tester le fonctionnement du jeux.
* 
* Une fois la fenêtre de jeux ouverte, le button start game commence une partie en fonction
* du board sélectionné.  le boutton end game permet d'arrêter une partie en cours pour en commencer
* une nouvelle.  Le déplacement des pièces est similaire à celui de chess.com
*/


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ui::Board echiquier;
	echiquier.show();
	
	

	return a.exec();
}
