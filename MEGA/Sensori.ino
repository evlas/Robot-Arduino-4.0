void Read_Sensors() {
#if (NANO_Serial == true)
  Read_Nano();
#endif

#if (INA226_SENSOR == true)
  //inserire la parte che legge da nano i2c
  ina226.readAndClearFlags();

//  shuntVoltage_mV = ina226.getShuntVoltage_mV();
  Volts = ina226.getBusVoltage_V();
  Amps = ina226.getCurrent_mA() * 1000.0;
//  power_mW = ina226.getBusPower();
//  loadVoltage_V = busVoltage_V + (shuntVoltage_mV / 1000);

/*  if (!ina226.overflow) {
    Serial.println("Values OK - no overflow");
  } else {
    Serial.println("Overflow! Choose higher current range");
  }
  Serial.println();
*/
#endif

  Calculate_Volt_Amp_Charge();
}
