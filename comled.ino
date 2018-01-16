/* El led azul integrado en el Photon está asociado al PIN D7
 * El botón esta conectado al PIN D1 */
int led = D7;
int button = D1;

int ledStatus; //0 - LOW, 1 - HIGH
int button_v;

void setup() {
    pinMode(led, OUTPUT); //led configurado como salida
    
    /* botón configurado como entrada con resistencia a tierra (PULLDOWN),
     * es decir, por defecto la entrada es 0 - LOW */
    pinMode(button, INPUT_PULLDOWN);
    
    /* Aquí se registra a la función ledCommand como la función "led"
     * la cual puede ser llamada desde un API query */
    Particle.function("led",ledCommand);
    ledStatus = LOW;
    digitalWrite(led, ledStatus); //Empezamos con el led apagado
}

void loop() {
    //leemos el estado del botón
    button_v = digitalRead(button);
    
    //Si el botón ha sido presionado.
    if(button_v)
    {
        delay(300); //Este delay es necesario para "debounce" del botón
        ledCommand("toggle"); //Cambia el estado del led
    }
    
    delay(10); //Evita que el loop se ejecute tan rapido
}

/*
La función ledCommand recibe uno de los siguiente tres comandos:
on--> para encender el led
off--> para apagar el led
toggle--> para cambiar el estado del led
Además, publica a la nube de Particle el nuevo estado del led.
Retorna 0 si el comando es correcto, -1 si es incorrectoo
*/
int ledCommand(String command) {
    
    if(command == "toggle")
        ledStatus = !ledStatus; 
    else if (command == "off")
        ledStatus = LOW;
    else if (command == "on")
        ledStatus = HIGH;
    else
        return -1;
        
    digitalWrite(led, ledStatus); // aplica nuevo estado del led (HIGH o LOW)
    Particle.publish("ledstatus",String(ledStatus)); // publica nuevo estado del led
    
    return 0;
}
