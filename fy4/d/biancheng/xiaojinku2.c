inherit DOOR_ROOM;
#include <ansi.h>
#include <room.h>

void create()

{
        set("short", "СԺ");
        set("long", @LONG
�߽������ţ����Ǵ�Ũ����롣СԺ��������������ż�ʮ�ʹ��񣬳��Ž���
������ÿ�����һ�Ե�����С�ƻ����Ե����Ŷ������ϡ�������������ľ�������
�������̲ݡ�����������Ǯ�ͷ紵����������
LONG
        );
        set("exits", ([ 
		"north": __DIR__"xiaojinku",
		"enter": __DIR__"xiaojinku3",
	]));
        set("objects", ([
        	__DIR__"npc/girl":	1,
	]) );
	set("item_desc", ([
		"flower": "����������ÿ������Ĳ��ã������̲�ס��ȥժ�ϼ��䡣(pick)\n",
		"���ÿ�": "����������ÿ������Ĳ��ã������̲�ס��ȥժ�ϼ��䡣(pick)\n",
	]));
	
        set("coor/x",-40);
        set("coor/y",-15);
        set("coor/z",0);
	set("map","zbwest");
        set("have_herb",5);
	setup();
	create_door("north","door","խ��","south",DOOR_CLOSED);
}

int init(){
        add_action("do_pick","pick");
}


int do_pick(string arg) {
        int num;
        object herb,girl, me = this_player();
        if (arg == "flower" || arg == "���ÿ�") {
                if (girl = present("little girl",this_object()))
                	return notify_fail("���۾���С����˵�����𶯣��⻨���Ǵ�Ũ�����ϲ���ġ���\n");
                if (query("have_herb")) {
                        message_vision("��û��ע�⣬$N�ӵ��ϰ��˼������ÿ����뻳�С�\n",this_player());
                        add("have_herb",-1);
                        herb = new(__DIR__"obj/flower");
                        if (!herb ->move(me))
                                herb->move(this_object());
                        return 1;
                }        
                 else {
                        tell_object(me, "��������ÿ��Ѿ�ժ���ˡ�\n");
                }
                return 1;
        }
        return notify_fail("����ժʲô��\n");
}

void reset() {
        set("have_herb",1);
        ::reset();
}
