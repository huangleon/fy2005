inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�ջ�԰��");
        set("long", @LONG
�ջ�԰�ܴ󣬾ջ�԰����÷��԰����ĵ����Ǿޱ����ҩ���軨������������԰��
���еĻ�԰�������˭Ҳ��֪������ռ�˶��ٵأ�ֻ֪��һ���˾��ߵúܿ�Ҳ����
һ����������Ƭ����һȦ����԰��ܾ���û���ˣ�û���������ϲ��Ļ�԰һ����
�����ӵģ�����ֻҪһ�߽�ȥ��ÿ�������ﶼ�������˺�Ȼ���֣�ÿ���˶�����Ҫ
�������
LONG
        );
        set("exits", ([ 
		"northeast" :  	__DIR__"garden2",
		"west":		__DIR__"stable",
		"northwest":	__DIR__"sroad1",
	]));
        set("objects", ([
	]) );
	set("item_desc", ([
    	]));
		
	set("outdoors", "zangbei");
        set("coor/x",-1340);
        set("coor/y",950);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}


void init() {
	add_action("do_pull","pull");
	add_action("do_look","look");
	add_action("do_search","search");
}

int do_search(){
	tell_object(this_player(),"԰����ľջ����������дУ�������һ�춼�����н����\n");
	return 1;
}

int do_look(string arg){

	object me = this_player();
		
	if (!arg || (arg!="�ջ�" && arg!="flower"))	return 0;
	
	if (REWARD_D->riddle_check(me,"��԰����")!=3)	{
		tell_object(me,"�����＾��Ժ����ľջ��а��˶�ߣ�Ѥ�ö�ʡ�\n");
		return 1;
	}
	
	tell_object(me,"�����＾��Ժ����ľջ��а��˶�ߣ��ѵ�����ס����ࡣ\n");
	return 1;
}

void reset() {
	int dayTime;
	mixed *local;
	object xiaohe;
	
	:: reset();
	if (xiaohe=present("xiao he",this_object()))
	if (!xiaohe->is_fighting()) {
		destruct(xiaohe);
		set("xiaohe",1);
		return;
	}
	
	local = NATURE_D->get_current_time();
	dayTime = local[5];
	if(dayTime > 0 && dayTime < 360) {
		call_out("do_reveal",2);
	}
	return;
}

int do_reveal() {
	
	object *inv, *players;
	int i;
	
	message("vision",BLU"\n�紵�ݶ���԰�����ƺ���һ����Ӱ������һ�ξ���ʧ�ھջ������ˡ�\n\n"NOR,this_object());
	
	inv = all_inventory();
    	players = filter_array(inv, (: interactive($1) :));
	for(i=0; i<sizeof(players); i++) {
		if (REWARD_D->riddle_check(players[i],"��԰����")==2)
			REWARD_D->riddle_set(players[i],"��԰����",3);
//		if (!players[i]->query("marks/kuaihuo/ҹ����Ӱ")) 
//			players[i]->set("marks/kuaihuo/ҹ����Ӱ", 1);
	}
	set("xiaohe",1);
	return 1;
}


int do_pull(string arg) {
	object me=this_player();
	object xiaohe;
	
	if (arg== "flower" || arg == "�ջ�") {
		tell_object(me,YEL"�����ȥ���ְ���һ��ջ�������ջ����ǻ�ģ�����һ�Σ�����������
���澹�и�СС�Ķ�Ѩ��"NOR);
		
		if (REWARD_D->riddle_check(me,"��԰����")!=3 || !query("xiaohe")) {
//		if (!me->query("marks/kuaihuo/ҹ����Ӱ") || !query("xiaohe")) {
			tell_object(me,WHT"��Ѩ��տյģ�ʲôҲû�С�\n"NOR);
			return 1;
		}
		message("vision","�ӵص��º�Ȼ������Ϣ��ð��һ��������\n",this_object(),me);
		tell_object(me,BLU"һ�����ź��µ��˴Ӷ�Ѩ��һԾ��������������\n"NOR);
		xiaohe=new(__DIR__"npc/xiaohe");
		xiaohe->move(this_object());
		xiaohe->kill_ob(this_player());
		set("xiaohe",0);
		return 1;
	}
	return notify_fail("�����/��ʲô��\n");
}

