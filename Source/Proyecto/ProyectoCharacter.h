#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ProyectoCharacter.generated.h"

UCLASS(config = Game)
class AProyectoCharacter : public ACharacter
{
    GENERATED_BODY()

    /** Side view camera */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* SideViewCameraComponent;

    /** Camera boom positioning the camera beside the character */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class USpringArmComponent* CameraBoom;

protected:
    /** Called for side to side input */
    void MoveRight(float Val);

    /** Handle touch inputs. */
    void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);
    void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

    // APawn interface
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
    // End of APawn interface

    virtual void BeginPlay() override;


    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
    AProyectoCharacter();

    /** Returns SideViewCameraComponent subobject **/
    FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
    /** Returns CameraBoom subobject **/
    FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
