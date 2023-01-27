// Search for:
int CInputMain::Analyze(LPDESC d, BYTE bHeader, const char * c_pData)
{
	
// Add before:
#ifdef ENABLE_MOVE_COSTUME_ATTR
void CInputMain::MoveCostume(LPCHARACTER ch, const char* c_pData)
{
	quest::PC* pPC = quest::CQuestManager::instance().GetPCForce(ch->GetPlayerID());
	if (pPC->IsRunning())
		return;

	const TMoveCostumeAttr* p = reinterpret_cast<const TMoveCostumeAttr*>(c_pData);

	ch->MoveCostumeAttr(p->slotMedium, p->slotBase, p->slotMaterial);
}
#endif

// Search for:
		case HEADER_CG_REFINE:
			Refine(ch, c_pData);
			break;

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		case HEADER_CG_MOVE_COSTUME_ATTR:
			MoveCostume(ch, c_pData);
			break;
#endif