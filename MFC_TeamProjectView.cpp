
// MFC_TeamProjectView.cpp: CMFCTeamProjectView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_TeamProject.h"
#endif

#include "MFC_TeamProjectDoc.h"
#include "MFC_TeamProjectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTeamProjectView

IMPLEMENT_DYNCREATE(CMFCTeamProjectView, CView)

BEGIN_MESSAGE_MAP(CMFCTeamProjectView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SIZE_1, &CMFCTeamProjectView::BrushSize)
	ON_COMMAND(ID_SIZE_3, &CMFCTeamProjectView::BrushSize_3)
	ON_COMMAND(ID_SIZE_5, &CMFCTeamProjectView::Brush_Size_5)
	ON_COMMAND(ID_SIZE_10, &CMFCTeamProjectView::Brush_Size_10)
	ON_COMMAND(ID_SIZE_20, &CMFCTeamProjectView::Brush_Size_20)
	ON_COMMAND(ID_COLORCHANGE, &CMFCTeamProjectView::OnColorchange)
	ON_COMMAND(ID_FILLCOLORCHANGE, &CMFCTeamProjectView::OnFillcolorchange)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_TYPE_SOLID, &CMFCTeamProjectView::OnTypeSolid)
	ON_COMMAND(ID_TYPE_DASH, &CMFCTeamProjectView::OnTypeDash)
	ON_COMMAND(ID_TYPE_DOT, &CMFCTeamProjectView::OnTypeDot)
	ON_COMMAND(ID_TYPE_DASHDOT, &CMFCTeamProjectView::OnTypeDashdot)
	ON_COMMAND(ID_TYPE_DASHDOTDOT, &CMFCTeamProjectView::OnTypeDashdotdot)
	ON_COMMAND(ID_COLORCHANGE_BLACK, &CMFCTeamProjectView::OnColorchangeBlack)
	ON_COMMAND(ID_BACKGROUND_COLORCHANGE, &CMFCTeamProjectView::OnBackgroundColorchange)
	ON_COMMAND(ID_DRAW_LINE, &CMFCTeamProjectView::OnDrawLine)
	ON_COMMAND(ID_DRAW_CIRCLE, &CMFCTeamProjectView::OnDrawCircle)
	ON_COMMAND(ID_DRAW_RECTANGLE, &CMFCTeamProjectView::OnDrawRectangle)
	ON_COMMAND(ID_DRAW_TEXT, &CMFCTeamProjectView::OnDrawText)
	ON_WM_CHAR()
	ON_COMMAND(ID_BRUSH_USEBRUSH, &CMFCTeamProjectView::OnBrushUsebrush)
	ON_COMMAND(ID_Eraser_Size, &CMFCTeamProjectView::OnEraser_Size)
	ON_COMMAND(ID_Eraser_Size_3, &CMFCTeamProjectView::OnEraser_Size_3)
	ON_COMMAND(ID_Eraser_Size_5, &CMFCTeamProjectView::OnEraser_Size_5)
	ON_COMMAND(ID_Eraser_Size_10, &CMFCTeamProjectView::OnEraser_Size_10)
	ON_COMMAND(ID_Eraser_Size_20, &CMFCTeamProjectView::OnEraser_Size_20)
END_MESSAGE_MAP()

// CMFCTeamProjectView 생성/소멸

CMFCTeamProjectView::CMFCTeamProjectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	Brush_Size = 1; //초기 브러시 크기
	Brush_Type = 0; //초기 브러시 타입
	Eraser_Size = 1; //초기 지우개 크기
	backgroundColor = RGB(255, 255, 255); //초기 캔버스 색상
	m_str = L"텍스트를 입력 후\r도형을 그려주세요"; //텍스트박스 안내문구

}

CMFCTeamProjectView::~CMFCTeamProjectView()
{
}

BOOL CMFCTeamProjectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCTeamProjectView 그리기

void CMFCTeamProjectView::OnDraw(CDC* pDC)
{
	CMFCTeamProjectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//캔버스 영역을 나타내는 사각형
	CBrush Canvas_Color;
	Canvas_Color.CreateSolidBrush(backgroundColor);
	pDC->SelectObject(Canvas_Color);
	CRect Canvas_rt;
	Canvas_rt = CRect(0, win_y, win_x, 0);
	pDC->Rectangle(Canvas_rt);
	

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCTeamProjectView 인쇄

BOOL CMFCTeamProjectView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCTeamProjectView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCTeamProjectView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCTeamProjectView 진단

#ifdef _DEBUG
void CMFCTeamProjectView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTeamProjectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTeamProjectDoc* CMFCTeamProjectView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTeamProjectDoc)));
	return (CMFCTeamProjectDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTeamProjectView 메시지 처리기


void CMFCTeamProjectView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	win_x = cx;
	win_y = cy;
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}



