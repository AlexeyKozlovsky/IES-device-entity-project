#include <iostream>

#include <modbuswrappers/modbusclientwrapper/modbusclientwrapperfactory.h>
#include <modbuswrappers/mocks/modbuswrappermockfactory.h>

#include "device/entity/impls/standaloneimpl1/deviceentityfactorystandaloneimpl1.h"
#include "device/entity/devicetypes.h"

int main() {
  auto modbus_wrapper_factory = std::make_shared<ModbusWrapperMockFactory>();
  auto device_entity_factory = std::make_shared<DeviceEntityFactoryStandaloneImpl1>();


  std::string ip = "192.168.127.10";
  int port = 4001;
  int modbus_id = 1;

  auto modbus_wrapper = modbus_wrapper_factory->createBaseModbusWrapper(ip, port);


  if (modbus_wrapper != nullptr) {
    auto dto = std::make_shared<DeviceEntityDTO>();
    // Здесь можно провести инициализацию DTO
    auto device_entity = device_entity_factory->createDeviceEntity(modbus_wrapper, dto);
    if (device_entity != nullptr) {
      std::cout << "SUCCESSFULLY CREATED DEVICE " << std::endl;
    } else {
      std::cerr << "Device entity creation error " << std::endl;
    }

  } else {
    std::cerr << "Error while creating modbus wrapper " << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Hello, World!" << std::endl;
  return EXIT_SUCCESS;
}
