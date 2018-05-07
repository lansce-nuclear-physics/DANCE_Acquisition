/********************************************************************\

  Name:         caen1527.c
  Created by:   Stefan Ritt

  Contents:     NULL Device Driver. This file can be used as a 
                template to write a read device driver

  $Id: caen1527.c 3260 2006-08-05 06:11:57Z ritt $

\********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "midas.h"
#include "CAENHVWrapper.h"

/*---- globals -----------------------------------------------------*/

#define DEFAULT_TIMEOUT 10000   /* 10 sec. */

/* Store any parameters the device driver needs in following 
   structure. Edit the CAEN1527_SETTINGS_STR accordingly. This 
   contains usually the address of the device. For a CAMAC device
   this could be crate and station for example. */

typedef struct {
   // stuff specific to my caen
   char CAENip[256];     // valid ip address or name to log to the CAEN
   char CAENuser[256];   // CAEN username
   char CAENpw[256];     // CAEN password
   char Sname[256];      // A name for the power supply
} CAEN1527_SETTINGS;

#define CAEN1527_SETTINGS_STR "\
Address = STRING : [256] 172.16.9.130\n\
User = STRING : [256] user\n\
Password = STRING : [256] user\n\
Sname = STRING : [256] SystemOne\n\
"

/* following structure contains private variables to the device
   driver. It is necessary to store it here in case the device
   driver is used for more than one device in one frontend. If it
   would be stored in a global variable, one device could over-
   write the other device's variables. */

typedef struct {
   CAEN1527_SETTINGS caen1527_settings;
   float *array;
   INT num_channels;
   // Not sure this part will be used....
    INT(*bd) (INT cmd, ...);    /* bus driver entry function */
   void *bd_info;               /* private info of bus driver */
   HNDLE hkey;                  /* ODB key for bus driver info */
} CAEN1527_INFO;

/*---- device driver routines --------------------------------------*/

/* the init function creates a ODB record which contains the
   settings and initialized it variables as well as the bus driver */

INT caen1527_init(HNDLE hkey, void **pinfo, INT channels, INT(*bd) (INT cmd, ...))
{
   int status, size;
   HNDLE hDB, hkeydd;
   CAEN1527_INFO *info;

   /* allocate info structure */
   info = calloc(1, sizeof(CAEN1527_INFO));
   *pinfo = info;

   cm_get_experiment_database(&hDB, NULL);

   /* create CAEN1527 settings record */
   status = db_create_record(hDB, hkey, "DD", CAEN1527_SETTINGS_STR);
   if (status != DB_SUCCESS)
      return FE_ERR_ODB;

   db_find_key(hDB, hkey, "DD", &hkeydd);
   size = sizeof(info->caen1527_settings);
   db_get_record(hDB, hkeydd, &info->caen1527_settings, &size, 0);

   /* initialize driver */
   info->num_channels = channels;
   info->array = calloc(channels, sizeof(float));
   /*
   // not sure this needs to be used since I'm going into
   // the caen driver for communication
   info->bd = bd;
   info->hkey = hkey;

   if (!bd)
      return FE_ERR_ODB;

   // initialize bus driver 
   status = info->bd(CMD_INIT, info->hkey, &info->bd_info);
   */
   // try to talk to the module
   CAENHVRESULT success;
   void *vptr;
   char myipstr[255];
   strcpy(myipstr,info->caen1527_settings.CAENip);
   vptr = myipstr;
   cm_msg(MINFO, "scfe_init", "Try to talk to module '%s' '%s' '%s', '%s'\n", vptr, info->caen1527_settings.Sname, info->caen1527_settings.CAENuser, info->caen1527_settings.CAENpw);
   success = CAENHVInitSystem( info->caen1527_settings.Sname, 
                               LINKTYPE_TCPIP, 
                               vptr, 
                               info->caen1527_settings.CAENuser, 
                               info->caen1527_settings.CAENpw);
   // success = CAENHVInitSystem( "SystemOne", 
   //                             LINKTYPE_TCPIP, 
   //                             "172.16.9.130", 
   //                             "user", 
   //                             "user");
   cm_msg(MINFO,"scfe_init","talked to module 0x%x\n\n",success);

   if (success != 0x0)
   {
      cm_msg(MERROR,"scfe_init","failed to talk to caen? 0x%x \n\n",success);
      return 0;
      }

   /* initialization of device, something like ... */
   //BD_PUTS("init");
   //printf("actually initialized device\n\n");

   // return 0;
   return FE_SUCCESS;
}

