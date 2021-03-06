// UpdateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "UpdateDlg.h"
#include "afxdialogex.h"
#include "DBtoListCtrl.h"


// UpdateDlg 对话框

IMPLEMENT_DYNAMIC(UpdateDlg, CDialogEx)

UpdateDlg::UpdateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UPDATEDLG, pParent)
	
{
	goodsId = _T("");
	sellerId = _T("");
	goodsName = _T("");
	goodsPrice = _T("");
	isOnSale = 0;
}

UpdateDlg::~UpdateDlg()
{
}

void UpdateDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Check(pDX, IDC_UPDATE_ONSALE, isOnSale);
	DDX_Text(pDX,IDC_UPDATE_GOODSID,goodsId);
	//DDX_Text(pDX, IDC_UPDATE_SELLERID, sellerId);
	DDX_Text(pDX, IDC_UPDATE_GOODSNAME, goodsName);
	//DDX_Text(pDX, IDC_UPDATE_GOODSPRICE, goodsPrice);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(UpdateDlg, CDialogEx)
	ON_BN_CLICKED(IDC_UPDATEDLG_QUEST, &UpdateDlg::OnBnClickedUpdatedlgQuest)
//	ON_WM_CREATE()
END_MESSAGE_MAP()


// UpdateDlg 消息处理程序


void UpdateDlg::OnBnClickedUpdatedlgQuest()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CMFCMaskedEdit *money = (CMFCMaskedEdit*)GetDlgItem(IDC_UPDATE_GOODSPRICE);
	money->GetWindowText(goodsPrice);
	CString init, mask, str_isOnSale;
	init = goodsPrice.Left(6);
	mask = goodsPrice.Mid(6, 2);
	str_isOnSale.Format(L"%d", isOnSale);
	if (goodsName == L"")
	{
		goodsName = L"null";
	}
	else
	{
		goodsName = L"'" + goodsName + L"'";
	}
	CString sql = L"exec updateproc "
		+ goodsId + L", "
		+ goodsName + L", "
		+ init + L"." + mask + ", "
		+ str_isOnSale;
	CDatabase db;
	db.Open(_T("MyDatabase"));
	try
	{
		db.ExecuteSQL(sql);
	}
	catch (CDBException* pe)
	{
		// The error code is in pe->m_nRetCode
		MessageBox(L"更新出错！");
		pe->ReportError();
		pe->Delete();
		return;
	}
	//MessageBox(L"更新成功");
	CListCtrl* lc = (CListCtrl*)GetDlgItem(IDC_UPDATE_LIST);
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly, L"select * from goods where goods_id =" + goodsId);
	DBtoListCtrl dblc(lc, &rs);
	dblc.GerenateLC();
	lc->ShowWindow(SW_SHOW);
}

//int UpdateDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  在此添加您专用的创建代码
//	//CMFCMaskedEdit *money = (CMFCMaskedEdit*)GetDlgItem(IDC_UPDATE_GOODSPRICE);
//	return 0;
//}
