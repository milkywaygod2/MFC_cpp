
// projectGRIMDlg.h: 헤더 파일
//
#pragma once

// CprojectGRIMDlg 대화 상자
class CprojectGRIMDlg : public CDialogEx {
// 생성입니다.
public:
	CprojectGRIMDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECTGRIM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

//--- CUSTOM ---//
private:
	CImage m_Oimage;
	CRect m_Orect;
	BOOL validImagePos(int _x, int _y) { return m_Orect.PtInRect( CPoint(_x, _y) ); }

public:


	int m_iNum;

	int iWidth = 640;
	int iHeight = 480;
	int iBpp = 8;

	int iColor_Gray = 80;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEditNum();

	afx_msg void OnBnClickedButtonImage();
	afx_msg void OnBnClickedButtonImageSave();
	afx_msg void OnBnClickedButtonImageLoad();
	afx_msg void OnBnClickedButtonImageMoveRect();

	void updateDC(){
		CClientDC OclientDC(this);
		m_Oimage.Draw(OclientDC, 0, 0);
	}
	void moveRect();
};
