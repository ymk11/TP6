#include <QApplication>
#include <QMessageBox>
#include "roi.hpp"
#include "kingException.hpp"
#include "echiquier.hpp"
#include <iostream>
#include <QSize>



void displayErrorBox() {
	//example for exercise 2
	try
	{
		chess::Roi r1(chess::Couleur::Blanc);
		chess::Roi r2(chess::Couleur::Blanc);
		chess::Roi r3(chess::Couleur::Blanc);



	}
	catch (const chess::KingException& e)
	{
		QMessageBox::critical(nullptr, "Error", e.what());

	}
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ui::Echiquier echiquier;
	echiquier.show();
	
	

	return a.exec();
}
