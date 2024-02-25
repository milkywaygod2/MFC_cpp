#pragma once
#include "afxdialogex.h"

#define MAX_POINT	100000

// Cdlgimage 대화 상자

class Cdlgimage : public CDialogEx
{
	DECLARE_DYNAMIC(Cdlgimage)

public:
	Cdlgimage(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Cdlgimage();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Cdlgimage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()


//--- CUSTOM ---//
private:
	void drawData(CDC* _pDC);
public:
	CWnd* m_pParent; //CprojectGRIMDlg* m_pParent;
	CImage m_Oimage2;
	int m_iDataCount = 0;
	CPoint m_Pdata[MAX_POINT];
	afx_msg void OnBnClickedOtherdlgPush();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void initImage();
};
