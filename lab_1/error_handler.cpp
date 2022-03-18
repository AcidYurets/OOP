#include "error_handler.h"
#include "QMessageBox"
#include <QObject>

void error_message(errors err)
{
    if (err == FILE_NOT_FOUND)
    {
        QMessageBox::critical(NULL, "ERROR", "Файл не найден");
    }
    else if (err == FILE_FORMAT_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Некорректный формат файла");
    }
    else if (err == FILE_CONTENT_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Некорректное содержимое файла");
    }
    else if (err == PTR_ALL_ERR)
    {
        QMessageBox::critical(NULL, "ERROR", "Ошибка выделения памяти");
    }
    else if (err == NO_DOTS)
    {
        QMessageBox::critical(NULL, "ERROR", "Файл не выбран");
    }
    else if (err == UNKNOWN_COMMAND)
    {
        QMessageBox::critical(NULL, "ERROR", "Неизвестная команда");
    }
    else
    {
        QMessageBox::critical(NULL, "ERROR", "Неизвестная ошибка");
    }
}
