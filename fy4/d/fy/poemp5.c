inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIR"̽����¥"NOR);
    set("long", "���¼�ʱ�У��Ѿ������졣��֪���Ϲ��ڣ���Ϧ�Ǻ��ꡣ�����˷��ȥ��
Ω����¥����ߴ���ʤ��������Ū��Ӱ���������˼䡣
ת��󣬵�粻��������ߡ���Ӧ�кޣ����³����ʱԲ�����б�����ϣ�
��������Բȱ�����¹���ȫ����Ը�˳��ã�ǧ�ﹲ濾ꡣ��\n"NOR                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp4",
]));
        set("objects", ([
 //	__DIR__"npc/mother4" : 1,
                        ]) );
	set("no_death_penalty",1);
	set("NONPC", 1);
	set("PK_FREE", 1);
	set("no_fly", 1);
  	set("coor/x",-40);
 	set("coor/y",20);
 	set("coor/z",40);
	setup();
}
