// Room: dong0
inherit ROOM;
#include <room.h>
string *names = ({
         __DIR__"npc/redgirl",
         __DIR__"npc/orggirl",
         __DIR__"npc/yelgirl",
         __DIR__"npc/grngirl",
         __DIR__"npc/cyngirl",
         __DIR__"npc/blugirl",
         __DIR__"npc/maggirl",
        });
void create()
{
        int i;
        object girl;
        set("short", "����");
        set("long", @LONG
Ϫ������������������ˮ�ϣ���ֻ�����ڻ����з�����ȥ����ƺ�����ռ䣬
б���ż���������Ů��������ɴ���������ۣ�����ӯӯǳЦ���������
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"gu0",
  "west" : __DIR__"gu2",
      
]));  
	set("outdoors","tieflag"); 	
	set("coor/x",40);
	set("coor/y",0);
	set("coor/z",40);
	setup(); 
	  for (i=6;i>=0;i--)
	  	if (random(100)>70)
	  	{
	  		girl=new(names[i]);
	        girl->move(this_object());
	    }

}

