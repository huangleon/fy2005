inherit ROOM;
#include <ansi.h>
string gotit();

void create()

{
        set("short", "���Ǹ�");
        set("long", @LONG
ʮ��ǰ���ϳ��˸����ˣ��뾩ǰ��������˸�������ү����������˻�û����
���ϣ��ͱ�ǿ�������Դ����Ӵ���û�˹�ˡ��Դ����������������ͳ�������
�����ǺȾ�ȡ�֣�����ˤ�ӱ���ĳ��������Ǹ���������������������磬����
д�ţ�[33m�����������������������лƽ���[32m
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"nstreet3",
		]));
        set("objects", ([
        	
		]) );
		
		set("item_desc", ([
			"����":		YEL"�����������������������лƽ���\n"NOR,
			"pingfeng":		YEL"�����������������������лƽ���\n"NOR,
			"��":		(: gotit() :),
		]));
		
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",0);
        set("thief",1);
		set("map","zbwest");
		setup();
}

string gotit(){
	
	object me;
	
	me = this_player();
	tell_object(me,"�������Դ������룬����������ֺ��񲻶԰ɡ�\n");
	tell_object(me,"���߽�������ϸ����������ԭ���������ϵ��ǵ�ʱ�䳤�˱�ĥ���ˡ�\n");
	me->set_temp("marks/wanma/pingfeng",1);
	if (query("thief"))
		call_out("falling",random(10)+5, me);
	set("thief",0);
	return "";
}


int falling(object me){
	object thief;
	if (!me || environment(me)!=this_object())	return 1;
	
	thief = new(__DIR__"npc/thief");
	if (!thief)	return 1;
	thief->move(this_object());
	
	message_vision("��ͨһ�������Ϻ�Ȼ���¸�������\n", thief);
	thief->ccommand("say ���������ô�㵽���ﶼ�ᱻ��ײ������");
	thief->ccommand("say С�ӣ������������ô��\n");
	message_vision("$N�����Լ��Ժ���ƺ���������һ�£���ϸһ����$n������û������\n", me, thief);
	thief->ccommand("say ��������������ң�������ң�\n");
	message_vision("$N����һת��ת����ȥ��˵���ˡ�\n", thief);
	if (!REWARD_D->riddle_check(me,"��͵����") && !REWARD_D->check_m_success(me,"��͵����"))
		REWARD_D->riddle_set(me,"��͵����",1);
	return 1;
}
	
	
void reset(){
	object sikong;
	
	sikong = present("sikong taoxing");
	if (sikong) {
		message_vision("˾�������������˵��û�¶��Ҿ����ˡ�
˾������һת������������ʧ�ˡ�\n",sikong);
	destruct(sikong);	
	}
	set("thief",1);
	::reset();
}
	
