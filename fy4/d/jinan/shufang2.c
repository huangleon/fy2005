#include <ansi.h>
inherit ROOM;
string script();
void create()
{
        set("short", "���");
        set("long", @LONG
�����Ǵ�ѧʿ������������ƽ���ռ��������׵����ڡ�����������ʱ׫д����
���书�ĵá�������ʰ�øɾ����࣬���ݵ�����϶������鼮���������Ų������
�Ʒ������������һ���ָ塣 
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"shufang",
	]));
	set("item_desc", ([
		"script" : (: script :),
		"�ָ�" : (: script :),
	]));
	set("no_fight", 1);
	set("no_magic", 1);
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

string script(){
	object me;
	me = this_player();
	tell_object(me, "һ����������Щ���Ƶ��ָ壬 ��ҳ���飺"RED"��������ƽ���¼�\n"NOR); 
	tell_object(me, "��study��\n");
	add_action("do_study", "study");
	return "";
}

int do_study(string arg){
	object me;
	me = this_player();
	if(!arg) {
		return notify_fail("��Ҫѧʲô��\n");
	}
	if (me->is_busy())	{
		tell_object(me,"��������æ��\n");
		return 1;
	}
	if(arg == "script" || arg == "�ָ�") {
		message_vision("$N����ط����˷����ϵ��ָ塣������\n", me); 
		me->start_busy(3);
		call_out("dream", 3, me);
	} else {
		return 0;
	}
	return 1;
}

int dream(object me){
	if(environment(me) != this_object() || !interactive(me)) {
		return 0;
	}
	if (REWARD_D->riddle_check( me, "�ݺ�����")>1)	{
//	if(me->query("marks/���������ݺ�����") && me->query("marks/����������ƽǹ��")) {
		if(!random(2)){
			tell_object(me, "��ͻȻ������Ƥ�������̲�ס�������۾���\n");
			me->set_temp("disable_inputs", 1);
			me->add_temp("block_msg/all", 1);
			me->set_temp("is_unconious", 1);
			me->set("disable_type", HIG "<������>"NOR);
			call_out("wake", 3, me);
		} else {
			message_vision("$N���˵�ͷ�������������ԭ����ˡ�������\n", me); 
		}
	} else {
		message_vision("$N���˵�ͷ�������������ԭ����ˡ�������\n", me); 
	}	
	return 1;
}

void wake(object me){
	object room;
	if(environment(me) != this_object() || !interactive(me)) {
		return 0;
	}	
	me->delete_temp("disable_inputs", 1);
	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);
	me->delete_temp("is_unconious", 1);
	me->delete("disable_type");
	tell_object(me, HIY"\n��ͻȻ��Զ����ս��˻����������, �����Լ��Ѿ�����֪����⣡\n\n"NOR);
	REWARD_D->riddle_set( me, "�ݺ�����",3);
//	me->set("marks/dreaming_yue", 1);
    room = find_object("/d/jinan/shanpo");
	if(!objectp(room)){
        room = load_object("/d/jinan/shanpo");
	}
	me->move(room);
}
