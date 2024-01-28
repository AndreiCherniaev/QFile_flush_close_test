#include <QCoreApplication>
#include <QFile>

void writer(){
    QFile csvDefaults;
    csvDefaults.setFileName("test.bin");
    if(!csvDefaults.open(QIODeviceBase::ReadWrite | QIODeviceBase::Truncate)){
        qWarning() << "err Can't open file" << csvDefaults.fileName();
    }
    const quint8 myData[] = { 1,2,3 };
    csvDefaults.write((const char*)myData, sizeof(myData));
    csvDefaults.flush();

//    //Why to get true arr size I need close, open?
//    csvDefaults.close();
//    csvDefaults.open(QIODeviceBase::ReadWrite);

    const QByteArray arr(csvDefaults.readAll());
    qDebug() << "arr size=" << arr.size();
    csvDefaults.close();
}

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    writer();
    QMetaObject::invokeMethod(&a, "quit", Qt::QueuedConnection);
    return a.exec();
}
