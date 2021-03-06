#pragma once


// DeleteDlg 对话框

class DeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteDlg)

public:
	DeleteDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DeleteDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDeletedlgQuery();
	CString sellerId;
	afx_msg void OnBnClickedOk();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CDatabase db;
//	DBtoListCtrl dblc;
	afx_msg void OnBnClickedCancel();
//	int isOnSale;
};
