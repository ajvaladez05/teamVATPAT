#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include "arduinoconnectionlib.h"
#include <QTextStream>
void Write (QString Filename){
    QFile mfile(Filename);

    if(!mfile.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Could not open file for writting.";
        return;
    }

    QTextStream out(&mfile);
    out << "Hello World.";
    mfile.flush();
    mfile.close();
}


void Read (QString Filename){
    QFile mfile(Filename);

    if(!mfile.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Could not open file for reading.";
        return;
    }

    QTextStream in(&mfile);
    QString mText = in.readAll();
    qDebug() << mText;
    mfile.flush();
    mfile.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString testLogfile = "C:\\Users\\Anthony\\Desktop\\School\\SeniorDesign\\TestLogLocation\\mfile.txt";
    Write(testLogfile);
    Read(testLogfile);

    MainWindow w;
    w.show();

    return a.exec();
}


