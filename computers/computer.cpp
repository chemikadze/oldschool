#include "computer.h"
#include <QtCore>

Computer::Computer()
{
	if (s_className.isNull())
		s_className=ComputerDefaultClassName;
	description=Tr("Default computer configuration");
	
	ramSize=512;
	ramSpeed=800;
	ramDDR=2;

	cpuCoreCount=1;
	cpuArch=x86;
	cpuSpeed=1600;
	cpuWordLen=32;
	cpuName=Tr("NoName");

	hasVideoCard=true;
	videoCardType=vctBuiltIn;
	videoCardRam=64;
	videoCardName=Tr("NoName");

	hddSize=100*gBytes;
	hddName=Tr("NoName");

	hasFdd=true;
	sizeFdd=inch35;

	hasCdrom=true;
	cdRomFlags=cdrfCDR | cdrfCDRW | cdrfDVDR;
	cdRomName=Tr("NoName");
}

QString Computer::className()
{
	return s_className;
}