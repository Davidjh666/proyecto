#include "ProyectoCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "ProyectoGameMode.h"

AProyectoCharacter::AProyectoCharacter()
{
    // Set size for collision capsule
    GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

    // Don't rotate when the controller rotates.
    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    // Create a camera boom attached to the root (capsule)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
    CameraBoom->bDoCollisionTest = false;
    CameraBoom->TargetArmLength = 500.f;
    CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
    CameraBoom->SetRelativeRotation(FRotator(0.f, 180.f, 0.f));

    // Create a camera and attach to boom
    SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
    SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

    // Configure character movement
    GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
    GetCharacterMovement()->GravityScale = 2.f;
    GetCharacterMovement()->AirControl = 0.80f;
    GetCharacterMovement()->JumpZVelocity = 1000.f;
    GetCharacterMovement()->GroundFriction = 3.f;
    GetCharacterMovement()->MaxWalkSpeed = 600.f;
    GetCharacterMovement()->MaxFlySpeed = 600.f;

    // Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character)
    // are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)

   // Register overlap event
    GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AProyectoCharacter::OnOverlapBegin);

}

void AProyectoCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    // set up gameplay key bindings
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
    PlayerInputComponent->BindAxis("MoveRight", this, &AProyectoCharacter::MoveRight);
    PlayerInputComponent->BindTouch(IE_Pressed, this, &AProyectoCharacter::TouchStarted);
    PlayerInputComponent->BindTouch(IE_Released, this, &AProyectoCharacter::TouchStopped);
}

void AProyectoCharacter::BeginPlay()
{
    Super::BeginPlay();
    // Set the spawn location
    FVector SpawnLocation(1206.6f, 500.0f, 700.0f); // Replace these values with your desired coordinates
    SetActorLocation(SpawnLocation);
}

void AProyectoCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{ // Print log to ensure this method is being called
    UE_LOG(LogTemp, Warning, TEXT("Overlap detected with %s"), *OtherActor->GetName());

    // Check if the overlapping actor is the platform (or tag it appropriately)
    if (OtherActor && (OtherActor != this) && OtherComp)
    {
        if (OtherActor->ActorHasTag("Plataforma"))
        {
            UE_LOG(LogTemp, Warning, TEXT("Touched Platform - Destroying"));
            Destroy();
        }
    }
}



void AProyectoCharacter::MoveRight(float Value)
{
    // add movement in that direction
    AddMovementInput(FVector(0.f, -1.f, 0.f), Value);
}

void AProyectoCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
    // jump on any touch
    Jump();
}

void AProyectoCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
    StopJumping();
}
