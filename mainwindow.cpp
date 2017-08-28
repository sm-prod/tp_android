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

    //localAdapters = QBluetoothLocalDevice::allDevices();

}

MainWindow::~MainWindow()
{
    delete ui;
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