void CMFCTeamProjectView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	dc.MoveTo(MovePoint.x, MovePoint.y);	
	MovePoint = point;
	m_GrapghicObj.m_ptStart = point; //마우스 포인터의 위치가 도형의 시작점 좌표

	CView::OnLButtonDown(nFlags, point);
}


void CMFCTeamProjectView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	m_GrapghicObj.m_ptEnd = point; //마우스가 이동중인지 확인 후 마우스의 위치를 저장
	

	// 브러시로 자유 곡선 그리기 구현부분
	if ((nFlags && MK_LBUTTON)==MK_LBUTTON)
	{
		// 펜 설정
		LOGBRUSH lbrush;
		lbrush.lbStyle = BS_SOLID;
		lbrush.lbColor = m_colLine;
		lbrush.lbHatch = 0;
		CPen pen,*oldPen;
		
		// 그림을 그릴 수 있는 캔버스 영역
		CRgn DrawArea;
		CRect DrawArea_rt;
		DrawArea_rt = CRect(0, win_y, win_x, 0);
		DrawArea.CreateRectRgnIndirect(DrawArea_rt);
		dc.SelectClipRgn(&DrawArea);

		switch (m_GrapghicObj.m_kind)
		{		
		case BRUSH:

			// 자유 곡선 그리기
			pen.CreatePen(PS_GEOMETRIC | Brush_Type, Brush_Size, &lbrush, 0, 0);
			oldPen = dc.SelectObject(&pen);

			dc.MoveTo(MovePoint.x, MovePoint.y);
			dc.LineTo(point.x, point.y);
			MovePoint.x = point.x;
			MovePoint.y = point.y;
			break;		

			//지우개

		case ERASER:
			CPen pen(PS_SOLID, Eraser_Size, backgroundColor);
			dc.SelectObject(&pen);
			oldPen = dc.SelectObject(&pen);

			dc.MoveTo(MovePoint.x, MovePoint.y);
			dc.LineTo(point.x, point.y);
			MovePoint.x = point.x;
			MovePoint.y = point.y;

			break;
		}		
		pen.DeleteObject();	
	}
	
	CView::OnMouseMove(nFlags, point);
}

//브러시 크기를 변경하는 함수들
void CMFCTeamProjectView::BrushSize()
{
	Brush_Size = 1;// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCTeamProjectView::BrushSize_3()
{
	Brush_Size = 3;// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCTeamProjectView::Brush_Size_5()
{
	Brush_Size = 5;// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCTeamProjectView::Brush_Size_10()
{
	Brush_Size = 10;// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCTeamProjectView::Brush_Size_20()
{
	Brush_Size = 20;// TODO: 여기에 명령 처리기 코드를 추가합니다.
}

// 지우개 크기를 변경하는 함수들
void CMFCTeamProjectView::OnEraser_Size()
{
	m_GrapghicObj.m_kind = ERASER;
	Eraser_Size = 1;
}

void CMFCTeamProjectView::OnEraser_Size_3()
{
	m_GrapghicObj.m_kind = ERASER;
	Eraser_Size = 3;
}


void CMFCTeamProjectView::OnEraser_Size_5()
{
	m_GrapghicObj.m_kind = ERASER;
	Eraser_Size = 5;
}


void CMFCTeamProjectView::OnEraser_Size_10()
{
	m_GrapghicObj.m_kind = ERASER;
	Eraser_Size = 10;
}


void CMFCTeamProjectView::OnEraser_Size_20()
{
	m_GrapghicObj.m_kind = ERASER;
	Eraser_Size = 20;
}

void CMFCTeamProjectView::OnColorchange()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_colLine = dlg.GetColor();
		m_colLineXor = (RGB(GetRValue(m_colLine), GetGValue(m_colLine), GetBValue(m_colLine)));
	}
}


void CMFCTeamProjectView::OnFillcolorchange()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		m_colFill = dlg.GetColor();
	}
}


