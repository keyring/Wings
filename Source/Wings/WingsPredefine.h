// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWingsTeam_t:uint8
{
    WINGS_TEAM_GOODGUYS UMETA(DisplayName = "���Ǻ���"),//DisPlayName��ʾ��ʾ�����ƣ�����ͼ�пɼ�,
    WINGS_TEAM_BUDGUYS UMETA(DisplayName = "���ǻ���"),
    WINGS_TEAM_NEUTRALS UMETA(DisplayName = "�ұ�������"),
    WINGS_TEAM_PEACE UMETA(DisplayName = "�Ұ��ú�ƽ")
};