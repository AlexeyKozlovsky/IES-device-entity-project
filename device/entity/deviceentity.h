#ifndef TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_

#include <string>
#include <memory>

#include <modbuswrappers/connectable.h>
#include <threadpooling/iprocessable.h>

#include "device/basedevice.h"


#include "devicetypes.h"


class DeviceEntityState {
 public:
  /**
   * Метод, который позволяет на основании ДТО обновить девайс
   * @param dto
   * @return код ошибки, который является SUCCESS только в том случае, когда аппаратный девайс полностью обновился в соответствие с DTO
   */
  virtual ErrorCode loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {return OPERATION_INTERRUPTED;};


  /**
   * Метод, который позволяет сформироват  ь DTO по актуальным настройками аппаратного девайса
   * @return ДТО
   */
  virtual std::shared_ptr<DeviceEntityDTO> updateDeviceDTO() {return nullptr;};
};

class DeviceEntityRegCard: public DeviceEntityState, public Connectable {
 public:
  virtual void updateRegCard() = 0;
};

class DeviceEntity: public BaseDevice, public DeviceEntityState, public Connectable, public IProcessable {
 public:
  virtual std::shared_ptr<DeviceEntityDTO> getDeviceDTO() = 0;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_DEVICEPLUGINS_TESTDEVICEPLUGIN_ENTITY_TESTDEVICEENTITY_H_
