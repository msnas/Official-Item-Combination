// Search for:
bool CPythonItem::GetOwnership(DWORD dwVID, const char ** c_pszName)
{
	TGroundItemInstanceMap::iterator itor = m_GroundItemInstanceMap.find(dwVID);

	if (m_GroundItemInstanceMap.end() == itor)
		return false;

	TGroundItemInstance * pGroundItemInstance = itor->second;
	*c_pszName = pGroundItemInstance->stOwnership.c_str();

	return true;
}

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
const char* CPythonItem::GetItemNameByVnum(int itemVnum)
{
	CItemData* pkItemData;
	if (!CItemManager::Instance().GetItemDataPointer(itemVnum, &pkItemData))
		return "";

	return pkItemData->GetName();
}
#endif
