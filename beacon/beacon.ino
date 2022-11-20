
// ----------------------------------------------------
// Radiar un beacon
// Laura Pamies
// ----------------------------------------------------
#include <bluefruit.h>
// ----------------------------------------------------
// setup
// ----------------------------------------------------


void setup() {
   //
   //
   //
   Serial.begin(115200);
  // while ( !Serial ) delay(10);

   Serial.println("-----------------------\n");
   Serial.println(" Beacon Laura  ");
   Serial.println("-----------------------\n");

   //
   // Initialise the Bluefruit module
   //
   Serial.println("Initialise the Bluefruit nRF52 module");
   Bluefruit.begin();

   //
   // Set the advertised device name (keep it short!)
   //
   Serial.println("Setting Device Name to Beacon(Laura) " );

   Bluefruit.setName("Beacon(Laura)");
   Bluefruit.ScanResponse.addName();

   //
   //


   //
   

   //
   //
   //
   Serial.println("\nAdvertising");

} // setup()
 
 // ----------------------------------------------------
// ----------------------------------------------------
void startAdvertising(int cont) {
 

   Serial.println( " startAdvertising() " );

   Serial.println( " Bluefruit.Advertising.stop(); ");
   Bluefruit.Advertising.stop(); // ya lo enchufo luego

   //
   // Advertising packet
   //
   Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
   Bluefruit.Advertising.addTxPower();

   //
   //
   //


  

   // Include Name
   Serial.println( " Bluefruit.Advertising.addName(); " );
   Bluefruit.Advertising.addName();

   //
   //
   //
   Serial.println( " Bluefruit.Advertising.setBeacon( elBeacon ); ");

   uint8_t beaconUUID[16] = {
     'E', 'P', 'S', 'G', '-', 'G', 'T', 'I',
     '-', 'P', 'R', 'O', 'Y', '-', '3', 'A'
     };
   BLEBeacon elBeacon( beaconUUID, cont, 34, 73);
   elBeacon.setManufacturer( 0x004c ); // aple id
   Bluefruit.Advertising.setBeacon( elBeacon );

   //
   //
   //
   Bluefruit.Advertising.restartOnDisconnect(true);
   Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
   Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
   Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds

   Serial.println( " Bluefruit.Advertising.start(0);" );

} // startAdvertising ()

// ----------------------------------------------------
// ----------------------------------------------------
namespace Loop {
   int cont = 0;  //se inicia el contador a 0
};
// ....................................................

//-----------------------------------------------------
//  LOOP
//-----------------------------------------------------
void loop() { //se hace un contador automático iniciado en 0

   using namespace Loop;

   cont++;

   delay(1000);
   startAdvertising(cont);

   //erial.print( " ** loop cont=" );
   
   
   //Serial.println( cont );
} // ()
// ----------------------------------------------------
// ----------------------------------------------------
// ----------------------------------------------------
// ----------------------------------------------------