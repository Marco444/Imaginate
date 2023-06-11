#ifndef ABSTRACT_SYNTAX_TREE_HEADER
#define ABSTRACT_SYNTAX_TREE_HEADER

#include <stdlib.h>

typedef struct ProgramNode {
    struct AssignmentsNode* assignments;
    struct DefinitionsNode* definitions;
    struct ImaginateNode* imaginate;
} ProgramNode;

typedef struct AssignmentsNode {
    struct AssignmentNode* assignment;
    struct AssignmentsNode* next;
} AssignmentsNode;

typedef struct DefinitionsNode {
    struct DefinitionNode* definition;
    struct DefinitionsNode* next;
} DefinitionsNode;

typedef struct ImaginateNode {
    struct FocusNode* focus;
    struct ForEachFocusNode * focuses;
    struct MethodChainNode* methodChain;
    struct RenderNode* render;
} ImaginateNode;

typedef struct AssignmentNode {
  	struct IdentifierNode * identifier;
    struct ValueNode * expression;
} AssignmentNode;

typedef struct DefinitionNode {
  	struct IdentifierNode * identifier;
    struct ArgumentsBlockNode * args;
    struct MethodChainNode * methodChain;
} DefinitionNode;

typedef struct FocusNode {
    struct ParamsBlockNode * var;
} FocusNode;

typedef struct ForEachFocusNode {
    //struct ValueNode * * var; //un arreglo de values almacen
    struct ParamsBlockNode * var;
} ForEachFocusNode ;

typedef struct MethodChainNode {
    struct MethodNode* method;
    struct MethodChainNode* next;
} MethodChainNode;

enum renderType{
    RENDER__,
    RENDERALL__
};

typedef struct RenderNode {
    enum renderType type;
} RenderNode;


typedef struct ExpressionNode{
} ExpressionNode;

typedef struct IdentifierNode {
    char* name;
} IdentifierNode;

typedef struct ValueNode {
    enum {INT_VALUE, STRING_VALUE, OBJECT_VALUE} type;
    union {
        int intValue;
        char* stringValue;
        IdentifierNode* objectValue;
    } value;
} ValueNode;

typedef struct ParamNode {
    ValueNode* value;
} ParamNode;

typedef struct ArgumentNode {
    ValueNode* value;
} ArgumentNode;

typedef struct ArgumentsNode {
    ArgumentNode * arg;
    struct ArgumentsNode * next;
} ArgumentsNode ;


typedef struct ParamsNode {
    ParamNode * param;
    struct ParamsNode* next;
} ParamsNode;

typedef struct ParamsBlockNode {
   struct ParamsNode * params; 
} ParamsBlockNode;

typedef struct ArgumentsBlockNode{
   struct ArgumentsNode * params; 
} ArgumentsBlockNode;
 
typedef struct OptionalNode {
    int isQuestionMarkPresent; 
} OptionalNode;

typedef struct MethodIdentifierNode {
    enum {CUSTOM_METHOD, ADDBLACKANDWHITE_METHOD, ADDCONTRAST_METHOD, ADDGRAYSCALE_METHOD, ADDBACKGROUND_METHOD, ADDFLAVOUR_METHOD, PICKFLAVOUR_METHOD} type;
    union{
        char * name;
        int id;
    } value;
} MethodIdentifierNode;

typedef struct EmptyParamsNode {
    int isEmpty; 
} EmptyParamsNode;

typedef struct MethodNode {
    OptionalNode * optional;
    MethodIdentifierNode * identifier;
    ParamsBlockNode * params;
    DefinitionNode * definition; 
} MethodNode;

typedef struct CustomMethodIdentifierNode {
    char* name;
} CustomMethodIdentifierNode;


typedef struct ObjectContentNode {
    struct ObjectContentNode* next;
    struct ObjectAssignmentNode* assignment;
} ObjectContentNode;


typedef struct ObjectNode {
    ObjectContentNode * content;
} ObjectNode;


typedef struct ObjectAssignmentNode {
    IdentifierNode* variable;
    IdentifierNode * rightHandIdentifier;
    ValueNode* rightHandValue;
} ObjectAssignmentNode;

typedef struct ObjectElementNode {
    IdentifierNode* identifier;
    IdentifierNode * value;
} ObjectElementNode;

typedef struct InlineObjectNode {
    ObjectContentNode* content;
} InlineObjectNode;
#endif
