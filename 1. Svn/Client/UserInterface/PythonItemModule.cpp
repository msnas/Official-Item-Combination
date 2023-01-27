// Search for:
PyObject* itemLoadItemTable(PyObject* poSelf, PyObject* poArgs)
{
	char * szFileName;
	if (!PyTuple_GetString(poArgs, 0, &szFileName))
		return Py_BadArgument();

	CItemManager::Instance().LoadItemTable(szFileName);
	return Py_BuildNone();
}

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
PyObject* itemGetItemNameByVnum(PyObject* poSelf, PyObject* poArgs)
{
	int itemVnum;
	if (!PyTuple_GetInteger(poArgs, 0, &itemVnum))
		return Py_BadArgument();
	DWORD dwItemID;

	auto itemName = CPythonItem::Instance().GetItemNameByVnum(itemVnum);
	
	return Py_BuildValue("s", itemName);
}

#endif

// Search for:
		{ "LoadItemTable",					itemLoadItemTable,						METH_VARARGS },

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		{ "GetItemNameByVnum",				itemGetItemNameByVnum,					METH_VARARGS },
#endif

// Search for:
	PyModule_AddIntConstant(poModule, "APPLY_ANTI_PENETRATE_PCT",	CItemData::APPLY_ANTI_PENETRATE_PCT );	

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	PyModule_AddIntConstant(poModule, "ITEM_TYPE_MEDIUM", CItemData::ITEM_TYPE_MEDIUM);
	PyModule_AddIntConstant(poModule, "MEDIUM_MOVE_COSTUME_ACCE_ATTR", CItemData::MEDIUM_MOVE_COSTUME_ACCE_ATTR);
	PyModule_AddIntConstant(poModule, "MEDIUM_MOVE_COSTUME_ATTR", CItemData::MEDIUM_MOVE_COSTUME_ATTR);
#endif