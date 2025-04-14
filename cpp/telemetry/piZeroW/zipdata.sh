mkdir telemetry_data
cp temperature.tsv humidity.tsv pressure.tsv temperature_us.tsv humidity_us.tsv pressure_us.tsv telemetry_data
zip -r telemetry_data.zip telemetry_data
rm -r telemetry_data
