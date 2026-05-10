#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


/*
class MainWindow : public QMainWindow
наследуется от QMainWindow.
Сначала должен создаться базовый класс.
*/
class MainWindow : public QMainWindow //Твоё окно — это QMainWindow.Qt почти весь построен на наследовании.
{
    Q_OBJECT
    /*
    Очень важная штука.
    Она включает:
    signals/slots
    meta-object system
    introspection.

    Без неё половина Qt работать не будет.
    */

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_textEdit_textChanged();

    void on_REZEimage_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui; //Это доступ к интерфейсу из .ui файла.
};
#endif // MAINWINDOW_H
