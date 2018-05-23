#include "stdafx.h"
#include "DBtoListCtrl.h"


DBtoListCtrl::DBtoListCtrl()
{
}

DBtoListCtrl::DBtoListCtrl(CListCtrl * CLC_list, CRecordset * CRS_result)
{
	list = CLC_list;
	result = CRS_result;
}


DBtoListCtrl::~DBtoListCtrl()
{
}

void DBtoListCtrl::GerenateLC()
{
	CString res;
	CODBCFieldInfo row;
	short nFields = result->GetODBCFieldCount(); 
	for (short index = 0; index < nFields; index++)
	{
		result->GetODBCFieldInfo(index, row);
		list->InsertColumn(index, row.m_strName);
		list->SetColumnWidth(index, 120);
	}
	short n = 0;
	while (!result->IsEOF())
	{
		list->InsertItem(n, L"");
		for (short index = 0; index < nFields; index++)
		{
			result->GetFieldValue(index, res);
			// do something with varValue
			list->SetItemText(n, index, res);
		}
		result->MoveNext();
		n++;
	}
}
