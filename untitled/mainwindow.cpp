#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
//Логика окна.

//Важная мысль - Qt — это: Событие → Signal → Slot → Твой код
MainWindow::MainWindow(QWidget *parent) //Это конструктор объекта MainWindow.
    /*
    QWidget *parent
    Указатель на родительский объект.
    В Qt почти все объекты образуют дерево
    Window
     ├── Button
     ├── Label
     └── TextEdit
    Родитель:
    владеет дочерними объектами
    удаляет их автоматически.
    */
    : QMainWindow(parent) // Это список инициализации конструктора.
    , ui(new Ui::MainWindow) //Создание объекта интерфейса. new - Создаёт объект в heap-памяти.
{
    ui->setupUi(this); //создаёт кнопки: labels, layouts, подключает всё к окну. Без этого интерфейс не появится.
    /*Qt:
    создаёт кнопки labels layouts из .ui файла.
    подключает всё к окну.
    Без этого интерфейс не появится.
    */
}

//this - это указатель на текущее окно MainWindow!!!

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,
                             "Сообщение",
                             "Кнопка нажата");
    /*
    Когда кнопку нажимают:
    Qt отправляет signal:
    clicked()   Qt автоматически вызывает: on_pushButton_clicked()
    */
}

void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();//Получаем текст
    ui->label->setText(text); //Кладём в label
    /*
    Если нужен std::string
    Qt использует QString.

    Конвертация:
    std::string s = text.toStdString();
    */
}

/*
После генерации .ui файла Qt создаёт скрытый класс примерно такого вида:
class Ui_MainWindow
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *window);
};
*/
//картинка
void MainWindow::on_REZEimage_linkActivated(const QString &link)
{

}

