
// MFC_0413_1View.cpp : CMFC_0413_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0413_1.h"
#endif

#include "MFC_0413_1Doc.h"
#include "MFC_0413_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0413_1View

IMPLEMENT_DYNCREATE(CMFC_0413_1View, CView)

BEGIN_MESSAGE_MAP(CMFC_0413_1View, CView)
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC_0413_1View 构造/析构

CMFC_0413_1View::CMFC_0413_1View()
{
	// TODO: 在此处添加构造代码
	flag = 0; f = 0;
}

CMFC_0413_1View::~CMFC_0413_1View()
{
}

BOOL CMFC_0413_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0413_1View 绘制

void CMFC_0413_1View::OnDraw(CDC* pDC)
{
	CMFC_0413_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	pDoc->cr.left = x - 50;
	pDoc->cr.top = y - 50;
	pDoc->cr.right = x + 50;
	pDoc->cr.bottom = y + 50;
	dc.Rectangle(pDoc->cr.left, pDoc->cr.top, pDoc->cr.right, pDoc->cr.bottom);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0413_1View 诊断

#ifdef _DEBUG
void CMFC_0413_1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0413_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0413_1Doc* CMFC_0413_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0413_1Doc)));
	return (CMFC_0413_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0413_1View 消息处理程序


void CMFC_0413_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	x = point.x;
	y = point.y;
	flag += 1;
	f = 1;
	CView::OnLButtonDown(nFlags, point);
}

void CMFC_0413_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	x1 = point.x;
	y1 = point.y;
	x = x1;
	y = y1;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CMFC_0413_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}
