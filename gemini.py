from typing import Final
import requests
from PIL import Image
import google.generativeai as genai
import io
import serial
import time

# API key and Model name
API_KEY: Final = "YOUR_GEMINI_API_KEY" # Replace with your actual API key
MODEL_NAME: Final = "gemini-2.0-flash"

# Initialization
genai.configure(api_key=API_KEY)
model = genai.GenerativeModel(model_name=MODEL_NAME)

# ESP32-CAM capture URL
esp32_cam_url = "http://<ESP32-CAM-IP-ADDRESS>/capture" # Replace with your ESP32-CAM IP address

response = requests.get(esp32_cam_url)

if response.status_code == 200:
    # Prompt and image processing 
    prompt = "Identify the object in the image. Please output 1 if the object is organic, 2 if the object is plastic and can be recyclable, 3 if the object can be recyclable as paper or cardboard and 4 if the object is something else or if the objects are from different categories."
    image = Image.open(io.BytesIO(response.content)) 

    # Gemini Response
    ai_response = model.generate_content([prompt, image])
    result = ai_response.text.strip()

    match ai_response.text:
        case "1":
            print(f"{result} Organic")
        case "2":
            print(f"{result} Plastic, recyclable")   
        case "3":
            print(f"{result} Paper or cardboard, recyclable")
        case "4":
            print(f"{result} Other or mixed categories")
        case _:
            print("Unknown category")

    print("Image processed successfully") 
else:
    print("Failed to capture image from ESP32-CAM")

# Send response back to Arduino
arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=115200, timeout=1) # Replace with your Arduino port

time.sleep(2)  # wait for Arduino to reset

if result in ["1", "2", "3", "4"]:
    arduino.write((result + "\n").encode())  # send "1", "2", etc.
    print(f"Sent '{result}' to Arduino!")
else:
    print("Unexpected response, not sending to Arduino.")

arduino.close()