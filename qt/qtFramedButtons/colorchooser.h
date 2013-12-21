#ifndef COLORCHOOSER_H
#define COLORCHOOSER_H

#include <QtGui>

class clickFilter : public QObject
{
    Q_OBJECT
signals:
    void clicked();
private:
    virtual bool eventFilter(QObject *filter, QEvent *event);
};

class colorChooser : public QWidget
{
    Q_OBJECT
    QColorDialog *dialog;
    QColor a_color;
    QLabel *colorLabel;
    QPushButton *colorWidget;
    clickFilter *filter;
public slots:
    QColor showDialog();
public:
    QColor color();
    void setColor(QColor newColor);
    colorChooser();
    colorChooser(QColor newColor);
};

#endif // COLORCHOOSER_H
