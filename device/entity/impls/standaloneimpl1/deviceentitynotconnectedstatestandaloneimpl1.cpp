#include "deviceentitynotconnectedstatestandaloneimpl1.h"
#include "device/entity/consts.h"

// TODO: Прописать потом ошибки коннекта

ErrorCode DeviceEntityNotConnectedStateStandaloneImpl1::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  return DeviceEntityState::loadDeviceDTO(dto);
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityNotConnectedStateStandaloneImpl1::updateDeviceDTO() {
  return DeviceEntityState::updateDeviceDTO();
}
