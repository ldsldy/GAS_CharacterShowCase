// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoPlayerGameplayTag.h"

namespace DemoPlayerGameplayTag
{
    // 인풋 액션 태그
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Interact, "InputTag.Interact");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Dash, "InputTag.Dash");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_1, "InputTag.Skill.1");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_2, "InputTag.Skill.2");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_3, "InputTag.Skill.3");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_Skill_4, "InputTag.Skill.4");
    UE_DEFINE_GAMEPLAY_TAG(InputTag_TestEquip, "InputTag.TestEquip");

    
    // 어빌리티 태그
    UE_DEFINE_GAMEPLAY_TAG(Player_Combat_Attack, "Player.Combat.Attack");
    UE_DEFINE_GAMEPLAY_TAG(Player_Combat_Dash, "Player.Combat.Dash");
    UE_DEFINE_GAMEPLAY_TAG(Player_Combat_Skill, "Player.Combat.Skill");

    // 플레이어 무기 태그
    UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_DimesionStaff, "Player.Weapon.DimesionStaff");
    UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_FireStaff, "Player.Weapon.FireStaff");
    UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe, "Player.Weapon.Axe");

    // 이벤트 트리거 태그
    UE_DEFINE_GAMEPLAY_TAG(Player_Event_Attack, "Player.Event.Attack");
}