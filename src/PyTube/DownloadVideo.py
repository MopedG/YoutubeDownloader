from pytube import YouTube
import sys

def downloadVideo(downloadPath, youtubeLink):
    try:
        video = YouTube(youtubeLink)
        stream = video.streams.get_highest_resolution()
        stream.download(downloadPath)
        print("woihfwiuhf")
    except Exception as e:
        print("An error has occured")


downloadVideo(sys.argv[1], sys.argv[2])
