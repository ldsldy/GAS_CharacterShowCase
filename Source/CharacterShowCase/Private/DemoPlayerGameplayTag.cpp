// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoPlayerGameplayTag.h"

namespace DemoPlayerGameplayTag
{
    // 인풋 액션 태그
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "Input.Action.Move");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "Input.Action.Look");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Interact, "Input.Action.Interact");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Dash, "Input.Action.Dash");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_1, "Input.Action.Skill.1");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_2, "Input.Action.Skill.2");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_3, "Input.Action.Skill.3");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_4, "Input.Action.Skill.4");

    // 어빌리티 태그
    UE_DEFINE_GAMEPLAY_TAG(Player_Combat_Attack, "Player.Combat.Attack");
    UE_DEFINE_GAMEPLAY_TAG(Player_Combat_Dash, "Player.Combat.Dash");
    UE_DEFINE_GAMEPLAY_TAG(Player_Combat_Skill, "Player.Combat.Skill");

    // 플레이어 무기 태그
    UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_DimesionStaff, "Player.Weapon.DimesionStaff");
    UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");

    // 이벤트 트리거 태그
    UE_DEFINE_GAMEPLAY_TAG(Player_Event_Attack, "Player.Event.Attack");
}