// annie. 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���·ת��һƬ����������ǰ��������ľï�ܣ�һƬ���̡����²��ߣ��±�֮
�����ٽ����ܲ�͸�磬һ��ˮ����������˿������Ʈ�䣬ˮ���ɽ��ڹ�����Ҷ֮
�ϣ����������ҫ���������⣬����ҹ���µ��ǳ���
LONG
        );
    set("exits", ([ 
  		"eastup" : __DIR__"yanluo",
        "northwest" : __DIR__"shanlu2",
	]));
	set("objects", ([
		__DIR__"obj/vine1" : 1, 
		__DIR__"npc/xian": 1,
	]));   
    set("outdoors", "huashan");

	set("coor/x",-55);
	set("coor/y",-60);
	set("coor/z",36);
	setup();
}

void init()
{
	object me;
	me = this_player();
	add_action("do_open", ({ "open","push","pull" }));
	if (REWARD_D->check_m_success(me,"����ëŮ��") 
		&& REWARD_D->riddle_check(me,"��������") == 3 
		&& !random(10))
	{
		tell_object(me,HIG"\n��̤�����£�����ᵽһ��������ƿ�е���ζ�·�ĵ������㡣\n\n"NOR);
		REWARD_D->riddle_set(me,"��������",4);
	}
}

int do_open(string arg)
{
	object me;
	me = this_player();
	if(arg != "����" && arg != "vine" && arg!="����")
		return 0;
	if (me->is_fighting() || me->is_busy())
		return notify_fail("��������æ��\n");
			
	if (REWARD_D->riddle_check(me,"��������") != 4 )
		return notify_fail("���ƿ����٣�ȴʲô��û�з��֡�\n");
	message_vision("$N�ƿ����٣�������±��е�һ�����С����\n",me);
	me->move(load_object("/d/huashan/hole"));
	tell_object(me,"���ڶ�������Ƭ�̣����ȵķ���ɽ���ﾹ���ж��졣\n");
	message("vision","$N���˹���",environment(me),me);
	return 1;
}

