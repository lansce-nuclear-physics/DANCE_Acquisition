#ifndef DANCEELOG_H
#define DANCEELOG_H

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
    BOOL calibration_run;
    char sample[32];
    char filter[32];
    INT start_message_id;
  } ELOG_PARAM;

  #define ELOG_PARAM_STR(_name) const char *_name[] = {\
    "[.]",\
    "Hostname = STRING : [32] dancedaq.lanl.gov",\
    "Logbook Port = INT : 8080",\
    "Logbook Name = STRING : [32] Auto Elog Entries",\
    "Elog User = STRING : [32] daq",\
    "Elog Password = STRING [32] autopasswd",\
    "Write Elog = BOOL : y",\
    "Calibration Run = BOOL : n",\
    "Sample = STRING : [32] None",\
    "Filter = STRING : [32] None",\
    "Start Message ID = INT : 0",\
    "",\
    NULL }

#endif


