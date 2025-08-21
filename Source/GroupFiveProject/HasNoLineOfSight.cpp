// Fill out your copyright notice in the Description page of Project Settings.


#include "HasNoLineOfSight.h"
#include "AIController.h"
#include"BehaviorTree/BlackboardComponent.h"

bool UHasNoLineOfSight::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	if (AAIController* AIController = OwnerComp.GetAIOwner())
	{
		if (UBlackboardComponent* Blackboard = AIController->GetBlackboardComponent())
		{
			if (AActor* TargetActor = Cast<AActor>(Blackboard->GetValueAsObject(TargetKey.SelectedKeyName)))
			{
				return !AIController->LineOfSightTo(TargetActor);
			}
		}
	}
	return true;
}
