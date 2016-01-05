inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "��ɳĮ");
        set("long", @LONG
��Ȼ��ͬһ��̫��������̫������ɳĮ�ϣ��ͺ�Ȼ����ֺ��ֶ�������Ҫ����
��ɳĮ��ɹ��ȼ�������Ƶġ�û�з磬һ˿�綼û�У�Ҳû��˿���������������£�
ɳĮ�����е����������ѽ�����һ������״̬��������ɳĮ�������������ȵ�����
�޲��ð��������Ѷ��ѹ⡣
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"yangguan1d",
		"south" : __DIR__"yangguan1d",
		"east" : __DIR__"yangguan1d",
		"north" : __DIR__"yangguan1d",
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
        set("coor/x",-90);
        set("coor/y",300);
        set("coor/z",0);
        set("map","zbeast");
	setup();
}

int valid_leave(object obj, string dir){
	object room;
	
	switch (random(5)) {
		case 0: room = find_object(__DIR__"desert_cabin");
			tell_object(obj,YEL"�߰��ߣ�ǰ���ƺ����˼����˼ң�\n"NOR);
			if (!room) room = load_object(__DIR__"desert_cabin");
			obj->move(__DIR__"desert_cabin");
			return notify_fail("");
		case 1: room = find_object(__DIR__"desert_ambush");
			tell_object(obj,YEL"�߰��ߣ�ǰ���Ǹ�С�����������Լ�����������\n"NOR);
			if (!room) room = load_object(__DIR__"desert_ambush");
			obj->move(__DIR__"desert_ambush");
			return notify_fail("");
		case 2: room = find_object(__DIR__"yangguan1d");
			tell_object(obj,YEL"�߰��ߣ�����ɳĮ��Խ��Խ�\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1d");
			obj->move(__DIR__"yangguan1d");
			return notify_fail("");	
		default: room = find_object(__DIR__"yangguan1c");
			tell_object(obj,YEL"�߰��ߣ�ǰ��ɳ�����н�ӡ������ԭ�����ֻص���ԭ�أ�\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1c");
			obj->move(__FILE__);
			return notify_fail("");	
	}	
	
	return 1;
}

void init() {
	add_action("do_go","go");
}

int do_go (string arg)
{
   	object obj, room;
   	obj = this_player();
	
	if (arg != "west" && arg != "south" && arg !="north" && arg!="east")	return 0;
		
	switch (random(5)) {
		case 0: room = find_object(__DIR__"desert_cabin");
			tell_object(obj,YEL"�߰��ߣ�ǰ���ƺ����˼����˼ң�\n"NOR);
			if (!room) room = load_object(__DIR__"desert_cabin");
			obj->move(__DIR__"desert_cabin");
			break;
		case 1: room = find_object(__DIR__"desert_ambush");
			tell_object(obj,YEL"�߰��ߣ�ǰ���Ǹ�С�����������Լ�����������\n"NOR);
			if (!room) room = load_object(__DIR__"desert_ambush");
			obj->move(__DIR__"desert_ambush");
			break;
		case 2: room = find_object(__DIR__"yangguan1d");
			tell_object(obj,YEL"�߰��ߣ�����ɳĮ��Խ��Խ�\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1d");
			obj->move(__DIR__"yangguan1d");
			break;	
		default: room = find_object(__DIR__"yangguan1c");
			tell_object(obj,YEL"�߰��ߣ�ǰ��ɳ�����н�ӡ������ԭ�����ֻص���ԭ�أ�\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1c");
			obj->move(__FILE__);
			break;	
	}	
	
	return 1; 	
}
