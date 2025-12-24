
# 🚗 Vehicle Digital Twin using AUTOSAR Classic Signals + AWS IoT (Serverless)

![Image](https://www.nxp.com/assets/images/en/blogs/BL-ARE-DIGITAL-TWIN-1-1.jpg)

![Image](https://miro.medium.com/v2/resize%3Afit%3A1400/1%2AIvAV10E6FgOEem0a19sMeQ.jpeg)

![Image](https://docs.aws.amazon.com/images/architecture-diagrams/latest/aws-connected-vehicle/images/1-modernization.png)

---

## 📌 Overview

This project demonstrates an **end-to-end Vehicle Digital Twin** by integrating **AUTOSAR Classic ECU signals** with **AWS IoT and serverless services**.

AUTOSAR signals are **simulated without proprietary tools**, securely published to **AWS IoT Core**, processed using **AWS Lambda**, and stored in **Amazon DynamoDB** to maintain a **cloud-side digital twin of the vehicle**.

---

## 🎯 Project Objectives

* Simulate **AUTOSAR Classic signal flow**
* Publish vehicle telemetry using **MQTT over TLS**
* Build a **serverless backend**
* Maintain a **real-time vehicle digital twin**
* Store historical telemetry for analysis
* Demonstrate **automotive + cloud integration**

---

## 🧠 What This Project Demonstrates

* AUTOSAR Classic architecture understanding
* ECU → Cloud telemetry pipeline
* Secure AWS IoT communication
* Serverless design (no EC2)
* Digital Twin concept for connected vehicles

---

## 🧩 AUTOSAR Classic Architecture Mapping

![Image](https://www.embitel.com/wp-content/uploads/1-AUTOSAR-Archtecture.jpg)

![Image](https://embetronicx.b-cdn.net/wp-content/uploads/2024/03/Virtual-Function-Bus.webp)

| AUTOSAR Layer     | Implementation                      |
| ----------------- | ----------------------------------- |
| Application Layer | Vehicle signal generation           |
| RTE               | Signal read abstraction (simulated) |
| COM Stack         | Signal packaging & transmission     |
| BSW               | Communication abstraction           |
| MCAL              | Hardware abstraction (simulated)    |

> Proprietary tools (Vector / DaVinci) are intentionally avoided.
> AUTOSAR behavior is **functionally simulated** while preserving signal semantics.

---

## 📡 AUTOSAR Signals Used

| Signal Name  | Type    | Description                |
| ------------ | ------- | -------------------------- |
| VehicleSpeed | uint16  | Vehicle speed (km/h)       |
| EngineRPM    | uint16  | Engine RPM                 |
| FuelLevel    | uint8   | Fuel percentage            |
| CoolantTemp  | sint8   | Engine coolant temperature |
| DoorStatus   | boolean | Door open / close          |

---

## 🏗️ System Architecture

```
AUTOSAR Classic ECU (Simulated)
        |
        v
MQTT Client (TLS)
        |
        v
AWS IoT Core
        |
        v
IoT Rule
        |
        v
AWS Lambda
        |
        +--> DynamoDB (Live Digital Twin)
        |
        +--> S3 (Historical Data)
```

---

## 🧰 Technology Stack

* **AUTOSAR**: Classic Platform (Simulated)
* **Language**: Python
* **Cloud**: AWS
* **IoT Protocol**: MQTT
* **Compute**: AWS Lambda
* **Database**: DynamoDB
* **Storage**: S3
* **Frontend**: HTML + JavaScript

---

## 📁 Repository Structure

```
vehicle-digital-twin/
│
├── autosar-classic/
│   ├── signal_generator.py
│   ├── rte_simulator.py
│   └── com_stack.py
│
├── mqtt-client/
│   └── publish_to_iot.py
│
├── lambda/
│   ├── realtime_processor.py
│   └── store_digital_twin.py
│
├── dashboard/
│   └── index.html
│
├── architecture/
│   └── architecture.png
│
├── requirements.txt
└── README.md
```

---

## ⚙️ Digital Twin Logic

The **Digital Twin** maintains:

* Current vehicle state
* Overspeed detection
* Last update timestamp
* Cloud-side representation of ECU data

**Example Rule**

* Speed > 100 km/h → Overspeed Alert

---

## 🔐 Security Design

* Mutual TLS (X.509 certificates)
* Least-privilege IoT policies
* IAM-based Lambda permissions
* Topic-level access control

---

## 🧪 Test Scenarios

* Overspeed detection
* Fuel low condition
* Door open alert
* Missing or invalid signal handling

---

