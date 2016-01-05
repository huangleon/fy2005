inherit ROOM;
// Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "С��");
        set("long", @LONG
һ��С����ª��ľ�ݣ�������©�ꡣǽ������ض���һ�����ɲ�ǽ�϶���һ
��ľ�ܣ����Ϲ���һЩ�����õĹ��ߡ�һ�����ʷ����������롣
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"frontyard",
	]));
    set("objects", ([
        __DIR__"obj/chair": 1,
		__DIR__"obj/rope" : 1,
		__DIR__"obj/drywoods" : 4,
    ]) );

	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset(){
	object obj;
	int i;

	::reset();
	if(!present("rope", this_object())){
		obj = new(__DIR__"obj/rope");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	if(!present("chair", this_object())){
		obj = new(__DIR__"obj/chair");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	if(!present("woods", this_object())){
		for(i=0; i < 5; i++){
			obj = new(__DIR__"obj/drywoods");
			if(objectp(obj)){
				obj->move(this_object());
			}
		}
	}
	return;
}