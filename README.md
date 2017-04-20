# Install platformio

See (http://docs.platformio.org/en/latest/installation.html)[http://docs.platformio.org/en/latest/installation.html]

Then in the project folder install the teensy platform with: `platformio platform install teensy`

# Upload code

```
pio run -e teensy31 -t upload
```

# Monitor serial port

```
pio device monitor
```
