
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from ../Source_Files/antlr/C.g4 by ANTLR 4.8


#include "CVisitor.h"

#include "CParser.h"


using namespace antlrcpp;
using namespace antlr4;

CParser::CParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CParser::~CParser() {
  delete _interpreter;
}

std::string CParser::getGrammarFileName() const {
  return "C.g4";
}

const std::vector<std::string>& CParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

CParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::FunctionDefinitionContext *> CParser::ProgramContext::functionDefinition() {
  return getRuleContexts<CParser::FunctionDefinitionContext>();
}

CParser::FunctionDefinitionContext* CParser::ProgramContext::functionDefinition(size_t i) {
  return getRuleContext<CParser::FunctionDefinitionContext>(i);
}

std::vector<CParser::FunctionDeclarationContext *> CParser::ProgramContext::functionDeclaration() {
  return getRuleContexts<CParser::FunctionDeclarationContext>();
}

CParser::FunctionDeclarationContext* CParser::ProgramContext::functionDeclaration(size_t i) {
  return getRuleContext<CParser::FunctionDeclarationContext>(i);
}

std::vector<CParser::C_statementContext *> CParser::ProgramContext::c_statement() {
  return getRuleContexts<CParser::C_statementContext>();
}

CParser::C_statementContext* CParser::ProgramContext::c_statement(size_t i) {
  return getRuleContext<CParser::C_statementContext>(i);
}


size_t CParser::ProgramContext::getRuleIndex() const {
  return CParser::RuleProgram;
}


antlrcpp::Any CParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

CParser::ProgramContext* CParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, CParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(109);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(106);
        functionDefinition();
        break;
      }

      case 2: {
        setState(107);
        functionDeclaration();
        break;
      }

      case 3: {
        setState(108);
        c_statement();
        break;
      }

      }
      setState(111); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::INT)
      | (1ULL << CParser::BOOL)
      | (1ULL << CParser::FLOAT)
      | (1ULL << CParser::VOID)
      | (1ULL << CParser::DO)
      | (1ULL << CParser::WHILE)
      | (1ULL << CParser::FOR)
      | (1ULL << CParser::IF)
      | (1ULL << CParser::PRINT)
      | (1ULL << CParser::PRINTLN)
      | (1ULL << CParser::READ)
      | (1ULL << CParser::READLN)
      | (1ULL << CParser::RETURN)
      | (1ULL << CParser::IDENTIFIER))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- C_statementContext ------------------------------------------------------------------

CParser::C_statementContext::C_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::StatementContext* CParser::C_statementContext::statement() {
  return getRuleContext<CParser::StatementContext>(0);
}

CParser::EmptyStatementContext* CParser::C_statementContext::emptyStatement() {
  return getRuleContext<CParser::EmptyStatementContext>(0);
}


size_t CParser::C_statementContext::getRuleIndex() const {
  return CParser::RuleC_statement;
}


antlrcpp::Any CParser::C_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitC_statement(this);
  else
    return visitor->visitChildren(this);
}

