#pragma once
#include "qwidget.h"
#include <QString>
#include <filesystem>

class Downloader : public QWidget
{
    Q_OBJECT
public:
    Downloader();

    bool downloadVideo(const QString &url);

    void runDownloadScript(const std::string downloadCommand);

signals:
    void downloadFinished();

private:
    std::filesystem::path getDownloadsFolderPath();
};
