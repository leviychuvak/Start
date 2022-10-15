#include "token.h"

#include <stdexcept>

using namespace std;

vector<Token> Tokenize(istream& cl) {
  vector<Token> tokens;

  char c;
  while (cl >> c) {
    if (isdigit(c)) {
        string date{c};
      for (int i = 0; i < 3; ++i) {
        while (isdigit(cl.peek())) {
          date += cl.get();
        }
        if (i < 2) {
          date += cl.get(); // Consume '-'
        }
      }
      tokens.emplace_back(std::move(date), TokenType::DATE);
    } else if (c == '"') {
      string event;
      getline(cl, event, '"');
      tokens.emplace_back(std::move(event), TokenType::EVENT);
    } else if (c == 'd') {
      if (cl.get() == 'a' && cl.get() == 't' && cl.get() == 'e') {
        tokens.emplace_back("date", TokenType::COLUMN);
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == 'e') {
      if (cl.get() == 'v' && cl.get() == 'e' && cl.get() == 'n' &&
          cl.get() == 't') {
        tokens.emplace_back("event", TokenType::COLUMN);
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == 'A') {
      if (cl.get() == 'N' && cl.get() == 'D') {
        tokens.emplace_back("AND", TokenType::LOGICAL_OP);
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == 'O') {
      if (cl.get() == 'R') {
        tokens.emplace_back("OR", TokenType::LOGICAL_OP);
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == '(') {
      tokens.emplace_back("(", TokenType::PAREN_LEFT);
    } else if (c == ')') {
      tokens.emplace_back(")", TokenType::PAREN_RIGHT);
    } else if (c == '<') {
      if (cl.peek() == '=') {
        cl.get();
        tokens.emplace_back("<=", TokenType::COMPARE_OP);
      } else {
        tokens.emplace_back("<", TokenType::COMPARE_OP);
      }
    } else if (c == '>') {
      if (cl.peek() == '=') {
        cl.get();
        tokens.emplace_back(">=", TokenType::COMPARE_OP);
      } else {
        tokens.emplace_back(">", TokenType::COMPARE_OP);
      }
    } else if (c == '=') {
      if (cl.get() == '=') {
        tokens.emplace_back("==", TokenType::COMPARE_OP);
      } else {
        throw logic_error("Unknown token");
      }
    } else if (c == '!') {
      if (cl.get() == '=') {
        tokens.emplace_back("!=", TokenType::COMPARE_OP);
      } else {
        throw logic_error("Unknown token");
      }
    }
  }

  return tokens;
}
