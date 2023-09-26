#pragma once
#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Downloader;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_downloadButton_clicked();

private:
    Ui::MainWindow *ui;

    std::unique_ptr<Downloader> downloader;
};
