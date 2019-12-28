/*!
 * \file
 * \brief Файл конфигурации.
 * \author Стоянов Руслан
    \date 2019
*/
#ifndef CONFIG_H
#define CONFIG_H

#include <QString>

// Настройки конфигурации
namespace Config
{
	static const QString nameApplication = "Железнодорожный вокзал";
    /*!
     * \brief Название приложения.*/
    static const QString fileUsers = "users.bin";
    /*!
     * \brief Двоичный файл для хранения данных о пользователях.*/
	static const QString fileTrains = "trains.bin";
    /*!
     * \brief Двоичный файл для хранения данных о поездах.*/
}

#endif // CONFIG_H
