inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"�ƺ�¥"NOR);
        set("long", "�����ѳ˻ƺ�ȥ���˵ؿ���ƺ�¥���ƺ�һȥ������������ǧ�ؿ����ơ�
�紨�������������������������ޣ���ĺ��غδ��ǣ��̲�����ʹ�˳\n"NOR                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp",
]));
        set("objects", ([
//       __DIR__"npc/yaren" : 1,
//   	__DIR__"npc/prince" : 1,
                        ]) );
	set("no_death_penalty",1);
	set("coor/x",-30);
	set("coor/y",3);
	set("coor/z",10);
	setup();
}
