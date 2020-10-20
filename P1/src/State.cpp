#include "../include/State.h"

State::State(/* args */) :
stateName("@"),
isInitial(0),
isFinal(0) {
}

State::~State() {
}

State::State(std::string name) :
stateName(name),
isInitial(0),
isFinal(0) {

}
