// Fill out your copyright notice in the Description page of Project Settings.


#include "MPCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMPCharacter::AMPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AMPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMPCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called every frame
void AMPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMPCharacter::MoveForward);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

