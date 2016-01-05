inherit ROOM;
// Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "Сľ��");
        set("long", @LONG
ľ��ֻ�а�߶���һ����÷����ס���ǰ�ߡ�ǽ�Ϲ��ż���ԡ������͸����
֦����ԡ���ϡ�һ����ܴӷ������£���ܵľ�ͷ����һ��[37mľ����[32m��ż������ˮ��
���¡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"frontyard",
]));
        set("objects", ([
        __DIR__"obj/towel": 1,
                        ]) );
        set("item_desc", ([
                "ľ����": "���ƺ����԰����Σ������죩������\n",

        ]) );
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_pull","pull");
	add_action("do_climb","climb");
}


int do_pull(string arg)
{
	object me;
	if (arg == "ľ����" || arg == "ľ��" || arg == "cork" ) {
		if(query("resource/water"))
			return notify_fail("ľ�����Ѿ����������ˡ�\n");
		me = this_player();
		message_vision("$N���ۣ���һ����ľ���Ӱ���������ð��������ˮ��������������\n",me);
		set("resource/water",1);
		set("liquid/name","��ˮ");
		call_out("remove_water",50);
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int remove_water()
{
	tell_object(this_object(),"��ˮ���˼��Σ��������ˡ�\n");
	delete("resource/water");
        delete("liquid/name");
	return 1;
}

int do_climb(string arg)
{
	object me,room;
	me = this_player();
	if (arg == "tree" || arg == "��÷��" || arg == "÷��") {
		message_vision("$N��ಣ���һ����˳����÷�������ݶ���\n",me);
		room = find_object(__DIR__"roof");
		if (!room)
			room = load_object(__DIR__"roof");
		me->move(room);
		return 1;	
	}
	return notify_fail("������ʲô��\n");
}

void reset(){
	object obj;
	::reset();
	if(!present("towel", this_object())){
		obj = new(__DIR__"obj/towel");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	return;
}