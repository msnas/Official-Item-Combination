// Search for:
		enum EAutoPotionType
		{
			AUTO_POTION_TYPE_HP = 0,
			AUTO_POTION_TYPE_SP = 1,
			AUTO_POTION_TYPE_NUM
		};

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		typedef std::map<int, int> TMoveCostumeAttrs;
#endif

// Search for:
		bool	IsEquipItemInSlot(TItemPos iSlotIndex);

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		void	SetItemCombinationWindowActivedItemSlot(int selectSlot, int slotIndex);
		int		GetInvenSlotAttachedToConbWindowSlot(int selectSlot);
		int		GetConbWindowSlotByAttachedInvenSlot(int slotIndex);
#endif

// Search for:
		BOOL					m_sysIsLevelLimit;

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
		TMoveCostumeAttrs		m_tMoveCostumeAttrs;
#endif