inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIM"̽������¥"NOR);
    set("long", 
"�������ƿ������λش�����Ӫ���˰�������¾ģ���ʮ�ҷ���������ɳ����
�����������¬�ɿ죬���������Ҿ�����ȴ���������£�������ǰ�����������
�׷�����\n"NOR                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp2",
  	"up" : __DIR__"poemp4",
]));
        set("objects", ([
 	//__DIR__"npc/mother2" : 1,
                        ]) );
	set("no_death_penalty",1);
	set("NONPC", 1);
  	set("PK_FREE", 1);
  	set("no_fly", 1);
  	set("coor/x",-40);
 	set("coor/y",20);
   	set("coor/z",20);
	setup();
}
