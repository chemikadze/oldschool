#ifndef ELEMENT_H
#define ELEMENT_H

#include <QtGlobal>
#include <QtDebug>

// make smth with that
namespace Elements
{
	extern const qint32 elements[20][4];
	extern const qint8 rotations[8];
	extern const qint8 count;
}

class Element
{
public:
	enum Type {No=0, Line, RCorn, LCorn, RSit, LSit, Sqr};

	const qint32* data();
	void rotate(bool right=true);
	void setType(Type ntype, qint8 rotat=0);
	qint8 cell(qint8 row, qint8 col);
	Element();
	Element(Type ntype, qint8 rotat=0);
private:
	const qint32 *m_val;
	Type m_type;
	qint8 m_rotat;
};

#endif // ELEMENT_H
