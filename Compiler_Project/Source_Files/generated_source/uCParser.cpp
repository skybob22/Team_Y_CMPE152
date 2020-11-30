
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from ../Source_Files/antlr/uC.g4 by ANTLR 4.8


#include "uCVisitor.h"

#include "uCParser.h"


using namespace antlrcpp;
using namespace antlr4;

uCParser::uCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

uCParser::~uCParser() {
  delete _interpreter;
}

std::string uCParser::getGrammarFileName() const {
  return "uC.g4";
}

const std::vector<std::string>& uCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& uCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

uCParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::FunctionDefinitionContext *> uCParser::ProgramContext::functionDefinition() {
  return getRuleContexts<uCParser::FunctionDefinitionContext>();
}

uCParser::FunctionDefinitionContext* uCParser::ProgramContext::functionDefinition(size_t i) {
  return getRuleContext<uCParser::FunctionDefinitionContext>(i);
}

std::vector<uCParser::FunctionDeclarationContext *> uCParser::ProgramContext::functionDeclaration() {
  return getRuleContexts<uCParser::FunctionDeclarationContext>();
}

uCParser::FunctionDeclarationContext* uCParser::ProgramContext::functionDeclaration(size_t i) {
  return getRuleContext<uCParser::FunctionDeclarationContext>(i);
}

std::vector<uCParser::VariableDeclarationContext *> uCParser::ProgramContext::variableDeclaration() {
  return getRuleContexts<uCParser::VariableDeclarationContext>();
}

uCParser::VariableDeclarationContext* uCParser::ProgramContext::variableDeclaration(size_t i) {
  return getRuleContext<uCParser::VariableDeclarationContext>(i);
}


size_t uCParser::ProgramContext::getRuleIndex() const {
  return uCParser::RuleProgram;
}


antlrcpp::Any uCParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ProgramContext* uCParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, uCParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(113);
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
        setState(108);
        match(uCParser::T__0);
        break;
      }

      case 3: {
        setState(110);
        variableDeclaration();
        setState(111);
        match(uCParser::T__0);
        break;
      }

      }
      setState(115); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::INT)
      | (1ULL << uCParser::BOOL)
      | (1ULL << uCParser::FLOAT)
      | (1ULL << uCParser::VOID))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- C_statementContext ------------------------------------------------------------------

uCParser::C_statementContext::C_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::FunctionDeclarationContext* uCParser::C_statementContext::functionDeclaration() {
  return getRuleContext<uCParser::FunctionDeclarationContext>(0);
}

uCParser::StatementContext* uCParser::C_statementContext::statement() {
  return getRuleContext<uCParser::StatementContext>(0);
}

uCParser::EmptyStatementContext* uCParser::C_statementContext::emptyStatement() {
  return getRuleContext<uCParser::EmptyStatementContext>(0);
}


size_t uCParser::C_statementContext::getRuleIndex() const {
  return uCParser::RuleC_statement;
}


