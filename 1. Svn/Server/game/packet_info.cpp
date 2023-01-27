// Search for:
	Set(HEADER_CG_STATE_CHECKER, sizeof(BYTE), "ServerStateCheck", false);

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	Set(HEADER_CG_MOVE_COSTUME_ATTR, sizeof(TMoveCostumeAttr), "MoveCostumeAttr", true);
#endif