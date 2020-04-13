
// 02_Draw位图View.h: CMy02Draw位图View 类的接口
//

#pragma once


class CMy02Draw位图View : public CView
{
protected: // 仅从序列化创建
	CMy02Draw位图View() noexcept;
	DECLARE_DYNCREATE(CMy02Draw位图View)

// 特性
public:
	CMy02Draw位图Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy02Draw位图View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 02_Draw位图View.cpp 中的调试版本
inline CMy02Draw位图Doc* CMy02Draw位图View::GetDocument() const
   { return reinterpret_cast<CMy02Draw位图Doc*>(m_pDocument); }
#endif

