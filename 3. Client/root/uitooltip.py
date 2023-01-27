# Search for:
	def AppendRealTimeStartFirstUseLastTime(self, item, metinSlot, limitIndex):		
		useCount = metinSlot[1]
		endTime = metinSlot[0]

		if 0 == useCount:
			if 0 == endTime:
				(limitType, limitValue) = item.GetLimit(limitIndex)
				endTime = limitValue

			endTime += app.GetGlobalTimeStamp()
	
		self.AppendMallItemLastTime(endTime)

# Add after:
	if app.ENABLE_MOVE_COSTUME_ATTR:
		def SetResulItemAttrMove(self, baseSlotIndex, materialSlotIndex, window_type = player.INVENTORY):
			baseItemVnum = player.GetItemIndex(window_type, baseSlotIndex)
			
			if 0 == baseItemVnum:
				return

			materialItemVnum = player.GetItemIndex(window_type, materialSlotIndex)
			
			if 0 == materialItemVnum:
				return
				
			self.ClearToolTip()

			item.SelectItem(materialItemVnum)
			itemSubType = item.GetItemSubType()

			if itemSubType == item.COSTUME_TYPE_ACCE: #US86
				metinSlot = [player.GetItemMetinSocket(window_type, materialSlotIndex, i) for i in xrange(player.METIN_SOCKET_MAX_NUM)] 
			else:
				metinSlot = [player.GetItemMetinSocket(window_type, baseSlotIndex, i) for i in xrange(player.METIN_SOCKET_MAX_NUM)]

			attrSlot = [player.GetItemAttribute(window_type, materialSlotIndex, i) for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM)]

			self.AddItemData(baseItemVnum, metinSlot, attrSlot)
