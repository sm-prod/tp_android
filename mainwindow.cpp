#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QByteArray>
#include <QIODevice>
#include <QtBluetooth/QtBluetooth>
#include <QtBluetooth/QBluetoothDeviceInfo>
#include <QtBluetooth/QBluetoothDeviceDiscoveryAgent>
#include <QtBluetooth/QBluetoothLocalDevice>
#include <QSettings>
#include <QChar>

uint8_t adc_i,t_i,t_u_i,adc_u_i;
bool mode0,mode1,mode2,mode3;
QChar type;


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
    settings = new QSettings("set",QSettings::NativeFormat);
    //localAdapters = QBluetoothLocalDevice::allDevices();
    /*
    settings->setValue("SET/TYPE", "A");
    settings->setValue("MODE/MODE_ADCW", "0");
    settings->setValue("MODE/MODE_t", "0");
    settings->setValue("MODE/MODE_t_u", "0");
    settings->setValue("MODE/MODE_U", "0");
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_set()
{
    type=settings->value("SET/TYPE","A").toChar();
    mode0=settings->value("SET/MODE_ADCW",0).toBool();
    mode1=settings->value("SET/MODE_t",0).toBool();
    mode2=settings->value("MODE/MODE_t_u",0).toBool();
    mode3=settings->value("MODE/MODE_U",0).toBool();
    switch (type.unicode())
    {
    case 'A':
    {
        socket->write("*set_t_A$");
        break;
    }
    case 'B':
    {
        socket->write("*set_t_B$");
        break;
    }
    case 'J':
    {
        socket->write("*set_t_J$");
        break;
    }
    case 'K':
    {
        socket->write("*set_t_K$");
        break;
    }
    case 'N':
    {
        socket->write("*set_t_N$");
        break;
    }
    case 'R':
    {
        socket->write("*set_t_R$");
        break;
    }
    case 'S':
    {
        socket->write("*set_t_S$");
        break;
    }
    case 'T':
    {
        socket->write("*set_t_T$");
        break;
    }
    default:
        break;
    }
    switch (mode0)
    {
    case 0:
    {
        socket->write("*ADC_OFF$");
        adc_i=0;
        ui->disp_ADCW->setText("Отображение\nADCW\nВыключено");
        break;
    }
    case 1:
    {
        socket->write("*ADC_ON$");
        adc_i=1;
        ui->disp_ADCW->setText("Отображение\nADCW\nВключено");
        break;
    }
    default:
        break;
    }
    switch (mode1)
    {
    case 0:
    {
        socket->write("*t_i_OFF$");
        t_i=0;
        ui->disp_T_cold_spot->setText("Отображение\nt°C ХС\nВыключено");
        break;
    }
    case 1:
    {
        socket->write("*t_i_ON$");
        t_i=1;
        ui->disp_T_cold_spot->setText("Отображение\nt°C ХС\nВключено");
        break;
    }
    default:
        break;
    }
    switch (mode2)
    {
    case 0:
    {
        socket->write("*t_u_i_OFF$");
        t_u_i=0;
        ui->disp_U_t->setText("Отображение\nU(t°C) ХС\nВыключено");
        break;
    }
    case 1:
    {
        socket->write("*t_u_i_ON$");
        t_u_i=1;
        ui->disp_U_t->setText("Отображение\nU(t°C) ХС\nВключено");
        break;
    }
    default:
        break;
    }
    switch (mode3)
    {
    case 0:
    {
        socket->write("*u_i_OFF$");
        adc_u_i=0;
        ui->disp_U->setText("Отображение\nU\nВыключено");
        break;
    }
    case 1:
    {
        socket->write("*u_i_ON$");
        adc_u_i=1;
        ui->disp_U->setText("Отображение\nU\nВключено");
        break;
    }
    default:
        break;
    }
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
    start_set();
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
    socket->write("*set_t_A$");
    //ui->label->setToolTip("Установлен тип A");
    settings->setValue("SET/TYPE", "A");
    settings->sync();
    writeInfo("Установлен тип A");
}

void MainWindow::writeData(QByteArray data)
{
    QTextCursor cur = ui->textBrowser->textCursor();
    cur.movePosition(QTextCursor::End);
    ui->textBrowser->setTextCursor(cur);
    ui->textBrowser->insertPlainText(data);
}

void MainWindow::writeInfo(QByteArray info)
{
    QTextCursor cur = ui->infoBrowser->textCursor();
    cur.movePosition(QTextCursor::End);
    ui->infoBrowser->setTextCursor(cur);
    ui->infoBrowser->insertPlainText(info);
}

void MainWindow::on_set_type_B_clicked()
{
    socket->write("*set_t_B$");
    settings->setValue("SET/TYPE", "B");
    settings->sync();
    writeInfo("Установлен тип B");
}

void MainWindow::on_set_type_T_clicked()
{
    socket->write("*set_t_T$");
    settings->setValue("SET/TYPE", "T");
    settings->sync();
    writeInfo("Установлен тип T");
}

void MainWindow::on_set_type_N_clicked()
{
    socket->write("*set_t_N$");
    settings->setValue("SET/TYPE", "N");
    settings->sync();
    writeInfo("Установлен тип N");
}

void MainWindow::on_set_type_J_clicked()
{
    socket->write("*set_t_J$");
    settings->setValue("SET/TYPE", "J");
    settings->sync();
    writeInfo("Установлен тип J");
}

void MainWindow::on_set_type_K_clicked()
{
    socket->write("*set_t_K$");
    settings->setValue("SET/TYPE", "K");
    settings->sync();
    writeInfo("Установлен тип K");
}

void MainWindow::on_set_type_R_clicked()
{
    socket->write("*set_t_R$");
    settings->setValue("SET/TYPE", "R");
    settings->sync();
    writeInfo("Установлен тип R");
}

void MainWindow::on_set_type_S_clicked()
{
    socket->write("*set_t_S$");
    settings->setValue("SET/TYPE", "S");
    settings->sync();
    writeInfo("Установлен тип S");
}

void MainWindow::on_disp_ADCW_clicked()
{
    switch (adc_i)
    {
    case 0:
    {
        socket->write("*ADC_ON$");
        adc_i=1;
        settings->setValue("MODE/MODE_ADCW", 1);
        settings->sync();
        ui->disp_ADCW->setText("Отображение ADCW\nВключено");
        //writeInfo("Отображение ADCW\nВключено");
        break;
    }
    case 1:
    {
        socket->write("*ADC_OFF$");
        adc_i=0;
        settings->setValue("MODE/MODE_ADCW", 0);
        settings->sync();
        ui->disp_ADCW->setText("Отображение ADCW\nВыключено");
        //writeInfo("Отображение ADCW\nВыключено");
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_disp_T_cold_spot_clicked()
{
    switch (t_i)
    {
    case 0:
    {
        socket->write("*t_i_ON$");
        t_i=1;
        settings->setValue("MODE/MODE_t", 1);
        settings->sync();
        ui->disp_T_cold_spot->setText("Отображение\nt°C ХС\nВключено");
        //writeInfo("Отображение T холодного спая\nВключено");
        break;
    }
    case 1:
    {
        socket->write("*t_i_OFF$");
        t_i=0;
        settings->setValue("MODE/MODE_t", 0);
        settings->sync();
        ui->disp_T_cold_spot->setText("Отображение\nt°C ХС\nВыключено");
        //writeInfo("Отображение T холодного спая\nВыключено");
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_disp_U_t_clicked()
{
    switch (t_u_i)
    {
    case 0:
    {
        socket->write("*t_u_i_ON$");
        t_u_i=1;
        settings->setValue("MODE/MODE_t_u", 1);
        settings->sync();
        ui->disp_U_t->setText("Отображение\nU(t°C) ХС\nВключено");
        //writeInfo();
        break;
    }
    case 1:
    {
        socket->write("*t_u_i_OFF$");
        t_u_i=0;
        settings->setValue("MODE/MODE_t_u", 0);
        settings->sync();
        ui->disp_U_t->setText("Отображение\nU(t°C) ХС\nВыключено");
        //writeInfo("Отображение экв U T холодного спая\nВыключено");
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_disp_U_clicked()
{
    switch (adc_u_i)
    {
    case 0:
    {
        socket->write("*u_i_ON$");
        adc_u_i=1;
        settings->setValue("MODE/MODE_U", 1);
        settings->sync();
        ui->disp_U->setText("Отображение\nU\nВключено");
        //writeInfo("Отображение экв U термопары\nВключено");
        break;
    }
    case 1:
    {
        socket->write("*u_i_OFF$");
        adc_u_i=0;
        settings->setValue("MODE/MODE_U", 0);
        settings->sync();
        ui->disp_U->setText("Отображение\nU\nВыключено");
        //writeInfo("Отображение экв U термопары\nВыключено");
        break;
    }
    default:
        break;
    }
}

void MainWindow::on_send_String_clicked()
{
    QString input = ui->lineEdit->text();
    //char send[16];
    socket->write(qPrintable(input));
}
