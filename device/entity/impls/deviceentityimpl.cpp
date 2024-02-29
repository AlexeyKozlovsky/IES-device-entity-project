#include "deviceentityimpl.h"
#include "device/entity/consts.h"

#include <iostream>


DeviceEntityImpl::DeviceEntityImpl(const std::shared_ptr<DeviceEntityDTO> &dto): _dto(dto) {

}

std::string DeviceEntityImpl::getDeviceName() {
  std::string result = "";

  if (_dto != nullptr) {
    result = _dto->name;
  }

  return result;
}

void DeviceEntityImpl::setDeviceName(const std::string &name) {
  if (_dto != nullptr) {
    _dto->name = name;
  }
}

std::string DeviceEntityImpl::getDeviceDescription() {
  std::string result = "";

  if (_dto != nullptr) {
    result = _dto->description;
  }

  return result;
}

void DeviceEntityImpl::setDeviceDescription(const std::string &description) {
  if (_dto != nullptr) {
    _dto->description = description;
  }
}

DeviceState DeviceEntityImpl::getDeviceState() {
  return _current_state_key;
}


void DeviceEntityImpl::setConnectionStatus(bool connection_status) {
  if (connection_status) {
    changeState(CONNECTED);
    std::cout << "CHANGED:::::" << CONNECTED << std::endl;
  } else {
    changeState(NOT_CONNECTED);
  }
}

bool DeviceEntityImpl::getConnectionStatus() {
  auto result = false;

  if (_reg_card != nullptr) {
    result = _reg_card->getConnectionStatus();
    setConnectionStatus(result);
  }

  return result;
}

ErrorCode DeviceEntityImpl::connect() {
  auto result = OPERATION_INTERRUPTED;

  if (_reg_card != nullptr) {
    result = _reg_card->connect();
    getConnectionStatus();
  }

  return result;
}

ErrorCode DeviceEntityImpl::disconnect() {
  auto result = OPERATION_INTERRUPTED;

  if (_reg_card != nullptr) {
    result = _reg_card->disconnect();
    getConnectionStatus();
  }

  return result;
}

void DeviceEntityImpl::addState(const std::pair<DeviceState, std::shared_ptr<DeviceEntityState>> &state) {
  _states.insert(state);
}

void DeviceEntityImpl::setRegCard(const std::shared_ptr<DeviceEntityRegCard> &reg_card) {
  _reg_card = reg_card;
}

void DeviceEntityImpl::changeState(DeviceState state) {
  std::cout << "Connection change state " << state << " " << __func__ << std::endl;
  if (_states.count(state) != 0) {

    bool to_load_dto = false;
    if (_current_state_key != state && state == CONNECTED) {
      to_load_dto = true;
      std::cout << "TO LOAD DTO " << to_load_dto << " " << __func__ << std::endl;
    }

    _current_state_key = state;
    _current_state = _states[state];

    if (to_load_dto) {
      loadDeviceDTO(_dto);
    }


    std::cout << "CURRENT STATE CHANGED to " << state << " " << __func__ << std::endl;
  }
}

void DeviceEntityImpl::process() {
  if (_reg_card != nullptr) {
    _reg_card->updateRegCard();
  }
}

ErrorCode DeviceEntityImpl::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  ErrorCode result = OPERATION_INTERRUPTED;

  if (dto != nullptr) {
    _dto = dto;
    if (_current_state != nullptr) {
      result = _current_state->loadDeviceDTO(dto);
    }
  }

  return result;
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityImpl::updateDeviceDTO() {
  return DeviceEntityState::updateDeviceDTO();
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityImpl::getDeviceDTO() {
  return _dto;
}
