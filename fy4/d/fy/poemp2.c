inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIG"̽�����¥"NOR);
    set("long", 
"���������ٷ��ƥ�������ݡ��غ��ζϺδ������������á���δ������
������������˭�ϣ�������ɽ�����ϲ��ޣ�\n"                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp",
  	"up" : __DIR__"poemp3",
  	"west" : __DIR__"poemp2a",
]));
        set("objects", ([
 //       __DIR__"npc/mother1" : 1,
   	]) );
	set("no_death_penalty",1);
	set("NONPC", 1);
	set("PK_FREE", 1);
	set("no_fly", 1);
  	set("coor/x",-40);
 	set("coor/y",20);
  	set("coor/z",10);
	setup();
}
