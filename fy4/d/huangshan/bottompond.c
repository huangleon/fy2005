// annie 07.2003
// dancingfaery@hotmail.com

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "��̶�");
    set("long", @LONG
������һƬ�������ı̣�����͸���������̶ˮ��ɢ����ӳ��̶�׵ı�ɳ�ϣ�
Ͷ���������������©�Ĺ�ߡ�������̬����Ķ���ʯɢ����ɳ���ϣ�����ˮ��
��̶��΢�ڣ�������̶ˮ����㸲�����������
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"pond", 
    	]) );
    	set("item_desc",([
        	"����ʯ" : "һ�����ʯ��ˮ������ҡ�Σ������ƺ�����ʲô������\n", 
        	"cobble" : "һ�����ʯ��ˮ������ҡ�Σ������ƺ�����ʲô������\n", 
    	]) );
    	set("no_fly",1);
    	set("count",1);
	set("coor/x",-50);
	set("coor/y",40);
	set("coor/z",-20);
	set("underwater",40);
	set("water_damage",20);
    	setup();
}

void init()
{
	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
	add_action("do_search", "search");
}

int do_search(){
    	object me;
    	me = this_player();
    
    	if(me->is_busy()) {
        	return notify_fail("������æ��\n");
    	}
    	if(me->is_fighting()){
        	return notify_fail("�����ȴ�����˵�ɡ�\n");
    	}
    	message_vision("$N��̶����ϸ��Ѱ��\n", me);
    	me->start_busy(2);
    	call_out("result", 4, me);
    	return 1;
}

int result(object me)
{
	object seashell;
	if(environment(me) == this_object())
	{
		if(!random(5) && query("count"))
		{
			message_vision("$N�����ȥ������һ�����ʯ����ʯ��������ʲô������\n", me);
			seashell = new(__DIR__"obj/icecrystal");
			seashell->move(me);
			set("count",0);
			return 1;
		}
		tell_object(me, "��ʲôҲû�з��֡�\n");
	}
    return 1;
}


int valid_leave(string dir)
{
	object me;
	me = this_player();
	message_vision("$N���˵���������ȥ��\n", me);
	return 1;
}
