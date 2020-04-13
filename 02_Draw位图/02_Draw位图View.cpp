
// 02_Draw位图View.cpp: CMy02Draw位图View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "02_Draw位图.h"
#endif

#include "02_Draw位图Doc.h"
#include "02_Draw位图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy02Draw位图View

IMPLEMENT_DYNCREATE(CMy02Draw位图View, CView)

BEGIN_MESSAGE_MAP(CMy02Draw位图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy02Draw位图View 构造/析构

CMy02Draw位图View::CMy02Draw位图View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy02Draw位图View::~CMy02Draw位图View()
{
}

BOOL CMy02Draw位图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy02Draw位图View 绘图

void CMy02Draw位图View::OnDraw(CDC* pDC)
{
	CMy02Draw位图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/*
	定义画家
	定义画笔（画刷）CPan，CBrush
	把画笔交给画家 CDC::SelectObject

	*/
	//PS_DASH:虚线 只有当画笔宽度为1或者更小（以设备单位计量）时才有效
	//线宽
	CPen pen(PS_DASH, 1, RGB(255, 0, 0));

	//返回设备前状态
	CPen* oldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(10, 10);
	pDC->LineTo(120, 10);

	//恢复原来的状态
	pDC->SelectObject(oldPen);

	//画圆形
	pDC->Ellipse(20, 20, 120, 120);

	//画刷
	CBrush brush(RGB(255, 0, 0));
	pDC->SelectObject(&brush);
	pDC->Ellipse(20, 20, 120, 120);



	//定义一个位图对象
	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);//加载位图

	CBrush brush2(&bitmap);//将位图放在画刷上
	pDC->SelectObject(&brush2);//使用画刷
	pDC->Ellipse(120, 20, 240, 120);//画刷画的位置


	CPen pen2(PS_DASH, 1, RGB(255, 0, 0));



	// TODO: 在此处为本机数据添加绘制代码
}


// CMy02Draw位图View 打印

BOOL CMy02Draw位图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy02Draw位图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy02Draw位图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy02Draw位图View 诊断

#ifdef _DEBUG
void CMy02Draw位图View::AssertValid() const
{
	CView::AssertValid();
}

void CMy02Draw位图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy02Draw位图Doc* CMy02Draw位图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy02Draw位图Doc)));
	return (CMy02Draw位图Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy02Draw位图View 消息处理程序
