# Taller de conexión entre Particle y MIT AppInventor

Este proyecto demuestra como conectar el dispositivo de prototipado IoT [Particle Photon](https://docs.particle.io/guide/getting-started/intro/photon/) con la herramienta de prototipado de aplicaciones móviles [MIT AppInventor](http://ai2.appinventor.mit.edu).

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
* Verificar que el photon puede ser controlado usando el App de Particle (encender y apagar el LED azul en D7)
* Crear una nueva aplicación en el [Web IDE de Particle](https://build.particle.io/build/new) y copiar el código en [comled.ino](photon-appinventor/comled.ino)
* Cargar o hacer Flash a la aplicación comled hacia el Photon

# Configuración Firebase
* Ir a https://console.firebase.google.com/ e ingresar con una cuenta personal de Google.
* Crear un proyecto nuevo. Usar el plan gratuito Spark, seleccionar Ecuador como la región y nombrar el proyecto.
![Nuevo proyecto Firebase](/imagenes/firebase_new.png)
* Ir a la sección de la base de datos y copiar el enlace.
![Nuevo proyecto Firebase](/imagenes/firebase_url.png)
* Ir a la sección de reglas (Rules) y abrir la base de datos para uso sin autenticación. Aquí el antes y después:
![Antes](/imagenes/firebase_rules_1.png) ![Después](/imagenes/firebase_rules_2.png)

# Configuración MIT AppInventor

