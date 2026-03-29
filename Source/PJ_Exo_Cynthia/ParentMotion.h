#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomMotion.h"
#include "ParentMotion.generated.h"

UENUM(BlueprintType)
enum class ERotationAxis : uint8
{
	X,
	Y,
	Z
};

UCLASS()
class PJ_EXO_CYNTHIA_API AParentMotion : public AActor
{
	GENERATED_BODY()

public:
	AParentMotion();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	ERotationAxis Axis = ERotationAxis::Z;

	UPROPERTY(EditAnywhere)
	float Speed = 90.f;

	UPROPERTY(EditAnywhere)
	AActor* Target;

private:

	float AngleAccumulated = 0.f;

	void RotateActor(float DeltaTime);
};