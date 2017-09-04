#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QBluetoothDeviceInfo>


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

private:
    Ui::MainWindow *ui;
    QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
    QBluetoothSocket *socket;
    QList <QBluetoothDeviceInfo> BT_FoundDevices;

    //QString string;
};

#endif // MAINWINDOW_H
