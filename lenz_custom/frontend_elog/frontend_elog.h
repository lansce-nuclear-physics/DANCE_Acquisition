#ifndef LENZELOGH
#define LENZELOGH

  char* null_buffer;
  INT null_buffer_size;
  char* null_file;

  
  #define ELOG_PARAM_DEFINED

  typedef struct {
    char hostname[32];
    INT port;
    char logbook_name[32];
    char elog_user[32];
    char elog_passwd[32];
    BOOL write_elog;
    char Sample[32];
    char Experiment[32];
    INT start_message_id;
  } ELOG_PARAM;

  #define ELOG_PARAM_STR(_name) const char *_name[] = {\
    "[.]",\
    "Hostname = STRING : [32] veedaq.lanl.gov",\
    "Logbook Port = INT : 8086",\
    "Logbook Name = STRING : [32] RunLog2017",\
    "Elog User = STRING : [32] daq",\
    "Elog Password = STRING [32] autopasswd",\
    "Write Elog = BOOL : y",\
    "Sample = STRING : [32] None",\
    "Experiment  = STRING : [32] None",\
    "Start Message ID = INT : 0",\
    "",\
    NULL }

#endif


