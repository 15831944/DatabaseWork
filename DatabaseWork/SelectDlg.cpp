// SelectDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "SelectDlg.h"
#include "afxdialogex.h"
#include "DBtoListCtrl.h"


// SelectDlg 对话框

IMPLEMENT_DYNAMIC(SelectDlg, CDialogEx)

SelectDlg::SelectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECTDLG, pParent)
{
	sellerId = 0;
}

SelectDlg::~SelectDlg()
{
}

void SelectDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Text(pDX, IDC_SELECTDLG_EDIT, sellerId);
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SELECTDLG_QUERY, &SelectDlg::OnBnClickedSelectdlgQuery)
	//ON_EN_KILLFOCUS(IDC_SELECTDLG_EDIT, &SelectDlg::OnEnKillfocusSelectdlgEdit)
END_MESSAGE_MAP()


// SelectDlg 消息处理程序


void SelectDlg::OnBnClickedSelectdlgQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	CDatabase db;
	db.Open(_T("MyDatabase"));
	CRecordset rs(&db);
	CListCtrl *list = (CListCtrl*)GetDlgItem(IDC_SELECTDLG_SELLER);
	//list->SetExtendedStyle(WS_VISIBLE);
	list->DeleteAllItems();
	CString sql = L"SELECT * FROM goodslist WHERE seller_id = ";
	CString id;
	id.Format(_T("%d"), sellerId);
	sql += id;
	rs.Open(CRecordset::forwardOnly,sql);
	DBtoListCtrl a(list, &rs);
	a.GerenateLC();
	/*
	CString result;
	CODBCFieldInfo row;
	short nFields = rs.GetODBCFieldCount();
	for (short index = 0; index < nFields; index++)
	{
		rs.GetODBCFieldInfo(index, row);
		list->InsertColumn(index, row.m_strName);
		list->SetColumnWidth(index, 120);
	}
	short n=0;
	while (!rs.IsEOF())
	{
		list->InsertItem(n, L"");
		for (short index = 0; index < nFields; index++)
		{
			rs.GetFieldValue(index, result);
			// do something with varValue
			list->SetItemText(n,index, result);
		}
		rs.MoveNext();
		n++;
	}
	*/
	
}


//void SelectDlg::OnEnKillfocusSelectdlgEdit()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CDataExchange *pDX;
//	DoDataExchange(pDX);
//}
