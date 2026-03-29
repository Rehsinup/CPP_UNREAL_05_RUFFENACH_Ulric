#include "ChildMotion.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AChildMotion::AChildMotion()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Game/LevelPrototyping/Meshes/SM_Cube.SM_Cube"));
	if (Cube.Succeeded())
	{
		Mesh->SetStaticMesh(Cube.Object);
	}
}

void AChildMotion::BeginPlay()
{
	Super::BeginPlay();
}

void AChildMotion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AChildMotion::TranslateFromRotationForward_Implementation(FRotator Rotation, float Distance)
{
	FVector Direction = Rotation.Vector();
	FVector NewLocation = GetActorLocation() + Direction * Distance;

	SetActorLocation(NewLocation);
}

void AChildMotion::HorizontalLookAtActor_Implementation(AActor* Actor)
{
	if (!Actor) return;

	FVector Start = GetActorLocation();
	FVector Target = Actor->GetActorLocation();

	Target.Z = Start.Z;

	FRotator LookAt = (Target - Start).Rotation();

	SetActorRotation(LookAt);
}