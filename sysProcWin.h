#ifndef SYSPROCWIN_H
#define SYSPROCWIN_H

#include <windows.h>
#include <w32api.h>
#include <tlhelp32.h>

#include <QMap>
#include <QString>
//#include <QMessageBox>

class LProcessInfo {
public:
        LProcessInfo() {
      memset( &pi, 0, sizeof(PROCESSENTRY32) );
   }
        LProcessInfo( PROCESSENTRY32 p ) {
      memset( &pi, 0, sizeof(PROCESSENTRY32) );
      init(p);
   }
  ~LProcessInfo() { }
        /**/
        void init( PROCESSENTRY32 p ) { memcpy( &pi, &p, sizeof(PROCESSENTRY32) ); }
   /**/
   uint32_t id()          const { return pi.th32ProcessID;       }
   uint32_t size()        const { return pi.dwSize;              }
   uint32_t usage()       const { return pi.cntUsage;            }
   uint32_t module_id()   const { return pi.th32ModuleID;        }
   uint32_t threads()     const { return pi.cntThreads;          }
   uint32_t parent_id()   const { return pi.th32ParentProcessID; }
   int32_t  parent_pri()  const { return pi.pcPriClassBase;      }
   uint32_t flags()       const { return pi.dwFlags;             }
   //const char name()    const { return &pi.szExeFile[0];       }
   /**/
   bool operator< ( const LProcessInfo& pi ) {
      //return l_strcmpi( name(), pi.name() ) < 0;
   }
private:
   PROCESSENTRY32 pi;
};

/***************************************************************************/

class LProcessInfoList: public LVector<LProcessInfo> {
public:
   LProcessInfoList() { refresh(); }
  ~LProcessInfoList() {}
   /**/
   void refresh() {
                HANDLE pl;
                PROCESSENTRY32 pe;
                /**/
                pl = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
                pe.dwSize = sizeof(PROCESSENTRY32);
                pe.th32ParentProcessID = 0;
                /**/
                if ( Process32First(pl, &pe) ) {
                        do {
                                push_back( LProcessInfo(pe) );
                                pe.th32ParentProcessID = 0;
                        } while ( Process32Next(pl, &pe) );
                }
                CloseHandle(pl);
        }
};


#endif // SYSPROCWIN_H
