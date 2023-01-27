// Search for:
void initPlayer()
{

// Add before:
#ifdef ENABLE_MOVE_COSTUME_ATTR
PyObject* playerSetItemCombinationWindowActivedItemSlot(PyObject* poSelf, PyObject* poArgs)
{
	int selectSlot = 0;
	if (!PyTuple_GetInteger(poArgs, 0, &selectSlot))
		return Py_BadArgument();

	int slotIndex = 0;
	if (!PyTuple_GetInteger(poArgs, 1, &slotIndex))
		return Py_BadArgument();

	CPythonPlayer::Instance().SetItemCombinationWindowActivedItemSlot(selectSlot, slotIndex);

	return Py_BuildNone();
}


PyObject* playerGetInvenSlotAttachedToConbWindowSlot(PyObject* poSelf, PyObject* poArgs)
{
	int selectSlot;
	if (!PyTuple_GetInteger(poArgs, 0, &selectSlot))
		return Py_BuildException();

	int iSlotIndex = CPythonPlayer::Instance().GetInvenSlotAttachedToConbWindowSlot(selectSlot);
		
	return Py_BuildValue("i", iSlotIndex);
}

PyObject* playerGetConbWindowSlotByAttachedInvenSlot(PyObject* poSelf, PyObject* poArgs)
{
	int slotIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &slotIndex))
		return Py_BuildException();

	int slot = CPythonPlayer::Instance().GetConbWindowSlotByAttachedInvenSlot(slotIndex);

	return Py_BuildValue("i", slot);
}
#endif

// Search for:
		{ "SendDragonSoulRefine",		playerSendDragonSoulRefine,			METH_VARARGS },

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		{ "SetItemCombinationWindowActivedItemSlot",		playerSetItemCombinationWindowActivedItemSlot,		METH_VARARGS },
		{ "GetInvenSlotAttachedToConbWindowSlot",			playerGetInvenSlotAttachedToConbWindowSlot,			METH_VARARGS },
		{ "GetConbWindowSlotByAttachedInvenSlot",			playerGetConbWindowSlotByAttachedInvenSlot,			METH_VARARGS },
#endif

// Search for:
	PyModule_AddIntConstant(poModule, "SLOT_TYPE_DRAGON_SOUL_INVENTORY",	SLOT_TYPE_DRAGON_SOUL_INVENTORY);

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_MEDIUM",				COMB_WND_SLOT_MEDIUM);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_BASE",					COMB_WND_SLOT_BASE);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_MATERIAL",				COMB_WND_SLOT_MATERIAL);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_RESULT",				COMB_WND_SLOT_RESULT);
	PyModule_AddIntConstant(poModule, "COMB_WND_SLOT_MAX",					COMB_WND_SLOT_MAX);
#endif