# Taller de conexión entre Particle y MIT AppInventor

En este taller se demuestra como conectar el dispositivo de prototipado IoT [Particle Photon](https://docs.particle.io/guide/getting-started/intro/photon/) con la herramienta de prototipado de aplicaciones móviles [MIT AppInventor](http://ai2.appinventor.mit.edu).

La intergración entre ambas plataformas se puede efectuar a través de la base de datos en tiempo real [Firebase](https://firebase.google.com/) usando la siguiente arquitectura:

![arquitectura](/imagenes/photon-appinventor.png)

## Requerimientos
* Android smartphone con App [Particle](https://play.google.com/store/apps/details?id=io.particle.android.app&hl=es) y opcional [MIT AI2 Companion](https://play.google.com/store/apps/details?id=edu.mit.appinventor.aicompanion3&hl=es)
* Cuenta en [Particle](https://www.particle.io/)
* Cuenta en [Firebase](https://firebase.google.com/)
* Cuenta en [MIT AppInventor](http://ai2.appinventor.mit.edu)
* Particle Photon conectado así:
![Photon esquematico](/imagenes/photon_bb.png)
![Photon foto](/imagenes/photon.PNG)

## Configuración Photon
* Conectar el Photon al internet [usando la aplicación de Particle](https://docs.particle.io/guide/getting-started/start/photon/#step-2b-connect-your-photon-to-the-internet-using-your-smartphone)
* Verificar que el photon pueda ser controlado usando el App de Particle (encender y apagar el LED azul en D7)
* Crear una nueva aplicación en el [Web IDE de Particle](https://build.particle.io/build/new) y copiar el código en [comled.ino](/comled.ino)
* Cargar o hacer Flash a la aplicación comled hacia el Photon

![Flash](/imagenes/flash.png)

* Una vez termina el flashing, probar el botón físico en el Photon, debe de encender y apagar el LED azul en D7

## Configuración Firebase
* Ir a https://console.firebase.google.com/ e ingresar con una cuenta personal de Google.
* Crear un proyecto nuevo. Usar el plan gratuito Spark, seleccionar Ecuador como la región y nombrar el proyecto.
![Nuevo proyecto Firebase](/imagenes/firebase_new.png)
* Ir a la sección de la base de datos y copiar el enlace.
![Nuevo proyecto Firebase](/imagenes/firebase_url.png)
* Ir a la sección de reglas (Rules) y abrir la base de datos para uso sin autenticación. Aquí el antes y después:

Antes | Después
--- | ---
![Antes](/imagenes/firebase_rules_1.png) | ![Después](/imagenes/firebase_rules_2.png)


## Conexión Nube Particle con Firebase
En el código en [comled.ino](/comled.ino) cada vez que se actualiza el led, este evento es publicado a la nube de particle:
```C
digitalWrite(led, ledStatus);
Particle.publish("ledstatus",String(ledStatus));
```
Es necesario crear un Webhook el cuál actualice Firebase cada vez que se genera este evento:

Ir a consola | Crear Webhook
--- | ---
![Ir a consola](/imagenes/consola.png) | ![Después](/imagenes/crear_webhook.png)

Y finalmente editar el Webhook de la siguiente forma:

![Webhook](/imagenes/webhook.png)

Verificar en Firebase que el campo respectivo en la base de datos se actualize cada vez que el led cambia:

![Firebase actualización](/imagenes/firebase_actualizacion.png)

Cuando esto este funcionando, se puede usar la extensión de Firebase en AppInventor para capturar eventos de cambios remotos en Firebase.


## Configuración MIT AppInventor con Firebase
Conectar la aplicación de MIT AppInventor a Firebase usando la extensión FirebaseDB:

![Firbase extensión](/imagenes/appinventor_firebase.png)

En la configuración de la extensión de Firebase:
* Remover el visto en *Use Default*
* Configurar de la siguiente forma:
![Firbase configuración](/imagenes/firebase.png)

## Conexión MIT AppInventor con Particle
En el código en [comled.ino](/comled.ino) la función "led":
```C
Particle.function("led",ledCommand);
```
es registrada en la nube de Particle y por lo tanto se la pueda ejecutar remotamente usando un API request. Este es un ejemplo de un botón en AppIventor que al ser presionado, llama a esta función remotamente:

Ejemplo Método 1

![Ejemplo bloques](/imagenes/ejemploBloquesBoton.PNG)

Ejemplo Método 2

![Ejemplo bloques2](/imagenes/ejemploBloquesBoton2.png)


El campo <Access Token> debe de ser reemplazada por el Access Token de su aplicación:
  
![Access Token](/imagenes/access_token.png)

Para que esto funcione, es necesario primero seleccionar la extensión Web en AppInventor:

![Extensión Web](/imagenes/extensiones_appinventor.png)

Para configurar la extensión Web:
* En AppInventor, en la configuración de la extensión Web, en el campo URL usar:
```
https://api.particle.io/v1/devices/<Device ID>/led
```
* Buscar el número del Device ID de su Photon en la consola de Particle https://console.particle.io
![Device ID](/imagenes/deviceID.png)
