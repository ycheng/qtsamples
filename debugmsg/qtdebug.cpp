
#include <QtCore/qdebug.h>
#include <QFile>
#include <QTextStream>

void
myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	QFile qf("/tmp/debug");
	qf.open(QIODevice::WriteOnly | QIODevice::Append);
	
	QTextStream qs( &qf );

	qs << msg << "\n";
}

int
main(int argc, char **argv) {

	qInstallMessageHandler(myMessageOutput);

	qDebug() << "Debug message";

	return 0;
}
