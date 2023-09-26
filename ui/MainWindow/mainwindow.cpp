#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Downloader/downloader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    styleSheet = ui->downloadProgress->styleSheet();
    downloader = std::make_unique<Downloader>();
    ui->stackedWidgetDownloader->setCurrentIndex(0);
    MainWindow::connect(downloader.get(), &Downloader::downloadFinished, this, &MainWindow::on_downloadFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_downloadButton_clicked()
{
    const QString testUrl = "https://youtu.be/SavZRISmn-Q?si=vISsn0bwGkM3dhal";
    const std::string url = ui->downloadLink->text().toStdString();
    showDownloadStarted();
    bool downloadSuccess = downloader->downloadVideo(testUrl/*QString::fromStdString(url)*/);
}

void MainWindow::showSuccess()
{
    ui->downloadProgress->setStyleSheet("background-color: #6bc95b");
    ui->stackedWidgetDownloader->setCurrentIndex(2);

}

void MainWindow::showDownloadStarted()
{
    ui->downloadProgress->setStyleSheet("background-color: #de9b14");
    ui->stackedWidgetDownloader->setCurrentIndex(1);
}


void MainWindow::resetView()
{
    ui->downloadProgress->setStyleSheet(styleSheet);
    ui->stackedWidgetDownloader->setCurrentIndex(0);
}

void MainWindow::on_openVideoButton_clicked()
{
    resetView();
}

void MainWindow::on_downloadFinished()
{
    showSuccess();
}

