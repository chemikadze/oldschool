/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Thu Apr 22 01:53:05 2010
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpinBox *taskCount;
    QCheckBox *useApperance;
    QTableWidget *inputTable;
    QPushButton *shuffleButton;
    QPushButton *generateButton;
    QPushButton *clearButton;
    QComboBox *shedulers;
    QPushButton *runButton;
    QSpinBox *quantumSize;
    QCheckBox *displacement;
    QTableWidget *outputTable;
    QLabel *resultLabel;
    QCheckBox *usePriority;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(382, 511);
        Widget->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        taskCount = new QSpinBox(Widget);
        taskCount->setObjectName(QString::fromUtf8("taskCount"));
        taskCount->setMinimum(1);
        taskCount->setValue(1);

        gridLayout->addWidget(taskCount, 0, 0, 1, 1);

        useApperance = new QCheckBox(Widget);
        useApperance->setObjectName(QString::fromUtf8("useApperance"));

        gridLayout->addWidget(useApperance, 0, 1, 1, 1);

        inputTable = new QTableWidget(Widget);
        inputTable->setObjectName(QString::fromUtf8("inputTable"));

        gridLayout->addWidget(inputTable, 1, 0, 1, 4);

        shuffleButton = new QPushButton(Widget);
        shuffleButton->setObjectName(QString::fromUtf8("shuffleButton"));

        gridLayout->addWidget(shuffleButton, 2, 0, 1, 1);

        generateButton = new QPushButton(Widget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));

        gridLayout->addWidget(generateButton, 2, 1, 1, 1);

        clearButton = new QPushButton(Widget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 2, 2, 1, 1);

        shedulers = new QComboBox(Widget);
        shedulers->setObjectName(QString::fromUtf8("shedulers"));

        gridLayout->addWidget(shedulers, 3, 0, 1, 2);

        runButton = new QPushButton(Widget);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        gridLayout->addWidget(runButton, 3, 2, 1, 1);

        quantumSize = new QSpinBox(Widget);
        quantumSize->setObjectName(QString::fromUtf8("quantumSize"));
        quantumSize->setMinimum(1);
        quantumSize->setValue(1);

        gridLayout->addWidget(quantumSize, 4, 0, 1, 1);

        displacement = new QCheckBox(Widget);
        displacement->setObjectName(QString::fromUtf8("displacement"));

        gridLayout->addWidget(displacement, 4, 1, 1, 1);

        outputTable = new QTableWidget(Widget);
        outputTable->setObjectName(QString::fromUtf8("outputTable"));

        gridLayout->addWidget(outputTable, 5, 0, 1, 4);

        resultLabel = new QLabel(Widget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));

        gridLayout->addWidget(resultLabel, 6, 0, 1, 3);

        usePriority = new QCheckBox(Widget);
        usePriority->setObjectName(QString::fromUtf8("usePriority"));

        gridLayout->addWidget(usePriority, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 3, 1, 1);

        gridLayout->setColumnStretch(3, 1);

        verticalLayout->addLayout(gridLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\320\233\320\260\320\261\320\276\321\200\320\260\321\202\320\276\321\200\320\275\320\260\321\217 \320\277\320\276 \320\236\320\241 \342\204\2261", 0, QApplication::UnicodeUTF8));
        taskCount->setSuffix(QString());
        taskCount->setPrefix(QApplication::translate("Widget", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201\320\276\320\262 ", 0, QApplication::UnicodeUTF8));
        useApperance->setText(QApplication::translate("Widget", "\320\222\321\200\320\265\320\274\321\217 \320\277\320\276\321\217\320\262\320\273.", 0, QApplication::UnicodeUTF8));
        shuffleButton->setText(QApplication::translate("Widget", "\320\237\320\265\321\200\320\265\320\274\320\265\321\210\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        generateButton->setText(QApplication::translate("Widget", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("Widget", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        runButton->setText(QApplication::translate("Widget", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        quantumSize->setPrefix(QApplication::translate("Widget", "\320\232\320\262\320\260\320\275\321\202 ", 0, QApplication::UnicodeUTF8));
        displacement->setText(QApplication::translate("Widget", "\320\222\321\213\321\202\320\265\321\201\320\275\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        resultLabel->setText(QString());
        usePriority->setText(QApplication::translate("Widget", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
