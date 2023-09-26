#include "downloader.h"
#include <filesystem>

Downloader::Downloader()
{

}

bool Downloader::downloadVideo(const QString &url)
{
    const std::filesystem::path downloadPath = std::filesystem::current_path().parent_path().parent_path() / "src";
    const std::filesystem::path downloadScript = std::filesystem::current_path().parent_path().parent_path() / "src" /"PyTube" / "DownloadVideo.py";
    const std::string downloadCommand = "python " + downloadScript.string() + " " + downloadPath.string() + " " + url.toStdString();
    system(downloadCommand.c_str());

    return true; //TODO Error Handling
}
