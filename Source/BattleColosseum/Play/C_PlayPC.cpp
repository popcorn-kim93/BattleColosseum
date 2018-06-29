// Fill out your copyright notice in the Description page of Project Settings.

#include "C_PlayPC.h"
#include "Kismet/GameplayStatics.h"
#include "C_SaveGame.h"
#include "UnrealNetwork.h"
#include "Play/C_PlayGM.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

void AC_PlayPC::Load() {
	SaveGameRef = Cast<UC_SaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SAVEGAME"), 0));
	if (SaveGameRef) {
		MyInfo = SaveGameRef->MyInfo;
	}
}

void AC_PlayPC::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AC_PlayPC, MyInfo);
}

bool AC_PlayPC::PassCharacterToServer_Validate(FC_S_PlayerInfo NewInfo)
{
	return true;
}
void AC_PlayPC::PassCharacterToServer_Implementation(FC_S_PlayerInfo NewInfo) {
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("2. PassCharacterToServer Call"), true, true, FLinearColor(0.3f, 1.f, 0.3f, 1.f), 10.f);
	MyInfo = NewInfo;
	AC_PlayGM* GM = Cast<AC_PlayGM>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GM) {
		GM->SpawnCharacter_WaitTime(this, MyInfo.SelectCharacter.GameCharacter);
	}

}

bool AC_PlayPC::PossessingPawn_Validate(APawn* TargetPawn)
{
	return true;
}
void AC_PlayPC::PossessingPawn_Implementation(APawn* TargetPawn) {
	Possess(TargetPawn);
	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("PlayPC PossessCall!!"), true, true, FLinearColor(0.3f, 1.f, 0.3f, 1.f), 10.f);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("%s is TargetPawn - 1"), *(TargetPawn->GetName())));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("%s is Possess Pawn Name of PlayPC - 1"), *(GetPawn()->GetName())));
}