
#include <QDebug>
#include <QFile>
#include <QTextStream>


static QTextStream *qs = NULL;

void
myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	*qs << msg;
	*qs << "\n";
}

int
main(int argc, char **argv) {
	QFile qf("/tmp/debug");
	qf.open(QIODevice::WriteOnly | QIODevice::Append);
	qs = new QTextStream( &qf );

	qInstallMessageHandler(myMessageOutput);

	qDebug() << "Debug message";

	delete qs;
	return 0;
}
