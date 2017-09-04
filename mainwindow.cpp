#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QByteArray>
#include <QIODevice>
#include <QtBluetooth/QtBluetooth>
#include <QtBluetooth/QBluetoothDeviceInfo>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothLocalDevice>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->comboBox->hide();
    connect(agent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
            agent->start();
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketRead()));
    //localAdapters = QBluetoothLocalDevice::allDevices();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::socketRead()
{
    QByteArray data;
    QApplication::processEvents();
    data.append(socket->readAll());
    writeData(data);
}

void MainWindow::on_find_clicked()
{
    ui->comboBox->show();
    ui->comboBox->clear();
    agent->stop();
    agent->start();
}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    //ui->comboBox->addItem(device.address().toString());
    ui->comboBox->addItem(device.name());
    BT_FoundDevices.append(device);
    //QString label = QString("%1 %2").arg(device.name().arg(device.address().toString()));
    //ui->comboBox->addItem(label, Qt::MatchExactly);
}

/*
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    string =item->text();

    ui->listWidget->addItem(string);


}
*/

void MainWindow::on_connect_clicked()
{
    int nIndex = ui->comboBox->currentIndex();

    if (nIndex != -1)
    {
        if (nIndex < BT_FoundDevices.count() && BT_FoundDevices.count() > 0)
        {
            socket->connectToService(QBluetoothAddress(BT_FoundDevices.at(nIndex).address()), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);
            //BT_LocalDevice->requestPairing(,QBluetoothLocalDevice::Paired);
        }
    }
    //QString adress =
    //static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    //socket->connectToService(QBluetoothAddress(ui->comboBox->currentText()), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);

}

void MainWindow::on_disconnect_clicked()
{
    socket->disconnectFromService();
}

void MainWindow::on_set_type_A_clicked()
{
    socket.write("*set_t_A$");
    //ui->label->setToolTip("Установлен тип A");
}

void MainWindow::writeData(QByteArray data)
{
    QTextCursor cur = ui->textBrowser->textCursor();
    cur.movePosition(QTextCursor::End);
    ui->textBrowser->setTextCursor(cur);
    ui->textBrowser->insertPlainText(data);
}


void MainWindow::on_set_type_B_clicked()
{
    socket.write("*set_t_B$");
}

void MainWindow::on_set_type_T_clicked()
{
    socket.write("*set_t_T$");
}
