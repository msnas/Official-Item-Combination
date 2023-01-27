// Search for:
PyObject* netRegisterErrorLog(PyObject* poSelf, PyObject* poArgs)
{
	char * szLog;
	if (!PyTuple_GetString(poArgs, 0, &szLog))
		return Py_BuildException();

	return Py_BuildNone();
}

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
PyObject* netSendItemCombinationPacket(PyObject* poSelf, PyObject* poArgs)
{
	TItemPos slotMediumPos;
	if (!PyTuple_GetInteger(poArgs, 0, &slotMediumPos.cell))
		return Py_BuildException();

	TItemPos slotBasePos;
	if (!PyTuple_GetInteger(poArgs, 1, &slotBasePos.cell))
		return Py_BuildException();

	TItemPos slotMaterialPos;
	if (!PyTuple_GetInteger(poArgs, 2, &slotMaterialPos.cell))
		return Py_BuildException();

	CPythonNetworkStream& rns = CPythonNetworkStream::Instance();
	rns.SendItemCombinationPacket(slotMediumPos, slotBasePos, slotMaterialPos);

	return Py_BuildNone();
}
#endif

// Search for:
		{ "RegisterErrorLog",						netRegisterErrorLog,						METH_VARARGS },

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		{ "SendItemCombinationPacket",				netSendItemCombinationPacket,						METH_VARARGS },
#endif