/*!
    \brief Класс билета

  */

#ifndef TICKET_H
#define TICKET_H

#include <QString>
#include <QDate>
#include <QDataStream>
#include <QTextStream>

// Класс билета
class Ticket
{
public:
	Ticket();
	Ticket(int number, int numTrain, int numWagon, const QString &typeWagon, const QDate &date, int price);

    //!Установка и получение значений --- //
	void setData(int number, int numTrain, int numWagon, const QString &typeWagon, const QDate &date, int price);

	int number() const;
    //!Установка номера
	void setNumber(int number);

	QString id() const;
    //!Установка идентификатора
	void setId(const QString &id);

	int numberTrain() const;
    //!Установка номера поезда
	void setNumberTrain(int numberTrain);

	int numberWagon() const;
    ///!Установка номера вагона
	void setNumberWagon(int numberWagon);

	QString typeWagon() const;
    //!Установка типа вагона
	void setTypeWagon(const QString &typeWagon);

	QDate date() const;
    //!Установка даты
	void setDate(const QDate &date);

	int price() const;
    //!Установка цены
	void setPrice(int price);

	QDateTime dateTimeBuy() const;
    //!Установка даты покупки билета
	void setDateTimeBuy(const QDateTime &dateTimeBuy);
	// -------------------------------------- //

private:
	int m_number;				// Номер билета
	QString m_id;				// Идентификационный номер билета
	QDateTime m_dateTimeBuy;	// Дата и время покупки билета
	int m_numberTrain;			// Номер поезда
	int m_numberWagon;			// Номер вагона
	QString m_typeWagon;		// Тип вагона
	QDate m_date;				// Дата отпарвления
	int m_price;				// Цена
};

// Запись в файл
inline QDataStream &operator<< (QDataStream &ost, const Ticket &ticket)
{
	ost << ticket.number() << ticket.numberTrain() << ticket.numberWagon() << ticket.typeWagon()
		<< ticket.date() << ticket.price() << ticket.id() << ticket.dateTimeBuy();
	return ost;
}

// Чтение из файла
inline QDataStream &operator>> (QDataStream &ist, Ticket &ticket)
{
	int number, numberTrain, numberWagon, price;
	QString typeWagon, id;
	QDate date;
	QDateTime dateTime;
	ist >> number >> numberTrain >> numberWagon >> typeWagon >> date >> price >> id >> dateTime;
	ticket.setData(number, numberTrain, numberWagon, typeWagon, date, price);
	ticket.setId(id);
	ticket.setDateTimeBuy(dateTime);

	return ist;
}

inline QTextStream &operator<< (QTextStream &ost, const Ticket &ticket)
{
	ost << QString("ID: ") << ticket.id()
        << endl << QString("Дата и время покупки: ") << ticket.dateTimeBuy().toString("dd.MM.yyyy hh:mm") << "\n";
	return ost;
}

// Перегрузка оператора '<' (необходим для сортировки билетов) [см. Dialog_BuyTicket.cpp]
inline bool operator< (const Ticket &ticket1, const Ticket &ticket2)
{
	return ticket1.number() < ticket2.number() ? true : false;
}

#endif // TICKET_H
