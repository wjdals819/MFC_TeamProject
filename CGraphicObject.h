#pragma once
#include "atltypes.h"
#define LINE 1
#define ELLIPES 2
#define RECTANGLE 3
#define TEXTBOX 4
#define BRUSH 5


class CGraphicObject
{
public:
	short m_kind;
	CPoint m_ptStart;
	CPoint m_ptEnd;
	CString m_strText;
};