void CMFCTeamProjectView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	MovePoint = point;
	m_GrapghicObj.m_ptEnd = point; //도형의 최종 좌표

	CClientDC dc(this);

	LOGBRUSH lbrush;
	lbrush.lbStyle = BS_SOLID;
	lbrush.lbColor = m_colLine;
	lbrush.lbHatch = 0;
	CPen pen, * oldPen;

	pen.CreatePen(PS_GEOMETRIC | Brush_Type, Brush_Size, &lbrush, 0, 0);
	oldPen = dc.SelectObject(&pen);

	//m_GraphicObject.m_kind체 저장되어 있는 도형의 종류를 가지고 어떤 도형을 그릴지 결정한다.
	switch (m_GrapghicObj.m_kind)
	{
	case LINE:

		dc.MoveTo(m_GrapghicObj.m_ptStart.x, m_GrapghicObj.m_ptStart.y);
		dc.LineTo(m_GrapghicObj.m_ptEnd.x, m_GrapghicObj.m_ptEnd.y);
		dc.MoveTo(m_GrapghicObj.m_ptStart.x, m_GrapghicObj.m_ptStart.y);

		break;

	case ELLIPES:
	
		dc.Ellipse(m_GrapghicObj.m_ptStart.x, m_GrapghicObj.m_ptStart.y, m_GrapghicObj.m_ptEnd.x, m_GrapghicObj.m_ptEnd.y);
		dc.Ellipse(m_GrapghicObj.m_ptStart.x, m_GrapghicObj.m_ptStart.y, point.x, point.y);

		break;

	case RECTANGLE:

		dc.Rectangle(m_GrapghicObj.m_ptStart.x, m_GrapghicObj.m_ptStart.y, m_GrapghicObj.m_ptEnd.x, m_GrapghicObj.m_ptEnd.y);
		dc.Rectangle(m_GrapghicObj.m_ptStart.x, m_GrapghicObj.m_ptStart.y, point.x, point.y);

		break;

	case TEXTBOX:

		CRect rt = CRect(m_GrapghicObj.m_ptStart, MovePoint);
		dc.Rectangle(m_GrapghicObj.m_ptStart.x, m_GrapghicObj.m_ptStart.y, m_GrapghicObj.m_ptEnd.x, m_GrapghicObj.m_ptEnd.y);
		dc.DrawTextW(m_str, &rt, DT_LEFT);
		m_str = L"";
		break;

	}

	CView::OnLButtonUp(nFlags, point);
}


void CMFCTeamProjectView::OnTypeSolid()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Brush_Type = 0;
}


void CMFCTeamProjectView::OnTypeDash()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Brush_Type = 1;
}


void CMFCTeamProjectView::OnTypeDot()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Brush_Type = 2;
}


void CMFCTeamProjectView::OnTypeDashdot()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Brush_Type = 3;
}


void CMFCTeamProjectView::OnTypeDashdotdot()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	Brush_Type = 4;
}


void CMFCTeamProjectView::OnColorchangeBlack()
{
	backgroundColor = RGB(0, 0, 0);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMFCTeamProjectView::OnBackgroundColorchange()
{
	CColorDialog dlg(RGB(255,255,255));

	if (dlg.DoModal() == IDOK) {
		backgroundColor = dlg.GetColor();
		Invalidate();
	}

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}



void CMFCTeamProjectView::OnDrawLine()
{
	m_GrapghicObj.m_kind = LINE; //도형의 종류를 결정하기 위해 메크로 상수 저장
}


void CMFCTeamProjectView::OnDrawCircle()
{
	m_GrapghicObj.m_kind = ELLIPES;
}


void CMFCTeamProjectView::OnDrawRectangle()
{
	m_GrapghicObj.m_kind = RECTANGLE;
}


void CMFCTeamProjectView::OnDrawText()
{
	m_GrapghicObj.m_kind = TEXTBOX;
}


void CMFCTeamProjectView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	if (m_GrapghicObj.m_kind == TEXTBOX) {
		if (nChar == VK_BACK) {
			m_str.Delete(m_str.GetLength() - 1);
		}
		else {
			m_str.AppendChar(nChar);
		}
		InvalidateRect(&rt, true);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFCTeamProjectView::OnBrushUsebrush()
{
	m_GrapghicObj.m_kind = BRUSH;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