/*----------------------------------------------------------------------------*/

INT caen1527_exit(CAEN1527_INFO * info)
{
   CAENHVRESULT success;
   success = CAENHVDeinitSystem(info->caen1527_settings.Sname);
   //printf("\n\n\ncalled deinit on %s with success 0x%x\n\n\n",info->caen1527_settings.Sname,success);
   // free local variables 
   if (info->array)
      free(info->array);
   free(info);
   /*
   // call EXIT function of bus driver, usually closes device 
   info->bd(CMD_EXIT, info->bd_info);

   // free local variables 
   if (info->array)
      free(info->array);

   free(info);
   */

   return FE_SUCCESS;
}

/*----------------------------------------------------------------------------*/

INT caen1527_set(CAEN1527_INFO * info, INT channel, float value)
{
   CAENHVRESULT success;
   if (channel<168) // quick and dirty way of dealing with the number of modules we've got
   {
   ushort slot = 2*(channel/24); // primitive map of HV crate slots
   ushort Ch = channel%24;       // primitive map of HV crate channels
   //printf("about to set\n");
   success = CAENHVSetChParam(info->caen1527_settings.Sname,slot,"V0Set",1,&Ch,&value);
   //printf("set channel %i slot %u channel %u with success 0x%x %f\n\n",channel,slot,Ch,success,value);
   /*
   char str[80];

   // set channel to a specific value, something like ... 
   sprintf(str, "SET %d %lf", channel, value);
   BD_PUTS(str);
   BD_GETS(str, sizeof(str), ">", DEFAULT_TIMEOUT);

   // simulate writing by storing value in local array, has to be removed
   //   in a real driver
   if (channel < info->num_channels)
      info->array[channel] = value;
   */
   }

   return FE_SUCCESS;
}

/*----------------------------------------------------------------------------*/