antlrcpp::Any uCParser::C_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitC_statement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::C_statementContext* uCParser::c_statement() {
  C_statementContext *_localctx = _tracker.createInstance<C_statementContext>(_ctx, getState());
  enterRule(_localctx, 2, uCParser::RuleC_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(126);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(117);
      functionDeclaration();
      setState(118);
      match(uCParser::T__0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(120);
      statement();
      setState(121);
      match(uCParser::T__0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      emptyStatement();
      setState(124);
      match(uCParser::T__0);
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

//----------------- StatementContext ------------------------------------------------------------------

uCParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::AssignmentStatementContext* uCParser::StatementContext::assignmentStatement() {
  return getRuleContext<uCParser::AssignmentStatementContext>(0);
}

uCParser::VariableDeclarationContext* uCParser::StatementContext::variableDeclaration() {
  return getRuleContext<uCParser::VariableDeclarationContext>(0);
}

uCParser::ControlStatementContext* uCParser::StatementContext::controlStatement() {
  return getRuleContext<uCParser::ControlStatementContext>(0);
}

uCParser::PrintStatementContext* uCParser::StatementContext::printStatement() {
  return getRuleContext<uCParser::PrintStatementContext>(0);
}

uCParser::PrintlnStatementContext* uCParser::StatementContext::printlnStatement() {
  return getRuleContext<uCParser::PrintlnStatementContext>(0);
}

uCParser::ReadStatementContext* uCParser::StatementContext::readStatement() {
  return getRuleContext<uCParser::ReadStatementContext>(0);
}

uCParser::ReadlnStatementContext* uCParser::StatementContext::readlnStatement() {
  return getRuleContext<uCParser::ReadlnStatementContext>(0);
}

uCParser::FunctionCallContext* uCParser::StatementContext::functionCall() {
  return getRuleContext<uCParser::FunctionCallContext>(0);
}

uCParser::ReturnStatementContext* uCParser::StatementContext::returnStatement() {
  return getRuleContext<uCParser::ReturnStatementContext>(0);
}


size_t uCParser::StatementContext::getRuleIndex() const {
  return uCParser::RuleStatement;
}


antlrcpp::Any uCParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::StatementContext* uCParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, uCParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(137);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(128);
      assignmentStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(129);
      variableDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(130);
      controlStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(131);
      printStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(132);
      printlnStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(133);
      readStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(134);
      readlnStatement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(135);
      functionCall();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(136);
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

uCParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t uCParser::EmptyStatementContext::getRuleIndex() const {
  return uCParser::RuleEmptyStatement;
}


antlrcpp::Any uCParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::EmptyStatementContext* uCParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, uCParser::RuleEmptyStatement);

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

uCParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::TypeIdentifierContext* uCParser::VariableDeclarationContext::typeIdentifier() {
  return getRuleContext<uCParser::TypeIdentifierContext>(0);
}

std::vector<uCParser::VariableIdentifierContext *> uCParser::VariableDeclarationContext::variableIdentifier() {
  return getRuleContexts<uCParser::VariableIdentifierContext>();
}

uCParser::VariableIdentifierContext* uCParser::VariableDeclarationContext::variableIdentifier(size_t i) {
  return getRuleContext<uCParser::VariableIdentifierContext>(i);
}

std::vector<uCParser::LengthContext *> uCParser::VariableDeclarationContext::length() {
  return getRuleContexts<uCParser::LengthContext>();
}

uCParser::LengthContext* uCParser::VariableDeclarationContext::length(size_t i) {
  return getRuleContext<uCParser::LengthContext>(i);
}


size_t uCParser::VariableDeclarationContext::getRuleIndex() const {
  return uCParser::RuleVariableDeclaration;
}


antlrcpp::Any uCParser::VariableDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitVariableDeclaration(this);
  else
    return visitor->visitChildren(this);
}

uCParser::VariableDeclarationContext* uCParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 8, uCParser::RuleVariableDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(161);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(141);
      typeIdentifier();
      setState(142);
      variableIdentifier();
      setState(147);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == uCParser::T__1) {
        setState(143);
        match(uCParser::T__1);
        setState(144);
        variableIdentifier();
        setState(149);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(150);
      typeIdentifier();
      setState(151);
      variableIdentifier();
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == uCParser::T__2) {
        setState(152);
        match(uCParser::T__2);
        setState(153);
        length();
        setState(154);
        match(uCParser::T__3);
        setState(160);
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

uCParser::LengthContext::LengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::LengthContext::INTEGER() {
  return getToken(uCParser::INTEGER, 0);
}


size_t uCParser::LengthContext::getRuleIndex() const {
  return uCParser::RuleLength;
}


antlrcpp::Any uCParser::LengthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitLength(this);
  else
    return visitor->visitChildren(this);
}

uCParser::LengthContext* uCParser::length() {
  LengthContext *_localctx = _tracker.createInstance<LengthContext>(_ctx, getState());
  enterRule(_localctx, 10, uCParser::RuleLength);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(uCParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

uCParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t uCParser::AssignmentStatementContext::getRuleIndex() const {
  return uCParser::RuleAssignmentStatement;
}

void uCParser::AssignmentStatementContext::copyFrom(AssignmentStatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssignVariableContext ------------------------------------------------------------------

uCParser::LhsContext* uCParser::AssignVariableContext::lhs() {
  return getRuleContext<uCParser::LhsContext>(0);
}

uCParser::RhsContext* uCParser::AssignVariableContext::rhs() {
  return getRuleContext<uCParser::RhsContext>(0);
}

uCParser::AssignVariableContext::AssignVariableContext(AssignmentStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::AssignVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitAssignVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DecrementVariableContext ------------------------------------------------------------------

uCParser::VariableContext* uCParser::DecrementVariableContext::variable() {
  return getRuleContext<uCParser::VariableContext>(0);
}

uCParser::DecrementVariableContext::DecrementVariableContext(AssignmentStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::DecrementVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitDecrementVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncrementVariableContext ------------------------------------------------------------------

uCParser::VariableContext* uCParser::IncrementVariableContext::variable() {
  return getRuleContext<uCParser::VariableContext>(0);
}

uCParser::IncrementVariableContext::IncrementVariableContext(AssignmentStatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::IncrementVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitIncrementVariable(this);
  else
    return visitor->visitChildren(this);
}
uCParser::AssignmentStatementContext* uCParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 12, uCParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(175);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<AssignmentStatementContext *>(_tracker.createInstance<uCParser::AssignVariableContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(165);
      lhs();
      setState(166);
      match(uCParser::T__4);
      setState(167);
      rhs();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<AssignmentStatementContext *>(_tracker.createInstance<uCParser::IncrementVariableContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(169);
      variable();
      setState(170);
      match(uCParser::T__5);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<AssignmentStatementContext *>(_tracker.createInstance<uCParser::DecrementVariableContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(172);
      variable();
      setState(173);
      match(uCParser::T__6);
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

uCParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::VariableContext* uCParser::LhsContext::variable() {
  return getRuleContext<uCParser::VariableContext>(0);
}

uCParser::VariableDeclarationContext* uCParser::LhsContext::variableDeclaration() {
  return getRuleContext<uCParser::VariableDeclarationContext>(0);
}


size_t uCParser::LhsContext::getRuleIndex() const {
  return uCParser::RuleLhs;
}


antlrcpp::Any uCParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

uCParser::LhsContext* uCParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 14, uCParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case uCParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(177);
        variable();
        break;
      }

      case uCParser::INT:
      case uCParser::BOOL:
      case uCParser::FLOAT:
      case uCParser::VOID: {
        enterOuterAlt(_localctx, 2);
        setState(178);
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

uCParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::ExpressionContext* uCParser::RhsContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}


size_t uCParser::RhsContext::getRuleIndex() const {
  return uCParser::RuleRhs;
}


antlrcpp::Any uCParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

uCParser::RhsContext* uCParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 16, uCParser::RuleRhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
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

uCParser::ControlScopeContext::ControlScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::C_statementContext *> uCParser::ControlScopeContext::c_statement() {
  return getRuleContexts<uCParser::C_statementContext>();
}

uCParser::C_statementContext* uCParser::ControlScopeContext::c_statement(size_t i) {
  return getRuleContext<uCParser::C_statementContext>(i);
}

std::vector<uCParser::ControlStatementContext *> uCParser::ControlScopeContext::controlStatement() {
  return getRuleContexts<uCParser::ControlStatementContext>();
}

uCParser::ControlStatementContext* uCParser::ControlScopeContext::controlStatement(size_t i) {
  return getRuleContext<uCParser::ControlStatementContext>(i);
}


size_t uCParser::ControlScopeContext::getRuleIndex() const {
  return uCParser::RuleControlScope;
}


antlrcpp::Any uCParser::ControlScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitControlScope(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ControlScopeContext* uCParser::controlScope() {
  ControlScopeContext *_localctx = _tracker.createInstance<ControlScopeContext>(_ctx, getState());
  enterRule(_localctx, 18, uCParser::RuleControlScope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(uCParser::T__7);
    setState(188);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__0)
      | (1ULL << uCParser::T__7)
      | (1ULL << uCParser::INT)
      | (1ULL << uCParser::BOOL)
      | (1ULL << uCParser::FLOAT)
      | (1ULL << uCParser::VOID)
      | (1ULL << uCParser::DO)
      | (1ULL << uCParser::WHILE)
      | (1ULL << uCParser::FOR)
      | (1ULL << uCParser::IF)
      | (1ULL << uCParser::PRINT)
      | (1ULL << uCParser::PRINTLN)
      | (1ULL << uCParser::READ)
      | (1ULL << uCParser::READLN)
      | (1ULL << uCParser::RETURN)
      | (1ULL << uCParser::IDENTIFIER))) != 0)) {
      setState(186);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(184);
        c_statement();
        break;
      }

      case 2: {
        setState(185);
        controlStatement();
        break;
      }

      }
      setState(190);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(191);
    match(uCParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ControlStatementContext ------------------------------------------------------------------

uCParser::ControlStatementContext::ControlStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::DoWhileLoopContext* uCParser::ControlStatementContext::doWhileLoop() {
  return getRuleContext<uCParser::DoWhileLoopContext>(0);
}

uCParser::WhileLoopContext* uCParser::ControlStatementContext::whileLoop() {
  return getRuleContext<uCParser::WhileLoopContext>(0);
}

uCParser::ForLoopContext* uCParser::ControlStatementContext::forLoop() {
  return getRuleContext<uCParser::ForLoopContext>(0);
}

uCParser::IfStatementContext* uCParser::ControlStatementContext::ifStatement() {
  return getRuleContext<uCParser::IfStatementContext>(0);
}

uCParser::ControlScopeContext* uCParser::ControlStatementContext::controlScope() {
  return getRuleContext<uCParser::ControlScopeContext>(0);
}


size_t uCParser::ControlStatementContext::getRuleIndex() const {
  return uCParser::RuleControlStatement;
}


antlrcpp::Any uCParser::ControlStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitControlStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ControlStatementContext* uCParser::controlStatement() {
  ControlStatementContext *_localctx = _tracker.createInstance<ControlStatementContext>(_ctx, getState());
  enterRule(_localctx, 20, uCParser::RuleControlStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(198);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case uCParser::DO: {
        enterOuterAlt(_localctx, 1);
        setState(193);
        doWhileLoop();
        break;
      }

      case uCParser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(194);
        whileLoop();
        break;
      }

      case uCParser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(195);
        forLoop();
        break;
      }

      case uCParser::IF: {
        enterOuterAlt(_localctx, 4);
        setState(196);
        ifStatement();
        break;
      }

      case uCParser::T__7: {
        enterOuterAlt(_localctx, 5);
        setState(197);
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

uCParser::DoWhileLoopContext::DoWhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::DoWhileLoopContext::DO() {
  return getToken(uCParser::DO, 0);
}

uCParser::ControlScopeContext* uCParser::DoWhileLoopContext::controlScope() {
  return getRuleContext<uCParser::ControlScopeContext>(0);
}

tree::TerminalNode* uCParser::DoWhileLoopContext::WHILE() {
  return getToken(uCParser::WHILE, 0);
}

uCParser::ExpressionContext* uCParser::DoWhileLoopContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}


size_t uCParser::DoWhileLoopContext::getRuleIndex() const {
  return uCParser::RuleDoWhileLoop;
}


antlrcpp::Any uCParser::DoWhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitDoWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

uCParser::DoWhileLoopContext* uCParser::doWhileLoop() {
  DoWhileLoopContext *_localctx = _tracker.createInstance<DoWhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 22, uCParser::RuleDoWhileLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(uCParser::DO);
    setState(201);
    controlScope();
    setState(202);
    match(uCParser::WHILE);
    setState(203);
    match(uCParser::T__9);
    setState(204);
    expression();
    setState(205);
    match(uCParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileLoopContext ------------------------------------------------------------------

uCParser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::WhileLoopContext::WHILE() {
  return getToken(uCParser::WHILE, 0);
}

uCParser::ExpressionContext* uCParser::WhileLoopContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}

uCParser::ControlScopeContext* uCParser::WhileLoopContext::controlScope() {
  return getRuleContext<uCParser::ControlScopeContext>(0);
}


size_t uCParser::WhileLoopContext::getRuleIndex() const {
  return uCParser::RuleWhileLoop;
}


antlrcpp::Any uCParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

uCParser::WhileLoopContext* uCParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 24, uCParser::RuleWhileLoop);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(uCParser::WHILE);
    setState(208);
    match(uCParser::T__9);
    setState(209);
    expression();
    setState(210);
    match(uCParser::T__10);
    setState(211);
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

uCParser::ForLoopContext::ForLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::ForLoopContext::FOR() {
  return getToken(uCParser::FOR, 0);
}

uCParser::ExpressionContext* uCParser::ForLoopContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}

uCParser::ControlScopeContext* uCParser::ForLoopContext::controlScope() {
  return getRuleContext<uCParser::ControlScopeContext>(0);
}

std::vector<uCParser::StatementContext *> uCParser::ForLoopContext::statement() {
  return getRuleContexts<uCParser::StatementContext>();
}

uCParser::StatementContext* uCParser::ForLoopContext::statement(size_t i) {
  return getRuleContext<uCParser::StatementContext>(i);
}


size_t uCParser::ForLoopContext::getRuleIndex() const {
  return uCParser::RuleForLoop;
}


antlrcpp::Any uCParser::ForLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitForLoop(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ForLoopContext* uCParser::forLoop() {
  ForLoopContext *_localctx = _tracker.createInstance<ForLoopContext>(_ctx, getState());
  enterRule(_localctx, 26, uCParser::RuleForLoop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(uCParser::FOR);
    setState(214);
    match(uCParser::T__9);
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__7)
      | (1ULL << uCParser::INT)
      | (1ULL << uCParser::BOOL)
      | (1ULL << uCParser::FLOAT)
      | (1ULL << uCParser::VOID)
      | (1ULL << uCParser::DO)
      | (1ULL << uCParser::WHILE)
      | (1ULL << uCParser::FOR)
      | (1ULL << uCParser::IF)
      | (1ULL << uCParser::PRINT)
      | (1ULL << uCParser::PRINTLN)
      | (1ULL << uCParser::READ)
      | (1ULL << uCParser::READLN)
      | (1ULL << uCParser::RETURN)
      | (1ULL << uCParser::IDENTIFIER))) != 0)) {
      setState(215);
      statement();
    }
    setState(218);
    match(uCParser::T__0);
    setState(219);
    expression();
    setState(220);
    match(uCParser::T__0);
    setState(222);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__7)
      | (1ULL << uCParser::INT)
      | (1ULL << uCParser::BOOL)
      | (1ULL << uCParser::FLOAT)
      | (1ULL << uCParser::VOID)
      | (1ULL << uCParser::DO)
      | (1ULL << uCParser::WHILE)
      | (1ULL << uCParser::FOR)
      | (1ULL << uCParser::IF)
      | (1ULL << uCParser::PRINT)
      | (1ULL << uCParser::PRINTLN)
      | (1ULL << uCParser::READ)
      | (1ULL << uCParser::READLN)
      | (1ULL << uCParser::RETURN)
      | (1ULL << uCParser::IDENTIFIER))) != 0)) {
      setState(221);
      statement();
    }
    setState(224);
    match(uCParser::T__10);
    setState(225);
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

uCParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> uCParser::IfStatementContext::IF() {
  return getTokens(uCParser::IF);
}

tree::TerminalNode* uCParser::IfStatementContext::IF(size_t i) {
  return getToken(uCParser::IF, i);
}

std::vector<uCParser::ExpressionContext *> uCParser::IfStatementContext::expression() {
  return getRuleContexts<uCParser::ExpressionContext>();
}

uCParser::ExpressionContext* uCParser::IfStatementContext::expression(size_t i) {
  return getRuleContext<uCParser::ExpressionContext>(i);
}

std::vector<uCParser::ControlScopeContext *> uCParser::IfStatementContext::controlScope() {
  return getRuleContexts<uCParser::ControlScopeContext>();
}

uCParser::ControlScopeContext* uCParser::IfStatementContext::controlScope(size_t i) {
  return getRuleContext<uCParser::ControlScopeContext>(i);
}

std::vector<tree::TerminalNode *> uCParser::IfStatementContext::ELSE() {
  return getTokens(uCParser::ELSE);
}

tree::TerminalNode* uCParser::IfStatementContext::ELSE(size_t i) {
  return getToken(uCParser::ELSE, i);
}


size_t uCParser::IfStatementContext::getRuleIndex() const {
  return uCParser::RuleIfStatement;
}


antlrcpp::Any uCParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::IfStatementContext* uCParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 28, uCParser::RuleIfStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(227);
    match(uCParser::IF);
    setState(228);
    match(uCParser::T__9);
    setState(229);
    expression();
    setState(230);
    match(uCParser::T__10);
    setState(231);
    controlScope();
    setState(241);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(232);
        match(uCParser::ELSE);
        setState(233);
        match(uCParser::IF);
        setState(234);
        match(uCParser::T__9);
        setState(235);
        expression();
        setState(236);
        match(uCParser::T__10);
        setState(237);
        controlScope(); 
      }
      setState(243);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
    setState(246);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == uCParser::ELSE) {
      setState(244);
      match(uCParser::ELSE);
      setState(245);
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

uCParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::FunctionDeclarationContext* uCParser::FunctionDefinitionContext::functionDeclaration() {
  return getRuleContext<uCParser::FunctionDeclarationContext>(0);
}

uCParser::ControlScopeContext* uCParser::FunctionDefinitionContext::controlScope() {
  return getRuleContext<uCParser::ControlScopeContext>(0);
}


size_t uCParser::FunctionDefinitionContext::getRuleIndex() const {
  return uCParser::RuleFunctionDefinition;
}


antlrcpp::Any uCParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

uCParser::FunctionDefinitionContext* uCParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 30, uCParser::RuleFunctionDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    functionDeclaration();
    setState(249);
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

uCParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::TypeIdentifierContext* uCParser::FunctionDeclarationContext::typeIdentifier() {
  return getRuleContext<uCParser::TypeIdentifierContext>(0);
}

uCParser::FunctionIdentifierContext* uCParser::FunctionDeclarationContext::functionIdentifier() {
  return getRuleContext<uCParser::FunctionIdentifierContext>(0);
}

uCParser::ParameterDeclarationsListContext* uCParser::FunctionDeclarationContext::parameterDeclarationsList() {
  return getRuleContext<uCParser::ParameterDeclarationsListContext>(0);
}

tree::TerminalNode* uCParser::FunctionDeclarationContext::VOID() {
  return getToken(uCParser::VOID, 0);
}


size_t uCParser::FunctionDeclarationContext::getRuleIndex() const {
  return uCParser::RuleFunctionDeclaration;
}


antlrcpp::Any uCParser::FunctionDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitFunctionDeclaration(this);
  else
    return visitor->visitChildren(this);
}

uCParser::FunctionDeclarationContext* uCParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 32, uCParser::RuleFunctionDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    typeIdentifier();
    setState(252);
    functionIdentifier();
    setState(253);
    match(uCParser::T__9);
    setState(256);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(254);
      parameterDeclarationsList();
      break;
    }

    case 2: {
      setState(255);
      match(uCParser::VOID);
      break;
    }

    }
    setState(258);
    match(uCParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionIdentifierContext ------------------------------------------------------------------

uCParser::FunctionIdentifierContext::FunctionIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::FunctionIdentifierContext::IDENTIFIER() {
  return getToken(uCParser::IDENTIFIER, 0);
}


size_t uCParser::FunctionIdentifierContext::getRuleIndex() const {
  return uCParser::RuleFunctionIdentifier;
}


antlrcpp::Any uCParser::FunctionIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitFunctionIdentifier(this);
  else
    return visitor->visitChildren(this);
}

uCParser::FunctionIdentifierContext* uCParser::functionIdentifier() {
  FunctionIdentifierContext *_localctx = _tracker.createInstance<FunctionIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 34, uCParser::RuleFunctionIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(260);
    match(uCParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclarationsListContext ------------------------------------------------------------------

uCParser::ParameterDeclarationsListContext::ParameterDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::ParameterDeclarationContext *> uCParser::ParameterDeclarationsListContext::parameterDeclaration() {
  return getRuleContexts<uCParser::ParameterDeclarationContext>();
}

uCParser::ParameterDeclarationContext* uCParser::ParameterDeclarationsListContext::parameterDeclaration(size_t i) {
  return getRuleContext<uCParser::ParameterDeclarationContext>(i);
}


size_t uCParser::ParameterDeclarationsListContext::getRuleIndex() const {
  return uCParser::RuleParameterDeclarationsList;
}


antlrcpp::Any uCParser::ParameterDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitParameterDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ParameterDeclarationsListContext* uCParser::parameterDeclarationsList() {
  ParameterDeclarationsListContext *_localctx = _tracker.createInstance<ParameterDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 36, uCParser::RuleParameterDeclarationsList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    parameterDeclaration();
    setState(267);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == uCParser::T__1) {
      setState(263);
      match(uCParser::T__1);
      setState(264);
      parameterDeclaration();
      setState(269);
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

uCParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::TypeIdentifierContext* uCParser::ParameterDeclarationContext::typeIdentifier() {
  return getRuleContext<uCParser::TypeIdentifierContext>(0);
}

uCParser::ParameterIdentifierContext* uCParser::ParameterDeclarationContext::parameterIdentifier() {
  return getRuleContext<uCParser::ParameterIdentifierContext>(0);
}

std::vector<tree::TerminalNode *> uCParser::ParameterDeclarationContext::ARRAYINDICATOR() {
  return getTokens(uCParser::ARRAYINDICATOR);
}

tree::TerminalNode* uCParser::ParameterDeclarationContext::ARRAYINDICATOR(size_t i) {
  return getToken(uCParser::ARRAYINDICATOR, i);
}


size_t uCParser::ParameterDeclarationContext::getRuleIndex() const {
  return uCParser::RuleParameterDeclaration;
}


antlrcpp::Any uCParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ParameterDeclarationContext* uCParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 38, uCParser::RuleParameterDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(270);
    typeIdentifier();
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == uCParser::ARRAYINDICATOR) {
      setState(271);
      match(uCParser::ARRAYINDICATOR);
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(277);
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

uCParser::ParameterIdentifierContext::ParameterIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::ParameterIdentifierContext::IDENTIFIER() {
  return getToken(uCParser::IDENTIFIER, 0);
}


size_t uCParser::ParameterIdentifierContext::getRuleIndex() const {
  return uCParser::RuleParameterIdentifier;
}


antlrcpp::Any uCParser::ParameterIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitParameterIdentifier(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ParameterIdentifierContext* uCParser::parameterIdentifier() {
  ParameterIdentifierContext *_localctx = _tracker.createInstance<ParameterIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 40, uCParser::RuleParameterIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(279);
    match(uCParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatementContext ------------------------------------------------------------------

uCParser::ReturnStatementContext::ReturnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::ReturnStatementContext::RETURN() {
  return getToken(uCParser::RETURN, 0);
}

uCParser::ExpressionContext* uCParser::ReturnStatementContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}


size_t uCParser::ReturnStatementContext::getRuleIndex() const {
  return uCParser::RuleReturnStatement;
}


antlrcpp::Any uCParser::ReturnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitReturnStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ReturnStatementContext* uCParser::returnStatement() {
  ReturnStatementContext *_localctx = _tracker.createInstance<ReturnStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, uCParser::RuleReturnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(uCParser::RETURN);
    setState(283);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__9)
      | (1ULL << uCParser::T__12)
      | (1ULL << uCParser::T__13)
      | (1ULL << uCParser::IDENTIFIER)
      | (1ULL << uCParser::INTEGER)
      | (1ULL << uCParser::REAL)
      | (1ULL << uCParser::CHARACTER)
      | (1ULL << uCParser::STRING))) != 0)) {
      setState(282);
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

uCParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::FunctionIdentifierContext* uCParser::FunctionCallContext::functionIdentifier() {
  return getRuleContext<uCParser::FunctionIdentifierContext>(0);
}

uCParser::ArgumentListContext* uCParser::FunctionCallContext::argumentList() {
  return getRuleContext<uCParser::ArgumentListContext>(0);
}


size_t uCParser::FunctionCallContext::getRuleIndex() const {
  return uCParser::RuleFunctionCall;
}


antlrcpp::Any uCParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

uCParser::FunctionCallContext* uCParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 44, uCParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    functionIdentifier();
    setState(286);
    match(uCParser::T__9);
    setState(288);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__9)
      | (1ULL << uCParser::T__12)
      | (1ULL << uCParser::T__13)
      | (1ULL << uCParser::IDENTIFIER)
      | (1ULL << uCParser::INTEGER)
      | (1ULL << uCParser::REAL)
      | (1ULL << uCParser::CHARACTER)
      | (1ULL << uCParser::STRING))) != 0)) {
      setState(287);
      argumentList();
    }
    setState(290);
    match(uCParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

uCParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::ArgumentContext *> uCParser::ArgumentListContext::argument() {
  return getRuleContexts<uCParser::ArgumentContext>();
}

uCParser::ArgumentContext* uCParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<uCParser::ArgumentContext>(i);
}


