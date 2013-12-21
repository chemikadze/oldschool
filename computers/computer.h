#ifndef COMPUTER_H
#define COMPUTER_H

#include <QString>
#include <QStringList>
#define Tr(_X_) QObject::tr(_X_)

const int gBytes=1024;
const QString ComputerDefaultClassName("Computer");

class Computer
{
protected:
	QString s_className;
public:
	QString description;
	
	int ramSize;
	int ramSpeed;
	int ramDDR;

	int cpuCoreCount;
	int cpuSpeed;
	int cpuWordLen;
	enum cpuArchT {x86, x86_64, sparc, arm, otherArch} cpuArch;
	QString cpuName;

	bool hasVideoCard;
	enum videoCardTypeT {vctBuiltIn, vctPCI, vctUSB} videoCardType;
	int videoCardRam;
	QString videoCardName;
	
	double hddSize;
	QString hddName;

	bool hasFdd;
	enum sizeFddT {inch525, inch35, otherSize} sizeFdd;
	
	bool hasCdrom;
	char cdRomFlags;
	enum cdRomFlagsT {cdrfCDR=1, cdrfCDRW=2, cdrfDVDR=4, cdrfDVDRW=8, cdrfBRR=16, cdrfBRRW=32};
	QString cdRomName;

	QStringList otherHardware;

	QString className();
	Computer();
	Computer(Computer &parent);
};

#endif
