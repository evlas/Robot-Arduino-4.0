<h1 align="left">Premessa</h1>

###

<p align="left">Questa è una versione derivata (fork) del progetto originale di Marco Bedendo. Il mio obiettivo è che le modifiche qui apportate possano un giorno essere integrate nel progetto principale.<br>

Le principali differenze rispetto all'originale per adesso includono:<br>

- Revisione del pinout per supportare futuri encoder sui motori.<br>
- Integrazione di motori brushless via i2c e su pinout su PCB.<br>
- Utilizzo del sensore INA226 sul PCB per la gestione di tensioni più elevate.<br>
- Adozione di un PCB più compatto.<br>
- Adozione di D1 Mini o ESP8266-01S per la comunicazione wireless.<br>
- Adozione di Motori a 24V.</p>

###

<div align="center">
  <img height="150" src="https://github.com/user-attachments/assets/ed07248b-e39b-4969-bd0f-9576c6b1846f"  />
</div>

###

<div align="center">
  <a href="www.youtube.com/@Focus978" target="_blank">
    <img src="https://img.shields.io/static/v1?message=Youtube&logo=youtube&label=&color=FF0000&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="youtube logo"  />
  </a>
  <a href="	marcobedendo78@gmail.com" target="_blank">
    <img src="https://img.shields.io/static/v1?message=Gmail&logo=gmail&label=&color=D14836&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="gmail logo"  />
  </a>
</div>

###

<h1 align="center">hey there 👋</h1>

###

<h3 align="left">👩‍💻  About Me</h3>

###

<h1 align="left">Bedendo Marco</h1>

###

<p align="left">Vivo in italia<br><br>- 🔭 Lavoro come programmatore CAM<br>- ⚡ Nel tempo libero Progetto ogni cosa che mi può servire e la realizzo con la stampa 3d</p>

###

<p align="left">Progetto le mia parti tramite Fusion 360 e stampo i pezzi con la mia stampante 3d Bambulab X1C</p>

###

<h3 align="left">🛠 Tools</h3>

###

<div align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/arduino/arduino-original.svg" height="40" alt="arduino logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" height="40" alt="vscode logo"  />
</div>

###
# 🤖 Robot Tagliaerba Arduino 4.0

Questo è un progetto di un robot tagliaerba autonomo, basato su **Arduino Mega** come unità centrale di controllo, con vari microcontrollori e moduli per la gestione della navigazione, sensori, alimentazione e connettività Wi-Fi tramite MQTT.

## 📦 Componenti Elettronici

