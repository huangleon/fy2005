
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "����");
        set("long", @LONG
������һ�������ĵ����磬�㼸�����������������������ɫ�����ޣ���״��
�����Ϻ���������������е�������ȥ��ˮ�����������Ư������һ���Ŵ�����
���ˮ�ݾ�����Ľűߡ�
LONG
        );
        set("exits", ([
  		"south" : __DIR__"bottom",
  		"north" : __DIR__"bottom1",
  		"east" : __DIR__"bottom2",
	]));

        set("objects", ([
        __DIR__"obj/watergrass" : 1,
        __DIR__"npc/killerfish" : 1,
                        ]) );

        set("outdoors", "palace");
	set("coor/x",-60);
	set("coor/y",70);
	set("coor/z",0);
	set("underwater",30);
	set("water_damage",20);
    	setup();
}


void init(){
    	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}

void reset()
{
	object con, item, watergrass;
	object *inv;
	::reset();
	watergrass = present("watergrass", this_object());
        inv = all_inventory(watergrass);
        if(!sizeof(inv)) {
	con = new(__DIR__"obj/woodcase");
	item = new(__DIR__"obj/ring");
	item->move(con);
	if (!random(4)) {
		item = new("obj/medicine/pill_medicine");
		item->move(con);
		}
	con->move(watergrass);
	}
	
}
