#include <QTime>
#include <QDate>
#include <QFile>
#include <QSaveFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
        QFile time_file("/sys/devices/sop716/time");
        if(!time_file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug("Unable to open file for write. Check permissions");
        }
        QTextStream out(&time_file);
        out << QDate::currentDate().toString(Qt::ISODate) << " " << QTime::currentTime().toString(Qt::TextDate);
        time_file.close();
        qDebug("Synchronised Narwhal hands with system time");

}
