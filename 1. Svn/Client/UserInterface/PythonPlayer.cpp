// Search for:
bool CPythonPlayer::IsEquipItemInSlot(TItemPos Cell)
{
	if (!Cell.IsEquipCell())
	{
		return false;
	}

	const TItemData * pData = GetItemData(Cell);
	
	if (NULL == pData)
	{
		return false;
	}

	DWORD dwItemIndex = pData->vnum;

	CItemManager::Instance().SelectItemData(dwItemIndex);
	CItemData * pItemData = CItemManager::Instance().GetSelectedItemDataPointer();
	if (!pItemData)
	{
		TraceError("Failed to find ItemData - CPythonPlayer::IsEquipItem(window_type=%d, iSlotindex=%d)\n", Cell.window_type, Cell.cell);
		return false;
	}

	return pItemData->IsEquipment() ? true : false;
}

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
void CPythonPlayer::SetItemCombinationWindowActivedItemSlot(int selectSlot, int slotIndex)
{
	m_tMoveCostumeAttrs[selectSlot] = slotIndex;
}

int CPythonPlayer::GetInvenSlotAttachedToConbWindowSlot(int selectSlot)
{
	if (m_tMoveCostumeAttrs.size())
	{
		for (TMoveCostumeAttrs::iterator it = m_tMoveCostumeAttrs.begin(); it != m_tMoveCostumeAttrs.end(); ++it)
		{
			if (it->first == selectSlot)
				return it->second;
		}
	}

	return -1;
}

int CPythonPlayer::GetConbWindowSlotByAttachedInvenSlot(int slotIndex)
{
	if (m_tMoveCostumeAttrs.size())
	{
		for (TMoveCostumeAttrs::iterator it = m_tMoveCostumeAttrs.begin(); it != m_tMoveCostumeAttrs.end(); ++it)
		{
			if (it->second == slotIndex)
				return it->first;
		}
	}

	return COMB_WND_SLOT_MAX;
}
#endif

// Search for:
	m_RevengeInstanceSet.clear();

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	m_tMoveCostumeAttrs.clear();
#endif