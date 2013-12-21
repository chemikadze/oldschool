/********************************************************************************
** Form generated from reading UI file 'niveler3classtab.ui'
**
** Created: Sat Feb 27 18:59:26 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVELER3CLASSTAB_H
#define UI_NIVELER3CLASSTAB_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Niveler3ClassTab
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *addBtn;
    QPushButton *deleteBtn;
    QPushButton *calculateBtn;
    QTableView *tableView;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Niveler3ClassTab)
    {
        if (Niveler3ClassTab->objectName().isEmpty())
            Niveler3ClassTab->setObjectName(QString::fromUtf8("Niveler3ClassTab"));
        Niveler3ClassTab->resize(287, 171);
        horizontalLayout = new QHBoxLayout(Niveler3ClassTab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addBtn = new QPushButton(Niveler3ClassTab);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));

        gridLayout->addWidget(addBtn, 0, 0, 1, 1);

        deleteBtn = new QPushButton(Niveler3ClassTab);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));

        gridLayout->addWidget(deleteBtn, 0, 1, 1, 1);

        calculateBtn = new QPushButton(Niveler3ClassTab);
        calculateBtn->setObjectName(QString::fromUtf8("calculateBtn"));

        gridLayout->addWidget(calculateBtn, 0, 2, 1, 1);

        tableView = new QTableView(Niveler3ClassTab);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(Niveler3ClassTab);

        QMetaObject::connectSlotsByName(Niveler3ClassTab);
    } // setupUi

    void retranslateUi(QWidget *Niveler3ClassTab)
    {
        Niveler3ClassTab->setWindowTitle(QApplication::translate("Niveler3ClassTab", "Form", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("Niveler3ClassTab", "Add pnt", 0, QApplication::UnicodeUTF8));
        deleteBtn->setText(QApplication::translate("Niveler3ClassTab", "Delete pnt", 0, QApplication::UnicodeUTF8));
        calculateBtn->setText(QApplication::translate("Niveler3ClassTab", "Calculate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Niveler3ClassTab: public Ui_Niveler3ClassTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVELER3CLASSTAB_H