size_t uCParser::ArgumentListContext::getRuleIndex() const {
  return uCParser::RuleArgumentList;
}


antlrcpp::Any uCParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ArgumentListContext* uCParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 46, uCParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    argument();
    setState(297);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == uCParser::T__1) {
      setState(293);
      match(uCParser::T__1);
      setState(294);
      argument();
      setState(299);
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

uCParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::ExpressionContext* uCParser::ArgumentContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}


size_t uCParser::ArgumentContext::getRuleIndex() const {
  return uCParser::RuleArgument;
}


antlrcpp::Any uCParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ArgumentContext* uCParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 48, uCParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(300);
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

uCParser::PrintStatementContext::PrintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::PrintStatementContext::PRINT() {
  return getToken(uCParser::PRINT, 0);
}

uCParser::PrintArgumentsContext* uCParser::PrintStatementContext::printArguments() {
  return getRuleContext<uCParser::PrintArgumentsContext>(0);
}


size_t uCParser::PrintStatementContext::getRuleIndex() const {
  return uCParser::RulePrintStatement;
}


antlrcpp::Any uCParser::PrintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitPrintStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::PrintStatementContext* uCParser::printStatement() {
  PrintStatementContext *_localctx = _tracker.createInstance<PrintStatementContext>(_ctx, getState());
  enterRule(_localctx, 50, uCParser::RulePrintStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(uCParser::PRINT);
    setState(303);
    match(uCParser::T__9);
    setState(304);
    printArguments();
    setState(305);
    match(uCParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintlnStatementContext ------------------------------------------------------------------

uCParser::PrintlnStatementContext::PrintlnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::PrintlnStatementContext::PRINTLN() {
  return getToken(uCParser::PRINTLN, 0);
}

uCParser::PrintArgumentsContext* uCParser::PrintlnStatementContext::printArguments() {
  return getRuleContext<uCParser::PrintArgumentsContext>(0);
}


size_t uCParser::PrintlnStatementContext::getRuleIndex() const {
  return uCParser::RulePrintlnStatement;
}


antlrcpp::Any uCParser::PrintlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitPrintlnStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::PrintlnStatementContext* uCParser::printlnStatement() {
  PrintlnStatementContext *_localctx = _tracker.createInstance<PrintlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 52, uCParser::RulePrintlnStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(307);
    match(uCParser::PRINTLN);
    setState(308);
    match(uCParser::T__9);
    setState(310);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__9)
      | (1ULL << uCParser::T__12)
      | (1ULL << uCParser::T__13)
      | (1ULL << uCParser::IDENTIFIER)
      | (1ULL << uCParser::INTEGER)
      | (1ULL << uCParser::REAL)
      | (1ULL << uCParser::CHARACTER)
      | (1ULL << uCParser::STRING))) != 0)) {
      setState(309);
      printArguments();
    }
    setState(312);
    match(uCParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintArgumentsContext ------------------------------------------------------------------

uCParser::PrintArgumentsContext::PrintArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::PrintArgumentContext *> uCParser::PrintArgumentsContext::printArgument() {
  return getRuleContexts<uCParser::PrintArgumentContext>();
}

uCParser::PrintArgumentContext* uCParser::PrintArgumentsContext::printArgument(size_t i) {
  return getRuleContext<uCParser::PrintArgumentContext>(i);
}


size_t uCParser::PrintArgumentsContext::getRuleIndex() const {
  return uCParser::RulePrintArguments;
}


antlrcpp::Any uCParser::PrintArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitPrintArguments(this);
  else
    return visitor->visitChildren(this);
}

uCParser::PrintArgumentsContext* uCParser::printArguments() {
  PrintArgumentsContext *_localctx = _tracker.createInstance<PrintArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 54, uCParser::RulePrintArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(314);
    printArgument();
    setState(319);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == uCParser::T__1) {
      setState(315);
      match(uCParser::T__1);
      setState(316);
      printArgument();
      setState(321);
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

uCParser::PrintArgumentContext::PrintArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::ExpressionContext* uCParser::PrintArgumentContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}

uCParser::FieldWidthContext* uCParser::PrintArgumentContext::fieldWidth() {
  return getRuleContext<uCParser::FieldWidthContext>(0);
}


size_t uCParser::PrintArgumentContext::getRuleIndex() const {
  return uCParser::RulePrintArgument;
}


antlrcpp::Any uCParser::PrintArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitPrintArgument(this);
  else
    return visitor->visitChildren(this);
}

uCParser::PrintArgumentContext* uCParser::printArgument() {
  PrintArgumentContext *_localctx = _tracker.createInstance<PrintArgumentContext>(_ctx, getState());
  enterRule(_localctx, 56, uCParser::RulePrintArgument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    expression();
    setState(325);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == uCParser::T__11) {
      setState(323);
      match(uCParser::T__11);
      setState(324);
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

uCParser::FieldWidthContext::FieldWidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::IntegerConstantContext* uCParser::FieldWidthContext::integerConstant() {
  return getRuleContext<uCParser::IntegerConstantContext>(0);
}

uCParser::SignContext* uCParser::FieldWidthContext::sign() {
  return getRuleContext<uCParser::SignContext>(0);
}

uCParser::DecimalPlacesContext* uCParser::FieldWidthContext::decimalPlaces() {
  return getRuleContext<uCParser::DecimalPlacesContext>(0);
}


size_t uCParser::FieldWidthContext::getRuleIndex() const {
  return uCParser::RuleFieldWidth;
}


antlrcpp::Any uCParser::FieldWidthContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitFieldWidth(this);
  else
    return visitor->visitChildren(this);
}

uCParser::FieldWidthContext* uCParser::fieldWidth() {
  FieldWidthContext *_localctx = _tracker.createInstance<FieldWidthContext>(_ctx, getState());
  enterRule(_localctx, 58, uCParser::RuleFieldWidth);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == uCParser::T__13) {
      setState(327);
      sign();
    }
    setState(330);
    integerConstant();
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == uCParser::T__11) {
      setState(331);
      match(uCParser::T__11);
      setState(332);
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

uCParser::DecimalPlacesContext::DecimalPlacesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::IntegerConstantContext* uCParser::DecimalPlacesContext::integerConstant() {
  return getRuleContext<uCParser::IntegerConstantContext>(0);
}


size_t uCParser::DecimalPlacesContext::getRuleIndex() const {
  return uCParser::RuleDecimalPlaces;
}


antlrcpp::Any uCParser::DecimalPlacesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitDecimalPlaces(this);
  else
    return visitor->visitChildren(this);
}

