// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AreaRenderSceneProxy.h"
#include "AreaVisComponent.h"
#include "Debug/DebugDrawComponent.h"
#include "UObject/Object.h"
#include "AreaRenderingComponent.generated.h"


UCLASS(Blueprintable, hidecategories=(Collision,Physics,Object,LOD,Lighting,TextureStreaming))
class AIMECHANICS_API UAreaRenderingComponent : public UPrimitiveComponent
{
	GENERATED_BODY()
public:
	UAreaRenderingComponent(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual FPrimitiveSceneProxy* CreateSceneProxy() override;
public:
	virtual FBoxSphereBounds CalcBounds(const FTransform& LocalToWorld) const override;

	virtual bool ShouldRecreateProxyOnUpdateTransform() const override { return true; }
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FEditorVisLine> Lines;
};
