// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
int ceiling();
void create()
{
        set("short", "С�ַ�");
        set("long", @LONG
�ڻ谵������£�����Լ���Կ�����������˶�����һ���һ������޹�����
ռ����С������䣬һ����һֱ�ѻ���������һЩ���Ƶ����ΰ��ɢ������һ����
�䣬�Աߵļ����������ѷ���һЩ�����߲ˡ�
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"cavehotel",
	]));
    set("objects", ([
        __DIR__"obj/bigbasket": 1,
    ]) );
	set("item_desc", ([
		"����" : "��Լ��һ˿΢�������͸������\n",
		"ceiling" : "��Լ��һ˿΢�������͸������\n",
		"���" : "���������ĵ����ţ����ƺ���������ȥ���������⣩\n",
		"madai" : "���������ĵ����ţ����ƺ���������ȥ���������⣩\n",
		"bag" : "���������ĵ����ţ����ƺ���������ȥ���������⣩\n",
	]));
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init(){
	add_action("do_climb", "climb");
}

int do_climb(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "madai" && arg != "bag" && arg != "���")){
		return notify_fail("��Ҫ��ʲô��\n");
	}
	message_vision("$N˳�����������ȥ��˳���ƿ�ľ�巭�˳�ȥ��\n", me);
	room = find_object(AREA_FY"ansheng");
	if(!objectp(room)){
		room = load_object(AREA_FY"ansheng");
	}
	me->move(room);
	message_vision("$N�Ӻ�ľ�������˳�����\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
 	REWARD_D->riddle_done(me,"��̽����",10,1);
	if (QUESTS_D->verify_quest(me,"��̽����"))
		QUESTS_D->special_reward(me,"��̽����");  
	return 1;
}