uCParser::DecimalPlacesContext* uCParser::decimalPlaces() {
  DecimalPlacesContext *_localctx = _tracker.createInstance<DecimalPlacesContext>(_ctx, getState());
  enterRule(_localctx, 60, uCParser::RuleDecimalPlaces);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
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

uCParser::ReadStatementContext::ReadStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::ReadStatementContext::READ() {
  return getToken(uCParser::READ, 0);
}

uCParser::ReadArgumentsContext* uCParser::ReadStatementContext::readArguments() {
  return getRuleContext<uCParser::ReadArgumentsContext>(0);
}


size_t uCParser::ReadStatementContext::getRuleIndex() const {
  return uCParser::RuleReadStatement;
}


antlrcpp::Any uCParser::ReadStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitReadStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ReadStatementContext* uCParser::readStatement() {
  ReadStatementContext *_localctx = _tracker.createInstance<ReadStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, uCParser::RuleReadStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(337);
    match(uCParser::READ);
    setState(338);
    match(uCParser::T__9);
    setState(339);
    readArguments();
    setState(340);
    match(uCParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadlnStatementContext ------------------------------------------------------------------

uCParser::ReadlnStatementContext::ReadlnStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::ReadlnStatementContext::READLN() {
  return getToken(uCParser::READLN, 0);
}

uCParser::ReadArgumentsContext* uCParser::ReadlnStatementContext::readArguments() {
  return getRuleContext<uCParser::ReadArgumentsContext>(0);
}


size_t uCParser::ReadlnStatementContext::getRuleIndex() const {
  return uCParser::RuleReadlnStatement;
}


antlrcpp::Any uCParser::ReadlnStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitReadlnStatement(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ReadlnStatementContext* uCParser::readlnStatement() {
  ReadlnStatementContext *_localctx = _tracker.createInstance<ReadlnStatementContext>(_ctx, getState());
  enterRule(_localctx, 64, uCParser::RuleReadlnStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(uCParser::READLN);
    setState(343);
    match(uCParser::T__9);
    setState(344);
    readArguments();
    setState(345);
    match(uCParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReadArgumentsContext ------------------------------------------------------------------

uCParser::ReadArgumentsContext::ReadArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::VariableContext *> uCParser::ReadArgumentsContext::variable() {
  return getRuleContexts<uCParser::VariableContext>();
}

uCParser::VariableContext* uCParser::ReadArgumentsContext::variable(size_t i) {
  return getRuleContext<uCParser::VariableContext>(i);
}


size_t uCParser::ReadArgumentsContext::getRuleIndex() const {
  return uCParser::RuleReadArguments;
}


antlrcpp::Any uCParser::ReadArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitReadArguments(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ReadArgumentsContext* uCParser::readArguments() {
  ReadArgumentsContext *_localctx = _tracker.createInstance<ReadArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 66, uCParser::RuleReadArguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    variable();
    setState(352);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == uCParser::T__1) {
      setState(348);
      match(uCParser::T__1);
      setState(349);
      variable();
      setState(354);
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

uCParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::SimpleExpressionContext *> uCParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<uCParser::SimpleExpressionContext>();
}

uCParser::SimpleExpressionContext* uCParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<uCParser::SimpleExpressionContext>(i);
}

uCParser::RelOpContext* uCParser::ExpressionContext::relOp() {
  return getRuleContext<uCParser::RelOpContext>(0);
}


size_t uCParser::ExpressionContext::getRuleIndex() const {
  return uCParser::RuleExpression;
}


antlrcpp::Any uCParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ExpressionContext* uCParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 68, uCParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    simpleExpression();
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__14)
      | (1ULL << uCParser::T__15)
      | (1ULL << uCParser::T__16)
      | (1ULL << uCParser::T__17)
      | (1ULL << uCParser::T__18)
      | (1ULL << uCParser::T__19))) != 0)) {
      setState(356);
      relOp();
      setState(357);
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

uCParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::TermContext *> uCParser::SimpleExpressionContext::term() {
  return getRuleContexts<uCParser::TermContext>();
}

uCParser::TermContext* uCParser::SimpleExpressionContext::term(size_t i) {
  return getRuleContext<uCParser::TermContext>(i);
}

uCParser::SignContext* uCParser::SimpleExpressionContext::sign() {
  return getRuleContext<uCParser::SignContext>(0);
}

std::vector<uCParser::AddOpContext *> uCParser::SimpleExpressionContext::addOp() {
  return getRuleContexts<uCParser::AddOpContext>();
}

uCParser::AddOpContext* uCParser::SimpleExpressionContext::addOp(size_t i) {
  return getRuleContext<uCParser::AddOpContext>(i);
}


size_t uCParser::SimpleExpressionContext::getRuleIndex() const {
  return uCParser::RuleSimpleExpression;
}


antlrcpp::Any uCParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

uCParser::SimpleExpressionContext* uCParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 70, uCParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(361);
      sign();
      break;
    }

    }
    setState(364);
    term();
    setState(370);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__13)
      | (1ULL << uCParser::T__20)
      | (1ULL << uCParser::T__21))) != 0)) {
      setState(365);
      addOp();
      setState(366);
      term();
      setState(372);
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

uCParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<uCParser::FactorContext *> uCParser::TermContext::factor() {
  return getRuleContexts<uCParser::FactorContext>();
}

uCParser::FactorContext* uCParser::TermContext::factor(size_t i) {
  return getRuleContext<uCParser::FactorContext>(i);
}

std::vector<uCParser::MulOpContext *> uCParser::TermContext::mulOp() {
  return getRuleContexts<uCParser::MulOpContext>();
}

uCParser::MulOpContext* uCParser::TermContext::mulOp(size_t i) {
  return getRuleContext<uCParser::MulOpContext>(i);
}


size_t uCParser::TermContext::getRuleIndex() const {
  return uCParser::RuleTerm;
}


antlrcpp::Any uCParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

uCParser::TermContext* uCParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 72, uCParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    factor();
    setState(379);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__22)
      | (1ULL << uCParser::T__23)
      | (1ULL << uCParser::T__24))) != 0)) {
      setState(374);
      mulOp();
      setState(375);
      factor();
      setState(381);
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

uCParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t uCParser::FactorContext::getRuleIndex() const {
  return uCParser::RuleFactor;
}

void uCParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
}

//----------------- NumberFactorContext ------------------------------------------------------------------

uCParser::NumberContext* uCParser::NumberFactorContext::number() {
  return getRuleContext<uCParser::NumberContext>(0);
}

uCParser::NumberFactorContext::NumberFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitNumberFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringFactorContext ------------------------------------------------------------------

uCParser::StringConstantContext* uCParser::StringFactorContext::stringConstant() {
  return getRuleContext<uCParser::StringConstantContext>(0);
}

uCParser::StringFactorContext::StringFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitStringFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharacterFactorContext ------------------------------------------------------------------

uCParser::CharacterConstantContext* uCParser::CharacterFactorContext::characterConstant() {
  return getRuleContext<uCParser::CharacterConstantContext>(0);
}

uCParser::CharacterFactorContext::CharacterFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitCharacterFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

uCParser::VariableContext* uCParser::VariableFactorContext::variable() {
  return getRuleContext<uCParser::VariableContext>(0);
}

uCParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallFactorContext ------------------------------------------------------------------

uCParser::FunctionCallContext* uCParser::FunctionCallFactorContext::functionCall() {
  return getRuleContext<uCParser::FunctionCallContext>(0);
}

uCParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFactorContext ------------------------------------------------------------------

uCParser::FactorContext* uCParser::NotFactorContext::factor() {
  return getRuleContext<uCParser::FactorContext>(0);
}

uCParser::NotFactorContext::NotFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitNotFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

uCParser::ExpressionContext* uCParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}

uCParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any uCParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
uCParser::FactorContext* uCParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 74, uCParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<uCParser::VariableFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(382);
      variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<uCParser::NumberFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(383);
      number();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<uCParser::CharacterFactorContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(384);
      characterConstant();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<uCParser::StringFactorContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(385);
      stringConstant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<uCParser::FunctionCallFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(386);
      functionCall();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<uCParser::NotFactorContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(387);
      match(uCParser::T__12);
      setState(388);
      factor();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<uCParser::ParenthesizedFactorContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(389);
      match(uCParser::T__9);
      setState(390);
      expression();
      setState(391);
      match(uCParser::T__10);
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

uCParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::VariableIdentifierContext* uCParser::VariableContext::variableIdentifier() {
  return getRuleContext<uCParser::VariableIdentifierContext>(0);
}

std::vector<uCParser::ModifierContext *> uCParser::VariableContext::modifier() {
  return getRuleContexts<uCParser::ModifierContext>();
}

uCParser::ModifierContext* uCParser::VariableContext::modifier(size_t i) {
  return getRuleContext<uCParser::ModifierContext>(i);
}


size_t uCParser::VariableContext::getRuleIndex() const {
  return uCParser::RuleVariable;
}


antlrcpp::Any uCParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

