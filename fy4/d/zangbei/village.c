inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����կ��Ժ");
        set("long", @LONG
����կ�������ֺ�����Ⱥɽ��������崣��������������һֻҰ�ޣ����Ŵ�
�����ڵ������˶��ɡ�ס��������ˣ�Ҳ������һȺҰ�ޡ�˭Ҳ��Ը�ⱻҰ������
ȥ��������ط��ǵ����ٿ��ü�İ���ˣ��������Ѽ���������������ǿ��������
��ȴ�������ˮ������ϲ�أ������ɽկ�������ǹȲ֣���������⣬�м�һ����
Ժ��ͷ�����ټ����µ����ڡ���Ժ��һ�໹���ų��ݣ�ͨ��կǽ��һ�з紵�ݶ���
ɽկ����˾ͻ����ǽͷ���ء�
LONG
        );
        set("exits", ([ 
//		"west" : __DIR__"v_barn",
		"east" : __DIR__"v_armory",
		"north": __DIR__"v_gate",
	]));
        set("objects", ([
        	__DIR__"npc/baimian":	1,
        	__DIR__"npc/tulaohu":	1,
        	__DIR__"npc/oneeye":	1,
        	__DIR__"npc/bandit1":   6,
	]) );
	set("item_desc",([
		"barn":	"һ��ľ��ͨ��Ȳ֡�\n",
		"�Ȳ�": "һ��ľ��ͨ��Ȳ֡�\n",
		"ladder":"��ǽ�£�һ�ų��ݰ�Ժ�Ӻ�կǽ����������\n",
		"����": "��ǽ�£�һ�ų��ݰ�Ժ�Ӻ�կǽ����������\n",
	]));
	
	set("outdoors", "zangbei");
        set("coor/x",-1540);
        set("coor/y",560);
        set("coor/z",0);
	set("map","zbwest");
        set("closed",1);
	setup();
//	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}

void init() {
	add_action("do_climb","climb");
	add_action("do_open","open");
}


int do_climb(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="up" || arg == "ladder" || arg== "����") {
		if (me->query_temp("zangbei/zaiqiang_2"))
			return notify_fail("���Ѿ������������ˡ�\n");
		message_vision("$N���ų���С�������������ȥ��\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/zaiqiang_2",1);
		return 1;
	}
	tell_object(me,"��Ҫ��ʲô��\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"e_wall3");
	if (!objectp(room)) room=load_object(__DIR__"e_wall3");
	tell_object(me,"�����ɵ��ϵ�կǽ�ϡ�\n");
	message("vision",me->name()+"������������������\n",room);
	me->move(room);
	me->delete_temp("zangbei/zaiqiang_2");
	return 1;
}


int do_open(string arg) {
	object me=this_player();
	object out_room;
	if (!arg || (arg!="door" && arg!="ľ��" && arg !="��"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!query("closed"))
		return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");
	message_vision("$N�ѹȲֵ��Ŵ򿪡�\n",me);
	set("exits/west",__DIR__"v_barn");	
	set("closed",0);
	out_room=find_object(__DIR__"v_barn");
	if (!objectp(out_room)) out_room=load_object(__DIR__"v_barn");
	message("vision","�Ȳֵ��ź�Ȼ�����汻���ˡ�\n",out_room);
	out_room->set("exits/east",__DIR__"village");
	call_out("door_close",20,out_room);
	return 1;
}
	
int door_close(object out_room){
	out_room->delete("exits/east");
	this_object()->delete("exits/west");
	this_object()->set("close",1);
	message("vision","�Ȳֵ����ֱ������ˡ�\n",this_object());
	message("vision","ľ�ŵ��˻��������ˡ�\n",out_room);
	set("closed",1);
	return 1;
}
/*
void reset() {
	object badguy,*inv,room=this_object();
	int count,i;
	
	::reset();
	
	inv=all_inventory();
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->name()=="ɽկ���")
			count++;
	}
	if (count<4) {
		badguy=new(__DIR__"npc/bandit");
		badguy->set("attitude", "friendly");
		badguy->move(room);
		badguy->ccommand("say ����,С��׼�����ˡ�");
	}
}
	
*/

/* 
void midnight_event() {
	object badguy;
	object room = this_object();
	int i, bandit_no = 2 + random(5);
	
	if(!random(10)) {
		for(i=0; i<bandit_no; i++) {
			if(objectp(badguy = new("/obj/npc/bandit"))) {
				badguy->setup_bandit("ɽ������", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "fy");
				badguy->move(room);
				badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
			}
		}
		NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
	} else {
		NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
	}
}

void sunrise_event() {
	object *ob_list;
	int i;
	
	ob_list = children("/obj/npc/bandit");
	for(i=0; i<sizeof(ob_list); i++) {
		if(ob_list[i]->query("area_mark") == "fy") {
			if(environment(ob_list[i])) {
				message_vision("$N�е�������Ҳ��������\n",ob_list[i]);
			}
			destruct(ob_list[i]);
		}
	}
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
*/