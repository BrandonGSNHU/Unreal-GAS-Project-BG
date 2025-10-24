// Fill out your copyright notice in the Description page of Project Settings.


#include "N_Character_Base.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
//#include "Project_N_Tutorial/GameplayAbilitySystem/Attributes/BasicAttributeSet.h"

// Sets default values
AN_Character_Base::AN_Character_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Add the Ability System Component
	// First we create our default subobject for the Ability System Component. This is basically 
	// adding the component to our character and naming it "AbilitySystemComponent".
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	// Then we set the component to be replicated and set the replication mode to Mixed.
	// Replication mode defines what kind of things should be replicated from server to client.
	// Mixed means a lot of things will be replicated, documentation recommends mixed for characters but minimal for enemies
	// Since we need this to work for both character and our enemy we need it to be a variable we can change
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(ASCReplicationMode);


	// Add the default values for player character and enemy starting points

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(35.0f, 90.0f);

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	// Character moves in the direction of input
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// At this rotation rate
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); 
	
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.0f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Add the basic attribute set
	BasicAttributeSet = CreateDefaultSubobject<UBasicAttributeSet>(TEXT("BasicAttributeSet"));

	// Add the Heal and Damage attribute set
	HealAndDmgAttributeSet = CreateDefaultSubobject<UHealAndDmgAttributeSet>(TEXT("HealAndDmgAttributeSet"));

}

UAbilitySystemComponent* AN_Character_Base::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

// Called when the game starts or when spawned
void AN_Character_Base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AN_Character_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AN_Character_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AN_Character_Base::PossessedBy(AController* NewController)
{
	// Call the super which is the parent implementation 
	Super::PossessedBy(NewController);
	// This is called on the server when the AIController possesses the enemy
	if (AbilitySystemComponent)
	{
		// If the Ability System Component is valid call the InitAbilityActorInfo function
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

void AN_Character_Base::OnRep_PlayerState()
{
	// Call the super which is the parent implementation 
	Super::OnRep_PlayerState();
	// This is called on the client when the PlayerState is replicated
	if (AbilitySystemComponent)
	{
		// If the Ability System Component is valid call the InitAbilityActorInfo function
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}
