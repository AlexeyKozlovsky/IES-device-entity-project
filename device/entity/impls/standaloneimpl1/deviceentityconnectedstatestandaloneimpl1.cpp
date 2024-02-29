#include "deviceentityconnectedstatestandaloneimpl1.h"
#include "device/entity/consts.h"

#include <iostream>


DeviceEntityConnectedStateStandaloneImpl1::DeviceEntityConnectedStateStandaloneImpl1(const std::shared_ptr<DeviceEntity> &device_entity,
                                                                                     const std::shared_ptr<DeviceEntityRegCard> &reg_card):
 _reg_card(reg_card),
 _device_entity(device_entity) {

}


ErrorCode DeviceEntityConnectedStateStandaloneImpl1::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  // TODO: В мобдас враппере добавить функционал отложенной множественной записи. Чтобы можно было писать много регистров за раз из массива, который заполняется постепенно
  //  Как вариант, можно написать ещё одну обертку modbus, где это будет реализовано

  ErrorCode result = OPERATION_INTERRUPTED;
  if (dto != nullptr && _device_entity != nullptr) {
    auto device_name = dto->name;
    _device_entity->setDeviceName(device_name);

    auto device_description = dto->description;
    _device_entity->setDeviceDescription(device_description);
  }
  return result;
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityConnectedStateStandaloneImpl1::updateDeviceDTO() {
  // TODO: Дописать процесс формирования DTO
  return DeviceEntityState::updateDeviceDTO();
}
