// Search for:
		bool	GetOwnership(DWORD dwVID, const char ** c_pszName);

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		const char* GetItemNameByVnum(int itemVnum);
#endif