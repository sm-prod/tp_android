/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_3;
    QPushButton *disp_U_t;
    QPushButton *disp_T_cold_spot;
    QPushButton *set_type_S;
    QLabel *label;
    QPushButton *disp_U;
    QLabel *label_2;
    QPushButton *disp_ADCW;
    QPushButton *set_type_A;
    QPushButton *set_type_K;
    QPushButton *set_type_R;
    QPushButton *set_type_T;
    QPushButton *set_type_B;
    QPushButton *set_type_J;
    QPushButton *set_type_N;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout_2;
    QPushButton *find;
    QComboBox *comboBox;
    QPushButton *disconnect;
    QPushButton *connect;
    QTextBrowser *infoBrowser;
    QTextBrowser *textBrowser;
    QPushButton *send_String;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(479, 609);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        disp_U_t = new QPushButton(centralWidget);
        disp_U_t->setObjectName(QStringLiteral("disp_U_t"));
        QFont font;
        font.setPointSize(10);
        disp_U_t->setFont(font);

        gridLayout_3->addWidget(disp_U_t, 8, 0, 1, 1);

        disp_T_cold_spot = new QPushButton(centralWidget);
        disp_T_cold_spot->setObjectName(QStringLiteral("disp_T_cold_spot"));
        disp_T_cold_spot->setFont(font);

        gridLayout_3->addWidget(disp_T_cold_spot, 6, 0, 1, 1);

        set_type_S = new QPushButton(centralWidget);
        set_type_S->setObjectName(QStringLiteral("set_type_S"));

        gridLayout_3->addWidget(set_type_S, 12, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        disp_U = new QPushButton(centralWidget);
        disp_U->setObjectName(QStringLiteral("disp_U"));
        QFont font1;
        font1.setPointSize(9);
        font1.setKerning(true);
        disp_U->setFont(font1);

        gridLayout_3->addWidget(disp_U, 12, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        disp_ADCW = new QPushButton(centralWidget);
        disp_ADCW->setObjectName(QStringLiteral("disp_ADCW"));
        disp_ADCW->setFont(font1);
        disp_ADCW->setIconSize(QSize(16, 16));

        gridLayout_3->addWidget(disp_ADCW, 1, 0, 1, 1);

        set_type_A = new QPushButton(centralWidget);
        set_type_A->setObjectName(QStringLiteral("set_type_A"));

        gridLayout_3->addWidget(set_type_A, 1, 1, 1, 1);

        set_type_K = new QPushButton(centralWidget);
        set_type_K->setObjectName(QStringLiteral("set_type_K"));

        gridLayout_3->addWidget(set_type_K, 7, 1, 1, 1);

        set_type_R = new QPushButton(centralWidget);
        set_type_R->setObjectName(QStringLiteral("set_type_R"));

        gridLayout_3->addWidget(set_type_R, 11, 1, 1, 1);

        set_type_T = new QPushButton(centralWidget);
        set_type_T->setObjectName(QStringLiteral("set_type_T"));

        gridLayout_3->addWidget(set_type_T, 13, 1, 1, 1);

        set_type_B = new QPushButton(centralWidget);
        set_type_B->setObjectName(QStringLiteral("set_type_B"));

        gridLayout_3->addWidget(set_type_B, 2, 1, 1, 1);

        set_type_J = new QPushButton(centralWidget);
        set_type_J->setObjectName(QStringLiteral("set_type_J"));

        gridLayout_3->addWidget(set_type_J, 6, 1, 1, 1);

        set_type_N = new QPushButton(centralWidget);
        set_type_N->setObjectName(QStringLiteral("set_type_N"));

        gridLayout_3->addWidget(set_type_N, 8, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 1, 1, 4, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 3, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        find = new QPushButton(centralWidget);
        find->setObjectName(QStringLiteral("find"));

        gridLayout_2->addWidget(find, 3, 0, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout_2->addWidget(comboBox, 1, 0, 1, 1);

        disconnect = new QPushButton(centralWidget);
        disconnect->setObjectName(QStringLiteral("disconnect"));
        QFont font2;
        font2.setPointSize(8);
        disconnect->setFont(font2);

        gridLayout_2->addWidget(disconnect, 3, 1, 1, 1);

        connect = new QPushButton(centralWidget);
        connect->setObjectName(QStringLiteral("connect"));
        connect->setFont(font2);

        gridLayout_2->addWidget(connect, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 1, 1, 1);

        infoBrowser = new QTextBrowser(centralWidget);
        infoBrowser->setObjectName(QStringLiteral("infoBrowser"));

        gridLayout->addWidget(infoBrowser, 0, 0, 2, 1);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 2, 0, 1, 1);

        send_String = new QPushButton(centralWidget);
        send_String->setObjectName(QStringLiteral("send_String"));

        gridLayout->addWidget(send_String, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        disp_U_t->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        disp_U_t->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265\n"
"U(t\302\260C) \320\245\320\241\n"
"\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        disp_T_cold_spot->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        disp_T_cold_spot->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265\n"
"t\302\260C \320\245\320\241\n"
"\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\276", Q_NULLPTR));
        set_type_S->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 S", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260</span></p><p align=\"center\"><span style=\" font-size:12pt;\">\321\202\320\270\320\277\320\260</span></p><p align=\"center\"><span style=\" font-size:12pt;\">\321\202\320\265\321\200\320\274\320\276\320\277\320\260\321\200\321\213</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        disp_U->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        disp_U->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265\n"
"U\n"
"\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\276", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\264\320\276\320\277</span></p><p><span style=\" font-size:12pt;\">\320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262</span></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        disp_ADCW->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        disp_ADCW->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265\n"
"ADCW\n"
"\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\276", Q_NULLPTR));
        set_type_A->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 A", Q_NULLPTR));
        set_type_K->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 K", Q_NULLPTR));
        set_type_R->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 R", Q_NULLPTR));
        set_type_T->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 T", Q_NULLPTR));
        set_type_B->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 B", Q_NULLPTR));
        set_type_J->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 J", Q_NULLPTR));
        set_type_N->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277 N", Q_NULLPTR));
        find->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", Q_NULLPTR));
        disconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        send_String->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
