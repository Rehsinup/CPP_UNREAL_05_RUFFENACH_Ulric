#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CustomMotion.generated.h"

UINTERFACE(BlueprintType)
class UCustomMotion : public UInterface
{
	GENERATED_BODY()
};

class PJ_EXO_CYNTHIA_API ICustomMotion
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TranslateFromRotationForward(FRotator Rotation, float Distance);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HorizontalLookAtActor(AActor* Actor);
};