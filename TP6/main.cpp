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
		chess::King r1(chess::Couleur::White);
		chess::King r2(chess::Couleur::White);
		chess::King r3(chess::Couleur::White);



	}
	catch (const chess::KingException& e)
	{
		QMessageBox::critical(nullptr, "Error", e.what());

	}
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ui::Board echiquier;
	echiquier.show();
	
	

	return a.exec();
}
