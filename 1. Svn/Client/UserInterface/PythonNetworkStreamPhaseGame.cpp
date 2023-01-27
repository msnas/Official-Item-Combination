// Search for:
bool CPythonNetworkStream::SendDragonSoulRefinePacket(BYTE bRefineType, TItemPos* pos)
{
	TPacketCGDragonSoulRefine pk;
	pk.header = HEADER_CG_DRAGON_SOUL_REFINE;
	pk.bSubType = bRefineType;
	memcpy (pk.ItemGrid, pos, sizeof (TItemPos) * DS_REFINE_WINDOW_MAX_NUM);
	if (!Send(sizeof (pk), &pk))
	{
		return false;
	}
	return true;
}

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
bool CPythonNetworkStream::SendItemCombinationPacket(TItemPos slotMedium, TItemPos slotBase, TItemPos slotMaterial)
{
	if (!__CanActMainInstance())
		return true;

	TMoveCostumeAttr moveCostume;
	moveCostume.header = HEADER_CG_MOVE_COSTUME_ATTR;
	moveCostume.slotMedium = slotMedium;
	moveCostume.slotBase = slotBase;
	moveCostume.slotMaterial = slotMaterial;

	if (!Send(sizeof(moveCostume), &moveCostume))
		return false;

	return SendSequence();
}
#endif
