/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Thu Jun 17 00:07:06 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLineEdit *inputEdit1;
    QLabel *label_2;
    QLineEdit *inputEdit2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *parallel;
    QRadioButton *line;
    QPushButton *pushButton;
    QLabel *label_3;
    QLineEdit *outputEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(255, 324);
        verticalLayout_4 = new QVBoxLayout(Widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);

        inputEdit1 = new QLineEdit(Widget);
        inputEdit1->setObjectName(QString::fromUtf8("inputEdit1"));

        verticalLayout_3->addWidget(inputEdit1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setWordWrap(true);

        verticalLayout_3->addWidget(label_2);

        inputEdit2 = new QLineEdit(Widget);
        inputEdit2->setObjectName(QString::fromUtf8("inputEdit2"));

        verticalLayout_3->addWidget(inputEdit2);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        parallel = new QRadioButton(groupBox);
        parallel->setObjectName(QString::fromUtf8("parallel"));
        parallel->setChecked(false);

        verticalLayout->addWidget(parallel);

        line = new QRadioButton(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setChecked(true);

        verticalLayout->addWidget(line);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addWidget(groupBox);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setWordWrap(true);

        verticalLayout_3->addWidget(label_3);

        outputEdit = new QLineEdit(Widget);
        outputEdit->setObjectName(QString::fromUtf8("outputEdit"));
        outputEdit->setReadOnly(true);

        verticalLayout_3->addWidget(outputEdit);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(Widget);
        QObject::connect(inputEdit1, SIGNAL(returnPressed()), inputEdit2, SLOT(setFocus()));
        QObject::connect(inputEdit2, SIGNAL(returnPressed()), pushButton, SLOT(setFocus()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\320\237\320\265\321\200\320\262\321\213\320\271 \321\200\320\265\320\267\320\270\321\201\321\202\320\276\321\200 (\320\236\320\274)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\320\222\321\202\320\276\321\200\320\276\320\271 \321\200\320\265\320\267\320\270\321\201\321\202\320\276\321\200 (\320\236\320\274)", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Widget", "\320\241\320\262\320\276\321\201\320\276\320\261 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        parallel->setText(QApplication::translate("Widget", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\276", 0, QApplication::UnicodeUTF8));
        line->setText(QApplication::translate("Widget", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\320\230\321\202\320\276\320\263\320\276\320\262\320\276\320\265 \321\201\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265 (\320\236\320\274)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
