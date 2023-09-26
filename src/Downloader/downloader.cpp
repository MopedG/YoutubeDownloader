#include "downloader.h"
#include <filesystem>
#include <ShlObj.h>

Downloader::Downloader()
{

}

bool Downloader::downloadVideo(const QString &url)
{
    const std::filesystem::path downloadPath = getDownloadsFolderPath();
    const std::filesystem::path downloadScript = std::filesystem::current_path().parent_path().parent_path() / "src" /"PyTube" / "DownloadVideo.py";
    const std::string downloadCommand = "python " + downloadScript.string() + " " + downloadPath.string() + " " + url.toStdString();
    std::system(downloadCommand.c_str());

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
