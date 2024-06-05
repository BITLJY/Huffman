#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolTip>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PB_compress_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Select File to Import", QDir::homePath(), "Text Files (*.txt *.log)");
    if (!filename.isEmpty()) {
        if (importDataFromFile(filename)) {
            // 导入成功
            QMessageBox::information(this, "导入成功", "Data imported successfully from file: " + filename);
            // 刷新界面显示
        } else {
            // 导入失败
            QMessageBox::warning(this, "导入失败", "Failed to import data from file: " + filename);
        }
    }
}
bool MainWindow::importDataFromFile(const QString &filename) {
       QFile file(filename);
       if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug() << "Failed to open file for reading:" << filename;
           return false;
       }

       QTextStream in(&file);
       QStringList lines;
       while (!in.atEnd()) {
           QString line = in.readLine();
           lines.append(line);
       }

       // 将文件中的数据储存在了lines中
      //可以在这里对字符进行处理
     qDebug() <<lines;
       file.close();
       return true;
   }

