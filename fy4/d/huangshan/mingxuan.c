// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����Ȫ");
        set("long", @LONG
��ǰһ���������������̲�������Ȫˮ�Ը�ɽʯ����Ȼ���£����һ�����
ɽ´������ұ��пգ�״����ٵ���ʯ�ϣ����������ˣ����ˡ��ö����н����
���졣���й�ʫ�޵���ȴ��������ϸ������ʮ���Ҿ㲻�ڡ���
LONG
        );
    set("exits", ([ 
  		"east"	: __DIR__"sandie",
	]));
        set("objects", ([
        __DIR__"obj/stone3" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-60);
	set("coor/y",-10);
	set("coor/z",0);
	set("mingxuan", 1);
	setup();
}

void init() {
	add_action("do_search", "search");
}

int do_search(){
	object me, stone;
	
	me = this_player();	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	me->start_busy(1);
	if (REWARD_D->riddle_check(me,"��¶��ʯ")== 5
		&& query("mingxuan")) {	
		message_vision("$N����ϸϸ����Ȫ���±�����Ѱ��\n", me);
		message_vision("$N������ʯ��һ����Щ�ɶ��� ������һ�⣬������������\n", me);
//		set("mingxuan",0);	
		
		if (!random(10))	// 1/10 ������ڶ���,
		{		
			stone = new(__DIR__"obj/ystone");
			if (stone->move(me))
			{
				REWARD_D->riddle_set(me,"��¶��ʯ",6);
				return 1;
			}
		}
		message_vision("ʯ����ڵ��ϣ�ž��һ��ˤ������ĩ��ǰ��������̫��ϧ�ˣ���\n", me);
		me->delete("riddle/��¶��ʯ");
		return 1;
	} 
	tell_object(me,"�����������һ�󣬽��ʲôҲû�ҵ���\n");
	return 1;
}


void reset(){
	::reset();
	if (!random(4)) set("mingxuan",1);
}


				