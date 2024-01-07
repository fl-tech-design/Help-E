import serial
import time

def serial_monitor_and_send(port, baudrate):
    ser = serial.Serial(port, baudrate)
    
    try:
        while True:
            # Warte auf Benutzereingabe
            user_input = input("Gib einen Buchstaben ein, um ihn zu senden (oder 'q' zum Beenden): ")

            if user_input.lower() == 'q':
                break  # Beende die Schleife, wenn 'q' eingegeben wird

            # Sende den eingegebenen Buchstaben
            ser.write(user_input.encode('utf-8'))

            # Warte auf die Antwort vom Arduino (falls erforderlich)
            if ser.in_waiting > 0:
                received_data = ser.readline().decode('utf-8').rstrip()
                print("Empfangene Daten:", received_data)

    except KeyboardInterrupt:
        pass  # Behandle die Tastaturunterbrechung, um die Verbindung ordnungsgemäß zu schließen
    finally:
        ser.close()


def serial_monitor(port, baud_rate=9600, num_samples=4, sample_interval=0.25):
    try:
        ser = serial.Serial(port, baud_rate, timeout=1)
        print(f"Serial Monitor gestartet auf {port} mit Baudrate {baud_rate}.\n")

        while(True):
            try:
                data = ser.readline().decode('utf-8').strip()
            except UnicodeDecodeError:
                data = ser.readline().decode('latin-1').strip()
            if data:
                print(f"Empfangene Daten: {data}")
            time.sleep(sample_interval)

    except serial.SerialException as e:
        print(f"Fehler beim Öffnen des Serial Ports: {e}")

    finally:
        if ser.is_open:
            ser.close()
            print("Serial Monitor beendet.")

if __name__ == "__main__":
    # Setze den COM-Port entsprechend deiner Konfiguration
    serial_port = "/dev/ttyCH341USB0"
    # Du kannst auch die Baudrate ändern, wenn sie von deinem Gerät abweicht
    baud_rate = 9600
    # Anzahl der Samples und Intervall zwischen den Samples
    num_samples = 4
    sample_interval = 0.25

    serial_monitor(serial_port, baud_rate, num_samples, sample_interval)