INT caen1527_get(CAEN1527_INFO * info, INT channel, float *pvalue)
{
   //printf("Looking at channel %i\n",channel);
   CAENHVRESULT success;
   if (channel<168)
   {
   ushort slot = 2*(channel/24); // primitive map of HV crate slots
   ushort Ch = channel%24;       // primitive map of HV crate channels
   //printf("abuot to read %f\n",*pvalue);
   success = CAENHVGetChParam(info->caen1527_settings.Sname,slot,"VMon",1,&Ch,pvalue);
   //printf("%i %i %i voltage reading success %x %f\n",channel,slot,Ch,success,success);
   //printf("read %f\n\n",*pvalue);
   if (success == 0)
   {
       return FE_SUCCESS;
   }
   else
   {
       cm_msg(MERROR,"scfe_get","failed to read voltage w/ status 0x%x %d... retry connection\n",success,success);
       void *vptr;
       char myipstr[255];
       strcpy(myipstr,info->caen1527_settings.CAENip);
       vptr = myipstr;
       //printf("Try to talk to module %s\n",info->caen1527_settings.CAENpw);
       success = CAENHVDeinitSystem(info->caen1527_settings.Sname);
       cm_msg(MINFO,"scfe_get","Deinit w/ status 0x%x",success);
       success = CAENHVInitSystem(info->caen1527_settings.Sname, LINKTYPE_TCPIP, vptr, info->caen1527_settings.CAENuser, info->caen1527_settings.CAENpw);
       printf(MINFO,"scfe_get","reconnect w/ status 0x%x \n",success);
       if (success == 0x0)
       {
           success = CAENHVGetChParam(info->caen1527_settings.Sname,slot,"Vmon",1,&Ch,pvalue);
           return FE_SUCCESS;
       }
       exit(1);
   }
   }
   else
   {
   *pvalue = 0;
   }
   return FE_SUCCESS;

}
INT caen1527_get_current(CAEN1527_INFO * info, INT channel, float *pvalue)
{
   CAENHVRESULT success;
   if (channel<168)
   {
   ushort slot = 2*(channel/24); // primitive map of HV crate slots
   ushort Ch = channel%24;       // primitive map of HV crate channels
   //printf("%i %i about to read %f\n",slot,Ch,*pvalue);
   success = CAENHVGetChParam(info->caen1527_settings.Sname,slot,"IMon",1,&Ch,pvalue);
   //printf("current reading success %x %f\n",success,success);
   //printf("%i %i read %f\n",slot,Ch,*pvalue);
   if (success == 0)
   {
       return FE_SUCCESS;
   }
   else
   {
       printf("failed to read current w/ status 0x%x... retry connection\n",success);
       void *vptr;
       char myipstr[255];
       strcpy(myipstr,info->caen1527_settings.CAENip);
       vptr = myipstr;
       //printf("Try to talk to module %s\n",info->caen1527_settings.CAENpw);
       success = CAENHVDeinitSystem(info->caen1527_settings.Sname);
       printf("Deinit w/ status 0x%x",success);
       success = CAENHVInitSystem(info->caen1527_settings.Sname, LINKTYPE_TCPIP, vptr, info->caen1527_settings.CAENuser, info->caen1527_settings.CAENpw);
       printf("reconnect w/ status 0x%x \n",success);
       if (success == 0x0)
       {
           success = CAENHVGetChParam(info->caen1527_settings.Sname,slot,"IMon",1,&Ch,pvalue);
           return FE_SUCCESS;
       }
   }
   }
   else
   {
       *pvalue = 0.;
   }
   return FE_SUCCESS;
}

/*---- device driver entry point -----------------------------------*/

INT caen1527(INT cmd, ...)
{
   va_list argptr;
   HNDLE hKey;
   INT channel, status;
   DWORD flags;
   float value, *pvalue;
   void *info, *bd;

   va_start(argptr, cmd);
   status = FE_SUCCESS;

   switch (cmd) {
   case CMD_INIT:
      hKey = va_arg(argptr, HNDLE);
      info = va_arg(argptr, void *);
      channel = va_arg(argptr, INT);
      flags = va_arg(argptr, DWORD);
      bd = va_arg(argptr, void *);
      status = caen1527_init(hKey, info, channel, bd);
      break;

   case CMD_EXIT:
      info = va_arg(argptr, void *);
      status = caen1527_exit(info);
      break;

   case CMD_SET:
      info = va_arg(argptr, void *);
      channel = va_arg(argptr, INT);
      value = (float) va_arg(argptr, double);   // floats are passed as double
      status = caen1527_set(info, channel, value);
      break;

   case CMD_GET:
      info = va_arg(argptr, void *);
      channel = va_arg(argptr, INT);
      pvalue = va_arg(argptr, float *);
      //printf("received  voltage pvalue %f\n",*pvalue);
      status = caen1527_get(info, channel, pvalue);
      break;

   case CMD_GET_CURRENT:
      info = va_arg(argptr, void *);
      channel = va_arg(argptr, INT);
      pvalue = va_arg(argptr, float *);
      //printf("received  current pvalue %f\n",*pvalue);
      status = caen1527_get_current(info, channel, pvalue);
      break;

   default:
      break;
   }

   va_end(argptr);

   return status;
}

/*------------------------------------------------------------------*/