CParser::C_statementContext* CParser::c_statement() {
  C_statementContext *_localctx = _tracker.createInstance<C_statementContext>(_ctx, getState());
  enterRule(_localctx, 2, CParser::RuleC_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::T__7:
      case CParser::INT:
      case CParser::BOOL:
      case CParser::FLOAT:
      case CParser::VOID:
      case CParser::DO:
      case CParser::WHILE:
      case CParser::FOR:
      case CParser::IF:
      case CParser::PRINT:
      case CParser::PRINTLN:
      case CParser::READ:
      case CParser::READLN:
      case CParser::RETURN:
      case CParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        statement();
        setState(114);
        match(CParser::T__0);
        break;
      }

      case CParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(116);
        emptyStatement();
        setState(117);
        match(CParser::T__0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

CParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::AssignmentStatementContext* CParser::StatementContext::assignmentStatement() {
  return getRuleContext<CParser::AssignmentStatementContext>(0);
}

CParser::VariableDeclarationContext* CParser::StatementContext::variableDeclaration() {
  return getRuleContext<CParser::VariableDeclarationContext>(0);
}

CParser::ControlStatementContext* CParser::StatementContext::controlStatement() {
  return getRuleContext<CParser::ControlStatementContext>(0);
}

CParser::PrintStatementContext* CParser::StatementContext::printStatement() {
  return getRuleContext<CParser::PrintStatementContext>(0);
}

CParser::PrintlnStatementContext* CParser::StatementContext::printlnStatement() {
  return getRuleContext<CParser::PrintlnStatementContext>(0);
}

CParser::ReadStatementContext* CParser::StatementContext::readStatement() {
  return getRuleContext<CParser::ReadStatementContext>(0);
}

CParser::ReadlnStatementContext* CParser::StatementContext::readlnStatement() {
  return getRuleContext<CParser::ReadlnStatementContext>(0);
}

CParser::FunctionCallContext* CParser::StatementContext::functionCall() {
  return getRuleContext<CParser::FunctionCallContext>(0);
}

CParser::ReturnStatementContext* CParser::StatementContext::returnStatement() {
  return getRuleContext<CParser::ReturnStatementContext>(0);
}


size_t CParser::StatementContext::getRuleIndex() const {
  return CParser::RuleStatement;
}


antlrcpp::Any CParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::StatementContext* CParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, CParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(121);
      assignmentStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      variableDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      controlStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      printStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(125);
      printlnStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(126);
      readStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(127);
      readlnStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(128);
      functionCall();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(129);
      returnStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

CParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::EmptyStatementContext::getRuleIndex() const {
  return CParser::RuleEmptyStatement;
}


antlrcpp::Any CParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::EmptyStatementContext* CParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, CParser::RuleEmptyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

CParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeIdentifierContext* CParser::VariableDeclarationContext::typeIdentifier() {
  return getRuleContext<CParser::TypeIdentifierContext>(0);
}

std::vector<CParser::VariableIdentifierContext *> CParser::VariableDeclarationContext::variableIdentifier() {
  return getRuleContexts<CParser::VariableIdentifierContext>();
}

CParser::VariableIdentifierContext* CParser::VariableDeclarationContext::variableIdentifier(size_t i) {
  return getRuleContext<CParser::VariableIdentifierContext>(i);
}

std::vector<CParser::LengthContext *> CParser::VariableDeclarationContext::length() {
  return getRuleContexts<CParser::LengthContext>();
}

CParser::LengthContext* CParser::VariableDeclarationContext::length(size_t i) {
  return getRuleContext<CParser::LengthContext>(i);
}


size_t CParser::VariableDeclarationContext::getRuleIndex() const {
  return CParser::RuleVariableDeclaration;
}


antlrcpp::Any CParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::VariableDeclarationContext* CParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, CParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      typeIdentifier();
      setState(135);
      variableIdentifier();
      setState(140);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CParser::T__1) {
        setState(136);
        match(CParser::T__1);
        setState(137);
        variableIdentifier();
        setState(142);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(143);
      typeIdentifier();
      setState(144);
      variableIdentifier();
      setState(151);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == CParser::T__2) {
        setState(145);
        match(CParser::T__2);
        setState(146);
        length();
        setState(147);
        match(CParser::T__3);
        setState(153);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LengthContext ------------------------------------------------------------------

CParser::LengthContext::LengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::LengthContext::INTEGER() {
  return getToken(CParser::INTEGER, 0);
}


size_t CParser::LengthContext::getRuleIndex() const {
  return CParser::RuleLength;
}


antlrcpp::Any CParser::LengthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLength(this);
  else
    return visitor->visitChildren(this);
}

CParser::LengthContext* CParser::length() {
  LengthContext *_localctx = _tracker.createInstance<LengthContext>(_ctx, getState());
  enterRule(_localctx, 10, CParser::RuleLength);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(CParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

CParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::AssignmentStatementContext::getRuleIndex() const {
  return CParser::RuleAssignmentStatement;
}

void CParser::AssignmentStatementContext::copyFrom(AssignmentStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssignVariableContext ------------------------------------------------------------------

CParser::LhsContext* CParser::AssignVariableContext::lhs() {
  return getRuleContext<CParser::LhsContext>(0);
}

CParser::RhsContext* CParser::AssignVariableContext::rhs() {
  return getRuleContext<CParser::RhsContext>(0);
}

CParser::AssignVariableContext::AssignVariableContext(AssignmentStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::AssignVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAssignVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecrementVariableContext ------------------------------------------------------------------

CParser::VariableContext* CParser::DecrementVariableContext::variable() {
  return getRuleContext<CParser::VariableContext>(0);
}

CParser::DecrementVariableContext::DecrementVariableContext(AssignmentStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::DecrementVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDecrementVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncrementVariableContext ------------------------------------------------------------------

CParser::VariableContext* CParser::IncrementVariableContext::variable() {
  return getRuleContext<CParser::VariableContext>(0);
}

CParser::IncrementVariableContext::IncrementVariableContext(AssignmentStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::IncrementVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIncrementVariable(this);
  else
    return visitor->visitChildren(this);
}
CParser::AssignmentStatementContext* CParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, CParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AssignmentStatementContext *>(_tracker.createInstance<CParser::AssignVariableContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(158);
      lhs();
      setState(159);
      match(CParser::T__4);
      setState(160);
      rhs();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AssignmentStatementContext *>(_tracker.createInstance<CParser::IncrementVariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(162);
      variable();
      setState(163);
      match(CParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AssignmentStatementContext *>(_tracker.createInstance<CParser::DecrementVariableContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(165);
      variable();
      setState(166);
      match(CParser::T__6);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

CParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::VariableContext* CParser::LhsContext::variable() {
  return getRuleContext<CParser::VariableContext>(0);
}

CParser::VariableDeclarationContext* CParser::LhsContext::variableDeclaration() {
  return getRuleContext<CParser::VariableDeclarationContext>(0);
}


size_t CParser::LhsContext::getRuleIndex() const {
  return CParser::RuleLhs;
}


antlrcpp::Any CParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

CParser::LhsContext* CParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 14, CParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(170);
        variable();
        break;
      }

      case CParser::INT:
      case CParser::BOOL:
      case CParser::FLOAT:
      case CParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(171);
        variableDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

CParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::RhsContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::RhsContext::getRuleIndex() const {
  return CParser::RuleRhs;
}


antlrcpp::Any CParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

CParser::RhsContext* CParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 16, CParser::RuleRhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlScopeContext ------------------------------------------------------------------

CParser::ControlScopeContext::ControlScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::C_statementContext *> CParser::ControlScopeContext::c_statement() {
  return getRuleContexts<CParser::C_statementContext>();
}

CParser::C_statementContext* CParser::ControlScopeContext::c_statement(size_t i) {
  return getRuleContext<CParser::C_statementContext>(i);
}

std::vector<CParser::ControlStatementContext *> CParser::ControlScopeContext::controlStatement() {
  return getRuleContexts<CParser::ControlStatementContext>();
}

CParser::ControlStatementContext* CParser::ControlScopeContext::controlStatement(size_t i) {
  return getRuleContext<CParser::ControlStatementContext>(i);
}


size_t CParser::ControlScopeContext::getRuleIndex() const {
  return CParser::RuleControlScope;
}


antlrcpp::Any CParser::ControlScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitControlScope(this);
  else
    return visitor->visitChildren(this);
}

CParser::ControlScopeContext* CParser::controlScope() {
  ControlScopeContext *_localctx = _tracker.createInstance<ControlScopeContext>(_ctx, getState());
  enterRule(_localctx, 18, CParser::RuleControlScope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(CParser::T__7);
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__0)
      | (1ULL << CParser::T__7)
      | (1ULL << CParser::INT)
      | (1ULL << CParser::BOOL)
      | (1ULL << CParser::FLOAT)
      | (1ULL << CParser::VOID)
      | (1ULL << CParser::DO)
      | (1ULL << CParser::WHILE)
      | (1ULL << CParser::FOR)
      | (1ULL << CParser::IF)
      | (1ULL << CParser::PRINT)
      | (1ULL << CParser::PRINTLN)
      | (1ULL << CParser::READ)
      | (1ULL << CParser::READLN)
      | (1ULL << CParser::RETURN)
      | (1ULL << CParser::IDENTIFIER))) != 0)) {
      setState(179);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(177);
        c_statement();
        break;
      }

      case 2: {
        setState(178);
        controlStatement();
        break;
      }

      }
      setState(183);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(184);
    match(CParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlStatementContext ------------------------------------------------------------------

CParser::ControlStatementContext::ControlStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::DoWhileLoopContext* CParser::ControlStatementContext::doWhileLoop() {
  return getRuleContext<CParser::DoWhileLoopContext>(0);
}

CParser::WhileLoopContext* CParser::ControlStatementContext::whileLoop() {
  return getRuleContext<CParser::WhileLoopContext>(0);
}

CParser::ForLoopContext* CParser::ControlStatementContext::forLoop() {
  return getRuleContext<CParser::ForLoopContext>(0);
}

CParser::IfStatementContext* CParser::ControlStatementContext::ifStatement() {
  return getRuleContext<CParser::IfStatementContext>(0);
}

CParser::ControlScopeContext* CParser::ControlStatementContext::controlScope() {
  return getRuleContext<CParser::ControlScopeContext>(0);
}


size_t CParser::ControlStatementContext::getRuleIndex() const {
  return CParser::RuleControlStatement;
}


antlrcpp::Any CParser::ControlStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitControlStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::ControlStatementContext* CParser::controlStatement() {
  ControlStatementContext *_localctx = _tracker.createInstance<ControlStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, CParser::RuleControlStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::DO: {
        enterOuterAlt(_localctx, 1);
        setState(186);
        doWhileLoop();
        break;
      }

      case CParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(187);
        whileLoop();
        break;
      }

      case CParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(188);
        forLoop();
        break;
      }

      case CParser::IF: {
        enterOuterAlt(_localctx, 4);
        setState(189);
        ifStatement();
        break;
      }

      case CParser::T__7: {
        enterOuterAlt(_localctx, 5);
        setState(190);
        controlScope();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DoWhileLoopContext ------------------------------------------------------------------

CParser::DoWhileLoopContext::DoWhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::DoWhileLoopContext::DO() {
  return getToken(CParser::DO, 0);
}

CParser::ControlScopeContext* CParser::DoWhileLoopContext::controlScope() {
  return getRuleContext<CParser::ControlScopeContext>(0);
}

tree::TerminalNode* CParser::DoWhileLoopContext::WHILE() {
  return getToken(CParser::WHILE, 0);
}

CParser::ExpressionContext* CParser::DoWhileLoopContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::DoWhileLoopContext::getRuleIndex() const {
  return CParser::RuleDoWhileLoop;
}


antlrcpp::Any CParser::DoWhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDoWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

CParser::DoWhileLoopContext* CParser::doWhileLoop() {
  DoWhileLoopContext *_localctx = _tracker.createInstance<DoWhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 22, CParser::RuleDoWhileLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(CParser::DO);
    setState(194);
    controlScope();
    setState(195);
    match(CParser::WHILE);
    setState(196);
    match(CParser::T__9);
    setState(197);
    expression();
    setState(198);
    match(CParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileLoopContext ------------------------------------------------------------------

CParser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::WhileLoopContext::WHILE() {
  return getToken(CParser::WHILE, 0);
}

CParser::ExpressionContext* CParser::WhileLoopContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ControlScopeContext* CParser::WhileLoopContext::controlScope() {
  return getRuleContext<CParser::ControlScopeContext>(0);
}


size_t CParser::WhileLoopContext::getRuleIndex() const {
  return CParser::RuleWhileLoop;
}


antlrcpp::Any CParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

CParser::WhileLoopContext* CParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 24, CParser::RuleWhileLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(CParser::WHILE);
    setState(201);
    match(CParser::T__9);
    setState(202);
    expression();
    setState(203);
    match(CParser::T__10);
    setState(204);
    controlScope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForLoopContext ------------------------------------------------------------------

CParser::ForLoopContext::ForLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ForLoopContext::FOR() {
  return getToken(CParser::FOR, 0);
}

CParser::ExpressionContext* CParser::ForLoopContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ControlScopeContext* CParser::ForLoopContext::controlScope() {
  return getRuleContext<CParser::ControlScopeContext>(0);
}

std::vector<CParser::StatementContext *> CParser::ForLoopContext::statement() {
  return getRuleContexts<CParser::StatementContext>();
}

CParser::StatementContext* CParser::ForLoopContext::statement(size_t i) {
  return getRuleContext<CParser::StatementContext>(i);
}


size_t CParser::ForLoopContext::getRuleIndex() const {
  return CParser::RuleForLoop;
}


antlrcpp::Any CParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}

CParser::ForLoopContext* CParser::forLoop() {
  ForLoopContext *_localctx = _tracker.createInstance<ForLoopContext>(_ctx, getState());
  enterRule(_localctx, 26, CParser::RuleForLoop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(CParser::FOR);
    setState(207);
    match(CParser::T__9);
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__7)
      | (1ULL << CParser::INT)
      | (1ULL << CParser::BOOL)
      | (1ULL << CParser::FLOAT)
      | (1ULL << CParser::VOID)
      | (1ULL << CParser::DO)
      | (1ULL << CParser::WHILE)
      | (1ULL << CParser::FOR)
      | (1ULL << CParser::IF)
      | (1ULL << CParser::PRINT)
      | (1ULL << CParser::PRINTLN)
      | (1ULL << CParser::READ)
      | (1ULL << CParser::READLN)
      | (1ULL << CParser::RETURN)
      | (1ULL << CParser::IDENTIFIER))) != 0)) {
      setState(208);
      statement();
    }
    setState(211);
    match(CParser::T__0);
    setState(212);
    expression();
    setState(213);
    match(CParser::T__0);
    setState(215);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__7)
      | (1ULL << CParser::INT)
      | (1ULL << CParser::BOOL)
      | (1ULL << CParser::FLOAT)
      | (1ULL << CParser::VOID)
      | (1ULL << CParser::DO)
      | (1ULL << CParser::WHILE)
      | (1ULL << CParser::FOR)
      | (1ULL << CParser::IF)
      | (1ULL << CParser::PRINT)
      | (1ULL << CParser::PRINTLN)
      | (1ULL << CParser::READ)
      | (1ULL << CParser::READLN)
      | (1ULL << CParser::RETURN)
      | (1ULL << CParser::IDENTIFIER))) != 0)) {
      setState(214);
      statement();
    }
    setState(217);
    match(CParser::T__10);
    setState(218);
    controlScope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

CParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> CParser::IfStatementContext::IF() {
  return getTokens(CParser::IF);
}

tree::TerminalNode* CParser::IfStatementContext::IF(size_t i) {
  return getToken(CParser::IF, i);
}

std::vector<CParser::ExpressionContext *> CParser::IfStatementContext::expression() {
  return getRuleContexts<CParser::ExpressionContext>();
}

CParser::ExpressionContext* CParser::IfStatementContext::expression(size_t i) {
  return getRuleContext<CParser::ExpressionContext>(i);
}

std::vector<CParser::ControlScopeContext *> CParser::IfStatementContext::controlScope() {
  return getRuleContexts<CParser::ControlScopeContext>();
}

CParser::ControlScopeContext* CParser::IfStatementContext::controlScope(size_t i) {
  return getRuleContext<CParser::ControlScopeContext>(i);
}

std::vector<tree::TerminalNode *> CParser::IfStatementContext::ELSE() {
  return getTokens(CParser::ELSE);
}

tree::TerminalNode* CParser::IfStatementContext::ELSE(size_t i) {
  return getToken(CParser::ELSE, i);
}


size_t CParser::IfStatementContext::getRuleIndex() const {
  return CParser::RuleIfStatement;
}


antlrcpp::Any CParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::IfStatementContext* CParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, CParser::RuleIfStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(CParser::IF);
    setState(221);
    match(CParser::T__9);
    setState(222);
    expression();
    setState(223);
    match(CParser::T__10);
    setState(224);
    controlScope();
    setState(234);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(225);
        match(CParser::ELSE);
        setState(226);
        match(CParser::IF);
        setState(227);
        match(CParser::T__9);
        setState(228);
        expression();
        setState(229);
        match(CParser::T__10);
        setState(230);
        controlScope(); 
      }
      setState(236);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
    setState(239);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::ELSE) {
      setState(237);
      match(CParser::ELSE);
      setState(238);
      controlScope();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

CParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::FunctionDeclarationContext* CParser::FunctionDefinitionContext::functionDeclaration() {
  return getRuleContext<CParser::FunctionDeclarationContext>(0);
}

CParser::ControlScopeContext* CParser::FunctionDefinitionContext::controlScope() {
  return getRuleContext<CParser::ControlScopeContext>(0);
}


size_t CParser::FunctionDefinitionContext::getRuleIndex() const {
  return CParser::RuleFunctionDefinition;
}


antlrcpp::Any CParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionDefinitionContext* CParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 30, CParser::RuleFunctionDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    functionDeclaration();
    setState(242);
    controlScope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

CParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeIdentifierContext* CParser::FunctionDeclarationContext::typeIdentifier() {
  return getRuleContext<CParser::TypeIdentifierContext>(0);
}

CParser::FunctionIdentifierContext* CParser::FunctionDeclarationContext::functionIdentifier() {
  return getRuleContext<CParser::FunctionIdentifierContext>(0);
}

CParser::ParameterDeclarationsListContext* CParser::FunctionDeclarationContext::parameterDeclarationsList() {
  return getRuleContext<CParser::ParameterDeclarationsListContext>(0);
}

tree::TerminalNode* CParser::FunctionDeclarationContext::VOID() {
  return getToken(CParser::VOID, 0);
}


size_t CParser::FunctionDeclarationContext::getRuleIndex() const {
  return CParser::RuleFunctionDeclaration;
}


antlrcpp::Any CParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionDeclarationContext* CParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 32, CParser::RuleFunctionDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    typeIdentifier();
    setState(245);
    functionIdentifier();
    setState(246);
    match(CParser::T__9);
    setState(249);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(247);
      parameterDeclarationsList();
      break;
    }

    case 2: {
      setState(248);
      match(CParser::VOID);
      break;
    }

    }
    setState(251);
    match(CParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionIdentifierContext ------------------------------------------------------------------

CParser::FunctionIdentifierContext::FunctionIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::FunctionIdentifierContext::IDENTIFIER() {
  return getToken(CParser::IDENTIFIER, 0);
}


size_t CParser::FunctionIdentifierContext::getRuleIndex() const {
  return CParser::RuleFunctionIdentifier;
}


antlrcpp::Any CParser::FunctionIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionIdentifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionIdentifierContext* CParser::functionIdentifier() {
  FunctionIdentifierContext *_localctx = _tracker.createInstance<FunctionIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 34, CParser::RuleFunctionIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(CParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsListContext ------------------------------------------------------------------

CParser::ParameterDeclarationsListContext::ParameterDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::ParameterDeclarationContext *> CParser::ParameterDeclarationsListContext::parameterDeclaration() {
  return getRuleContexts<CParser::ParameterDeclarationContext>();
}

CParser::ParameterDeclarationContext* CParser::ParameterDeclarationsListContext::parameterDeclaration(size_t i) {
  return getRuleContext<CParser::ParameterDeclarationContext>(i);
}


size_t CParser::ParameterDeclarationsListContext::getRuleIndex() const {
  return CParser::RuleParameterDeclarationsList;
}


antlrcpp::Any CParser::ParameterDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterDeclarationsListContext* CParser::parameterDeclarationsList() {
  ParameterDeclarationsListContext *_localctx = _tracker.createInstance<ParameterDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 36, CParser::RuleParameterDeclarationsList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    parameterDeclaration();
    setState(260);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::T__1) {
      setState(256);
      match(CParser::T__1);
      setState(257);
      parameterDeclaration();
      setState(262);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

CParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::TypeIdentifierContext* CParser::ParameterDeclarationContext::typeIdentifier() {
  return getRuleContext<CParser::TypeIdentifierContext>(0);
}

CParser::ParameterIdentifierContext* CParser::ParameterDeclarationContext::parameterIdentifier() {
  return getRuleContext<CParser::ParameterIdentifierContext>(0);
}

std::vector<tree::TerminalNode *> CParser::ParameterDeclarationContext::ARRAYINDICATOR() {
  return getTokens(CParser::ARRAYINDICATOR);
}

tree::TerminalNode* CParser::ParameterDeclarationContext::ARRAYINDICATOR(size_t i) {
  return getToken(CParser::ARRAYINDICATOR, i);
}


size_t CParser::ParameterDeclarationContext::getRuleIndex() const {
  return CParser::RuleParameterDeclaration;
}


antlrcpp::Any CParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterDeclarationContext* CParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 38, CParser::RuleParameterDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    typeIdentifier();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::ARRAYINDICATOR) {
      setState(264);
      match(CParser::ARRAYINDICATOR);
      setState(269);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(270);
    parameterIdentifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdentifierContext ------------------------------------------------------------------

CParser::ParameterIdentifierContext::ParameterIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ParameterIdentifierContext::IDENTIFIER() {
  return getToken(CParser::IDENTIFIER, 0);
}


size_t CParser::ParameterIdentifierContext::getRuleIndex() const {
  return CParser::RuleParameterIdentifier;
}


antlrcpp::Any CParser::ParameterIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::ParameterIdentifierContext* CParser::parameterIdentifier() {
  ParameterIdentifierContext *_localctx = _tracker.createInstance<ParameterIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 40, CParser::RuleParameterIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(CParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

CParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ReturnStatementContext::RETURN() {
  return getToken(CParser::RETURN, 0);
}

CParser::ExpressionContext* CParser::ReturnStatementContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ReturnStatementContext::getRuleIndex() const {
  return CParser::RuleReturnStatement;
}


antlrcpp::Any CParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::ReturnStatementContext* CParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, CParser::RuleReturnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(274);
    match(CParser::RETURN);
    setState(276);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__9)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::IDENTIFIER)
      | (1ULL << CParser::INTEGER)
      | (1ULL << CParser::REAL)
      | (1ULL << CParser::CHARACTER)
      | (1ULL << CParser::STRING))) != 0)) {
      setState(275);
      expression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

CParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::FunctionIdentifierContext* CParser::FunctionCallContext::functionIdentifier() {
  return getRuleContext<CParser::FunctionIdentifierContext>(0);
}

CParser::ArgumentListContext* CParser::FunctionCallContext::argumentList() {
  return getRuleContext<CParser::ArgumentListContext>(0);
}


size_t CParser::FunctionCallContext::getRuleIndex() const {
  return CParser::RuleFunctionCall;
}


antlrcpp::Any CParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

CParser::FunctionCallContext* CParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 44, CParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    functionIdentifier();
    setState(279);
    match(CParser::T__9);
    setState(281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__9)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::IDENTIFIER)
      | (1ULL << CParser::INTEGER)
      | (1ULL << CParser::REAL)
      | (1ULL << CParser::CHARACTER)
      | (1ULL << CParser::STRING))) != 0)) {
      setState(280);
      argumentList();
    }
    setState(283);
    match(CParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

CParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::ArgumentContext *> CParser::ArgumentListContext::argument() {
  return getRuleContexts<CParser::ArgumentContext>();
}

CParser::ArgumentContext* CParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<CParser::ArgumentContext>(i);
}