| Componente | Link | Q.tà | Prezzo unitario | Totale | Note |
|-----------|------|------|------------------|--------|------|
| <del>Arduino Mega 2560 R3</del> | [Amazon](https://www.amazon.it/dp/B071W7WP35) | 1 | €25.99 | €25.99 | Unità principale |
| Arduino Mega 2560 PRO | [Amazon](https://www.amazon.it/dp/B07HBTSLCF) | 1 | €20.99 | €20.99 | Unità principale |
| Arduino Nano | [Amazon](https://www.amazon.it/dp/B01LWSJBTD) | 1 | €11.99 | €11.99 | Telemetria batteria e sensori |
| <del>NodeMCU ESP8266</del> | [Amazon](https://www.amazon.it/dp/B06Y1ZPNMS) | 1 | €9.99 | €9.99 | Wi-Fi MQTT |</del>
| D1 Mini | [Amazon](https://www.amazon.it/dp/B01N9RXGHY) | 1 | €8.99 | €8.99 | Wi-Fi MQTT |
| ESP8266-01S  | [Amazon](https://www.amazon.it/dp/B0B2RSZ8F6) | 1 | €11.99 | €11.99 | Wi-Fi MQTT |
| Arduino UNO R3 | [Amazon](https://www.amazon.it/dp/B0C1V3QT9T) | 1 | €14.99 | €14.99 | Generatore filo perimetrale |
| Display 16x2 I2C | [Amazon](https://www.amazon.it/dp/B07CQG6CMT) | 1 | €7.64 | €7.64 | Visualizzazione info |
| Sensore ultrasuoni JSN-SR04T | [Amazon](https://www.amazon.it/dp/B0CLS8B5LH) | 2 | €9.99 | €19.98 | Ostacoli |
| Sensore magnetico Reed NO | [Mouser](https://www.mouser.it/ProductDetail/934-59165-1-U-00-A) | 2 | €1.42 | €2.84 | Limiti corsa |
| Driver BTS7960 43A | [Amazon](https://www.amazon.it/dp/B0CZDQRB5C) | 3 | €9.99 | €29.97 | Motori ruote e lama |
| Driver L298 | [Amazon](https://www.amazon.it/dp/B07DK6Q8F9) | 2 | €6.99 | €13.98 | Attuatori secondari |
| Sensori corrente ACS712 | [Amazon](https://www.amazon.it/dp/B07CMXFS13) | 2 | €10.99 | €21.98 | Monitoraggio motori |
| Sensore tensione DC 2-25V | [Amazon](https://www.amazon.it/dp/B07RFJYSM4) | 1 | €7.99 | €7.99 | Batteria |
| Sensore pioggia / acqua | [Amazon](https://www.amazon.it/dp/B06XQ496SW) | 1 | €7.99 | €7.99 | Sicurezza ambientale |
| Orologio DS1302 RTC | [Amazon](https://www.amazon.it/dp/B0D8Q8BMH6) | 1 | €6.01 | €6.01 | Scheduling |
| Gy-271 HMC5883L | [Amazon](https://www.amazon.it/dp/B0CR98JLQL) | 1 | €8.48 | €8.48 | Bussola digitale |
| Modulo relè 1 canale | [Amazon](https://www.amazon.it/dp/B07V1YQQGL) | 1 | €6.99 | €6.99 | Comandi remoti |
| Buck LM2596 | [Amazon](https://www.amazon.it/dp/B07MY2NTFV) | 2 | €9.59 | €19.18 | Regolazione tensione |
| Step down 300W | [Amazon](https://www.amazon.it/dp/B07VRD5GZG) | 1 | €8.99 | €8.99 | Motori lama |
| <del>BMS 4S 30A</del> | [Amazon](https://www.amazon.it/dp/B09DYD4GVN) | 1 | €8.99 | €8.99 | Gestione batteria |
| <del>Bilanciatore attivo 4S 5A</del> | [Amazon](https://www.amazon.it/dp/B0B7CW6BRC) | 1 | €17.18 | €17.18 | Bilanciamento celle |
| <del>Batteria LiPo 4S 6200mAh 80C</del> | [Amazon](https://www.amazon.it/dp/B0CB6HTW7S) | 1 | €46.99 | €46.99 | Alimentazione principale |
| <del>Motore Micromotors 22/20 RPM</del> | [CSElettronica](https://www.cselettronica.net/default.asp?cmd=getProd&cmdID=20156) | 2 | €36.70 | €73.40 | Motori trazione |
| Motore Brushless 42GP-4260 27/22 RPM | [Aliexpress](https://it.aliexpress.com/item/1005006885830154.html) | 2 | €42.09 | €84.18 | Motori trazione |
| Motore Brushless CM36-3650 32/24 RPM | [Aliexpress](https://it.aliexpress.com/item/1005002542329171.html) | 2 | €24.49 | €48.98 | Motori trazione |
| <del>Motore lama 12V 30W</del> | [Amazon](https://www.amazon.it/dp/B076M53HC9) | 1 | €27.79 | €27.79 | Rotore taglio |
| Ventole 40x40x10 24V | [Amazon](https://www.amazon.it/dp/B07WJGHTCF) | 2 | €8.99 | €17.98 | Raffreddamento |
| Alimentatore Mean Well 150W 24V | [Leroy Merlin](https://www.leroymerlin.it/prodotti/alimentatore-trasformatore-mean-well-150w-24v-6-25a-xlg-150-24-a-ip67-impermeabile-89756671.html) | 1 | €39.50 | €39.50 | Base ricarica |
| <del>Scheda madre robot personalizzata</del> | [MakerWorld](https://makerworld.com/it/models/420276-arduino-robot-lawnmower-robot-tagliaerba-arduino#profileId-323001) | 1 | €25.00 | €25.00 | Prodotta da Marco |
| Scheda madre robot personalizzata | presto su questo repository | 1 | €?? | €?? | Prodotta da Me |

**Totale stimato**: **€497,21** (solo elettronica, escluso meccanica e struttura)

## 🔧 Architettura generale

- 🧠 **Arduino Mega**: logica principale, gestione motori e ultrasuoni
- 📶 **ESP8266**: comunicazione MQTT per comandi e telemetria
- 🔋 **Arduino Nano**: monitoraggio batteria, pioggia, correnti
- 🔄 **Arduino Uno**: generazione segnale filo perimetrale
- 📟 Display I2C: messaggi e stato
- ⚡ Alimentazione a 24V con step-down e BMS per la batteria 4S

## 🛠️ Stato

Il robot è in fase avanzata di sviluppo. Il codice è disponibile nella directory principale del [repository](https://github.com/Marcobedendo78/Robot-Arduino-4.0), insieme allo schema dei moduli collegati.

---

## 📫 Contatti

Per domande o suggerimenti puoi aprire una issue o contattare direttamente [Marco](https://github.com/Marcobedendo78).

## 🆕 Aggiornamenti Maggio 2025

### ✅ Integrazione NodeMCU con Home Assistant
- Il firmware `NODEMCU_MQTT_v2` consente la comunicazione MQTT tra il robot e Home Assistant.
- Le funzioni `TX_Functions.ino` e `Rx_Functions.ino` gestiscono l’invio e la ricezione dei comandi.

### ✅ Controllo PID con Bussola
- È stato aggiunto un sistema PID per mantenere la direzione di marcia del robot in modo preciso.
- Nuova funzione: `Controllo_PID_Bussola(headingAttuale)`, integrata nelle manovre di taglio.
- La direzione target (`targetHeading`) viene aggiornata dopo ogni manovra.

### ✅ Migliorata lettura della bussola
- Ottimizzata la funzione `Get_Compass_Reading()` per maggiore stabilità e precisione.
- Ridotto il rumore con filtraggi e controlli aggiuntivi.

### ✅ Menu per modificare i valori PID da display
- Aggiunto nuovo menu interattivo per modificare i parametri `Kp`, `Ki`, `Kd` tramite pulsanti a membrana.
- I valori vengono salvati in EEPROM.


---

> Queste modifiche migliorano la stabilità, la precisione e l'integrazione domotica del robot rasaerba.

## ⚙️ Configurazione MQTT

Il file `robot_arduino.yaml` include tutti i sensori e i comandi MQTT utilizzati da Home Assistant per interagire con il robot.

📄 [Visualizza il file robot_arduino.yaml](./robot_arduino.yaml)

Per integrarlo in Home Assistant:

```yaml
mqtt: !include robot_arduino.yaml
```

---

## 🖥️ Dashboard Home Assistant – Controllo Robot

Puoi controllare il robot tagliaerba direttamente da Home Assistant usando la dashboard interattiva inclusa nel file `robot_card.yaml`.

📄 [Visualizza il file robot_card.yaml](./interface/robot_card.yaml)

### ✅ Requisiti

- Home Assistant configurato con MQTT
- Plugin [button-card](https://github.com/custom-cards/button-card) installato via HACS

### 🧭 Come usarla

1. Vai su **Impostazioni → Dashboard → Modifica dashboard**
2. Clicca su **Aggiungi scheda → Scheda Manuale**
3. Incolla tutto il contenuto del file `robot_card.yaml`
4. Salva!

### 🕹️ Funzionalità della dashboard

- Avvio e stop del robot
- Uscita e rientro nella base
- Modalità automatica/manuale
- Comandi direzionali: avanti, indietro, sinistra, destra
- Pulsanti colorati con icone intuitive

## 📡 MQTT Topics utilizzati

| Tipo         | Topic                                | Descrizione                     |
|--------------|---------------------------------------|----------------------------------|
| Stato batteria | `home/robot/mower/status/battery`    | Tensione in Volt                |
| Parcheggio     | `home/robot/mower/status/parked`     | Parcheggiato o OFF              |
| Taglio attivo  | `home/robot/mower/status/running`    | Stato taglio attivo             |
| Carica         | `home/robot/mower/status/charge`     | In carica o OFF                 |
| Comandi        | `home/robot/mower/control`           | Avvio, stop, movimento, ecc.    |

## 📡 Integrazione con Home Assistant

### 🧠 Configurazione Sensori MQTT

È disponibile un file di configurazione `robot_arduino.yaml` che definisce tutti i sensori MQTT e i comandi per il controllo del robot tramite Home Assistant.

📄 [Visualizza il file `robot_arduino.yaml`](./robot_arduino.yaml)

Per integrarlo nel tuo Home Assistant, aggiungi questa riga al tuo `configuration.yaml`:

```yaml
mqtt: !include robot_arduino.yaml
```

Il file include sensori per:
- Tensione batteria
- Stato taglio, parcheggio, docking
- Carica in corso
- Tracciamento del filo perimetrale

E switch per:
- Avvia/stoppa il robot
- Modalità manuale/automatica
- Controlli direzionali manuali (avanti, indietro, destra, sinistra, stop)

---

Per suggerimenti o problemi con l'integrazione MQTT, sentiti libero di aprire una issue sul repository!
