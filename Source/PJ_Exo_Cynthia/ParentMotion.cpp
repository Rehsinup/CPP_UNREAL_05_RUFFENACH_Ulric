#include "ParentMotion.h"

AParentMotion::AParentMotion()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AParentMotion::BeginPlay()
{
	Super::BeginPlay();
}

void AParentMotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotateActor(DeltaTime);

	if (Target && Target->GetClass()->ImplementsInterface(UCustomMotion::StaticClass()))
	{
		ICustomMotion::Execute_HorizontalLookAtActor(Target, this);

		if (AngleAccumulated >= 360.f)
		{
			ICustomMotion::Execute_TranslateFromRotationForward(
				Target,
				GetActorRotation(),
				200.f
			);

			AngleAccumulated = 0.f;
		}
	}
}

void AParentMotion::RotateActor(float DeltaTime)
{
	float DeltaAngle = Speed * DeltaTime;
	AngleAccumulated += DeltaAngle;

	FRotator Rotation = GetActorRotation();

	switch (Axis)
	{
	case ERotationAxis::X:
		Rotation.Roll += DeltaAngle;
		break;

	case ERotationAxis::Y:
		Rotation.Pitch += DeltaAngle;
		break;

	case ERotationAxis::Z:
		Rotation.Yaw += DeltaAngle;
		break;
	}

	SetActorRotation(Rotation);
}