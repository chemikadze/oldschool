#include "window.h"
#include <QtGui>
#include <mcheck.h>

int main(int argc, char **argv)
{
	mcheck(NULL);
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QApplication app(argc, argv);
	Window *mainWindow=new Window;
	
	Computer *myHomeComputer=new Computer;
	
	myHomeComputer->description=Tr("Мой домашний компьютер");
	myHomeComputer->ramSize=512;
	myHomeComputer->ramSpeed=241;
	myHomeComputer->ramDDR=1;
	
	myHomeComputer->cpuCoreCount=1;
	myHomeComputer->cpuSpeed=3001;
	myHomeComputer->cpuWordLen=32;
	myHomeComputer->cpuArch=Computer::x86;
	myHomeComputer->cpuName=Tr("Intel Pentium 4");
	
	myHomeComputer->hasVideoCard=true;
	myHomeComputer->videoCardType=Computer::vctPCI;
	myHomeComputer->videoCardRam=126;
	myHomeComputer->videoCardName=Tr("ATI Radeon 9600");
	
	myHomeComputer->hddSize=110*gBytes;
	myHomeComputer->hddName=Tr("Seagate Barracuda");
	
	myHomeComputer->hasFdd=true;
	myHomeComputer->sizeFdd=Computer::inch35;
	
	myHomeComputer->hasCdrom=true;
	myHomeComputer->cdRomFlags=Computer::cdrfCDRW | Computer::cdrfCDR | Computer::cdrfDVDR;

	myHomeComputer->otherHardware << Tr("Оптическая мышь") << Tr("Клавиатура") << Tr("Монитор LG Flatron"); 
	
	mainWindow->addComputerData(myHomeComputer);
	
	//==============================================
	myHomeComputer=new Notebook;
	myHomeComputer->description=Tr("ACER Aspire 7720 ZG");
	myHomeComputer->ramSize=4096;
	myHomeComputer->ramSpeed=800;
	myHomeComputer->ramDDR=2;
	
	myHomeComputer->cpuCoreCount=2;
	myHomeComputer->cpuSpeed=1886;
	myHomeComputer->cpuWordLen=32;
	myHomeComputer->cpuArch=Computer::x86;
	myHomeComputer->cpuName=Tr("Intel Dual-Core");
	
	myHomeComputer->hasVideoCard=true;
	myHomeComputer->videoCardType=Computer::vctPCI;
	myHomeComputer->videoCardRam=256;
	myHomeComputer->videoCardName=Tr("Nvidia 9200 MG");
	
	myHomeComputer->hddSize=250*gBytes;
	//myHomeComputer->hddName=Tr("");
	
	myHomeComputer->hasFdd=false;
	//myHomeComputer->sizeFdd=Computer::inch35;
	
	myHomeComputer->hasCdrom=true;
	myHomeComputer->cdRomFlags=Computer::cdrfCDRW | Computer::cdrfCDR | Computer::cdrfDVDR | Computer::cdrfDVDRW;
	
	((Notebook*)myHomeComputer)->notebookName=Tr("Acer Aspire 7720 ZG");
	((Notebook*)myHomeComputer)->notebookOrigin=Tr("Тайвань");
	((Notebook*)myHomeComputer)->notebookCost=29000;
	((Notebook*)myHomeComputer)->monitorDiagonal=17;
	((Notebook*)myHomeComputer)->monitorSize=QSize(1440, 900);
	((Notebook*)myHomeComputer)->weight=3.5;
	((Notebook*)myHomeComputer)->color=Tr("черный");
	((Notebook*)myHomeComputer)->batterySize=4400;
	((Notebook*)myHomeComputer)->batteryTime=2.5;
	myHomeComputer->otherHardware << Tr("Оптическая мышь") << Tr("Веб-камера 0.3 МПикс") << Tr("Сетевая карта Broadcom") << Tr("WiFi карта Atheros");
	mainWindow->addComputerData(myHomeComputer);
	//==============================================
	myHomeComputer=new Notebook;
	myHomeComputer->description=Tr("ASUS Eee PC 900");
	myHomeComputer->ramSize=1024;
	myHomeComputer->ramSpeed=400;// ?????
	myHomeComputer->ramDDR=1;
	
	myHomeComputer->cpuCoreCount=1;
	myHomeComputer->cpuSpeed=900;
	myHomeComputer->cpuWordLen=32;
	myHomeComputer->cpuArch=Computer::x86;
	myHomeComputer->cpuName=Tr("Intel Celeron M");
	
	myHomeComputer->hasVideoCard=true;
	myHomeComputer->videoCardType=Computer::vctBuiltIn;
	myHomeComputer->videoCardRam=0;
	myHomeComputer->videoCardName=Tr("Intel 915GM");
	
	myHomeComputer->hddSize=20*gBytes;
	myHomeComputer->hddName=Tr("SSD Drive");
	
	myHomeComputer->hasFdd=false;
	//myHomeComputer->sizeFdd=Computer::inch35;
	
	myHomeComputer->hasCdrom=false;
	//myHomeComputer->cdRomFlags=Computer::cdrfCDRW | Computer::cdrfCDR | Computer::cdrfDVDR | Computer::cdrfDVDRW;
	
	((Notebook*)myHomeComputer)->notebookName=Tr("Asus Eee PC 900");
	((Notebook*)myHomeComputer)->notebookOrigin=Tr("");
	((Notebook*)myHomeComputer)->notebookCost=8500;
	((Notebook*)myHomeComputer)->monitorDiagonal=10;
	((Notebook*)myHomeComputer)->monitorSize=QSize(1024, 600);
	((Notebook*)myHomeComputer)->weight=0.9;
	((Notebook*)myHomeComputer)->color=Tr("белый");
	((Notebook*)myHomeComputer)->batterySize=5200;
	((Notebook*)myHomeComputer)->batteryTime=3.5;
	myHomeComputer->otherHardware << Tr("Сетевая карта") << Tr("WiFi карта Atheros") << Tr("Веб-камера 1.3 МПикс");
	mainWindow->addComputerData(myHomeComputer);
	
	
	mainWindow->resize(mainWindow->width()+50, mainWindow->height()+50);
	mainWindow->show();
	mtrace();
	app.exec();
	mtrace();
}