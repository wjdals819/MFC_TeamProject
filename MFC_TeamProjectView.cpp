
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
END_MESSAGE_MAP()

// CMFCTeamProjectView 생성/소멸

CMFCTeamProjectView::CMFCTeamProjectView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

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

	CBrush gray;
	gray.CreateSolidBrush(RGB(224, 224, 224));
	pDC->SelectObject(gray);

	CRect ToolBar;
	ToolBar = CRect(win_x / 4, 40, win_x/2+400, 130);
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
	if ((nFlags && MK_LBUTTON)==MK_LBUTTON)
	{
		CPen pen,*oldPen;
		pen.CreatePen(PS_SOLID, 1, PenColor);
		oldPen=dc.SelectObject(&pen);

		dc.MoveTo(MovePoint.x, MovePoint.y);
		dc.LineTo(point.x, point.y);
		MovePoint.x = point.x;
		MovePoint.y = point.y;

		pen.DeleteObject();
	}
	
	CView::OnMouseMove(nFlags, point);
}
