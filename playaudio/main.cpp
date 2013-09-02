
#include <QCoreApplication>
// #include <QTimer>
#include <QDebug>

#include <QtMultimedia/QMediaPlayer>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QMediaPlayer *player;

    if (argc != 2) {
        qDebug() << "usage: " << argv[0] << " audiofile";
        return 0;
    }

    player = new QMediaPlayer(0, 0);

    player->setMedia(QUrl::fromLocalFile(argv[1]));
    player->setVolume(50);
    // player->setPlaybackRate(1.2);
    player->play();

    QObject::connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),&app, SLOT(quit())); // as state change, quit app.
//  QTimer::singleShot(1000, &app, SLOT(quit())); //stop after 5 seconds

    return app.exec();
}
