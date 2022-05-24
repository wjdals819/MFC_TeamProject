
// MFC_TeamProjectView.h: CMFCTeamProjectView 클래스의 인터페이스
//

#pragma once


class CMFCTeamProjectView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCTeamProjectView() noexcept;
	DECLARE_DYNCREATE(CMFCTeamProjectView)

// 특성입니다.
public:
	CMFCTeamProjectDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCTeamProjectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
	int win_x=0; //window 창의 x축
	int win_y=0; //window창의 y축
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint MovePoint;
	COLORREF PenColor=RGB(0,0,0); // 색상 저장 변수
	
	afx_msg void BrushSize(); 
	int Brush_Size; //브러시 크기를 저장하는 변수
	afx_msg void BrushSize_3();
	afx_msg void Brush_Size_5();
	afx_msg void Brush_Size_10();
	afx_msg void Brush_Size_20();
};

#ifndef _DEBUG  // MFC_TeamProjectView.cpp의 디버그 버전
inline CMFCTeamProjectDoc* CMFCTeamProjectView::GetDocument() const
   { return reinterpret_cast<CMFCTeamProjectDoc*>(m_pDocument); }
#endif

