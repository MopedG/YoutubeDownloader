#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Downloader/downloader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    downloader = std::make_unique<Downloader>();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_downloadButton_clicked()
{
    const std::string url = ui->downloadLink->text().toStdString();
    downloader->downloadVideo(QString::fromStdString(url));
}

