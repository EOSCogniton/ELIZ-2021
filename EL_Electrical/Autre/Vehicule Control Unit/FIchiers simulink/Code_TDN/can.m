function msg = can(msgname,type)
  if(255==type)
  msg = struct;
  msg.num=3;
  msg.list= cell(1, msg.num);
  msg.list{1}='VCU_INV_16';
  msg.list{2}='VCU_INV_32';
  msg.list{3}='INV_VCU';
  else 
  msg = struct;
  switch msgname 
%%
%Network Node:VCU
%Message Name:VCU_INV_16
%Message Number:1
case 'VCU_INV_16'
    ECOCAN.VCU_INV_16 = struct;
    ECOCAN.VCU_INV_16.name = 'VCU_INV_16';
    ECOCAN.VCU_INV_16.description = 'VCU_INV_16';
    ECOCAN.VCU_INV_16.protocol  = 'ECOCAN';
    ECOCAN.VCU_INV_16.id = hex2dec('201');
    ECOCAN.VCU_INV_16.idext = 'STANDARD';
    ECOCAN.VCU_INV_16.payload_size =3;
    ECOCAN.VCU_INV_16.interval =-1;

    ECOCAN.VCU_INV_16.fields{1}.name = 'VCU_INV_16_RegID';
    ECOCAN.VCU_INV_16.fields{1}.units = '';
    ECOCAN.VCU_INV_16.fields{1}.start_bit = 0;
    ECOCAN.VCU_INV_16.fields{1}.bit_length = 8;
    ECOCAN.VCU_INV_16.fields{1}.byte_order = 'LITTLE_ENDIAN';
    ECOCAN.VCU_INV_16.fields{1}.data_type = 'UNSIGNED';
    ECOCAN.VCU_INV_16.fields{1}.scale = 1;
    ECOCAN.VCU_INV_16.fields{1}.offset = 0;
    ECOCAN.VCU_INV_16.fields{1}.multiplex_type = 'Standard';
    ECOCAN.VCU_INV_16.fields{1}.multiplex_value = 0;

    ECOCAN.VCU_INV_16.fields{2}.name = 'VCU_INV_16_Data';
    ECOCAN.VCU_INV_16.fields{2}.units = '';
    ECOCAN.VCU_INV_16.fields{2}.start_bit = 8;
    ECOCAN.VCU_INV_16.fields{2}.bit_length = 16;
    ECOCAN.VCU_INV_16.fields{2}.byte_order = 'LITTLE_ENDIAN';
    ECOCAN.VCU_INV_16.fields{2}.data_type = 'UNSIGNED';
    ECOCAN.VCU_INV_16.fields{2}.scale = 1;
    ECOCAN.VCU_INV_16.fields{2}.offset = 0;
    ECOCAN.VCU_INV_16.fields{2}.multiplex_type = 'Standard';
    ECOCAN.VCU_INV_16.fields{2}.multiplex_value = 0;


%%
%Network Node:VCU
%Message Name:VCU_INV_32
%Message Number:2
case 'VCU_INV_32'
    ECOCAN.VCU_INV_32 = struct;
    ECOCAN.VCU_INV_32.name = 'VCU_INV_32';
    ECOCAN.VCU_INV_32.description = 'VCU_INV_32';
    ECOCAN.VCU_INV_32.protocol  = 'ECOCAN';
    ECOCAN.VCU_INV_32.id = hex2dec('201');
    ECOCAN.VCU_INV_32.idext = 'STANDARD';
    ECOCAN.VCU_INV_32.payload_size =5;
    ECOCAN.VCU_INV_32.interval =-1;

    ECOCAN.VCU_INV_32.fields{1}.name = 'VCU_INV_32_RegID';
    ECOCAN.VCU_INV_32.fields{1}.units = '';
    ECOCAN.VCU_INV_32.fields{1}.start_bit = 0;
    ECOCAN.VCU_INV_32.fields{1}.bit_length = 8;
    ECOCAN.VCU_INV_32.fields{1}.byte_order = 'LITTLE_ENDIAN';
    ECOCAN.VCU_INV_32.fields{1}.data_type = 'UNSIGNED';
    ECOCAN.VCU_INV_32.fields{1}.scale = 1;
    ECOCAN.VCU_INV_32.fields{1}.offset = 0;
    ECOCAN.VCU_INV_32.fields{1}.multiplex_type = 'Standard';
    ECOCAN.VCU_INV_32.fields{1}.multiplex_value = 0;

    ECOCAN.VCU_INV_32.fields{2}.name = 'VCU_INV_32_Data';
    ECOCAN.VCU_INV_32.fields{2}.units = '';
    ECOCAN.VCU_INV_32.fields{2}.start_bit = 8;
    ECOCAN.VCU_INV_32.fields{2}.bit_length = 32;
    ECOCAN.VCU_INV_32.fields{2}.byte_order = 'LITTLE_ENDIAN';
    ECOCAN.VCU_INV_32.fields{2}.data_type = 'UNSIGNED';
    ECOCAN.VCU_INV_32.fields{2}.scale = 1;
    ECOCAN.VCU_INV_32.fields{2}.offset = 0;
    ECOCAN.VCU_INV_32.fields{2}.multiplex_type = 'Standard';
    ECOCAN.VCU_INV_32.fields{2}.multiplex_value = 0;


%%
%Network Node:INV
%Message Name:INV_VCU
%Message Number:3
case 'INV_VCU'
    ECOCAN.INV_VCU = struct;
    ECOCAN.INV_VCU.name = 'INV_VCU';
    ECOCAN.INV_VCU.description = 'INV_VCU';
    ECOCAN.INV_VCU.protocol  = 'ECOCAN';
    ECOCAN.INV_VCU.id = hex2dec('181');
    ECOCAN.INV_VCU.idext = 'STANDARD';
    ECOCAN.INV_VCU.payload_size =6;
    ECOCAN.INV_VCU.interval =-1;

    ECOCAN.INV_VCU.fields{1}.name = 'INV_VCU_RegID';
    ECOCAN.INV_VCU.fields{1}.units = '';
    ECOCAN.INV_VCU.fields{1}.start_bit = 0;
    ECOCAN.INV_VCU.fields{1}.bit_length = 8;
    ECOCAN.INV_VCU.fields{1}.byte_order = 'LITTLE_ENDIAN';
    ECOCAN.INV_VCU.fields{1}.data_type = 'UNSIGNED';
    ECOCAN.INV_VCU.fields{1}.scale = 1;
    ECOCAN.INV_VCU.fields{1}.offset = 0;
    ECOCAN.INV_VCU.fields{1}.multiplex_type = 'Standard';
    ECOCAN.INV_VCU.fields{1}.multiplex_value = 0;

    ECOCAN.INV_VCU.fields{2}.name = 'INV_VCU_Data';
    ECOCAN.INV_VCU.fields{2}.units = '';
    ECOCAN.INV_VCU.fields{2}.start_bit = 8;
    ECOCAN.INV_VCU.fields{2}.bit_length = 32;
    ECOCAN.INV_VCU.fields{2}.byte_order = 'LITTLE_ENDIAN';
    ECOCAN.INV_VCU.fields{2}.data_type = 'UNSIGNED';
    ECOCAN.INV_VCU.fields{2}.scale = 1;
    ECOCAN.INV_VCU.fields{2}.offset = 0;
    ECOCAN.INV_VCU.fields{2}.multiplex_type = 'Standard';
    ECOCAN.INV_VCU.fields{2}.multiplex_value = 0;


  end
  try
    msg = ECOCAN.(msgname);
  catch
  end
end
end
