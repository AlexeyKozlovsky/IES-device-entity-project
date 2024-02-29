#ifndef CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYREGCARDIMPL1_H_
#define CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYREGCARDIMPL1_H_

#include <modbuswrappers/modbuswrapper.h>
#include <utils/services/domain/regreaddivider.h>
#include <utils/services/domain/valueconverter.h>
#include <modbuswrappers/modbuspostponedwritewrapper/modbuspostponedwritewrapper.h>

#include "device/entity/deviceentity.h"


class DeviceEntityRegCardImpl1: public DeviceEntityRegCard {
 public:
  explicit DeviceEntityRegCardImpl1(std::shared_ptr<ModbusWrapper> modbus_wrapper);

  void setConnectionStatus(bool connection_status) override;
  bool getConnectionStatus() override;
  ErrorCode connect() override;
  ErrorCode disconnect() override;

  void updateRegCard() override;
  ErrorCode loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) override;
  std::shared_ptr<DeviceEntityDTO> updateDeviceDTO() override;

 private:
  /**
   * Основной модбас враппер
   */
  std::shared_ptr<ModbusWrapper> _modbus_wrapper = nullptr;


  bool _connection_status = false;

  std::shared_ptr<RegReadDivider> _reg_read_divider = nullptr;
};

#endif //CPSDEVICESTANDALONEPLUGIN_DEVICEPLUGIN_ENTITY_IMPLS_STANDALONEIMPL1_DEVICEENTITYREGCARDIMPL1_H_
