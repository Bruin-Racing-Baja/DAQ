# Synchronized time Reset Library

This is designed to be a lightweight library, that will use a master slave architecture to "sync" several microcontrollers to a single clock. We should note that this will not produce perfect synchronization during the actual running of our microcontrollers. However, the library will attempt to reset the timers on all microcontrollers in a synchronized manner to avoid large drifts. The library will also record the value of each timer at the reset point for the purpose of benefitting the postprocessing of data. This will provide insight to any drift that occurs, so that data being recorded can be synchronized for analysis. We should note that this libray is initially created for the use of Strain Gauge testing.

# API

