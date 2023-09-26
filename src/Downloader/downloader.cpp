#include "downloader.h"
#include <filesystem>
#include <ShlObj.h>
#include <thread>

Downloader::Downloader()
{

}

void Downloader::runDownloadScript(const std::string downloadCommand)
{
    std::system(downloadCommand.c_str());
}

bool Downloader::downloadVideo(const QString &url)
{
    const std::filesystem::path downloadPath = getDownloadsFolderPath();
    const std::filesystem::path downloadScript = std::filesystem::current_path().parent_path().parent_path() / "src" /"PyTube" / "DownloadVideo.py";
    const std::string downloadCommand = "python " + downloadScript.string() + " " + downloadPath.string() + " " + url.toStdString();
    std::thread backgroundThread([this, downloadCommand]() {
        runDownloadScript(downloadCommand);
        emit downloadFinished();
    });
    backgroundThread.detach();


    return true; //TODO Error Handling
}

std::filesystem::path Downloader::getDownloadsFolderPath() {
    PWSTR path;
    if (SHGetKnownFolderPath(FOLDERID_Downloads, 0, NULL, &path) == S_OK) {
        std::wstring downloadsPath = path;
        CoTaskMemFree(path);
        return downloadsPath;
    } else {
        throw std::runtime_error("Failed to get the Downloads folder path.");
    }
}
