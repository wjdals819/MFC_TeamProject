#pragma once
#include "atltypes.h"
#define LINE 1
#define ELLIPES 2
#define RECTANGLE 3
#define TEXTBOX 4
#define BRUSH 5
#define ERASER 6
//정의된 상수는 CGraphicObject의 m_kind에 저장될 값이다. 


class CGraphicObject
{
public:
	short m_kind; //도형의 종류
	CPoint m_ptStart; //시작점
	CPoint m_ptEnd; //끝점
	CString m_strText; //텍스트
};

