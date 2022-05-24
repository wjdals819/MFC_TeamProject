﻿
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
END_MESSAGE_MAP()

// CMFCTeamProjectView 생성/소멸

CMFCTeamProjectView::CMFCTeamProjectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	Brush_Size = 1; //초기 브러시 크기
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
	CRect Canvas_rt;
	Canvas_rt = CRect(0, win_y, win_x, 120);
	pDC->Rectangle(Canvas_rt);

	//툴바의 바탕색
	CBrush gray;
	gray.CreateSolidBrush(RGB(224, 224, 224));
	pDC->SelectObject(gray);

	//툴바 구현
	CRect ToolBar;
	ToolBar = CRect(win_x / 4, 20, win_x/2+400, 110);
	pDC->Rectangle(ToolBar);

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
	dc.MoveTo(point.x, point.y);
	MovePoint.x = point.x;
	MovePoint.y = point.y;

	CView::OnLButtonDown(nFlags, point);
}


void CMFCTeamProjectView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	// 브러시로 자유 곡선 그리기 구현부분
	if ((nFlags && MK_LBUTTON)==MK_LBUTTON)
	{
		// 펜 설정
		CPen pen,*oldPen;
		pen.CreatePen(PS_SOLID, Brush_Size, m_colLine);
		oldPen=dc.SelectObject(&pen);

		// 그림을 그릴 수 있는 캔버스 영역
		CRgn DrawArea;
		CRect DrawArea_rt;
		DrawArea_rt = CRect(0, win_y, win_x, 135);
		DrawArea.CreateRectRgnIndirect(DrawArea_rt);
		dc.SelectClipRgn(&DrawArea);

		//자유 곡선 그리기
		dc.MoveTo(MovePoint.x, MovePoint.y);
		dc.LineTo(point.x, point.y);
		MovePoint.x = point.x;
		MovePoint.y = point.y;

		pen.DeleteObject();
	}
	
	CView::OnMouseMove(nFlags, point);
}


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
