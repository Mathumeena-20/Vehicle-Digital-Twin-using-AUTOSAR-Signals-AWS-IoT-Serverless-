

Vehicle Digital Twin using AUTOSAR Signals + AWS IoT (Serverless)

AUTOSAR • AWS IoT • AWS Lambda • AWS DynamoDB • AWS API Gateway • Serverless Framework

Website • Documentation • GitHub • Community • Forum

🚗 Vehicle Digital Twin – AUTOSAR + AWS Serverless

Vehicle Digital Twin using AUTOSAR Signals + AWS IoT and Serverless is a reference architecture and open-source project that demonstrates how AUTOSAR Classic & Adaptive signals from an embedded automotive ECU can be streamed to the cloud and represented as a real-time digital twin using serverless AWS services.

This project is designed for AUTOSAR engineers, embedded developers, and cloud/IoT architects who want to bridge automotive ECUs with cloud-native digital twins—without relying on proprietary tools like Vector DaVinci.

🔧 Technology Stack
Automotive / Embedded

AUTOSAR Classic (ARXML, SWC, RTE, BSW – simulated)

AUTOSAR Adaptive (C++ / ara::com – simulated)

Vehicle signals (Speed, RPM, Temperature, Gear, SOC)

Cloud & Serverless

Amazon Web Services

AWS IoT Core (MQTT)

AWS Lambda (Python)

AWS DynamoDB

AWS API Gateway (REST)

AWS IAM

Serverless Framework (v4)

🌐 High-Level Architecture

Data Flow

AUTOSAR ECU (Classic / Adaptive) generates vehicle signals

Signals are published via MQTT to AWS IoT Core

IoT Rules trigger AWS Lambda functions

Lambda updates the Digital Twin state in DynamoDB

API Gateway exposes REST APIs to query vehicle state

Frontend dashboard visualizes live vehicle data

✨ Key Features

📡 AUTOSAR signal-to-cloud pipeline

☁️ Fully serverless (no EC2, no containers)

🧩 Works without Vector DaVinci / CANoe

🔁 Real-time Digital Twin updates

📊 Cloud-native telemetry storage

🔐 IAM-based security and isolation

🚀 Ready for AWS Community Builder / portfolio use


🚀 Why Serverless for Automotive Digital Twins?

The Serverless Framework makes it easy to deploy Lambda, DynamoDB, IoT rules, and APIs together using simple YAML—perfect for scalable automotive telemetry workloads.

Benefits

Zero infrastructure management

Auto-scaling for thousands of vehicles

Pay-per-use (idle = ₹0)

Fast iteration and deployment

Ideal for PoCs and production

⚙️ Features in This Project
AUTOSAR Side

Custom-written ARXML (no DaVinci)

Simulated BSW (CanIf, Com)

Classic SWC signal generation

Adaptive AUTOSAR MQTT publisher

Cloud Side

IoT Core MQTT topics per vehicle

Lambda-based Digital Twin updater

DynamoDB schema per Vehicle ID

REST APIs for:

Get live vehicle state

Get historical snapshots

🚀 Quick Start
Prerequisites

Node.js ≥ 18

Python ≥ 3.10

AWS Account

AWS CLI configured

Serverless Framework v4

Install Serverless Framework
npm install -g serverless
serverless --version

☁️ Deploy Cloud Infrastructure
cd infrastructure
serverless deploy


This deploys:

AWS IoT Rules

AWS Lambda functions

DynamoDB tables

API Gateway endpoints

📡 Publish AUTOSAR Signals (Simulation)
cd autosar-adaptive
mkdir build && cd build
cmake ..
make
./vehicle_publisher


Signals are published to:

iot/vehicle/{vehicleId}/telemetry

🔍 Query Digital Twin
curl https://<api-id>.execute-api.<region>.amazonaws.com/dev/vehicle/VIN123

🧪 Local Development
serverless dev


Live AWS events

Local Lambda execution

No repeated deployments

🧩 Example AUTOSAR Signals
Signal Name	Description
VehicleSpeed	km/h
EngineRPM	RPM
GearPosition	P/N/D/R
BatterySOC	%
CoolantTemp	°C
📈 Use Cases

Vehicle Digital Twin

Fleet Telemetry

Predictive Maintenance

OTA readiness simulation

Automotive cloud PoCs

AWS Community Builder projects

🛡️ Security

AWS IoT certificates per device

IAM least-privilege roles

Encrypted DynamoDB storage

📜 License

MIT License
Free to use for learning, demos, and community contributions.