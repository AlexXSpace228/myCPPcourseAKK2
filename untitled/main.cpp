#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

//Точка входа.
int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //Главный объект Qt-приложения.
    /*
    QApplication Управляет:
    окнами
    событиями
    мышью
    клавиатурой
    event loop.
    */
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "untitled_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w; //Создание окна.
    w.show(); //Показ окна.
    return a.exec(); //Запуск event loop.
    /*
    Вот тут программа начинает жить:
    обрабатывать клики
    кнопки
    ввод
    события.
    */
}
