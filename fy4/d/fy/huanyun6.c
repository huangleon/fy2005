#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", CYN"���Ƶ�"NOR);
    set("long", @LONG
���Ƶ������ƽ�Ϊ���ᣬ�ᴩ���������ϳǣ������ǽ����˳�ȥ�Ŀ�ջ���̼�
��ͤ�ȣ��������ǵƺ���̵��̻�֮�أ����ַǷ�����Ȼ���������ĺö඼�ǳ���
����������ŮŮ��˭��˵�����н����Ľ��������ɮ������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"swind3",
	"east" : __DIR__"huanyun7",
      ]));
    set("outdoors", "fengyun");
    set("objects", ([
	//        __DIR__"npc/mei": 1,
      ]) );

    set("coor/x",20);
    set("coor/y",-120);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    //	replace_program(ROOM);
}


/*
void init() {
	  add_action("do_dazuo","dazuo");
	}

int do_dazuo(string arg) {
	object me;
	me=this_player();
	tell_object(me,"�˵ز��ܴ�����\n");
	return 1;
}*/

