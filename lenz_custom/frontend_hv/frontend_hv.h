#ifndef LENZELOGH
#define LENZELOGH

//char* null_buffer;
//INT null_buffer_size;
//char* null_file;

#define ELOG_PARAM_DEFINED

typedef struct {
  INT nmodules;
  struct {
    char statusfiledirectory[80];
    char statusfilename[80];
    INT monitoringactive; //1 is yes 0 is no
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_0;
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_1;
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_2;
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_3;
  } MHV4_0;
  struct {
    char statusfiledirectory[80];
    char statusfilename[80];
    INT monitoringactive; //1 is yes 0 is no
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_0;
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_1;
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_2;
    struct {
      char detector[32];
      INT channelon;  //1 is on 0 is off
      INT channelpolarity; //1 is positive 0 is negative
      double channelvoltage;
      double channelcurrent;
      double channelvoltagelimit;
      double channelcurrentlimit;
    }Channel_3;
  } MHV4_1;
} MHV4_PARAM;

#define MHV4_PARAM_STR(_name) const char *_name[] = {	\
    "[.]",						\
    "Number of MHV4 Modules = INT : 2",			\
    "[MHV4_0]",						\
    "Status File Directory = STRING : [80] /home/daq/MHV4_Controller",	\
    "Status File Name = STRING : [80] MHV4_Status.txt",		\
    "Monitoring Active = INT : -1",			\
    "[MHV4_0/Channel_0]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "[MHV4_0/Channel_1]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "[MHV4_0/Channel_2]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "[MHV4_0/Channel_3]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "[MHV4_1]",						\
    "Status File Directory = STRING : [80] /home/daq/MHV4_Controller",	\
    "Status File Name = STRING : [80]  MHV4_Status.txt",		\
    "Monitoring Active = INT : -1",			\
    "[MHV4_1/Channel_0]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "[MHV4_1/Channel_1]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "[MHV4_1/Channel_2]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "[MHV4_1/Channel_3]",				\
    "Detector = STRING : [32] null",			\
    "Channel On = INT : -1",				\
    "Channel Polarity = INT : -1",			\
    "Channel Voltage = DOUBLE : -1",			\
    "Channel Current = DOUBLE : -1",			\
    "Channel Voltage Limit = DOUBLE : -1",		\
    "Channel Current Limit = DOUBLE : -1",		\
    "",							\
    NULL }

#endif


