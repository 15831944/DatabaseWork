// SelectDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DatabaseWork.h"
#include "SelectDlg.h"
#include "afxdialogex.h"


// SelectDlg 对话框

IMPLEMENT_DYNAMIC(SelectDlg, CDialogEx)

SelectDlg::SelectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECTDLG, pParent)
{

}

SelectDlg::~SelectDlg()
{
}

void SelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SelectDlg, CDialogEx)
END_MESSAGE_MAP()


// SelectDlg 消息处理程序
