#pragma once
#include <stdint.h>
#include "../hal.h"


#define UNDEF_PIN (-1)

/// General Features ///
#define LED_MAX_BRIGHTNESS 50 //0..255 for max led brightness

/////////////////////////

#define WORD_ALIGNED_ATTR __attribute__((aligned(4)))

#define ICACHE_RAM_ATTR //nothing//

#define DEVICE_NAME          "HM ES900TX"

#define USE_TX_BACKPACK

// GPIO pin definitions
/*
#define GPIO_PIN_NSS            5
#define GPIO_PIN_DIO0           26
#define GPIO_PIN_DIO1           25
#define GPIO_PIN_MOSI           23
#define GPIO_PIN_MISO           19
#define GPIO_PIN_SCK            18
#define GPIO_PIN_RST            14
#define GPIO_PIN_RX_ENABLE      13
#define GPIO_PIN_TX_ENABLE      12

#define GPIO_PIN_RCSIGNAL_RX    2
#define GPIO_PIN_RCSIGNAL_TX    2 // so we don't have to solder the extra resistor, we switch rx/tx using gpio mux
#define GPIO_PIN_LED_WS2812     27
#define GPIO_PIN_FAN_EN         17
#define GPIO_PIN_RFamp_APC2     25
*/
#define  ERFLY_BOARDI6 1

// Output Power
#define MinPower                PWR_10mW
#define HighPower               PWR_250mW
#define MaxPower                PWR_1000mW
#define POWER_OUTPUT_DACWRITE
#define POWER_OUTPUT_VALUES     {41,60,73,90,110,132,190}

#define WS2812_IS_GRB

#define  Regulatory_Domain_AU_915
#define  DBGLN(...) while(0){}
#define DBG(...) while(0){}
#define  INFOLN(...) while(0){}
 #define DBGCR

#define  delay mDelay
#ifndef NULL
#define  NULL 0
#endif

#define TARGET_TX 1

#define OUTPUT 1
#define  INPUT 0
#define LOW 0
#define  HIGH 1

#define nullptr 0

#define constexpr const

#if defined(Regulatory_Domain_ISM_2400)
// ISM 2400 band is use => undefine other requlatory domain defines
#undef Regulatory_Domain_AU_915
#undef Regulatory_Domain_EU_868
#undef Regulatory_Domain_IN_866
#undef Regulatory_Domain_FCC_915
#undef Regulatory_Domain_AU_433
#undef Regulatory_Domain_EU_433

#elif !(defined(Regulatory_Domain_AU_915) || defined(Regulatory_Domain_FCC_915) || \
        defined(Regulatory_Domain_EU_868) || defined(Regulatory_Domain_IN_866) || \
        defined(Regulatory_Domain_AU_433) || defined(Regulatory_Domain_EU_433) || \
        defined(UNIT_TEST))
#error "Regulatory_Domain is not defined for 900MHz devices. Check user_defines.txt!"
#endif
