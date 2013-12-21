#include "computerwidget.h"
#include <mcheck.h>

ComputerWidget::ComputerWidget(QWidget* parent/*=0*/):QTreeWidget(parent)
{
	QStringList l;
	l << tr("Параметр") << tr("Значение");
	
	setHeaderLabels(l);

	p_comp=NULL;
	p_compClassName="";
	setColumnCount(2);
	createCaptions();
	outputData();
}

void ComputerWidget::createCaptions()
{
	int i, j;
	QStringList text;
	QVector <QStringList> propText;
	QTreeWidgetItem *top, *cur;
	
	text << Tr("Процессор")
	     << Tr("Память (RAM)")
	     << Tr("FDD")
	     << Tr("CD-ROM")
	     << Tr("Жесткий диск")
	     << Tr("Видеокарта");
	
	if (p_comp!=NULL)
	if (p_comp->className() == NotebookDefaultClassName)
	{
		text << Tr("Монитор")
		     << Tr("Внеший вид")
		     << Tr("Батарея")
		     << Tr("Производитель");
	}
	
	text << Tr("Переферия");
	
	if (p_comp!=NULL)
		propText.resize(7 + (p_comp->className()==NotebookDefaultClassName)*4);
	else
		propText.resize(7);
	propText[0] << Tr("Модель")
		    << Tr("Кол-во ядер")
		    << Tr("Частота")
		    << Tr("Разрядность (длинна слова)")
		    << Tr("Архитектура");
	
	propText[1] << Tr("Размер")
		    << Tr("Частота")
		    << Tr("Тип");

	propText[2] << Tr("Наличие")
		    << Tr("Размер дискет");
	
	//CD
	propText[3] << Tr("Наличие")
		    << Tr("Название")
		    << Tr("Параметры");
	//HDD
	propText[4] << Tr("Название")
		    << Tr("Размер");
	//Video
	propText[5] << Tr("Наличие")
		    << Tr("Тип")
		    << Tr("Название")
		    << Tr("Размер памяти");
	
	if (p_comp!=NULL)
	if (p_comp->className()==NotebookDefaultClassName)
	{
		propText[6] << Tr("Диагональ")
			    << Tr("Разрешение");
	
		propText[7] << Tr("Вес")
			    << Tr("Цвет");
			    
		propText[8] << Tr("Заряд")
			    << Tr("Время работы");
	
		propText[9] << Tr("Название")
			    << Tr("Страна-производитель")
			    << Tr("Стоимость");
	}
	caption.resize(0);
	for (i=0; i<text.size(); i++)
	{
		top=new QTreeWidgetItem(this);
		top->setText(0, text[i]);
		top->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		top->setBackground(0, QBrush(QColor::fromRgb(0xB5, 0xFF, 0xB5)));
		caption.push_back(top);
		for (j=0; j<propText[i].size(); j++)
		{
			cur=new QTreeWidgetItem(top);
			cur->setText(0, propText[i][j]);
			cur->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
			caption.push_back(cur);
		}
	}
}

