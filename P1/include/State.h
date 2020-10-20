#pragma once
#include <string>

const bool INITIAL = true;
const bool FINAL = false;


class State {
 private:
  std::string stateName;
  bool isInitial;
  bool isFinal;

 public:
  State(/* args */);
  State(std::string);
  ~State();
  inline void setState(std::string name) { stateName = name; };
  inline void setToInitial(void) { isInitial = true; };
  inline void setToFinal(void) { isFinal = true; };
  inline bool isStateInitial(void) { return isInitial; };
  inline bool isStateFinal(void) { return isFinal; };
  inline std::string getStateName() { return stateName; };
  inline bool operator<(const State& st) const {
    return stateName < st.stateName;
  };
  friend std::ostream& operator<<(std::ostream& os, const State& st) {
    return os << st.stateName;
  }
};