uCParser::VariableContext* uCParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 76, uCParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    variableIdentifier();
    setState(399);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == uCParser::T__2) {
      setState(396);
      modifier();
      setState(401);
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

uCParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::IndexContext* uCParser::ModifierContext::index() {
  return getRuleContext<uCParser::IndexContext>(0);
}


size_t uCParser::ModifierContext::getRuleIndex() const {
  return uCParser::RuleModifier;
}


antlrcpp::Any uCParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

uCParser::ModifierContext* uCParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 78, uCParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(402);
    match(uCParser::T__2);
    setState(403);
    index();
    setState(404);
    match(uCParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

uCParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::ExpressionContext* uCParser::IndexContext::expression() {
  return getRuleContext<uCParser::ExpressionContext>(0);
}


size_t uCParser::IndexContext::getRuleIndex() const {
  return uCParser::RuleIndex;
}


antlrcpp::Any uCParser::IndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitIndex(this);
  else
    return visitor->visitChildren(this);
}

uCParser::IndexContext* uCParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 80, uCParser::RuleIndex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
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

uCParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::VariableIdentifierContext::IDENTIFIER() {
  return getToken(uCParser::IDENTIFIER, 0);
}


size_t uCParser::VariableIdentifierContext::getRuleIndex() const {
  return uCParser::RuleVariableIdentifier;
}


antlrcpp::Any uCParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

uCParser::VariableIdentifierContext* uCParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 82, uCParser::RuleVariableIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(408);
    match(uCParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

uCParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::UnsignedNumberContext* uCParser::NumberContext::unsignedNumber() {
  return getRuleContext<uCParser::UnsignedNumberContext>(0);
}

uCParser::SignContext* uCParser::NumberContext::sign() {
  return getRuleContext<uCParser::SignContext>(0);
}


size_t uCParser::NumberContext::getRuleIndex() const {
  return uCParser::RuleNumber;
}


antlrcpp::Any uCParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

uCParser::NumberContext* uCParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 84, uCParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == uCParser::T__13) {
      setState(410);
      sign();
    }
    setState(413);
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

uCParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

uCParser::IntegerConstantContext* uCParser::UnsignedNumberContext::integerConstant() {
  return getRuleContext<uCParser::IntegerConstantContext>(0);
}

uCParser::RealConstantContext* uCParser::UnsignedNumberContext::realConstant() {
  return getRuleContext<uCParser::RealConstantContext>(0);
}


size_t uCParser::UnsignedNumberContext::getRuleIndex() const {
  return uCParser::RuleUnsignedNumber;
}


antlrcpp::Any uCParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

uCParser::UnsignedNumberContext* uCParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 86, uCParser::RuleUnsignedNumber);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(417);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case uCParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(415);
        integerConstant();
        break;
      }

      case uCParser::REAL: {
        enterOuterAlt(_localctx, 2);
        setState(416);
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

uCParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t uCParser::SignContext::getRuleIndex() const {
  return uCParser::RuleSign;
}


antlrcpp::Any uCParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

uCParser::SignContext* uCParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 88, uCParser::RuleSign);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(419);
    match(uCParser::T__13);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerConstantContext ------------------------------------------------------------------

uCParser::IntegerConstantContext::IntegerConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::IntegerConstantContext::INTEGER() {
  return getToken(uCParser::INTEGER, 0);
}


size_t uCParser::IntegerConstantContext::getRuleIndex() const {
  return uCParser::RuleIntegerConstant;
}


antlrcpp::Any uCParser::IntegerConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitIntegerConstant(this);
  else
    return visitor->visitChildren(this);
}

uCParser::IntegerConstantContext* uCParser::integerConstant() {
  IntegerConstantContext *_localctx = _tracker.createInstance<IntegerConstantContext>(_ctx, getState());
  enterRule(_localctx, 90, uCParser::RuleIntegerConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(uCParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RealConstantContext ------------------------------------------------------------------

uCParser::RealConstantContext::RealConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::RealConstantContext::REAL() {
  return getToken(uCParser::REAL, 0);
}


size_t uCParser::RealConstantContext::getRuleIndex() const {
  return uCParser::RuleRealConstant;
}


antlrcpp::Any uCParser::RealConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitRealConstant(this);
  else
    return visitor->visitChildren(this);
}

uCParser::RealConstantContext* uCParser::realConstant() {
  RealConstantContext *_localctx = _tracker.createInstance<RealConstantContext>(_ctx, getState());
  enterRule(_localctx, 92, uCParser::RuleRealConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(423);
    match(uCParser::REAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

uCParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t uCParser::RelOpContext::getRuleIndex() const {
  return uCParser::RuleRelOp;
}


antlrcpp::Any uCParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

uCParser::RelOpContext* uCParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 94, uCParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__14)
      | (1ULL << uCParser::T__15)
      | (1ULL << uCParser::T__16)
      | (1ULL << uCParser::T__17)
      | (1ULL << uCParser::T__18)
      | (1ULL << uCParser::T__19))) != 0))) {
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

uCParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t uCParser::AddOpContext::getRuleIndex() const {
  return uCParser::RuleAddOp;
}


antlrcpp::Any uCParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

uCParser::AddOpContext* uCParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 96, uCParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__13)
      | (1ULL << uCParser::T__20)
      | (1ULL << uCParser::T__21))) != 0))) {
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

uCParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t uCParser::MulOpContext::getRuleIndex() const {
  return uCParser::RuleMulOp;
}


antlrcpp::Any uCParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

uCParser::MulOpContext* uCParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 98, uCParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::T__22)
      | (1ULL << uCParser::T__23)
      | (1ULL << uCParser::T__24))) != 0))) {
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

uCParser::TypeIdentifierContext::TypeIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::TypeIdentifierContext::INT() {
  return getToken(uCParser::INT, 0);
}

tree::TerminalNode* uCParser::TypeIdentifierContext::BOOL() {
  return getToken(uCParser::BOOL, 0);
}

tree::TerminalNode* uCParser::TypeIdentifierContext::FLOAT() {
  return getToken(uCParser::FLOAT, 0);
}

tree::TerminalNode* uCParser::TypeIdentifierContext::VOID() {
  return getToken(uCParser::VOID, 0);
}


size_t uCParser::TypeIdentifierContext::getRuleIndex() const {
  return uCParser::RuleTypeIdentifier;
}


antlrcpp::Any uCParser::TypeIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitTypeIdentifier(this);
  else
    return visitor->visitChildren(this);
}

