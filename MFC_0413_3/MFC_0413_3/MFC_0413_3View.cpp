
// MFC_0413_3View.cpp : CMFC_0413_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_0413_3.h"
#endif

#include "MFC_0413_3Doc.h"
#include "MFC_0413_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0413_3View

IMPLEMENT_DYNCREATE(CMFC_0413_3View, CView)

BEGIN_MESSAGE_MAP(CMFC_0413_3View, CView)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
//	ON_WM_MBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC_0413_3View ����/����

CMFC_0413_3View::CMFC_0413_3View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	flag1 = false;
	flag2 = false;

}

CMFC_0413_3View::~CMFC_0413_3View()
{
}

BOOL CMFC_0413_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0413_3View ����

void CMFC_0413_3View::OnDraw(CDC* pDC)
{
	CMFC_0413_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (set)
	{
		SetTimer(1,500, NULL);
		set = false;
	}
	pDC->Ellipse(pDoc->cr);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0413_3View ���

#ifdef _DEBUG
void CMFC_0413_3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0413_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0413_3Doc* CMFC_0413_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0413_3Doc)));
	return (CMFC_0413_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0413_3View ��Ϣ�������


void CMFC_0413_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CMFC_0413_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect ct; int r = 50;
	GetClientRect(&ct);
	if (flag1) {
		if (!flag2 && ct.right - pDoc->cr.right >= 0)
		{
			pDoc->cr.right += 10;
			pDoc->cr.left += 10;
		}
		else flag2 = true;
		if (flag2 && pDoc->cr.left > 0)
		{
			pDoc->cr.left -= 10;
			pDoc->cr.right -= 10;
		}
		else flag2 = false;
	}
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}



void CMFC_0413_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag1 = true;
	CView::OnLButtonDown(nFlags, point);
}



void CMFC_0413_3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag1 = false;
	CView::OnLButtonDblClk(nFlags, point);
}