void ComputerWidget::outputData()
{
	QString s;
	int i;
		
	qDebug() << "outputData()";	
	if (p_comp==NULL) return;
	caption[1]->setText(1, p_comp->cpuName);
	caption[2]->setText(1, QString::number(p_comp->cpuCoreCount));
	caption[3]->setText(1, QString::number(p_comp->cpuSpeed)+tr(" Мгц"));
	caption[4]->setText(1, QString::number(p_comp->cpuWordLen)+tr(" бит"));
	switch (p_comp->cpuArch)
	{
		case Computer::x86: caption[5]->setText(1, "x86");break;
		case Computer::x86_64: caption[5]->setText(1, "x86_64");break;
		case Computer::sparc: caption[5]->setText(1, "sparc");break;
		case Computer::arm: caption[5]->setText(1, "arm");break;
		case Computer::otherArch: caption[5]->setText(1, "неизвестно");break;
	};
	
	caption[7]->setText(1, QString::number(p_comp->ramSize)+tr(" МБайт"));
	caption[8]->setText(1, QString::number(p_comp->ramSpeed)+tr(" МГц"));
	caption[9]->setText(1, Tr("DDR%1").arg(p_comp->ramDDR));

	caption[11]->setText(1, p_comp->hasFdd ? Tr("Да") : Tr("Нет") );
	if (p_comp->hasFdd)
		switch (p_comp->sizeFdd)
		{
			case Computer::inch525: caption[12]->setText(1, Tr("5,25 дюма"));break;
			case Computer::inch35: caption[12]->setText(1, Tr("3,5 дюма"));break;
			case Computer::otherSize: caption[12]->setText(1, Tr("Неизвестный размер"));
		}
	else
		caption[12]->setText(1, Tr(""));
	
	caption[14]->setText(1, p_comp->hasCdrom ? Tr("Есть") : Tr("Нет"));
	if (p_comp->hasCdrom)
	{
		caption[15]->setText(1, p_comp->cdRomName);
		if (p_comp->cdRomFlags & Computer::cdrfCDRW)
			s+="CD-RW ";
		else if (p_comp->cdRomFlags & Computer::cdrfCDR)
			s+="CD-R" ;
		if (p_comp->cdRomFlags & Computer::cdrfDVDRW)
			s+="DVD-RW ";
		else if (p_comp->cdRomFlags & Computer::cdrfDVDR)
			s+="DVD-R ";
		if (p_comp->cdRomFlags & Computer::cdrfBRRW)
			s+="BluRay-RW ";
		else if (p_comp->cdRomFlags & Computer::cdrfBRR)
			s+="BluRay-R";
		caption[16]->setText(1, s);
	}
	caption[18]->setText(1, p_comp->hddName);
	caption[19]->setText(1, QString::number(p_comp->hddSize/gBytes)+tr(" ГБайт"));
	
	caption[21]->setText(1, p_comp->hasVideoCard ? Tr("Есть") : Tr("Нет"));
	if (p_comp->hasVideoCard)
	switch (p_comp->videoCardType)
	{
		case Computer::vctBuiltIn:  caption[22]->setText(1, Tr("Встроенная"));break;
		case Computer::vctPCI:  caption[22]->setText(1, Tr("PCI"));break;
		case Computer::vctUSB:  caption[22]->setText(1, Tr("USB"));break;
	}
	caption[23]->setText(1, p_comp->videoCardName);
	caption[24]->setText(1, QString::number(p_comp->videoCardRam)+tr(" МБайт"));
	
	if (p_comp->className() != ComputerDefaultClassName)
	{
	/*
		propText[6] << Tr("Диагональ")
			    << Tr("Разрешение");
	
		propText[7] << Tr("Вес")
			    << Tr("Цвет");
	
		propText[8] << Tr("Название")
			    << Tr("Страна-производитель")
			    << Tr("Стоимость");
	*/
		caption[26]->setText(1, QString::number(((Notebook*)p_comp)->monitorDiagonal)+tr(" дюйм(ов)"));
		caption[27]->setText(1, QString("%1 x %2").arg(((Notebook*)p_comp)->monitorSize.width()).arg(((Notebook*)p_comp)->monitorSize.height()));
		caption[29]->setText(1, QString::number(((Notebook*)p_comp)->weight)+tr(" кг"));
		caption[30]->setText(1, ((Notebook*)p_comp)->color);
		caption[32]->setText(1, QString::number(((Notebook*)p_comp)->batterySize)+tr(" мАч"));
		caption[33]->setText(1, QString::number(((Notebook*)p_comp)->batteryTime)+tr(" час(а)"));
		caption[35]->setText(1, ((Notebook*)p_comp)->notebookName);
		caption[36]->setText(1, ((Notebook*)p_comp)->notebookOrigin);
		caption[37]->setText(1, QString::number(((Notebook*)p_comp)->notebookCost)+tr(" руб."));
	}
	
	QList <QTreeWidgetItem*> list=caption[caption.size()-1]->takeChildren();
	QList <QTreeWidgetItem*>::iterator it;
	it=list.begin();
	qDebug() << *it;
	qDebug() << list.size();
	for (i=0; i<p_comp->otherHardware.size(); i++)
	{
		qDebug() << p_comp->otherHardware[i];
		if (list.size() <= i)
		{
			list.push_back(new QTreeWidgetItem(caption[caption.size()-1]));
			it=list.end();
			--it;
		}
		(*it)->setText(0, p_comp->otherHardware[i]);
		(*it)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		qDebug() << (*it)->data(0, Qt::DisplayRole);
		++it;
	}
	while (list.size() > i)
		delete list.takeLast();
	caption[caption.size()-1]->addChildren(list);	// Qt 4.3 bug -- no repaint
//	collapseItem(caption[caption.size()-1]);
//	expandItem(caption[caption.size()-1]);
}

Computer* ComputerWidget::comp() const
{
	return p_comp;
}

void ComputerWidget::setComp(Computer* newComp/*=0*/)
{
	qDebug() << "setComp()";
	p_comp=newComp;
	if (p_comp==NULL)
	{
		qDebug() << "p_comp=NULL";
		p_compClassName=tr("");
		clear();
		createCaptions();
		return;
	}
	if (p_comp->className() != p_compClassName)
	{
		p_compClassName=p_comp->className();
		clear();
		createCaptions();
	}
	outputData();
}

void ComputerWidget::resizeEvent(QResizeEvent* event)
{
	setColumnWidth(0, width()/2);
}