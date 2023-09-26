#pragma once
#include <QString>
#include <filesystem>

class Downloader
{
public:
    Downloader();

    bool downloadVideo(const QString &url);

private:
    std::filesystem::path getDownloadsFolderPath();
};
