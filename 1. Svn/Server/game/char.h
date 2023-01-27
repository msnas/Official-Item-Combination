// Search for:
	public:
		void			SetLastSyncTime(const timeval &tv) { memcpy(&m_tvLastSyncTime, &tv, sizeof(timeval)); }
		const timeval&	GetLastSyncTime() { return m_tvLastSyncTime; }
		void			SetSyncHackCount(int iCount) { m_iSyncHackCount = iCount;}
		int				GetSyncHackCount() { return m_iSyncHackCount; }

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
	private:
		enum MOVE_COSTUME_INDEX
		{
			ACCE_SUCCESS = 1,
			ACCE_PARTIAL_SUCCESS,
			ACCE_FAILED,

			COSTUME_SUCCESS,
		};
	public:
		void	MoveCostumeAttr(TItemPos slotMedium, TItemPos slotBase, TItemPos slotMaterial);
		void	SetBonusTransfer(int index, LPITEM medium, LPITEM base, LPITEM material);
#endif
