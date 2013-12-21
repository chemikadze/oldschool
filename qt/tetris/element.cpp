#include "element.h"

namespace Elements
{
	// Это не баг, это фича (ц)
	const qint32 elements[20][4]=
							{
							{0x0, 0x0, 0x0, 0x0},

							{0x11111111,
							 0x0, 0x0, 0x0
							},

							{0x11000000,
							 0x11000000,
							 0x11000000,
							 0x11000000
							},

							{0x00002222,
							 0x00000022,
							 0x00000022,
							 0x0
							},

							{0x00222222,
							 0x00220000,
							 0x0, 0x0
							},

							{0x00002200,
							 0x00002200,
							 0x00002222,
							 0x0
							},

							{0x00000022,
							 0x00222222,
							 0x0, 0x0
							},

							{0x00003333,
							 0x00003300,
							 0x00003300,
							 0x0
							},

							{0x00330000,
							 0x00333333,
							 0x0, 0x0
							},

							{0x00000033,
							 0x00000033,
							 0x00003333,
							 0x0
							},

							{0x00333333,
							 0x00000033,
							 0x0, 0x0
							},

							{0x00444400,
							 0x00004444,
							 0x0, 0x0
							},

							{0x00000044,
							 0x00004444,
							 0x00004400,
							 0x0
							},

							{0x00005555,
							 0x00555500,
							 0x0, 0x0
							},

							{0x00005500,
							 0x00005555,
							 0x00000055
							},

							{0x00006666,
							 0x00006666,
							 0x0, 0x0
							},

							{0x00007700,
							 0x00777777,
							 0x0, 0x0
							},

							{0x00000077,
							 0x00007777,
							 0x00000077,
							 0x0
							},

							{0x00777777,
							 0x00007700,
							 0x0, 0x0
							},

							{0x00007700,
							 0x00007777,
							 0x00007700,
							 0x0
							}

							};
	// Зато у меня поворот за O(1) xD
	const qint8 rotations[8]={1, 2, 4, 4, 2, 2, 1, 4};
	const qint8 rotation0[8]={0, 1, 3, 7, 11, 13, 15, 16};
	const qint8 count=8;
}

Element::Element()
{
	int i;
	for (i=0; i<4; i++)
		m_val=0x0;
	m_type=No;
	m_rotat=0;
	m_val=&(Elements::elements[0][0]);
}

Element::Element(Type ntype, qint8 rotat/*=0*/)
{
	setType(ntype, rotat);
}

void Element::rotate(bool right/*=true*/)
{
	if (right)
		m_rotat++;
	else
		m_rotat--;
	if (m_rotat >= Elements::rotations[m_type] || m_rotat<0)
		m_rotat=(m_rotat+Elements::rotations[m_type])%Elements::rotations[m_type];
	m_val=&(Elements::elements[Elements::rotation0[m_type]+m_rotat][0]);
}

void Element::setType(Type ntype, qint8 rotat/*=0*/)
{
	m_type=ntype;
	m_rotat=rotat;
	if (m_rotat >= Elements::rotations[m_type] || m_rotat<0)
		m_rotat=(m_rotat+Elements::rotations[m_type])%Elements::rotations[m_type];
	m_val=&(Elements::elements[Elements::rotation0[m_type]+m_rotat][0]);
	m_type=ntype;
}

qint8 Element::cell(qint8 row, qint8 col)
{
	return *(((qint8*)m_val+row*sizeof(qint32)+col));
}

const qint32* Element::data()
{
	return m_val;
}