uCParser::TypeIdentifierContext* uCParser::typeIdentifier() {
  TypeIdentifierContext *_localctx = _tracker.createInstance<TypeIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 100, uCParser::RuleTypeIdentifier);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << uCParser::INT)
      | (1ULL << uCParser::BOOL)
      | (1ULL << uCParser::FLOAT)
      | (1ULL << uCParser::VOID))) != 0))) {
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

uCParser::CharacterConstantContext::CharacterConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::CharacterConstantContext::CHARACTER() {
  return getToken(uCParser::CHARACTER, 0);
}


size_t uCParser::CharacterConstantContext::getRuleIndex() const {
  return uCParser::RuleCharacterConstant;
}


antlrcpp::Any uCParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

uCParser::CharacterConstantContext* uCParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 102, uCParser::RuleCharacterConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(uCParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

uCParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* uCParser::StringConstantContext::STRING() {
  return getToken(uCParser::STRING, 0);
}


size_t uCParser::StringConstantContext::getRuleIndex() const {
  return uCParser::RuleStringConstant;
}


antlrcpp::Any uCParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<uCVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

uCParser::StringConstantContext* uCParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 104, uCParser::RuleStringConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    match(uCParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> uCParser::_decisionToDFA;
atn::PredictionContextCache uCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN uCParser::_atn;
std::vector<uint16_t> uCParser::_serializedATN;

std::vector<std::string> uCParser::_ruleNames = {
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

std::vector<std::string> uCParser::_literalNames = {
  "", "';'", "','", "'['", "']'", "'='", "'++'", "'--'", "'{'", "'}'", "'('", 
  "')'", "':'", "'!'", "'-'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", 
  "'+'", "'||'", "'*'", "'/'", "'&&'", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "'[]'", "'''", "'\"'", "'//'"
};

std::vector<std::string> uCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "INT", "BOOL", "FLOAT", "VOID", "DO", 
  "WHILE", "FOR", "IF", "ELSEIF", "ELSE", "SWITCH", "PRINT", "PRINTLN", 
  "READ", "READLN", "RETURN", "ARRAYINDICATOR", "SINGLEQUOTE", "DOUBLEQUOTE", 
  "DOUBLESLASH", "IDENTIFIER", "INTEGER", "REAL", "CHARACTER", "STRING", 
  "NEWLINE", "WS", "COMMENT"
};

dfa::Vocabulary uCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> uCParser::_tokenNames;

uCParser::Initializer::Initializer() {
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
    0x3, 0x37, 0x1b8, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4, 0x36, 0x9, 0x36, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x74, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x75, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x81, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x8c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x94, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x97, 0xb, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 
    0x9f, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0xa2, 0xb, 0x6, 0x5, 0x6, 0xa4, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0xb2, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xb6, 0xa, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xbd, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0xc0, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xc9, 0xa, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x5, 0xf, 0xdb, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x5, 0xf, 0xe1, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xf2, 0xa, 0x10, 
    0xc, 0x10, 0xe, 0x10, 0xf5, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0xf9, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x103, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 
    0x14, 0x10c, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x10f, 0xb, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x7, 0x15, 0x113, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 
    0x116, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x5, 0x17, 0x11e, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x5, 0x18, 0x123, 0xa, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x7, 0x19, 0x12a, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x12d, 
    0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x139, 
    0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 
    0x1d, 0x140, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x143, 0xb, 0x1d, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x148, 0xa, 0x1e, 0x3, 0x1f, 
    0x5, 0x1f, 0x14b, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
    0x150, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
    0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x161, 0xa, 0x23, 
    0xc, 0x23, 0xe, 0x23, 0x164, 0xb, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x16a, 0xa, 0x24, 0x3, 0x25, 0x5, 0x25, 0x16d, 
    0xa, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x173, 
    0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x176, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 0x17c, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 
    0x17f, 0xb, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
    0x27, 0x18c, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 0x190, 0xa, 
    0x28, 0xc, 0x28, 0xe, 0x28, 0x193, 0xb, 0x28, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2c, 0x5, 0x2c, 0x19e, 0xa, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x5, 0x2d, 0x1a4, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 
    0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x2, 0x2, 0x37, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 
    0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 
    0x6a, 0x2, 0x6, 0x3, 0x2, 0x11, 0x16, 0x4, 0x2, 0x10, 0x10, 0x17, 0x18, 
    0x3, 0x2, 0x19, 0x1b, 0x3, 0x2, 0x1c, 0x1f, 0x2, 0x1b9, 0x2, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x80, 0x3, 0x2, 0x2, 0x2, 0x6, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xa, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xe, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x10, 0xb5, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x14, 0xb9, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xca, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd7, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x24, 0x106, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x108, 0x3, 0x2, 0x2, 0x2, 0x28, 0x110, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x119, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x11f, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x126, 0x3, 0x2, 0x2, 0x2, 0x32, 0x12e, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x130, 0x3, 0x2, 0x2, 0x2, 0x36, 0x135, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x144, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x153, 0x3, 0x2, 0x2, 0x2, 0x42, 0x158, 0x3, 0x2, 0x2, 0x2, 0x44, 0x15d, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x165, 0x3, 0x2, 0x2, 0x2, 0x48, 0x16c, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x177, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x18b, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x194, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x198, 0x3, 0x2, 0x2, 0x2, 0x54, 0x19a, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x1a5, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1a9, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1ad, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1b1, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1b5, 0x3, 0x2, 0x2, 
    0x2, 0x6c, 0x74, 0x5, 0x20, 0x11, 0x2, 0x6d, 0x6e, 0x5, 0x22, 0x12, 
    0x2, 0x6e, 0x6f, 0x7, 0x3, 0x2, 0x2, 0x6f, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x70, 0x71, 0x5, 0xa, 0x6, 0x2, 0x71, 0x72, 0x7, 0x3, 0x2, 0x2, 0x72, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x73, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0x70, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x3, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x5, 0x22, 0x12, 
    0x2, 0x78, 0x79, 0x7, 0x3, 0x2, 0x2, 0x79, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0x7b, 0x5, 0x6, 0x4, 0x2, 0x7b, 0x7c, 0x7, 0x3, 0x2, 0x2, 0x7c, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x8, 0x5, 0x2, 0x7e, 0x7f, 
    0x7, 0x3, 0x2, 0x2, 0x7f, 0x81, 0x3, 0x2, 0x2, 0x2, 0x80, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x5, 0x3, 0x2, 0x2, 0x2, 0x82, 0x8c, 0x5, 0xe, 0x8, 
    0x2, 0x83, 0x8c, 0x5, 0xa, 0x6, 0x2, 0x84, 0x8c, 0x5, 0x16, 0xc, 0x2, 
    0x85, 0x8c, 0x5, 0x34, 0x1b, 0x2, 0x86, 0x8c, 0x5, 0x36, 0x1c, 0x2, 
    0x87, 0x8c, 0x5, 0x40, 0x21, 0x2, 0x88, 0x8c, 0x5, 0x42, 0x22, 0x2, 
    0x89, 0x8c, 0x5, 0x2e, 0x18, 0x2, 0x8a, 0x8c, 0x5, 0x2c, 0x17, 0x2, 
    0x8b, 0x82, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x83, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x85, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x5, 0x66, 0x34, 0x2, 
    0x90, 0x95, 0x5, 0x54, 0x2b, 0x2, 0x91, 0x92, 0x7, 0x4, 0x2, 0x2, 0x92, 
    0x94, 0x5, 0x54, 0x2b, 0x2, 0x93, 0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x96, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x99, 0x5, 0x66, 0x34, 0x2, 0x99, 0xa0, 0x5, 0x54, 0x2b, 
    0x2, 0x9a, 0x9b, 0x7, 0x5, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0xc, 0x7, 0x2, 
    0x9c, 0x9d, 0x7, 0x6, 0x2, 0x2, 0x9d, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xa2, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa3, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa6, 0x7, 0x31, 0x2, 0x2, 0xa6, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xa7, 0xa8, 0x5, 0x10, 0x9, 0x2, 0xa8, 0xa9, 0x7, 0x7, 0x2, 0x2, 0xa9, 
    0xaa, 0x5, 0x12, 0xa, 0x2, 0xaa, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 
    0x5, 0x4e, 0x28, 0x2, 0xac, 0xad, 0x7, 0x8, 0x2, 0x2, 0xad, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xaf, 0x5, 0x4e, 0x28, 0x2, 0xaf, 0xb0, 0x7, 0x9, 
    0x2, 0x2, 0xb0, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0xb1, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb6, 0x5, 0x4e, 0x28, 0x2, 0xb4, 
    0xb6, 0x5, 0xa, 0x6, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0x11, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x5, 
    0x46, 0x24, 0x2, 0xb8, 0x13, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xbe, 0x7, 0xa, 
    0x2, 0x2, 0xba, 0xbd, 0x5, 0x4, 0x3, 0x2, 0xbb, 0xbd, 0x5, 0x16, 0xc, 
    0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0xbf, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0xb, 0x2, 0x2, 0xc2, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xc3, 0xc9, 0x5, 0x18, 0xd, 0x2, 0xc4, 0xc9, 0x5, 0x1a, 
    0xe, 0x2, 0xc5, 0xc9, 0x5, 0x1c, 0xf, 0x2, 0xc6, 0xc9, 0x5, 0x1e, 0x10, 
    0x2, 0xc7, 0xc9, 0x5, 0x14, 0xb, 0x2, 0xc8, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x20, 0x2, 0x2, 0xcb, 0xcc, 0x5, 
    0x14, 0xb, 0x2, 0xcc, 0xcd, 0x7, 0x21, 0x2, 0x2, 0xcd, 0xce, 0x7, 0xc, 
    0x2, 0x2, 0xce, 0xcf, 0x5, 0x46, 0x24, 0x2, 0xcf, 0xd0, 0x7, 0xd, 0x2, 
    0x2, 0xd0, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x7, 0x21, 0x2, 0x2, 
    0xd2, 0xd3, 0x7, 0xc, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x46, 0x24, 0x2, 0xd4, 
    0xd5, 0x7, 0xd, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x14, 0xb, 0x2, 0xd6, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x7, 0x22, 0x2, 0x2, 0xd8, 0xda, 0x7, 
    0xc, 0x2, 0x2, 0xd9, 0xdb, 0x5, 0x6, 0x4, 0x2, 0xda, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0xdc, 0xdd, 0x7, 0x3, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x46, 0x24, 0x2, 
    0xde, 0xe0, 0x7, 0x3, 0x2, 0x2, 0xdf, 0xe1, 0x5, 0x6, 0x4, 0x2, 0xe0, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0xd, 0x2, 0x2, 0xe3, 0xe4, 0x5, 
    0x14, 0xb, 0x2, 0xe4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x7, 0x23, 
    0x2, 0x2, 0xe6, 0xe7, 0x7, 0xc, 0x2, 0x2, 0xe7, 0xe8, 0x5, 0x46, 0x24, 
    0x2, 0xe8, 0xe9, 0x7, 0xd, 0x2, 0x2, 0xe9, 0xf3, 0x5, 0x14, 0xb, 0x2, 
    0xea, 0xeb, 0x7, 0x25, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x23, 0x2, 0x2, 0xec, 
    0xed, 0x7, 0xc, 0x2, 0x2, 0xed, 0xee, 0x5, 0x46, 0x24, 0x2, 0xee, 0xef, 
    0x7, 0xd, 0x2, 0x2, 0xef, 0xf0, 0x5, 0x14, 0xb, 0x2, 0xf0, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xea, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 
    0x2, 0xf4, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xf7, 0x7, 0x25, 0x2, 0x2, 0xf7, 0xf9, 0x5, 0x14, 0xb, 0x2, 0xf8, 
    0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x22, 0x12, 0x2, 0xfb, 0xfc, 0x5, 
    0x14, 0xb, 0x2, 0xfc, 0x21, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x66, 
    0x34, 0x2, 0xfe, 0xff, 0x5, 0x24, 0x13, 0x2, 0xff, 0x102, 0x7, 0xc, 
    0x2, 0x2, 0x100, 0x103, 0x5, 0x26, 0x14, 0x2, 0x101, 0x103, 0x7, 0x1f, 
    0x2, 0x2, 0x102, 0x100, 0x3, 0x2, 0x2, 0x2, 0x102, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x102, 0x103, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x104, 0x105, 0x7, 0xd, 0x2, 0x2, 0x105, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x107, 0x7, 0x30, 0x2, 0x2, 0x107, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x108, 0x10d, 0x5, 0x28, 0x15, 0x2, 0x109, 0x10a, 0x7, 0x4, 0x2, 
    0x2, 0x10a, 0x10c, 0x5, 0x28, 0x15, 0x2, 0x10b, 0x109, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 
    0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x110, 0x114, 0x5, 0x66, 0x34, 0x2, 
    0x111, 0x113, 0x7, 0x2c, 0x2, 0x2, 0x112, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x113, 0x116, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 
    0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x5, 0x2a, 0x16, 0x2, 
    0x118, 0x29, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x30, 0x2, 0x2, 
    0x11a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11d, 0x7, 0x2b, 0x2, 0x2, 
    0x11c, 0x11e, 0x5, 0x46, 0x24, 0x2, 0x11d, 0x11c, 0x3, 0x2, 0x2, 0x2, 
    0x11d, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x120, 0x5, 0x24, 0x13, 0x2, 0x120, 0x122, 0x7, 0xc, 0x2, 0x2, 0x121, 
    0x123, 0x5, 0x30, 0x19, 0x2, 0x122, 0x121, 0x3, 0x2, 0x2, 0x2, 0x122, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x125, 0x7, 0xd, 0x2, 0x2, 0x125, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x126, 0x12b, 
    0x5, 0x32, 0x1a, 0x2, 0x127, 0x128, 0x7, 0x4, 0x2, 0x2, 0x128, 0x12a, 
    0x5, 0x32, 0x1a, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12d, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x31, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x12e, 0x12f, 0x5, 0x46, 0x24, 0x2, 0x12f, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x130, 0x131, 0x7, 0x27, 0x2, 0x2, 0x131, 0x132, 0x7, 
    0xc, 0x2, 0x2, 0x132, 0x133, 0x5, 0x38, 0x1d, 0x2, 0x133, 0x134, 0x7, 
    0xd, 0x2, 0x2, 0x134, 0x35, 0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x7, 0x28, 
    0x2, 0x2, 0x136, 0x138, 0x7, 0xc, 0x2, 0x2, 0x137, 0x139, 0x5, 0x38, 
    0x1d, 0x2, 0x138, 0x137, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x139, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 0x7, 0xd, 
    0x2, 0x2, 0x13b, 0x37, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x141, 0x5, 0x3a, 
    0x1e, 0x2, 0x13d, 0x13e, 0x7, 0x4, 0x2, 0x2, 0x13e, 0x140, 0x5, 0x3a, 
    0x1e, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x140, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 
    0x2, 0x2, 0x142, 0x39, 0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 
    0x2, 0x144, 0x147, 0x5, 0x46, 0x24, 0x2, 0x145, 0x146, 0x7, 0xe, 0x2, 
    0x2, 0x146, 0x148, 0x5, 0x3c, 0x1f, 0x2, 0x147, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x147, 0x148, 0x3, 0x2, 0x2, 0x2, 0x148, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x14b, 0x5, 0x5a, 0x2e, 0x2, 0x14a, 0x149, 0x3, 0x2, 0x2, 0x2, 
    0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x14c, 0x14f, 0x5, 0x5c, 0x2f, 0x2, 0x14d, 0x14e, 0x7, 0xe, 0x2, 0x2, 
    0x14e, 0x150, 0x5, 0x3e, 0x20, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x151, 
    0x152, 0x5, 0x5c, 0x2f, 0x2, 0x152, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x153, 
    0x154, 0x7, 0x29, 0x2, 0x2, 0x154, 0x155, 0x7, 0xc, 0x2, 0x2, 0x155, 
    0x156, 0x5, 0x44, 0x23, 0x2, 0x156, 0x157, 0x7, 0xd, 0x2, 0x2, 0x157, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0x158, 0x159, 0x7, 0x2a, 0x2, 0x2, 0x159, 
    0x15a, 0x7, 0xc, 0x2, 0x2, 0x15a, 0x15b, 0x5, 0x44, 0x23, 0x2, 0x15b, 
    0x15c, 0x7, 0xd, 0x2, 0x2, 0x15c, 0x43, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x162, 
    0x5, 0x4e, 0x28, 0x2, 0x15e, 0x15f, 0x7, 0x4, 0x2, 0x2, 0x15f, 0x161, 
    0x5, 0x4e, 0x28, 0x2, 0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 
    0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 
    0x3, 0x2, 0x2, 0x2, 0x163, 0x45, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 
    0x2, 0x2, 0x2, 0x165, 0x169, 0x5, 0x48, 0x25, 0x2, 0x166, 0x167, 0x5, 
    0x60, 0x31, 0x2, 0x167, 0x168, 0x5, 0x48, 0x25, 0x2, 0x168, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x169, 0x166, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x16a, 0x47, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16d, 0x5, 0x5a, 
    0x2e, 0x2, 0x16c, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x3, 0x2, 
    0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x174, 0x5, 0x4a, 
    0x26, 0x2, 0x16f, 0x170, 0x5, 0x62, 0x32, 0x2, 0x170, 0x171, 0x5, 0x4a, 
    0x26, 0x2, 0x171, 0x173, 0x3, 0x2, 0x2, 0x2, 0x172, 0x16f, 0x3, 0x2, 
    0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 0x2, 0x174, 0x172, 0x3, 0x2, 
    0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17d, 0x5, 0x4c, 0x27, 
    0x2, 0x178, 0x179, 0x5, 0x64, 0x33, 0x2, 0x179, 0x17a, 0x5, 0x4c, 0x27, 
    0x2, 0x17a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x178, 0x3, 0x2, 0x2, 
    0x2, 0x17c, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x180, 0x18c, 0x5, 0x4e, 0x28, 0x2, 
    0x181, 0x18c, 0x5, 0x56, 0x2c, 0x2, 0x182, 0x18c, 0x5, 0x68, 0x35, 0x2, 
    0x183, 0x18c, 0x5, 0x6a, 0x36, 0x2, 0x184, 0x18c, 0x5, 0x2e, 0x18, 0x2, 
    0x185, 0x186, 0x7, 0xf, 0x2, 0x2, 0x186, 0x18c, 0x5, 0x4c, 0x27, 0x2, 
    0x187, 0x188, 0x7, 0xc, 0x2, 0x2, 0x188, 0x189, 0x5, 0x46, 0x24, 0x2, 
    0x189, 0x18a, 0x7, 0xd, 0x2, 0x2, 0x18a, 0x18c, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x180, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x181, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x182, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x183, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x184, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x185, 0x3, 0x2, 0x2, 0x2, 
    0x18b, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x18d, 
    0x191, 0x5, 0x54, 0x2b, 0x2, 0x18e, 0x190, 0x5, 0x50, 0x29, 0x2, 0x18f, 
    0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x193, 0x3, 0x2, 0x2, 0x2, 0x191, 
    0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x3, 0x2, 0x2, 0x2, 0x192, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 0x2, 0x2, 0x194, 0x195, 
    0x7, 0x5, 0x2, 0x2, 0x195, 0x196, 0x5, 0x52, 0x2a, 0x2, 0x196, 0x197, 
    0x7, 0x6, 0x2, 0x2, 0x197, 0x51, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x5, 
    0x46, 0x24, 0x2, 0x199, 0x53, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x7, 
    0x30, 0x2, 0x2, 0x19b, 0x55, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19e, 0x5, 
    0x5a, 0x2e, 0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 
    0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x5, 
    0x58, 0x2d, 0x2, 0x1a0, 0x57, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a4, 0x5, 
    0x5c, 0x2f, 0x2, 0x1a2, 0x1a4, 0x5, 0x5e, 0x30, 0x2, 0x1a3, 0x1a1, 0x3, 
    0x2, 0x2, 0x2, 0x1a3, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x1a5, 0x1a6, 0x7, 0x10, 0x2, 0x2, 0x1a6, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x1a7, 0x1a8, 0x7, 0x31, 0x2, 0x2, 0x1a8, 0x5d, 0x3, 0x2, 
    0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x32, 0x2, 0x2, 0x1aa, 0x5f, 0x3, 0x2, 
    0x2, 0x2, 0x1ab, 0x1ac, 0x9, 0x2, 0x2, 0x2, 0x1ac, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x1ad, 0x1ae, 0x9, 0x3, 0x2, 0x2, 0x1ae, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x1af, 0x1b0, 0x9, 0x4, 0x2, 0x2, 0x1b0, 0x65, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1b2, 0x9, 0x5, 0x2, 0x2, 0x1b2, 0x67, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 
    0x7, 0x33, 0x2, 0x2, 0x1b4, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 
    0x7, 0x34, 0x2, 0x2, 0x1b6, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x73, 0x75, 
    0x80, 0x8b, 0x95, 0xa0, 0xa3, 0xb1, 0xb5, 0xbc, 0xbe, 0xc8, 0xda, 0xe0, 
    0xf3, 0xf8, 0x102, 0x10d, 0x114, 0x11d, 0x122, 0x12b, 0x138, 0x141, 
    0x147, 0x14a, 0x14f, 0x162, 0x169, 0x16c, 0x174, 0x17d, 0x18b, 0x191, 
    0x19d, 0x1a3, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

uCParser::Initializer uCParser::_init;
