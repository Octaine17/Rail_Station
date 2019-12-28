#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
class User;
/*!
 * \brief Класс главного окна программы.
 *
 * Отвечает за реализацию функций, специфичных для данной конкретной
 * программы. За реализацию функций, общих для всех программ с графическим
 * интерфейсом, отвечает класс QMainWindow из библиотеки Qt.
 *
 * MainWindow является производным классом от QMainWindow и может добавлять свои
 * атрибуты и методы к тем, которые уже есть в QMainWindow.
 */
class MainWidget : public QWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = nullptr);
	~MainWidget();

private:
	QWidget *m_currentWidget;	// текущий отображаемый виджет
								// (авторизация, регистрация, окно с таблицами)

private slots:
    //! Окно авторизации
	void slotOpenAuthorization();
    //! Окно регистрации
    void slotOpenRegistration();
    //! Окно рабочего окна
	void slotOpenWorkWidget(User*);
};
#endif // MAINWIDGET_H
