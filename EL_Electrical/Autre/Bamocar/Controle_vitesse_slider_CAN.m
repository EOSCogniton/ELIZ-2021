clear
close all

set(true);
bamocar_r = 0x201;
bamocar_t = 0x181;
maximum_speed = 5000;
maximum_current = 340;

% canch = canChannel('MathWorks','Virtual 1',1);

canch = canChannel('PEAK-System','PCAN_USBBUS1');
configBusSpeed(canch,500000);

start(canch)

speed_act = 0;
current_act = 0;

%--------maximum speed transmission request-----------

message_maximum_speed = canMessage(bamocar_r,false,3);
message_maximum_speed.Data = ([0x3d 0xc8 0x00]);
transmit(canch,message_maximum_speed);

%--------maximum current transmission request-----------

message_maximum_current = canMessage(bamocar_r,false,3);
message_maximum_current.Data = ([0x3d 0xc4 0x00]);
transmit(canch,message_maximum_current);

%--------speed command = 0-----------

message_speed = canMessage(bamocar_r,false,3);
message_speed.Data = ([0x31 0x00 0x00]);
transmit(canch,message_speed);

%--------speed transmision requested every 100 ms---------

message_speed_request = canMessage(bamocar_r,false,3);
message_speed_request.Data = ([0x3d 0xa8 0x64]);
transmit(canch,message_speed_request);

%--------current transmision requested every 100 ms---------

message_current_request = canMessage(bamocar_r,false,3);
message_current_request.Data = ([0x3d 0x5f 0x64]);
transmit(canch,message_current_request);


hFig = uifigure('Color','w','Name','Speed command');
hFig.Position = [270 500 1000 200];
text_speed = annotation(hFig,'textbox',[0 0 0.2 0.2],'String','Speed (RPM)','FontWeight','bold','FontSize',17,'FitBoxToText','off','EdgeColor','none');
text_courant = annotation(hFig,'textbox',[0.82 0 0.2 0.2],'String','Current (Arms)','FontWeight','bold','FontSize',17,'FitBoxToText','off','EdgeColor','none');

hSlider1 = controllib.widget.Slider(hFig, [50,20,900,200], -maximum_speed:1:maximum_speed);
hSlider1.FontSize = 35;
hSlider1.Value = 0;

exit_button = uibutton(hFig, 'ButtonPushedFcn', @(exit_button,event) exitButtonPushed(hFig));
exit_button.Position = [440 10 120 60];
exit_button.BackgroundColor = 'w';
exit_button.Text = 'Exit';
exit_button.FontSize = 20;
exit_button.Icon = 'Logo_Valk.jpg';

disp_speed = annotation(hFig,'textbox',[0.15 0 0.25 0.31],'Color',[0.635294117647059 0.0784313725490196 0.184313725490196],...
    'String',{'500',''},...
    'FontWeight','bold','FontSize',35,'FitBoxToText','off','EdgeColor','none');

disp_current = annotation(hFig,'textbox',[0.69 0 0.25 0.31],'Color',[0.635294117647059 0.0784313725490196 0.184313725490196],...
    'String',{'1.222',''},...
    'FontWeight','bold','FontSize',35,'FitBoxToText','off','EdgeColor','none');

while get
    %------envoi de la consigne de vitesse---------------------------------
    speed_conv = int16(floor(hSlider1.Value*32767/maximum_speed));
    speed_hex = dec2hex(speed_conv,4);
    message_speed = canMessage(bamocar_r,false,3);
    message_speed.Data = ([0x31 hex2dec(speed_hex(3:4)) hex2dec(speed_hex(1:2))]);
    transmit(canch,message_speed);
    
    %-------Réception et traitement des données reçues-----------------
    REC = receive(canch,Inf);
    for i=1:length(REC)
        if REC(i).ID == bamocar_t
            switch REC(i).Data(1)
                case 0xc4
                    byte2 = dec2hex(REC(i).Data(2));
                    if length(byte2) ~= 2
                        byte2 = strcat('0',byte2);
                    end
                    byte3 = dec2hex(REC(i).Data(3));
                    if length(byte3) ~= 2
                        byte3 = strcat('0',byte3);
                    end
                    maximum_current = strcat(byte3, byte2);
                    maximum_current = hex2dec(maximum_current); 
                case 0xc8
                    byte2 = dec2hex(REC(i).Data(2));
                    if length(byte2) ~= 2
                        byte2 = strcat('0',byte2);
                    end
                    byte3 = dec2hex(REC(i).Data(3));
                    if length(byte3) ~= 2
                        byte3 = strcat('0',byte3);
                    end
                    maximum_speed = strcat(byte3, byte2);
                    maximum_speed = hex2dec(maximum_speed); 
                %------filtered actual speed------------
                case 0xa8
                    byte2 = dec2hex(REC(i).Data(2));
                    if length(byte2) ~= 2
                        byte2 = strcat('0',byte2);
                    end
                    byte3 = dec2hex(REC(i).Data(3));
                    if length(byte3) ~= 2
                        byte3 = strcat('0',byte3);
                    end
                    speed_act_hex = strcat(byte3, byte2);
                    speed_act_conv = typecast(uint16(sscanf(speed_act_hex, '%x')), 'int16');
                    speed_act = int16(single(speed_act_conv)*maximum_speed/32767);
                %------filtered actual current----------  
                case 0x5f
                    byte2 = dec2hex(REC(i).Data(2));
                    if length(byte2) ~= 2
                        byte2 = strcat('0',byte2);
                    end
                    byte3 = dec2hex(REC(i).Data(3));
                    if length(byte3) ~= 2
                        byte3 = strcat('0',byte3);
                    end
                    current_act_hex = strcat(byte3, byte2);
                    current_act_conv = typecast(uint16(sscanf(current_act_hex, '%x')), 'int16');
                    current_act = single(current_act_conv)*maximum_current/32767;
                    
            end
        end
    end
    
    disp_speed.String = num2str(speed_act);
    disp_current.String = num2str(current_act,'%.2f');
    
    pause(0.1);
    
end

%--------speed command = 0-----------

message_speed = canMessage(bamocar_r,false,3);
message_speed.Data = ([0x31 0x00 0x00]);
transmit(canch,message_speed);%--------speed command = 0-----------

%--------speed transmision stopped---------

message_speed_request = canMessage(bamocar_r,false,3);
message_speed_request.Data = ([0x3d 0xa8 0xff]);
transmit(canch,message_speed_request);

%--------current transmision stopped---------

message_current_request = canMessage(bamocar_r,false,3);
message_current_request.Data = ([0x3d 0x5f 0xff]);
transmit(canch,message_current_request);

%stop(canch)

function set(val)
    global s
    s = val;
end

function x = get
global s
x = s;
end

function exitButtonPushed(hFig)
    close(hFig)
    set(false);
end