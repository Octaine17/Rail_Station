#include "dialog_adduser.h"
#include "ui_dialog_adduser.h"

#include "config.h"
#include "user.h"

#include <QFile>
#include <QDataStream>


Dialog_AddUser::Dialog_AddUser(QWidget *parent) :
	QDialog(parent),
	mUi(new Ui::Dialog_AddUser)
{
	mUi->setupUi(this);
}

Dialog_AddUser::~Dialog_AddUser()
{
	delete mUi;
}

const User &Dialog_AddUser::getUser() const
{
	return m_user;
}

bool Dialog_AddUser::isLoginExists(const QString &login)
{
    QFile file(Config::fileUsers);
    // Если файл существует
    if (file.exists()) {
        // Если не удалось открыть файл...
        if (!file.open(QIODevice::ReadOnly)) {
            // Сообщаем об ошибке.
            mUi->labelError->setText("Ошибка: чтение файла невозможно!");
            return false;
        }
        // Создаем поток.
        QDataStream ist(&file);
        // Пока не конец файла
        while (!ist.atEnd()) {
            // Считываем данные.
            User buf_user;
            ist >> buf_user;
            // Проверяем.
            if (buf_user.login() == login)
                return true;
        }

        return false;
    }
    else
        return false;
}

void Dialog_AddUser::accept()
{
	// Получаем введенные данные
	const QString login = mUi->login->text();
	const QString password = mUi->password->text();
	// Преобразуем статус из QString в необходимый тип (Status)
	User::Status status = User::getListStatus().key(mUi->status->currentText());
    // Проверяем на корректность.
	if (login.isEmpty() || password.isEmpty()) {
		mUi->labelError->setText("Ошибка: заполните все поля!");
    }
    else if (login.size() < 3 || login.size() > 20) {
		mUi->labelError->setText("Ошибка: имя пользователя должено содержать от 3 до 20 символов!");
	}
    else if (isLoginExists(login)) {
        // Если во время выполнения метода произошла непредвиденная ошибка
        // (например, файл неудалось открыть), то сообщение об ошибке будет выведено в лейбл.
        // Если же ошибок не было, то лейбл останется пустым.
        if (mUi->labelError->text().isEmpty())
            mUi->labelError->setText("Ошибка: данное имя пользователя уже существует!");
    }
	else if (password.size() < 6 || password.size() > 15) {
		mUi->labelError->setText("Ошибка: пароль должен содержать от 6 до 15 символов!");
	}
    else { // Если всё ОК...
		m_user.setData(login, password, status);
        QDialog::accept();
	}
}
