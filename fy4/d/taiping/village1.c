#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ǰԺ");
        set("long", @LONG
ǰԺʵ����һƬ���ƺ����ƺ���룬��һ����ˮȪ���ð״���ʯ���ɣ�������
�ž��µĵ�̡�һ��ʯ����Բ�����ţ������ڳ������ģ���ˮ�����䵽��ա�ׯ
԰�����Ž����ر��ţ������һ�ȹ����˽�����[33m����[32m����ǰԺ�������������
ʯ�׾�����һ�����á������еƻ�ͨ����������硣
LONG
        );
        set("exits", ([ 
		"south": __DIR__"village2",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
		"door": "���Źص������ģ����ı����ƺ������ƿ���\n",
		"��": "���Źص������ģ����ı����ƺ������ƿ���\n",	    
		"����": "���Źص������ģ����ı����ƺ������ƿ���\n",	    
	]));
	set("coor/x",70);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
       	add_action("do_push", "push");
}


void close_passage()
{
        object room;
        message("vision", "����������Ϣ���ֹ����ˡ�\n", this_object() );
        delete("exits/north");
}

int do_push(string arg)
{
        object obj, room;
        if(!arg || (arg != "����" && arg != "door" && arg !="��")) {
                return 0;
        }
		if (query("exits/north"))
		return notify_fail("�����Ѿ����ˡ�\n");
		message_vision(WHT"$N����һ�ƣ�֨ѽһ�����Ŵ��ˡ�\n"NOR, this_player());
		set("exits/north",__DIR__"gate");
        call_out("close_passage", 10);
        return 1;
}


void reset()
{
        ::reset();
        delete("exits/north");
}