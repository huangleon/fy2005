// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�Ϲټ�������֮�����������м��������ݳޣ���Ů����Ӧ�о��С���ʱ����
����һ�ˣ�������������һ�������ζ������������������ﴫ����Ů��Ц֮����
���ݶ����µĹ�ɴ�����ƻð������Ʈ��������������Ķ�����
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq1-maze/exit",
	]));
        set("objects", ([
                __DIR__"npc/jq1-hyguard" : 1,
       	]) );
        
        set("item_desc", ([
        	"��ɴ":	"
���ݶ����µĹ�ɴ�����ƻð������Ʈ������ɴ��pull�����ƺ�һ����Ů�������ꡣ��\n",
        	"sha":	"
���ݶ����µĹ�ɴ�����ƻð������Ʈ������ɴ��pull�����ƺ�һ����Ů�������ꡣ��\n",
	]) );
	setup();
	
}



void 	init(){
	add_action("do_pull","pull");
    	add_action("do_listen","listen");
}

int do_listen(string arg) {
	
	if (!arg) {
		tell_object(this_player(),HIM"\n~~~~~~~~��~~~~��~~~~~~��~~��~~~~~~~~~\n\n"NOR);
	}
	return 1;
}

int	do_pull(string arg){
	
	object me = this_player();
	object room, guard, *inv;
	int i;
	if (me->is_busy())
		return notify_fail("��������æ�š�\n");
	if (guard = present("yellow sentry",this_object()))
	if (guard->query("attitude")== "aggressive")
		return notify_fail("�������ȵ��������ʲô����\n");
	if (!arg)	return notify_fail("������ʲô?\n");
	if (arg == "��ɴ" || arg == "sha" || arg=="ɴ" || arg=="guasha") {
		room = find_object(__DIR__"jq1-end");
		if (!room) room = load_object(__DIR__"jq1-end");
		if (!REWARD_D->riddle_check(me,"��̽��Ǯ")|| room->usr_in() )
			return notify_fail("֪����֮�ˣ������������˺��£�\n");
		message_vision(WHT"\n$N�ߵ��űߣ�����һ����ɴ���˽�ȥ�� \n\n"NOR,me);
		
		inv = all_inventory(room);
		for (i=0;i<sizeof(inv);i++)
			if (!userp(inv[i]))
			if (inv[i]->query("id")=="lu fengxian" 
				|| inv[i]->query("id")=="meihuadan")
			destruct (inv[i]);
		
		room->reset();
		me ->move(room);
		me->start_busy(5);
		room ->event1(me,0);
		return 1;
	}
	tell_object(me, "�ⶫ��û���򿪡�\n");
	return 1;
}
