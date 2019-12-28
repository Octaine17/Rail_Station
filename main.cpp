/*!
 * \file
 * \brief Файл главной функции.
 * \author Стоянов Руслан
 * \date 2019
 */
#include "mainwidget.h"

#include <QApplication>
/*!
 * \brief main
 * \param argc количество параметров командной строки
 * \param argv параметры командной строки
 * \return код результата
 *
 * Главная функция программы
 */
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWidget w;
    w.resize(400, 400);
	w.show();
	return a.exec();
}
