// Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "Сé��");
        set("long", @LONG
é��ͨ�����ã��ɾ���ˬ���������ǵİ���С��Ͱ�����������ǽ�ߡ�ÿ����
Ͱ�ϻ���һ���ҹ��������ǿ��Թ��ڱⵣ�ϵġ�ǽ�Ϲ���һ������ľˢ�����ڵ���
ˮ��
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"backyard",
	]));
    set("objects", ([
		__DIR__"obj/matong":2,
		__DIR__"obj/brush" : 1,
    ]) );

	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void reset(){
	object obj;
	::reset();
	if(!present("matong", this_object())){
		obj = new(__DIR__"obj/matong");
		if(objectp(obj)){
			obj->move(this_object());
		}
		obj = new(__DIR__"obj/matong");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	if(!present("brush", this_object())){
		obj = new(__DIR__"obj/brush");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	return;
}