#ifndef CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYCONNECTEDSTATESTANDALONEIMPL1_H_
#define CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYCONNECTEDSTATESTANDALONEIMPL1_H_

#include <memory>

#include "device/entity/deviceentity.h"


class DeviceEntityConnectedStateStandaloneImpl1: public DeviceEntityState {
 public:
  explicit DeviceEntityConnectedStateStandaloneImpl1(const std::shared_ptr<DeviceEntity> &device_entity,
                                                     const std::shared_ptr<DeviceEntityRegCard> &reg_card);


  ErrorCode loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) override;
  std::shared_ptr<DeviceEntityDTO> updateDeviceDTO() override;

 private:
  std::shared_ptr<DeviceEntityRegCard> _reg_card = nullptr;
  std::shared_ptr<DeviceEntity> _device_entity = nullptr;
};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYCONNECTEDSTATESTANDALONEIMPL1_H_
