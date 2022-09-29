// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaComponentVisualizer.h"

void FAreaComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
	FPrimitiveDrawInterface* PDI)
{
	FComponentVisualizer::DrawVisualization(Component, View, PDI);
}
