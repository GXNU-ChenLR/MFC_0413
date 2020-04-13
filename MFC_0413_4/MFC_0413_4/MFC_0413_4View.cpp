
// MFC_0413_4View.cpp : CMFC_0413_4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_0413_4.h"
#endif

#include "MFC_0413_4Doc.h"
#include "MFC_0413_4View.h"
#include "MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0413_4View

IMPLEMENT_DYNCREATE(CMFC_0413_4View, CView)

BEGIN_MESSAGE_MAP(CMFC_0413_4View, CView)
	ON_COMMAND(ID_POPOUT, &CMFC_0413_4View::OnPopout)
END_MESSAGE_MAP()

// CMFC_0413_4View 构造/析构

CMFC_0413_4View::CMFC_0413_4View()
{
	// TODO: 在此处添加构造代码

}

CMFC_0413_4View::~CMFC_0413_4View()
{
}

BOOL CMFC_0413_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_0413_4View 绘制

void CMFC_0413_4View::OnDraw(CDC* /*pDC*/)
{
	CMFC_0413_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC_0413_4View 诊断

#ifdef _DEBUG
void CMFC_0413_4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0413_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0413_4Doc* CMFC_0413_4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0413_4Doc)));
	return (CMFC_0413_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0413_4View 消息处理程序


void CMFC_0413_4View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
}
