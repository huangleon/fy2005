// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "ҩ���ڼ�");
        set("long", @LONG
һ��Ũ�ҵ��в�ҩ��ζ���˱Ƕ�����ǽ��һ��С¯��¯��һ�����ڵĴɹ���ī
��ɫ��Һ������߲߲��ð����������Ȼ�ڼ���ҩ�ġ���һ������һ����ɫ��ľ��
����������Ĵ������ľϻ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yao",
]));
        set("objects", ([
        __DIR__"npc/medman": 1,
        __DIR__"npc/pettrainer2" : 1,
                        ]) );
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_soup","����");
	add_action("do_soup","cook");
}

int do_soup()
{
	object ob1,ob2,ob3,ob4,ob5,ob6;
	object me;
	me = this_player();
	ob1 = present("pilosulae",me);
	ob2 = present("dioscoreae",me);
	ob3 = present("codonopsis",me);
	ob4 = present("astragalt",me);
	ob5 = present("lycii",me);
	ob6 = present("freshfish",me);
	if( ob1 && ob2 && ob3 && ob4 && ob5 && ob6 )
	{
		message_vision("$N��һ�����һЩ��ҩ����ɹ��У�����������\n",me);
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		destruct(ob4);
		destruct(ob5);
		destruct(ob6);
		call_out("give_soup",random(5)+1,me);
		return 1;
	}
	tell_object(me, "���ԭ�ϲ�ȫ��û�������鲹Ѫ������\n");
	return 1;
}

int give_soup(object me)
{
	object soup;
	if(me) 
	if( environment(me) == this_object())
	{
		soup = new(__DIR__"obj/med");
		REWARD_D->riddle_done( me, "�ɰ�����", 10, 1);
		if(soup->move(me))
			message_vision("$N�����õĵ��鲹Ѫ�������ڻ��\n",me);
		QUESTS_D->special_reward(me,"�ɰ�����");
	}
	return 1;
}
