#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <iostream>
#include <sstream>

#include "player.h"

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


void MainWindow::on_pushButton_5_clicked()
{
    std::ostringstream out;
    player aPlayer;
    savedPlayer = aPlayer;
    out<<savedPlayer;
    ui->textBrowser->setText(QString::fromStdString(out.str()));
}

void MainWindow::on_pushButton_clicked()
{
    savedPlayer.movePlayerUp();
    std::ostringstream out;
    out<<savedPlayer;
    ui->textBrowser->setText(QString::fromStdString(out.str()));
}

void MainWindow::on_pushButton_3_clicked()
{
    savedPlayer.movePlayerRight();
    std::ostringstream out;
    out<<savedPlayer;
    ui->textBrowser->setText(QString::fromStdString(out.str()));
}

void MainWindow::on_pushButton_4_clicked()
{
    savedPlayer.movePlayerDown();
    std::ostringstream out;
    if(savedPlayer.getPlayerRow()==savedPlayer.totalRows)
    {
        out<<"you win!";
    }
    else
    {
        out<<savedPlayer;
    }
    ui->textBrowser->setText(QString::fromStdString(out.str()));
}

void MainWindow::on_pushButton_2_clicked()
{
    savedPlayer.movePlayerLeft();
    std::ostringstream out;
    out<<savedPlayer;
    ui->textBrowser->setText(QString::fromStdString(out.str()));
}
