#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
����һ������������������Ƕ��ͭ�ơ���бб��������£���֪�ж೤��
Ҳ��֪����δ���������ͭ�ƾ㶼���ü�Ϊ�������Լ��˵ؾ����������ߡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secretpath2",
  "west" : __DIR__"secretpath0",
]));
        set("objects", ([
        __DIR__"npc/redbeast" : 1,
                        ]) );


	set("coor/x",-10);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}
void init()
{       object ob;
        int exp;
        if( interactive( ob = this_player()))
        {
        exp = ob->query("combat_exp");
        if(exp < 2000) {
        ob->move(__DIR__"secretpath0.c");
        message_vision(HIR"\n$N��һ�����˵��˻�����\n\n"NOR, ob);
        }
        }
}

