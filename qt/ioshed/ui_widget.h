/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Tue May 4 16:58:31 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "hddwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QSpinBox *cylinderCount;
    QSpinBox *queryCount;
    QSpinBox *startPosition;
    QPushButton *generateButton;
    QPushButton *shuffleButton;
    QPushButton *runButton;
    QLabel *label_2;
    QComboBox *algoBox;
    QTableWidget *inputTable;
    QTableWidget *outputTable;
    QScrollBar *directionBar;
    QLabel *label_4;
    QLabel *label_5;
    HddWidget *hddSheme;
    QLabel *infoLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(532, 336);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        cylinderCount = new QSpinBox(Widget);
        cylinderCount->setObjectName(QString::fromUtf8("cylinderCount"));

        gridLayout->addWidget(cylinderCount, 2, 0, 1, 1);

        queryCount = new QSpinBox(Widget);
        queryCount->setObjectName(QString::fromUtf8("queryCount"));

        gridLayout->addWidget(queryCount, 2, 1, 1, 1);

        startPosition = new QSpinBox(Widget);
        startPosition->setObjectName(QString::fromUtf8("startPosition"));

        gridLayout->addWidget(startPosition, 2, 2, 1, 1);

        generateButton = new QPushButton(Widget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));

        gridLayout->addWidget(generateButton, 3, 0, 1, 1);

        shuffleButton = new QPushButton(Widget);
        shuffleButton->setObjectName(QString::fromUtf8("shuffleButton"));

        gridLayout->addWidget(shuffleButton, 3, 1, 1, 1);

        runButton = new QPushButton(Widget);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        gridLayout->addWidget(runButton, 3, 2, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        algoBox = new QComboBox(Widget);
        algoBox->setObjectName(QString::fromUtf8("algoBox"));

        gridLayout->addWidget(algoBox, 5, 0, 1, 2);

        inputTable = new QTableWidget(Widget);
        inputTable->setObjectName(QString::fromUtf8("inputTable"));
        inputTable->horizontalHeader()->setDefaultSectionSize(50);

        gridLayout->addWidget(inputTable, 0, 0, 1, 3);

        outputTable = new QTableWidget(Widget);
        outputTable->setObjectName(QString::fromUtf8("outputTable"));
        outputTable->horizontalHeader()->setDefaultSectionSize(50);

        gridLayout->addWidget(outputTable, 6, 0, 1, 3);

        directionBar = new QScrollBar(Widget);
        directionBar->setObjectName(QString::fromUtf8("directionBar"));
        directionBar->setEnabled(true);
        directionBar->setMaximum(1);
        directionBar->setSingleStep(1);
        directionBar->setPageStep(1);
        directionBar->setSliderPosition(1);
        directionBar->setTracking(false);
        directionBar->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(directionBar, 5, 2, 1, 1);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 2);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 2, 1, 1);

        hddSheme = new HddWidget(Widget);
        hddSheme->setObjectName(QString::fromUtf8("hddSheme"));
        hddSheme->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(hddSheme, 0, 3, 7, 1);


        verticalLayout->addLayout(gridLayout);

        infoLabel = new QLabel(Widget);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));

        verticalLayout->addWidget(infoLabel);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \320\277\320\276 \320\236\320\241 \342\204\2263", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\320\234\320\260\320\272\321\201. \321\206\320\270\320\273\320\270\320\275\320\264\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\320\235\320\260\321\207. \320\277\320\276\320\267.", 0, QApplication::UnicodeUTF8));
        generateButton->setText(QApplication::translate("Widget", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        shuffleButton->setText(QApplication::translate("Widget", "\320\237\320\265\321\200\320\265\320\274\320\265\321\210\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        runButton->setText(QApplication::translate("Widget", "\320\227\320\260\320\277\321\203\321\201\320\272", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\320\227\320\260\320\277\321\200\320\276\321\201\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        infoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
