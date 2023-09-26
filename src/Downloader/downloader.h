#pragma once
#include <QString>

class Downloader
{
public:
    Downloader();

    bool downloadVideo(const QString &url);
};
