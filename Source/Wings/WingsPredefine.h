// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWingsTeam_t:uint8
{
    WINGS_TEAM_GOODGUYS UMETA(DisplayName = "我是好人"),//DisPlayName表示显示的名称，在蓝图中可见,
    WINGS_TEAM_BUDGUYS UMETA(DisplayName = "我是坏人"),
    WINGS_TEAM_NEUTRALS UMETA(DisplayName = "我保持中立"),
    WINGS_TEAM_PEACE UMETA(DisplayName = "我爱好和平")
};