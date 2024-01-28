#include <QCoreApplication>
#include <QFile>

void writer(){
    QFile file;
    file.setFileName("test.bin");
    if(!file.open(QIODeviceBase::ReadWrite | QIODeviceBase::Truncate)){
        qWarning() << "err Can't open file" << file.fileName();
    }
    const quint8 myData[] = { 1,2,3 };
    file.write((const char*)myData, sizeof(myData));
    //instead of file.flush(); should be file.seek(0);
    file.seek(0);

//    //Why to get true arr size I need close, open?
//    csvDefaults.close();
//    csvDefaults.open(QIODeviceBase::ReadWrite);

    const QByteArray arr(file.readAll());
    qDebug() << "arr size=" << arr.size();
    file.close();
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    writer();
    QMetaObject::invokeMethod(&a, "quit", Qt::QueuedConnection);
    return a.exec();
}
