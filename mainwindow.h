#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QBluetoothDeviceInfo>
#include <QSettings>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_find_clicked();

    void deviceDiscovered(const QBluetoothDeviceInfo &device);

    //void on_listWidget_itemClicked(QListWidgetItem *item);

   // void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_connect_clicked();

    void on_disconnect_clicked();

    void on_set_type_A_clicked();

    void on_set_type_B_clicked();

    void on_set_type_T_clicked();

    void on_set_type_N_clicked();

    void on_set_type_J_clicked();

    void on_set_type_K_clicked();

    void on_set_type_R_clicked();

    void on_set_type_S_clicked();

    void on_disp_ADCW_clicked();

    void on_disp_T_cold_spot_clicked();

    void on_disp_U_t_clicked();

    void on_disp_U_clicked();

    void on_send_String_clicked();

    void socketRead();

    void writeData(QByteArray data);

    void writeInfo(QByteArray info);

    void start_set();

private:
    Ui::MainWindow *ui;
    QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
    QBluetoothSocket *socket;
    QList <QBluetoothDeviceInfo> BT_FoundDevices;
    QSettings *settings;// = new QSettings("set.ini",QSettings::IniFormat);

    //QString string;
};

#endif // MAINWINDOW_H
