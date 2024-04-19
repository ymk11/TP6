#include <QApplication>
#include <QMessageBox>
#include "roi.hpp"
#include "kingException.hpp"
#include "echiquier.hpp"
#include <iostream>


void displayErrorBox(QString erreur) {
	QMessageBox::critical(nullptr, "Error", erreur);
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	try
	{
		chess::Roi r1(chess::Couleur::Blanc) ;
		chess::Roi r2(chess::Couleur::Blanc);
		chess::Roi r3(chess::Couleur::Blanc);



	}
	catch (const chess::KingException& e)
	{
		displayErrorBox(e.what());

	}
   
    return a.exec();
}
