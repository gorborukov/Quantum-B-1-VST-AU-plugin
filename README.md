# Hyperspace Lab Quantum-B-1-VST-AU-plugin

<img src="https://github.com/gorborukov/Quantum-B-1-VST-AU-plugin/blob/main/quantum-b-1.png?raw=true">

Probability based drum synthesizer &amp; sequencer. Example of Pure Data patch integration into Juce through the hvcc compiler.

I do not publish the .pd patch source because I'm doing another project based on it, but in the repository you will find c++ compiled patch integrated into a project based on a JUCE Framework.

If you want to compile your own patch you can use great hvcc compiler https://github.com/enzienaudio/hvcc. Despite its age, it is still relevant today, and with hvcc you can compile patches into working code which you can refer to from your JUCE project.

Usage example:
`python hvcc.py YourPatchName.pd -n YourProjectName`

Plugin [video demo](https://www.youtube.com/watch?v=IOt8d_SLA68).

Plugin [website](https://hyperspacelab.info/products/quantum-b-1).
