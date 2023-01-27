// Search for:
int	CHARACTER::GetSkillPowerByLevel(int level, bool bMob) const
{
	return CTableBySkill::instance().GetSkillPowerByLevelFromType(GetJob(), GetSkillGroup(), MINMAX(0, level, SKILL_MAX_LEVEL), bMob); 
}

// Add after:
#ifdef ENABLE_MOVE_COSTUME_ATTR
void CHARACTER::MoveCostumeAttr(TItemPos slotMedium, TItemPos slotBase, TItemPos slotMaterial)
{
	LPITEM itemSlotMedium = GetItem(slotMedium);
	LPITEM itemSlotBase = GetItem(slotBase);
	LPITEM itemSlotMaterial = GetItem(slotMaterial);

	if (!itemSlotMedium || !itemSlotBase || !itemSlotMaterial)
		return;

	if (itemSlotMedium->GetType() != ITEM_MEDIUM)
		return;
	
	if (itemSlotMedium->GetSubType() == MEDIUM_MOVE_COSTUME_ACCE_ATTR) // #US86
	{
		if ((itemSlotBase->GetType() == ITEM_COSTUME && itemSlotBase->GetSubType() == COSTUME_ACCE)
			&& (itemSlotMaterial->GetType() == ITEM_COSTUME && itemSlotMaterial->GetSubType() == COSTUME_ACCE))
		{
			if (itemSlotBase->GetAttributeCount() > 0)
			{
				ChatPacket(CHAT_TYPE_INFO, "You cannot use a sash with a bonus for the target.");
				return;
			}

			if (itemSlotMaterial->GetSocket(ACCE_ABSORBED_SOCKET) == 0)
			{
				if (itemSlotMaterial->GetAttributeCount() == 0)
				{
					ChatPacket(CHAT_TYPE_INFO, "You cannot use a sash without a bonus as the source.");
					return;
				}
			}

			if (itemSlotBase->GetValue(ACCE_GRADE_VALUE_FIELD) != itemSlotMaterial->GetValue(ACCE_GRADE_VALUE_FIELD))
			{
				ChatPacket(CHAT_TYPE_INFO, "You cannot transfer the bonus as the sashes have different grades.");
				return;
			}

			if (itemSlotBase->GetSocket(ACCE_ABSORPTION_SOCKET) != itemSlotMaterial->GetSocket(ACCE_ABSORPTION_SOCKET))
			{
				ChatPacket(CHAT_TYPE_INFO, "You cannot transfer the bonus as the sashes have different absorption rates.");
				return;
			}

			int random = number(1, 3);
			SetBonusTransfer(random, itemSlotMedium, itemSlotBase, itemSlotMaterial);
		}

	}
	else if (itemSlotMedium->GetSubType() == MEDIUM_MOVE_COSTUME_ATTR)
	{
		if ((itemSlotBase->GetType() == ITEM_COSTUME && itemSlotBase->GetSubType() != COSTUME_ACCE)
			&& (itemSlotMaterial->GetType() == ITEM_COSTUME && itemSlotMaterial->GetSubType() != COSTUME_ACCE))
		{
			if ((itemSlotBase->GetType() == itemSlotMaterial->GetType()) && (itemSlotBase->GetSubType() == itemSlotMaterial->GetSubType()))
			{
				if (itemSlotMaterial->GetAttributeCount() == 0)
				{
					ChatPacket(CHAT_TYPE_INFO, "Target item doesn't have bonus.");
					return;
				}

				SetBonusTransfer(COSTUME_SUCCESS, itemSlotMedium, itemSlotBase, itemSlotMaterial);
			}
			else
				ChatPacket(CHAT_TYPE_INFO, "Both items doesn't have the same type and subtype.");
		}
	}
}

void CHARACTER::SetBonusTransfer(int index, LPITEM medium, LPITEM base, LPITEM material)
{
	switch (index)
	{
		case ACCE_SUCCESS:
		{
			base->SetSockets(material->GetSockets());
			base->SetAttributes(material->GetAttributes());
			base->UpdatePacket();

			ChatPacket(CHAT_TYPE_INFO, "Success! The bonus was transferred successfully.");
		}
		break;

		case ACCE_PARTIAL_SUCCESS:
		case ACCE_FAILED:
		{
			if (base->GetSocket(ACCE_ABSORPTION_SOCKET) > 1)
				base->SetSocket(ACCE_ABSORPTION_SOCKET, base->GetSocket(ACCE_ABSORPTION_SOCKET) - 1);

			if (index == ACCE_PARTIAL_SUCCESS)
			{
				base->SetSocket(ACCE_ABSORBED_SOCKET, material->GetSocket(ACCE_ABSORBED_SOCKET));

				for (int i = 0; i < ITEM_ATTRIBUTE_MAX_NUM; ++i)
				{
					if (material->GetAttributeValue(i))
					{
						short originalTypeValue = material->GetAttribute(i).sValue;
						double originalValue = ((double)originalTypeValue * 100) / material->GetSocket(ACCE_ABSORPTION_SOCKET);
						double newValue = (originalValue * base->GetSocket(ACCE_ABSORPTION_SOCKET)) / 100;

						base->SetForceAttribute(i, material->GetAttributeType(i), (short)newValue);
					}
				}

				ChatPacket(CHAT_TYPE_INFO, "Partial success! The absorption rate was reduced by 1%.");
			}
			else
				ChatPacket(CHAT_TYPE_INFO, "Failure! The absorption rate was reduced by 1%.");
		}
		break;

		case COSTUME_SUCCESS:
		{
			base->SetAttributes(material->GetAttributes());
			base->UpdatePacket();
			ChatPacket(CHAT_TYPE_INFO, "Success! The bonus was transferred successfully.");
		}
		break;
	}

	medium->SetCount(medium->GetCount() - 1);
	
	if (index != ACCE_FAILED)
		material->RemoveFromCharacter();
}
#endif
