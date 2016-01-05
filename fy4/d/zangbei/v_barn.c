inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "�Ȳ�");
        set("long", @LONG
��ʽ�����Ĺ����һ��ټ��ĹȲּ��������ģ���ǽһ����¯�ϲ����˳��ң�
ש�����͵��̴�ͨ�򷿶���װ�Ź��������ϴ��Ų�ͬ������ӡ�ǣ���Ȼ������կ
��ǿ������ɽ��ٵ��ջ�����ٱ��˷˵ķ����ս�������կƾ����㴢��������
��������ؾ�û�����⡣ͨ���Ժ��һ��ľ�Ž������š�
LONG
        );
        set("exits", ([ 
//		"east" : __DIR__"village",
	]));
	set("item_desc", ([
        	"chimney": "���̴���Ȼ�Ѿ�������ʱ�ˣ�����ȥ��ǿ�������һ���ˣ�squeeze through����\n",
        	"�̴�":	 "���̴���Ȼ�Ѿ�������ʱ�ˣ�����ȥ��ǿ�������һ���ˣ�squeeze through����\n",
        	"ľ��":	 "����ľ�����������š�\n",
        	"door":	 "����ľ�����������š�\n",
        ]));
        set("objects", ([
        	__DIR__"obj/bag":	1,
	]) );
        set("coor/x",-1560);
        set("coor/y",560);
        set("coor/z",0);
	set("map","zbwest");
	set("closed",1);
	setup();
}

void init() {
	add_action("do_squeeze","squeeze");
	add_action("do_open","open");
}

int do_open(string arg) {
	object me=this_player();
	object out_room;
	if (!arg || (arg!="door" && arg!="ľ��" && arg !="��"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!query("closed"))
		return notify_fail("���Ѿ��ǿ��ŵ��ˡ�\n");
//	if (me->query_skill("stealing")<200)
//		return notify_fail("������ֿտ�֮��̫�û���������š�\n");
	message_vision("$N������һ�󣬴�������Ŵ��ˡ�\n",me);
	set("exits/east",__DIR__"village");	
	set("closed",0);
	out_room=find_object(__DIR__"village");
	if (!objectp(out_room)) out_room=load_object(__DIR__"village");
	message("vision","�Ȳֵ��ź�Ȼ�����汻���ˡ�\n",out_room);
	out_room->set("exits/west",__DIR__"v_barn");
	call_out("door_close",20,out_room);
	return 1;
}
	
int door_close(object out_room){
	out_room->delete("exits/west");
	this_object()->delete("exits/east");
	this_object()->set("close",1);
	message("vision","�Ȳֵ����ֱ������ˡ�\n",out_room);
	message("vision","ľ�ŵ��˻��������ˡ�\n",this_object());
	set("closed",1);
	return 1;
}
	
int do_squeeze(string arg) {
	
	object me;
	
	me=this_player();
	if (arg=="through" || arg == "�̴�" || arg== "chimney" || arg =="through chimney") {
		if (me->query_temp("zangbei/chimney_2"))
			return notify_fail("���Ѿ����̴����ˡ�\n");
		message_vision("$Nһè�������̴ѣ�С�������������ȥ��\n\n",me);
		call_out("pass_river",6,me);
		me->start_busy(3);
		me->set_temp("zangbei/chimney_2",2);
		return 1;
	}
	tell_object(me,"��Ҫ��ʲô��\n");
	return 1;
}


int pass_river(object me) {
	object room;
	if (!objectp(me) || me->is_ghost()) return 0;
	room=find_object(__DIR__"w_wall3");
	if (!objectp(room)) room=load_object(__DIR__"w_wall3");
	tell_object(me,"������ش��̴������˳�ȥ��\n");
	message("vision",me->name()+"���̴������˳�����\n",room);
	me->move(room);
	me->delete_temp("zangbei/chimney_2");
	return 1;
}


void reset(){
	object bag,seed,*player,*inv;
	::reset();
	
	inv=all_inventory(this_object());
	player=filter_array(inv,(: userp($1) :));
	if (player && sizeof(player)) return;
	
	bag=present("big bag",this_object());
	if (bag)
		seed=present("seed",bag);
	if (!seed) {
		seed=new(__DIR__"obj/seed");
		seed->move(bag);
	}
	return;
}
	