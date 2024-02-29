#include "deviceentityregcardimpl1.h"

#include <utils/modbusutils.h>

#include "device/entity/consts.h"


DeviceEntityRegCardImpl1::DeviceEntityRegCardImpl1(std::shared_ptr<ModbusWrapper> modbus_wrapper) :
    _modbus_wrapper(modbus_wrapper) {

}

void DeviceEntityRegCardImpl1::setConnectionStatus(bool connection_status) {
  _connection_status = connection_status;
}

bool DeviceEntityRegCardImpl1::getConnectionStatus() {
  return _connection_status;
}

ErrorCode DeviceEntityRegCardImpl1::connect() {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_wrapper != nullptr) {
    bool connection_result = _modbus_wrapper->connect();
    _modbus_wrapper->isConnected(connection_result);
    setConnectionStatus(connection_result);
    if (connection_result) {
      result = SUCCESS;
    }
  }
  return result;
}

ErrorCode DeviceEntityRegCardImpl1::disconnect() {
  auto result = OPERATION_INTERRUPTED;
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->disconnect();
    setConnectionStatus(false);
    result = SUCCESS;
  }
  return result;
}

void DeviceEntityRegCardImpl1::updateRegCard() {
  if (_modbus_wrapper != nullptr) {
    _modbus_wrapper->process();
  }
}

ErrorCode DeviceEntityRegCardImpl1::loadDeviceDTO(const std::shared_ptr<DeviceEntityDTO> &dto) {
  ErrorCode result = OPERATION_INTERRUPTED;

  return result;
}

std::shared_ptr<DeviceEntityDTO> DeviceEntityRegCardImpl1::updateDeviceDTO() {
  return DeviceEntityState::updateDeviceDTO();
}
