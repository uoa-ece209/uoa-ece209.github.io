clear 
f = 50;
Voff = 2;

%Analog signal at ADC input
t = [0:.02e-3:20e-3];
%ti = [1e-3:.02e-3:21e-3];
Vvo = 1.414*sin(2*pi*f.*t)+Voff;
Ivo = 1.5*sin(2*pi*f.*t-pi/3.5)+Voff;
%figure(1)
%plot(t*1e3,Vvo)

%Sampled signal
t_sample = [0:2e-3:20e-3];
VADC = round((1.414*sin(2*pi*f.*t_sample)+Voff)*1024/5);
%figure(2)
%plot(t_sample*1e3,VADC)


%Reconstructed waveform
Voltage_Array = (VADC*5/1024-Voff)/0.1
figure(3)
plot(t_sample*1e3,Voltage_Array)
hold on
plot(t*1e3,(Vvo-Voff)/.1)
%RMS
%figure(4)
%plot(t*1e3,(10*(Vvo-Voff)).^2,t_sample*1e3,Voltage_Array.^2)

%V & I Waveforms
ti_sample = [1e-3:2e-3:21e-3];
IADC = round((1.5*sin(2*pi*f.*ti_sample - pi/3.5)+Voff)*1024/5);
Current_Array = (IADC*5/1024-Voff)/1;
figure(5)
%plotyy(t_sample*1e3,Voltage_Array,ti_sample*1e3,Current_Array);

%Power
Voltage_with_Appx = 1:1:20;
Voltage_with_Appx(1:2:20)=Voltage_Array(1:1:10);
Voltage_with_Appx(2:2:20)= (Voltage_Array(1:1:10) + [Voltage_Array(2:1:10) 0])/2;
Current_with_Appx = 1:1:20;
Current_with_Appx(2:2:20)= Current_Array(1:1:10);
Current_with_Appx(1:2:20)= (Current_Array(1:1:10) + [-1.5 Current_Array(1:1:9)])/2;
VI = Voltage_with_Appx.*Current_with_Appx;
sum(VI)/20
%plot(t*1e3,(1*(Ivo-Voff)).*(10*(Vvo-Voff)),[0e-3:1e-3:19e-3]*1e3,VI)

%Sampled peak
t = [0:.2e-3:40e-3];
Vvo = 15*sin(2*pi*f.*t);
t_sample = [0:2.083e-3:40e-3];
VADC = round((1.5*sin(2*pi*f.*t_sample)+Voff)*1024/5);
Voltage_Array = (VADC*5/1024-Voff)/0.1;
%figure(6)
%plot(t*1e3,Vvo,t_sample*1e3,Voltage_Array)


