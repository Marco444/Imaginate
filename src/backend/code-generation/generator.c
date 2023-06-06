#include "../support/logger.h"
#include "generator.h"

/**
 * Implementación de "generator.h".
 */

void Generator(ProgramNode * program) {
	LogInfo("Llegue al program Node .");

	generateImagenate(program->imaginate);
}
void generateImagenate(ImaginateNode * imaginateNode){
	LogInfo("Llegue al imaginate Node .");
	generateFocus(imaginateNode->focus);
	generateForEachFocus(imaginateNode->focuses);
	generateMethodChain(imaginateNode->methodChain);
	generateRender(imaginateNode->render);
}
void generateForEachFocus(ForEachFocusNode * forEachFocusNode){
	LogInfo("Llegue al forEachFocus Node .");
	//TODO Fijase que forEachFocusNode->var es un arreglo de ValueNode
}
void generateFocus(FocusNode * focusNode){
	LogInfo("Llegue al focus Node .");
	generateValue(focusNode->var);

}
void generateMethodChain(MethodChainNode * methodChainNode){
	LogInfo("Llegue al methodChain Node .");
	generateMethod(methodChainNode->method);
	if(methodChainNode->next != NULL)
		generateMethodChain(methodChainNode->next);
}
void generateMethod(MethodNode * methodNode){
	LogInfo("Llegue al method Node .");
	//TODO Fijate que methodNode->params es un arreglo de ValueNode

	//TODO Fijate que methodNode->identifier es un arreglo tiene internamente un string
}
void generateValue(ValueNode * valueNode){
	LogInfo("Llegue al value Node .");
	switch (valueNode->type)
	{
	case INT_VALUE:
		LogInfo("Llegue al value Node con INT.");
		break;
	case STRING_VALUE:
		LogInfo("Llegue al value Node con STRING.");
		break;
	case OBJECT_VALUE:
		LogInfo("Llegue al value Node con OBJECT.");
		break;
	default:
		break;
	}
}
void generateRender(RenderNode * renderNode){
	LogInfo("Llegue al render Node .");
	switch (renderNode->type)
	{
	case RENDER__:
		LogInfo("Llegue al render Node con RENDER__.");
		break;
	case RENDERALL__:
		LogInfo("Llegue al render Node con RENDERALL__.");
		break;
	default:
		break;
	}
}