size_t CParser::ArgumentListContext::getRuleIndex() const {
  return CParser::RuleArgumentList;
}


antlrcpp::Any CParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

CParser::ArgumentListContext* CParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 46, CParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    argument();
    setState(290);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::T__1) {
      setState(286);
      match(CParser::T__1);
      setState(287);
      argument();
      setState(292);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

CParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::ArgumentContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::ArgumentContext::getRuleIndex() const {
  return CParser::RuleArgument;
}


antlrcpp::Any CParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

CParser::ArgumentContext* CParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 48, CParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintStatementContext ------------------------------------------------------------------

CParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PrintStatementContext::PRINT() {
  return getToken(CParser::PRINT, 0);
}

CParser::PrintArgumentsContext* CParser::PrintStatementContext::printArguments() {
  return getRuleContext<CParser::PrintArgumentsContext>(0);
}


size_t CParser::PrintStatementContext::getRuleIndex() const {
  return CParser::RulePrintStatement;
}


antlrcpp::Any CParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrintStatementContext* CParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, CParser::RulePrintStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(295);
    match(CParser::PRINT);
    setState(296);
    match(CParser::T__9);
    setState(297);
    printArguments();
    setState(298);
    match(CParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintlnStatementContext ------------------------------------------------------------------

CParser::PrintlnStatementContext::PrintlnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::PrintlnStatementContext::PRINTLN() {
  return getToken(CParser::PRINTLN, 0);
}

CParser::PrintArgumentsContext* CParser::PrintlnStatementContext::printArguments() {
  return getRuleContext<CParser::PrintArgumentsContext>(0);
}


size_t CParser::PrintlnStatementContext::getRuleIndex() const {
  return CParser::RulePrintlnStatement;
}


antlrcpp::Any CParser::PrintlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrintlnStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrintlnStatementContext* CParser::printlnStatement() {
  PrintlnStatementContext *_localctx = _tracker.createInstance<PrintlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, CParser::RulePrintlnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
    match(CParser::PRINTLN);
    setState(301);
    match(CParser::T__9);
    setState(303);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__9)
      | (1ULL << CParser::T__12)
      | (1ULL << CParser::T__13)
      | (1ULL << CParser::IDENTIFIER)
      | (1ULL << CParser::INTEGER)
      | (1ULL << CParser::REAL)
      | (1ULL << CParser::CHARACTER)
      | (1ULL << CParser::STRING))) != 0)) {
      setState(302);
      printArguments();
    }
    setState(305);
    match(CParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintArgumentsContext ------------------------------------------------------------------

CParser::PrintArgumentsContext::PrintArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::PrintArgumentContext *> CParser::PrintArgumentsContext::printArgument() {
  return getRuleContexts<CParser::PrintArgumentContext>();
}

CParser::PrintArgumentContext* CParser::PrintArgumentsContext::printArgument(size_t i) {
  return getRuleContext<CParser::PrintArgumentContext>(i);
}


size_t CParser::PrintArgumentsContext::getRuleIndex() const {
  return CParser::RulePrintArguments;
}


antlrcpp::Any CParser::PrintArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrintArguments(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrintArgumentsContext* CParser::printArguments() {
  PrintArgumentsContext *_localctx = _tracker.createInstance<PrintArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 54, CParser::RulePrintArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    printArgument();
    setState(312);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::T__1) {
      setState(308);
      match(CParser::T__1);
      setState(309);
      printArgument();
      setState(314);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintArgumentContext ------------------------------------------------------------------

CParser::PrintArgumentContext::PrintArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::PrintArgumentContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::FieldWidthContext* CParser::PrintArgumentContext::fieldWidth() {
  return getRuleContext<CParser::FieldWidthContext>(0);
}


size_t CParser::PrintArgumentContext::getRuleIndex() const {
  return CParser::RulePrintArgument;
}


antlrcpp::Any CParser::PrintArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitPrintArgument(this);
  else
    return visitor->visitChildren(this);
}

CParser::PrintArgumentContext* CParser::printArgument() {
  PrintArgumentContext *_localctx = _tracker.createInstance<PrintArgumentContext>(_ctx, getState());
  enterRule(_localctx, 56, CParser::RulePrintArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    expression();
    setState(318);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::T__11) {
      setState(316);
      match(CParser::T__11);
      setState(317);
      fieldWidth();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldWidthContext ------------------------------------------------------------------

CParser::FieldWidthContext::FieldWidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::IntegerConstantContext* CParser::FieldWidthContext::integerConstant() {
  return getRuleContext<CParser::IntegerConstantContext>(0);
}

CParser::SignContext* CParser::FieldWidthContext::sign() {
  return getRuleContext<CParser::SignContext>(0);
}

CParser::DecimalPlacesContext* CParser::FieldWidthContext::decimalPlaces() {
  return getRuleContext<CParser::DecimalPlacesContext>(0);
}


size_t CParser::FieldWidthContext::getRuleIndex() const {
  return CParser::RuleFieldWidth;
}


antlrcpp::Any CParser::FieldWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFieldWidth(this);
  else
    return visitor->visitChildren(this);
}

CParser::FieldWidthContext* CParser::fieldWidth() {
  FieldWidthContext *_localctx = _tracker.createInstance<FieldWidthContext>(_ctx, getState());
  enterRule(_localctx, 58, CParser::RuleFieldWidth);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::T__13) {
      setState(320);
      sign();
    }
    setState(323);
    integerConstant();
    setState(326);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::T__11) {
      setState(324);
      match(CParser::T__11);
      setState(325);
      decimalPlaces();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DecimalPlacesContext ------------------------------------------------------------------

CParser::DecimalPlacesContext::DecimalPlacesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::IntegerConstantContext* CParser::DecimalPlacesContext::integerConstant() {
  return getRuleContext<CParser::IntegerConstantContext>(0);
}


size_t CParser::DecimalPlacesContext::getRuleIndex() const {
  return CParser::RuleDecimalPlaces;
}


antlrcpp::Any CParser::DecimalPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitDecimalPlaces(this);
  else
    return visitor->visitChildren(this);
}

CParser::DecimalPlacesContext* CParser::decimalPlaces() {
  DecimalPlacesContext *_localctx = _tracker.createInstance<DecimalPlacesContext>(_ctx, getState());
  enterRule(_localctx, 60, CParser::RuleDecimalPlaces);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    integerConstant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadStatementContext ------------------------------------------------------------------

CParser::ReadStatementContext::ReadStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ReadStatementContext::READ() {
  return getToken(CParser::READ, 0);
}

CParser::ReadArgumentsContext* CParser::ReadStatementContext::readArguments() {
  return getRuleContext<CParser::ReadArgumentsContext>(0);
}


size_t CParser::ReadStatementContext::getRuleIndex() const {
  return CParser::RuleReadStatement;
}


antlrcpp::Any CParser::ReadStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitReadStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::ReadStatementContext* CParser::readStatement() {
  ReadStatementContext *_localctx = _tracker.createInstance<ReadStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, CParser::RuleReadStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(CParser::READ);
    setState(331);
    match(CParser::T__9);
    setState(332);
    readArguments();
    setState(333);
    match(CParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadlnStatementContext ------------------------------------------------------------------

CParser::ReadlnStatementContext::ReadlnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::ReadlnStatementContext::READLN() {
  return getToken(CParser::READLN, 0);
}

CParser::ReadArgumentsContext* CParser::ReadlnStatementContext::readArguments() {
  return getRuleContext<CParser::ReadArgumentsContext>(0);
}


size_t CParser::ReadlnStatementContext::getRuleIndex() const {
  return CParser::RuleReadlnStatement;
}


antlrcpp::Any CParser::ReadlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitReadlnStatement(this);
  else
    return visitor->visitChildren(this);
}

CParser::ReadlnStatementContext* CParser::readlnStatement() {
  ReadlnStatementContext *_localctx = _tracker.createInstance<ReadlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, CParser::RuleReadlnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    match(CParser::READLN);
    setState(336);
    match(CParser::T__9);
    setState(337);
    readArguments();
    setState(338);
    match(CParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadArgumentsContext ------------------------------------------------------------------

CParser::ReadArgumentsContext::ReadArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::VariableContext *> CParser::ReadArgumentsContext::variable() {
  return getRuleContexts<CParser::VariableContext>();
}

CParser::VariableContext* CParser::ReadArgumentsContext::variable(size_t i) {
  return getRuleContext<CParser::VariableContext>(i);
}


size_t CParser::ReadArgumentsContext::getRuleIndex() const {
  return CParser::RuleReadArguments;
}


antlrcpp::Any CParser::ReadArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitReadArguments(this);
  else
    return visitor->visitChildren(this);
}

CParser::ReadArgumentsContext* CParser::readArguments() {
  ReadArgumentsContext *_localctx = _tracker.createInstance<ReadArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 66, CParser::RuleReadArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(340);
    variable();
    setState(345);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::T__1) {
      setState(341);
      match(CParser::T__1);
      setState(342);
      variable();
      setState(347);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

CParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::SimpleExpressionContext *> CParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<CParser::SimpleExpressionContext>();
}

CParser::SimpleExpressionContext* CParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<CParser::SimpleExpressionContext>(i);
}

CParser::RelOpContext* CParser::ExpressionContext::relOp() {
  return getRuleContext<CParser::RelOpContext>(0);
}


size_t CParser::ExpressionContext::getRuleIndex() const {
  return CParser::RuleExpression;
}


antlrcpp::Any CParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::ExpressionContext* CParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 68, CParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    simpleExpression();
    setState(352);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__14)
      | (1ULL << CParser::T__15)
      | (1ULL << CParser::T__16)
      | (1ULL << CParser::T__17)
      | (1ULL << CParser::T__18)
      | (1ULL << CParser::T__19))) != 0)) {
      setState(349);
      relOp();
      setState(350);
      simpleExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

CParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::TermContext *> CParser::SimpleExpressionContext::term() {
  return getRuleContexts<CParser::TermContext>();
}

CParser::TermContext* CParser::SimpleExpressionContext::term(size_t i) {
  return getRuleContext<CParser::TermContext>(i);
}

CParser::SignContext* CParser::SimpleExpressionContext::sign() {
  return getRuleContext<CParser::SignContext>(0);
}

std::vector<CParser::AddOpContext *> CParser::SimpleExpressionContext::addOp() {
  return getRuleContexts<CParser::AddOpContext>();
}

CParser::AddOpContext* CParser::SimpleExpressionContext::addOp(size_t i) {
  return getRuleContext<CParser::AddOpContext>(i);
}


size_t CParser::SimpleExpressionContext::getRuleIndex() const {
  return CParser::RuleSimpleExpression;
}


antlrcpp::Any CParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

CParser::SimpleExpressionContext* CParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 70, CParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(354);
      sign();
      break;
    }

    }
    setState(357);
    term();
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__13)
      | (1ULL << CParser::T__20)
      | (1ULL << CParser::T__21))) != 0)) {
      setState(358);
      addOp();
      setState(359);
      term();
      setState(365);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

CParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<CParser::FactorContext *> CParser::TermContext::factor() {
  return getRuleContexts<CParser::FactorContext>();
}

CParser::FactorContext* CParser::TermContext::factor(size_t i) {
  return getRuleContext<CParser::FactorContext>(i);
}

std::vector<CParser::MulOpContext *> CParser::TermContext::mulOp() {
  return getRuleContexts<CParser::MulOpContext>();
}

CParser::MulOpContext* CParser::TermContext::mulOp(size_t i) {
  return getRuleContext<CParser::MulOpContext>(i);
}


size_t CParser::TermContext::getRuleIndex() const {
  return CParser::RuleTerm;
}


antlrcpp::Any CParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

CParser::TermContext* CParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 72, CParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(366);
    factor();
    setState(372);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__22)
      | (1ULL << CParser::T__23)
      | (1ULL << CParser::T__24))) != 0)) {
      setState(367);
      mulOp();
      setState(368);
      factor();
      setState(374);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

CParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::FactorContext::getRuleIndex() const {
  return CParser::RuleFactor;
}

void CParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- NumberFactorContext ------------------------------------------------------------------

CParser::NumberContext* CParser::NumberFactorContext::number() {
  return getRuleContext<CParser::NumberContext>(0);
}

CParser::NumberFactorContext::NumberFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitNumberFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringFactorContext ------------------------------------------------------------------

CParser::StringConstantContext* CParser::StringFactorContext::stringConstant() {
  return getRuleContext<CParser::StringConstantContext>(0);
}

CParser::StringFactorContext::StringFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStringFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharacterFactorContext ------------------------------------------------------------------

CParser::CharacterConstantContext* CParser::CharacterFactorContext::characterConstant() {
  return getRuleContext<CParser::CharacterConstantContext>(0);
}

CParser::CharacterFactorContext::CharacterFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCharacterFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

CParser::VariableContext* CParser::VariableFactorContext::variable() {
  return getRuleContext<CParser::VariableContext>(0);
}

CParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallFactorContext ------------------------------------------------------------------

CParser::FunctionCallContext* CParser::FunctionCallFactorContext::functionCall() {
  return getRuleContext<CParser::FunctionCallContext>(0);
}

CParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFactorContext ------------------------------------------------------------------

CParser::FactorContext* CParser::NotFactorContext::factor() {
  return getRuleContext<CParser::FactorContext>(0);
}

CParser::NotFactorContext::NotFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitNotFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

CParser::ExpressionContext* CParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}

CParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any CParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
CParser::FactorContext* CParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 74, CParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<CParser::VariableFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(375);
      variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<CParser::NumberFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(376);
      number();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<CParser::CharacterFactorContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(377);
      characterConstant();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<CParser::StringFactorContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(378);
      stringConstant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<CParser::FunctionCallFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(379);
      functionCall();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<CParser::NotFactorContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(380);
      match(CParser::T__12);
      setState(381);
      factor();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<CParser::ParenthesizedFactorContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(382);
      match(CParser::T__9);
      setState(383);
      expression();
      setState(384);
      match(CParser::T__10);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

CParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::VariableIdentifierContext* CParser::VariableContext::variableIdentifier() {
  return getRuleContext<CParser::VariableIdentifierContext>(0);
}

std::vector<CParser::ModifierContext *> CParser::VariableContext::modifier() {
  return getRuleContexts<CParser::ModifierContext>();
}

CParser::ModifierContext* CParser::VariableContext::modifier(size_t i) {
  return getRuleContext<CParser::ModifierContext>(i);
}


size_t CParser::VariableContext::getRuleIndex() const {
  return CParser::RuleVariable;
}


antlrcpp::Any CParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

CParser::VariableContext* CParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 76, CParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    variableIdentifier();
    setState(392);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == CParser::T__2) {
      setState(389);
      modifier();
      setState(394);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

CParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::IndexContext* CParser::ModifierContext::index() {
  return getRuleContext<CParser::IndexContext>(0);
}


size_t CParser::ModifierContext::getRuleIndex() const {
  return CParser::RuleModifier;
}


antlrcpp::Any CParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::ModifierContext* CParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 78, CParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(CParser::T__2);
    setState(396);
    index();
    setState(397);
    match(CParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

CParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::ExpressionContext* CParser::IndexContext::expression() {
  return getRuleContext<CParser::ExpressionContext>(0);
}


size_t CParser::IndexContext::getRuleIndex() const {
  return CParser::RuleIndex;
}


antlrcpp::Any CParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

CParser::IndexContext* CParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 80, CParser::RuleIndex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierContext ------------------------------------------------------------------

CParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::VariableIdentifierContext::IDENTIFIER() {
  return getToken(CParser::IDENTIFIER, 0);
}


size_t CParser::VariableIdentifierContext::getRuleIndex() const {
  return CParser::RuleVariableIdentifier;
}


antlrcpp::Any CParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::VariableIdentifierContext* CParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 82, CParser::RuleVariableIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(CParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

CParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::UnsignedNumberContext* CParser::NumberContext::unsignedNumber() {
  return getRuleContext<CParser::UnsignedNumberContext>(0);
}

CParser::SignContext* CParser::NumberContext::sign() {
  return getRuleContext<CParser::SignContext>(0);
}


size_t CParser::NumberContext::getRuleIndex() const {
  return CParser::RuleNumber;
}


antlrcpp::Any CParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

CParser::NumberContext* CParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 84, CParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(404);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == CParser::T__13) {
      setState(403);
      sign();
    }
    setState(406);
    unsignedNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

CParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CParser::IntegerConstantContext* CParser::UnsignedNumberContext::integerConstant() {
  return getRuleContext<CParser::IntegerConstantContext>(0);
}

CParser::RealConstantContext* CParser::UnsignedNumberContext::realConstant() {
  return getRuleContext<CParser::RealConstantContext>(0);
}


size_t CParser::UnsignedNumberContext::getRuleIndex() const {
  return CParser::RuleUnsignedNumber;
}


antlrcpp::Any CParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

CParser::UnsignedNumberContext* CParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 86, CParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(410);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(408);
        integerConstant();
        break;
      }

      case CParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(409);
        realConstant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

CParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::SignContext::getRuleIndex() const {
  return CParser::RuleSign;
}


antlrcpp::Any CParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

CParser::SignContext* CParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 88, CParser::RuleSign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(CParser::T__13);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerConstantContext ------------------------------------------------------------------

CParser::IntegerConstantContext::IntegerConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::IntegerConstantContext::INTEGER() {
  return getToken(CParser::INTEGER, 0);
}


size_t CParser::IntegerConstantContext::getRuleIndex() const {
  return CParser::RuleIntegerConstant;
}


antlrcpp::Any CParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

CParser::IntegerConstantContext* CParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 90, CParser::RuleIntegerConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    match(CParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealConstantContext ------------------------------------------------------------------

CParser::RealConstantContext::RealConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::RealConstantContext::REAL() {
  return getToken(CParser::REAL, 0);
}


size_t CParser::RealConstantContext::getRuleIndex() const {
  return CParser::RuleRealConstant;
}


antlrcpp::Any CParser::RealConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitRealConstant(this);
  else
    return visitor->visitChildren(this);
}

CParser::RealConstantContext* CParser::realConstant() {
  RealConstantContext *_localctx = _tracker.createInstance<RealConstantContext>(_ctx, getState());
  enterRule(_localctx, 92, CParser::RuleRealConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(CParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

CParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::RelOpContext::getRuleIndex() const {
  return CParser::RuleRelOp;
}


antlrcpp::Any CParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

CParser::RelOpContext* CParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 94, CParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__14)
      | (1ULL << CParser::T__15)
      | (1ULL << CParser::T__16)
      | (1ULL << CParser::T__17)
      | (1ULL << CParser::T__18)
      | (1ULL << CParser::T__19))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

CParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::AddOpContext::getRuleIndex() const {
  return CParser::RuleAddOp;
}


antlrcpp::Any CParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

CParser::AddOpContext* CParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 96, CParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__13)
      | (1ULL << CParser::T__20)
      | (1ULL << CParser::T__21))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

CParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CParser::MulOpContext::getRuleIndex() const {
  return CParser::RuleMulOp;
}


antlrcpp::Any CParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

CParser::MulOpContext* CParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 98, CParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(422);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::T__22)
      | (1ULL << CParser::T__23)
      | (1ULL << CParser::T__24))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeIdentifierContext ------------------------------------------------------------------

CParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::TypeIdentifierContext::INT() {
  return getToken(CParser::INT, 0);
}

tree::TerminalNode* CParser::TypeIdentifierContext::BOOL() {
  return getToken(CParser::BOOL, 0);
}

tree::TerminalNode* CParser::TypeIdentifierContext::FLOAT() {
  return getToken(CParser::FLOAT, 0);
}

tree::TerminalNode* CParser::TypeIdentifierContext::VOID() {
  return getToken(CParser::VOID, 0);
}


size_t CParser::TypeIdentifierContext::getRuleIndex() const {
  return CParser::RuleTypeIdentifier;
}


antlrcpp::Any CParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

CParser::TypeIdentifierContext* CParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 100, CParser::RuleTypeIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CParser::INT)
      | (1ULL << CParser::BOOL)
      | (1ULL << CParser::FLOAT)
      | (1ULL << CParser::VOID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharacterConstantContext ------------------------------------------------------------------

CParser::CharacterConstantContext::CharacterConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::CharacterConstantContext::CHARACTER() {
  return getToken(CParser::CHARACTER, 0);
}


size_t CParser::CharacterConstantContext::getRuleIndex() const {
  return CParser::RuleCharacterConstant;
}


antlrcpp::Any CParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

CParser::CharacterConstantContext* CParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 102, CParser::RuleCharacterConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(CParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

CParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CParser::StringConstantContext::STRING() {
  return getToken(CParser::STRING, 0);
}


size_t CParser::StringConstantContext::getRuleIndex() const {
  return CParser::RuleStringConstant;
}


antlrcpp::Any CParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

CParser::StringConstantContext* CParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 104, CParser::RuleStringConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    match(CParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> CParser::_decisionToDFA;
atn::PredictionContextCache CParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CParser::_atn;
std::vector<uint16_t> CParser::_serializedATN;

std::vector<std::string> CParser::_ruleNames = {
  "program", "c_statement", "statement", "emptyStatement", "variableDeclaration", 
  "length", "assignmentStatement", "lhs", "rhs", "controlScope", "controlStatement", 
  "doWhileLoop", "whileLoop", "forLoop", "ifStatement", "functionDefinition", 
  "functionDeclaration", "functionIdentifier", "parameterDeclarationsList", 
  "parameterDeclaration", "parameterIdentifier", "returnStatement", "functionCall", 
  "argumentList", "argument", "printStatement", "printlnStatement", "printArguments", 
  "printArgument", "fieldWidth", "decimalPlaces", "readStatement", "readlnStatement", 
  "readArguments", "expression", "simpleExpression", "term", "factor", "variable", 
  "modifier", "index", "variableIdentifier", "number", "unsignedNumber", 
  "sign", "integerConstant", "realConstant", "relOp", "addOp", "mulOp", 
  "typeIdentifier", "characterConstant", "stringConstant"
};

std::vector<std::string> CParser::_literalNames = {
  "", "';'", "','", "'['", "']'", "'='", "'++'", "'--'", "'{'", "'}'", "'('", 
  "')'", "':'", "'!'", "'-'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", 
  "'+'", "'||'", "'*'", "'/'", "'&&'", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "'[]'", "'''", "'\"'", "'//'"
};

std::vector<std::string> CParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "INT", "BOOL", "FLOAT", "VOID", "DO", 
  "WHILE", "FOR", "IF", "ELSEIF", "ELSE", "SWITCH", "PRINT", "PRINTLN", 
  "READ", "READLN", "RETURN", "ARRAYINDICATOR", "SINGLEQUOTE", "DOUBLEQUOTE", 
  "DOUBLESLASH", "IDENTIFIER", "INTEGER", "REAL", "CHARACTER", "STRING", 
  "NEWLINE", "WS", "COMMENT"
};

dfa::Vocabulary CParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CParser::_tokenNames;

CParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x37, 0x1b1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x70, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x71, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x7a, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x85, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x8d, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x90, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x98, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x9b, 0xb, 0x6, 0x5, 0x6, 0x9d, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0xab, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xaf, 0xa, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xb6, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0xb9, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xc2, 0xa, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0xd4, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0xda, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xeb, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0xee, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0xf2, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xfc, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 
    0x14, 0x105, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x108, 0xb, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x7, 0x15, 0x10c, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
    0x10f, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x117, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x5, 0x18, 0x11c, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x7, 0x19, 0x123, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x126, 
    0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x132, 
    0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 
    0x1d, 0x139, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x13c, 0xb, 0x1d, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x141, 0xa, 0x1e, 0x3, 0x1f, 
    0x5, 0x1f, 0x144, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
    0x149, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x15a, 0xa, 0x23, 
    0xc, 0x23, 0xe, 0x23, 0x15d, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x163, 0xa, 0x24, 0x3, 0x25, 0x5, 0x25, 0x166, 
    0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x16c, 
    0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x16f, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x175, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 
    0x178, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
    0x27, 0x185, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x189, 0xa, 
    0x28, 0xc, 0x28, 0xe, 0x28, 0x18c, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2c, 0x5, 0x2c, 0x197, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x19d, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x2, 0x2, 0x37, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
    0x6a, 0x2, 0x6, 0x3, 0x2, 0x11, 0x16, 0x4, 0x2, 0x10, 0x10, 0x17, 0x18, 
    0x3, 0x2, 0x19, 0x1b, 0x3, 0x2, 0x1c, 0x1f, 0x2, 0x1b1, 0x2, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x79, 0x3, 0x2, 0x2, 0x2, 0x6, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x86, 0x3, 0x2, 0x2, 0x2, 0xa, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x9e, 0x3, 0x2, 0x2, 0x2, 0xe, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x10, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xca, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd0, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0xde, 0x3, 0x2, 0x2, 0x2, 0x20, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x24, 0xff, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x101, 0x3, 0x2, 0x2, 0x2, 0x28, 0x109, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x114, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x127, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x129, 0x3, 0x2, 0x2, 0x2, 0x36, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x135, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x13d, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x143, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x14c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x151, 0x3, 0x2, 0x2, 0x2, 0x44, 0x156, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x48, 0x165, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x170, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x186, 0x3, 0x2, 0x2, 0x2, 0x50, 0x18d, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x191, 0x3, 0x2, 0x2, 0x2, 0x54, 0x193, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x196, 0x3, 0x2, 0x2, 0x2, 0x58, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x19e, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1a2, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1a6, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1aa, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x70, 0x5, 0x20, 0x11, 0x2, 0x6d, 0x70, 0x5, 0x22, 0x12, 
    0x2, 0x6e, 0x70, 0x5, 0x4, 0x3, 0x2, 0x6f, 0x6c, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x3, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x5, 
    0x6, 0x4, 0x2, 0x74, 0x75, 0x7, 0x3, 0x2, 0x2, 0x75, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x77, 0x5, 0x8, 0x5, 0x2, 0x77, 0x78, 0x7, 0x3, 0x2, 
    0x2, 0x78, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x79, 0x73, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x5, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x85, 0x5, 0xe, 0x8, 0x2, 0x7c, 0x85, 0x5, 0xa, 0x6, 0x2, 0x7d, 0x85, 
    0x5, 0x16, 0xc, 0x2, 0x7e, 0x85, 0x5, 0x34, 0x1b, 0x2, 0x7f, 0x85, 0x5, 
    0x36, 0x1c, 0x2, 0x80, 0x85, 0x5, 0x40, 0x21, 0x2, 0x81, 0x85, 0x5, 
    0x42, 0x22, 0x2, 0x82, 0x85, 0x5, 0x2e, 0x18, 0x2, 0x83, 0x85, 0x5, 
    0x2c, 0x17, 0x2, 0x84, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x84, 0x7e, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x84, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x7, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x9, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 
    0x66, 0x34, 0x2, 0x89, 0x8e, 0x5, 0x54, 0x2b, 0x2, 0x8a, 0x8b, 0x7, 
    0x4, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x54, 0x2b, 0x2, 0x8c, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x9d, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x66, 0x34, 0x2, 0x92, 
    0x99, 0x5, 0x54, 0x2b, 0x2, 0x93, 0x94, 0x7, 0x5, 0x2, 0x2, 0x94, 0x95, 
    0x5, 0xc, 0x7, 0x2, 0x95, 0x96, 0x7, 0x6, 0x2, 0x2, 0x96, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x93, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x9c, 0x88, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x91, 0x3, 0x2, 0x2, 0x2, 0x9d, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x31, 0x2, 0x2, 0x9f, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x10, 0x9, 0x2, 0xa1, 0xa2, 0x7, 
    0x7, 0x2, 0x2, 0xa2, 0xa3, 0x5, 0x12, 0xa, 0x2, 0xa3, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa5, 0x5, 0x4e, 0x28, 0x2, 0xa5, 0xa6, 0x7, 0x8, 0x2, 
    0x2, 0xa6, 0xab, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x4e, 0x28, 0x2, 
    0xa8, 0xa9, 0x7, 0x9, 0x2, 0x2, 0xa9, 0xab, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xa0, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0xf, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x5, 
    0x4e, 0x28, 0x2, 0xad, 0xaf, 0x5, 0xa, 0x6, 0x2, 0xae, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xb1, 0x5, 0x46, 0x24, 0x2, 0xb1, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb7, 0x7, 0xa, 0x2, 0x2, 0xb3, 0xb6, 0x5, 0x4, 0x3, 0x2, 0xb4, 
    0xb6, 0x5, 0x16, 0xc, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0xb, 0x2, 
    0x2, 0xbb, 0x15, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xc2, 0x5, 0x18, 0xd, 0x2, 
    0xbd, 0xc2, 0x5, 0x1a, 0xe, 0x2, 0xbe, 0xc2, 0x5, 0x1c, 0xf, 0x2, 0xbf, 
    0xc2, 0x5, 0x1e, 0x10, 0x2, 0xc0, 0xc2, 0x5, 0x14, 0xb, 0x2, 0xc1, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbe, 0x3, 
    0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x20, 0x2, 
    0x2, 0xc4, 0xc5, 0x5, 0x14, 0xb, 0x2, 0xc5, 0xc6, 0x7, 0x21, 0x2, 0x2, 
    0xc6, 0xc7, 0x7, 0xc, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x46, 0x24, 0x2, 0xc8, 
    0xc9, 0x7, 0xd, 0x2, 0x2, 0xc9, 0x19, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 
    0x7, 0x21, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0xc, 0x2, 0x2, 0xcc, 0xcd, 0x5, 
    0x46, 0x24, 0x2, 0xcd, 0xce, 0x7, 0xd, 0x2, 0x2, 0xce, 0xcf, 0x5, 0x14, 
    0xb, 0x2, 0xcf, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x22, 0x2, 
    0x2, 0xd1, 0xd3, 0x7, 0xc, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x6, 0x4, 0x2, 
    0xd3, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x7, 0x3, 0x2, 0x2, 0xd6, 0xd7, 
    0x5, 0x46, 0x24, 0x2, 0xd7, 0xd9, 0x7, 0x3, 0x2, 0x2, 0xd8, 0xda, 0x5, 
    0x6, 0x4, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0xd, 0x2, 
    0x2, 0xdc, 0xdd, 0x5, 0x14, 0xb, 0x2, 0xdd, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xdf, 0x7, 0x23, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0xc, 0x2, 0x2, 0xe0, 
    0xe1, 0x5, 0x46, 0x24, 0x2, 0xe1, 0xe2, 0x7, 0xd, 0x2, 0x2, 0xe2, 0xec, 
    0x5, 0x14, 0xb, 0x2, 0xe3, 0xe4, 0x7, 0x25, 0x2, 0x2, 0xe4, 0xe5, 0x7, 
    0x23, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0xc, 0x2, 0x2, 0xe6, 0xe7, 0x5, 0x46, 
    0x24, 0x2, 0xe7, 0xe8, 0x7, 0xd, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x14, 0xb, 
    0x2, 0xe9, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe3, 0x3, 0x2, 0x2, 0x2, 
    0xeb, 0xee, 0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xee, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x25, 0x2, 0x2, 0xf0, 0xf2, 0x5, 
    0x14, 0xb, 0x2, 0xf1, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0x22, 0x12, 
    0x2, 0xf4, 0xf5, 0x5, 0x14, 0xb, 0x2, 0xf5, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xf7, 0x5, 0x66, 0x34, 0x2, 0xf7, 0xf8, 0x5, 0x24, 0x13, 0x2, 
    0xf8, 0xfb, 0x7, 0xc, 0x2, 0x2, 0xf9, 0xfc, 0x5, 0x26, 0x14, 0x2, 0xfa, 
    0xfc, 0x7, 0x1f, 0x2, 0x2, 0xfb, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfa, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0xd, 0x2, 0x2, 0xfe, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0x100, 0x7, 0x30, 0x2, 0x2, 0x100, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0x106, 0x5, 0x28, 0x15, 0x2, 0x102, 0x103, 0x7, 0x4, 0x2, 
    0x2, 0x103, 0x105, 0x5, 0x28, 0x15, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x105, 0x108, 0x3, 0x2, 0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 0x2, 0x107, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x108, 0x106, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10d, 0x5, 0x66, 0x34, 0x2, 
    0x10a, 0x10c, 0x7, 0x2c, 0x2, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 
    0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x5, 0x2a, 0x16, 0x2, 
    0x111, 0x29, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x7, 0x30, 0x2, 0x2, 
    0x113, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x114, 0x116, 0x7, 0x2b, 0x2, 0x2, 
    0x115, 0x117, 0x5, 0x46, 0x24, 0x2, 0x116, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x118, 
    0x119, 0x5, 0x24, 0x13, 0x2, 0x119, 0x11b, 0x7, 0xc, 0x2, 0x2, 0x11a, 
    0x11c, 0x5, 0x30, 0x19, 0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11b, 
    0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11e, 0x7, 0xd, 0x2, 0x2, 0x11e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x124, 
    0x5, 0x32, 0x1a, 0x2, 0x120, 0x121, 0x7, 0x4, 0x2, 0x2, 0x121, 0x123, 
    0x5, 0x32, 0x1a, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x123, 0x126, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x31, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x128, 0x5, 0x46, 0x24, 0x2, 0x128, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x27, 0x2, 0x2, 0x12a, 0x12b, 0x7, 
    0xc, 0x2, 0x2, 0x12b, 0x12c, 0x5, 0x38, 0x1d, 0x2, 0x12c, 0x12d, 0x7, 
    0xd, 0x2, 0x2, 0x12d, 0x35, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x28, 
    0x2, 0x2, 0x12f, 0x131, 0x7, 0xc, 0x2, 0x2, 0x130, 0x132, 0x5, 0x38, 
    0x1d, 0x2, 0x131, 0x130, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x7, 0xd, 
    0x2, 0x2, 0x134, 0x37, 0x3, 0x2, 0x2, 0x2, 0x135, 0x13a, 0x5, 0x3a, 
    0x1e, 0x2, 0x136, 0x137, 0x7, 0x4, 0x2, 0x2, 0x137, 0x139, 0x5, 0x3a, 
    0x1e, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13c, 0x3, 0x2, 
    0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13a, 0x3, 0x2, 0x2, 
    0x2, 0x13d, 0x140, 0x5, 0x46, 0x24, 0x2, 0x13e, 0x13f, 0x7, 0xe, 0x2, 
    0x2, 0x13f, 0x141, 0x5, 0x3c, 0x1f, 0x2, 0x140, 0x13e, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x144, 0x5, 0x5a, 0x2e, 0x2, 0x143, 0x142, 0x3, 0x2, 0x2, 0x2, 
    0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 
    0x145, 0x148, 0x5, 0x5c, 0x2f, 0x2, 0x146, 0x147, 0x7, 0xe, 0x2, 0x2, 
    0x147, 0x149, 0x5, 0x3e, 0x20, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 
    0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x14a, 
    0x14b, 0x5, 0x5c, 0x2f, 0x2, 0x14b, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x14d, 0x7, 0x29, 0x2, 0x2, 0x14d, 0x14e, 0x7, 0xc, 0x2, 0x2, 0x14e, 
    0x14f, 0x5, 0x44, 0x23, 0x2, 0x14f, 0x150, 0x7, 0xd, 0x2, 0x2, 0x150, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x7, 0x2a, 0x2, 0x2, 0x152, 
    0x153, 0x7, 0xc, 0x2, 0x2, 0x153, 0x154, 0x5, 0x44, 0x23, 0x2, 0x154, 
    0x155, 0x7, 0xd, 0x2, 0x2, 0x155, 0x43, 0x3, 0x2, 0x2, 0x2, 0x156, 0x15b, 
    0x5, 0x4e, 0x28, 0x2, 0x157, 0x158, 0x7, 0x4, 0x2, 0x2, 0x158, 0x15a, 
    0x5, 0x4e, 0x28, 0x2, 0x159, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15c, 
    0x3, 0x2, 0x2, 0x2, 0x15c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15b, 0x3, 
    0x2, 0x2, 0x2, 0x15e, 0x162, 0x5, 0x48, 0x25, 0x2, 0x15f, 0x160, 0x5, 
    0x60, 0x31, 0x2, 0x160, 0x161, 0x5, 0x48, 0x25, 0x2, 0x161, 0x163, 0x3, 
    0x2, 0x2, 0x2, 0x162, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 
    0x2, 0x2, 0x2, 0x163, 0x47, 0x3, 0x2, 0x2, 0x2, 0x164, 0x166, 0x5, 0x5a, 
    0x2e, 0x2, 0x165, 0x164, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 
    0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 0x2, 0x167, 0x16d, 0x5, 0x4a, 
    0x26, 0x2, 0x168, 0x169, 0x5, 0x62, 0x32, 0x2, 0x169, 0x16a, 0x5, 0x4a, 
    0x26, 0x2, 0x16a, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x168, 0x3, 0x2, 
    0x2, 0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x170, 0x176, 0x5, 0x4c, 0x27, 
    0x2, 0x171, 0x172, 0x5, 0x64, 0x33, 0x2, 0x172, 0x173, 0x5, 0x4c, 0x27, 
    0x2, 0x173, 0x175, 0x3, 0x2, 0x2, 0x2, 0x174, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x175, 0x178, 0x3, 0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x176, 0x177, 0x3, 0x2, 0x2, 0x2, 0x177, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 0x185, 0x5, 0x4e, 0x28, 0x2, 
    0x17a, 0x185, 0x5, 0x56, 0x2c, 0x2, 0x17b, 0x185, 0x5, 0x68, 0x35, 0x2, 
    0x17c, 0x185, 0x5, 0x6a, 0x36, 0x2, 0x17d, 0x185, 0x5, 0x2e, 0x18, 0x2, 
    0x17e, 0x17f, 0x7, 0xf, 0x2, 0x2, 0x17f, 0x185, 0x5, 0x4c, 0x27, 0x2, 
    0x180, 0x181, 0x7, 0xc, 0x2, 0x2, 0x181, 0x182, 0x5, 0x46, 0x24, 0x2, 
    0x182, 0x183, 0x7, 0xd, 0x2, 0x2, 0x183, 0x185, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x179, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17a, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17c, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17e, 0x3, 0x2, 0x2, 0x2, 
    0x184, 0x180, 0x3, 0x2, 0x2, 0x2, 0x185, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x186, 
    0x18a, 0x5, 0x54, 0x2b, 0x2, 0x187, 0x189, 0x5, 0x50, 0x29, 0x2, 0x188, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18a, 
    0x188, 0x3, 0x2, 0x2, 0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 
    0x7, 0x5, 0x2, 0x2, 0x18e, 0x18f, 0x5, 0x52, 0x2a, 0x2, 0x18f, 0x190, 
    0x7, 0x6, 0x2, 0x2, 0x190, 0x51, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x5, 
    0x46, 0x24, 0x2, 0x192, 0x53, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x7, 
    0x30, 0x2, 0x2, 0x194, 0x55, 0x3, 0x2, 0x2, 0x2, 0x195, 0x197, 0x5, 
    0x5a, 0x2e, 0x2, 0x196, 0x195, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 
    0x2, 0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x5, 
    0x58, 0x2d, 0x2, 0x199, 0x57, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19d, 0x5, 
    0x5c, 0x2f, 0x2, 0x19b, 0x19d, 0x5, 0x5e, 0x30, 0x2, 0x19c, 0x19a, 0x3, 
    0x2, 0x2, 0x2, 0x19c, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x19e, 0x19f, 0x7, 0x10, 0x2, 0x2, 0x19f, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x1a0, 0x1a1, 0x7, 0x31, 0x2, 0x2, 0x1a1, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x1a2, 0x1a3, 0x7, 0x32, 0x2, 0x2, 0x1a3, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x1a4, 0x1a5, 0x9, 0x2, 0x2, 0x2, 0x1a5, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x1a6, 0x1a7, 0x9, 0x3, 0x2, 0x2, 0x1a7, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x1a8, 0x1a9, 0x9, 0x4, 0x2, 0x2, 0x1a9, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1aa, 
    0x1ab, 0x9, 0x5, 0x2, 0x2, 0x1ab, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 
    0x7, 0x33, 0x2, 0x2, 0x1ad, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 
    0x7, 0x34, 0x2, 0x2, 0x1af, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x6f, 0x71, 
    0x79, 0x84, 0x8e, 0x99, 0x9c, 0xaa, 0xae, 0xb5, 0xb7, 0xc1, 0xd3, 0xd9, 
    0xec, 0xf1, 0xfb, 0x106, 0x10d, 0x116, 0x11b, 0x124, 0x131, 0x13a, 0x140, 
    0x143, 0x148, 0x15b, 0x162, 0x165, 0x16d, 0x176, 0x184, 0x18a, 0x196, 
    0x19c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CParser::Initializer CParser::_init;
