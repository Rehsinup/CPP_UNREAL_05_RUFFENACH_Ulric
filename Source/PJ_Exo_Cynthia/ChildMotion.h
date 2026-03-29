#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomMotion.h"
#include "ChildMotion.generated.h"

UCLASS()
class PJ_EXO_CYNTHIA_API AChildMotion : public AActor, public ICustomMotion
{
	GENERATED_BODY()

public:
	AChildMotion();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void TranslateFromRotationForward_Implementation(FRotator Rotation, float Distance) override;
	virtual void HorizontalLookAtActor_Implementation(AActor* Actor) override;

private:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY()
	USceneComponent* Root;
};