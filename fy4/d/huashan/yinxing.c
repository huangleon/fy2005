#include <ansi.h>
inherit ROOM;
string tree();
string vine();
void create()
{
        set("short", "����Ϫ��");
        set("long", @LONG
Ϫ����������СϪ������һ�þ޴�������������������ϱ����������ʮ��
ï�ܣ��Ϻ�ɫ�Ĺ������������������������Ӳݹ�ľ��������ϸ����Լ�ɱ�һ��
����������С·���򶫱�����
LONG
        );
    set("exits", ([ 
		"northeast" : __DIR__"meigu",
	]));
	set("item_desc", ([
		"СϪ" : "СϪ������ˮ�峺�������Ծ��ȥ��������裩��\n",
		"stream" : "СϪ������ˮ�峺�������Ծ��ȥ��������裩��\n",
		"tree" : (: tree :),
		"������" : (: tree :),
		"vine" : (: vine :),
		"����" : (: vine :),
	]));   
	set("leaf_amount", 10);
	set("baiguo_amount", 5);
	set("have_snake", 1);
	set("have_herb", 1);
    set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",-50);
	set("coor/z",30);
	setup();
}

void init(){
	add_action("do_dash", "dash");
}

string vine(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 4) {
		tell_object(me, "���ٽ��������������ϣ�����ӵ����һ������ˡ�\n");
	} else {
		tell_object(me, "���ٽ��������������ϣ�����ӵ����һ������ˡ�\n");
		if(me->query_skill("herb", 1) >=100 && query("have_herb")) {
			tell_object(me, "��ע�⵽�����Ե�һ�ò����۵�С�ݡ�������룩\n");
			add_action("do_pick", "pick");
		}
		if(!random(10) && query("have_snake") && (i == 2 || i ==3)){
			tell_object(me, "���ƺ�����һ���Ϻ�ɫ�Ĺ����䶯��һ�£����ֺ����Լ��ۻ���\n");
			call_out("snake_come", 10, me);
		}
	}
	return "";
}

void snake_come(object me){
	object obj;
	if(!interactive(me) || environment(me) != this_object()){
		return;
	}
	message_vision(MAG"\nһ��ȫ���Ϻ�ɫ��С�ߴӹ����������˳�����\n"NOR, me);
	obj = new(__DIR__"npc/snake");
	obj -> move(this_object());
	set("have_snake", 0);
	call_out("snake_leave", 10);
}

void snake_leave(){
	object obj;
	if(obj = present("little snake", this_object())){
		message_vision("С�߻�����������С�\n", obj);
		set("have_snake", 1);
		destruct(obj);
	}
}

string tree(){
	object me;
	int i;
	me = this_player();
	i = NATURE_D->get_season();
	if(i == 1 || i == 2){
		tell_object(me, "����ɫ�����ŵ�ס����գ����ε���Ҷ��΢����ҡҷ������롡����棩��\n");
		add_action("do_pick", "pick");
	} else if(i == 3){
		if(query("baiguo_amount") > 0) {
			tell_object(me, "�����Ľ������Ų����Ŀ�⣬����е�׺�Ű�ɫ�Ĺ�ʵ������롡���������\n");
			add_action("do_pick", "pick");
		} else {
			tell_object(me, "�����Ľ������Ų����Ŀ�⡣\n");
		}
	} else if(i == 4){
		tell_object(me, "��ͺ������͸������ɫ���Ե�򰾢������\n");
	}
	return "";
}

int do_pick(string arg){
	object me, obj;
	int i;
	me = this_player();
	if(!arg || (arg != "leaf" && arg != "baiguo" && arg != "��ʵ" && arg != "Ҷ"
			&& arg != "grass" && arg != "С��")){
		return 0;
	}
	i = NATURE_D->get_season();
	
	if((i == 1 || i == 2) && query("leaf_amount") > 0 && (arg == "leaf" || arg == "Ҷ")){
		message_vision("$N��Ŵ�����ժ��һƬҶ�ӡ�\n", me);
		obj = new(__DIR__"obj/leaf"); 
		if(objectp(obj)){
			obj->move(me);
		}
		add("leaf_amount", -1);
		return 1;
	} else if(i == 3 && query("baiguo_amount") > 0 && (arg == "baiguo" || arg == "��ʵ")) {
		message_vision("$N̽��ժ��һ�Ű�ɫ�Ĺ�ʵ��\n", me);
		obj = new(__DIR__"obj/ginkgo");
		if(objectp(obj)){
			obj->move(me);
		}
		add("baiguo_amount", -1);	
		return 1;
	}
	if(query("have_herb") > 0 && (arg == "grass" || arg == "С��")) {
		message_vision("$N̽�ְ��¿ú������۵�С�ݡ�\n", me);
		obj = new(__DIR__"obj/herb");
		if(objectp(obj)){
			obj->move(me);
		}
		add("have_herb", -1);
		return 1;
	}
	tell_object(me, "�Ѿ���ժ���ˡ�\n");
	return 1;
}

int do_dash(){
	object me, room;
	
	me = this_player();
	message_vision("$N�˺���������Ȼ�ӿ�Ų�һ��������ӯ��Խ����СϪ��\n", me);
	room = find_object(__DIR__"xiaodao1");
	if(!objectp(room)){
		room = load_object(__DIR__"xiaodao1");
	}
	me->move(room);
	message("vision", me->name() + "��СϪ������һ��Ծ�˹�����\n", environment(me), me);
	return 1;
}

void reset(){
	::reset();
	set("baiguo_amount", 5);
	set("leaf_amount", 10);
	set("have_snake", 1);
	set("have_herb", 1);
}
