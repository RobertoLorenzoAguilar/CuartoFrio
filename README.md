# Proyecto de Monitoreo de Humedad y Temperatura con ESP8266

## Descripción
Este proyecto utiliza un **ESP8266** junto con un **sensor de humedad y temperatura** para recopilar datos en tiempo real. La información se transmite mediante **MQTT** a **Node-RED**, donde se procesa y almacena en **MongoDB**. Además, si los valores de temperatura o humedad salen de los rangos establecidos, se envía una notificación por **Telegram**.

## Tecnologías Utilizadas
- **ESP8266**: Microcontrolador WiFi para la recolección de datos.
- **Sensor de humedad y temperatura**: Para medir las condiciones ambientales.
- **MQTT**: Protocolo de comunicación ligero para enviar datos.
- **Node-RED**: Plataforma para el procesamiento y enrutamiento de datos.
- **MongoDB**: Base de datos NoSQL para el almacenamiento histórico.
- **Telegram**: Para enviar alertas en caso de valores fuera de rango.

## Instalación y Configuración
1. **Configurar el ESP8266** con el código adecuado para leer los datos del sensor y enviarlos por MQTT.
2. **Configurar un broker MQTT** (como Mosquitto) para la comunicación entre el ESP8266 y Node-RED.
3. **Importar el flujo en Node-RED** para procesar los datos y almacenarlos en MongoDB.
4. **Configurar el bot de Telegram** y añadir la lógica en Node-RED para las alertas.
5. **Ejecutar el sistema** y monitorear los datos en tiempo real.




![image](https://github.com/user-attachments/assets/0dfdc5bf-1358-4e80-8f51-62d52e3a7908)


![image](https://github.com/user-attachments/assets/fbf2cee7-082c-420b-9c4f-647a3865def8)


![image](https://github.com/user-attachments/assets/bb79e92f-d495-4ffe-8eb3-8e929e91f368)

![Recording 2025-03-13 at 16 11 53](https://github.com/user-attachments/assets/1f9686d7-f2dd-4663-8b4d-b0be9d4f4708)


Integrando Lectura de sensor por vision de computadora.

![image](https://github.com/user-attachments/assets/dccdfaf7-4782-465e-b431-add2006e5803)

referencia codigo por referencia.

Mejora para Tkinter

![image](https://github.com/user-attachments/assets/7266c7fe-bac8-4b9a-b758-67c4a1a16a28)



## Contacto
Para más información o mejoras, puedes contribuir o contactar a través de GitHub.

---
¡Si te gusta el proyecto, no olvides darle ⭐ en GitHub!


