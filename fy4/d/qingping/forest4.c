#include <ansi.h>
inherit ROOM;
string stone();
void create()
{
        set("short", "������");
        set("long", @LONG
������һƬ��ֵ����֣���ľ�����Ƿǳ����ܼ����������������͸����ľ��
ҫ������Ȼ�������Եĸо���һ������Ľӽ���������Ϣ���ּ�û���κο��Ա���
�ĵ�·���ߵ������Ѿ������ֵľ�ͷ���ͱڶ�������Ҳû�г�·��
LONG
        );
	set("item_desc", ([
		"stone" : (: stone :),
		"ɽʯ" : (: stone :),
		"�ͱ�" : (: stone :),
	]));
	
	set("exits", ([ /* sizeof() == 4 */
	  	 "west" : __DIR__"path1",	
   ]));
   
	set("outdoors","qingping");
	set("coor/x",50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init(){

    add_action("do_push", "push");
}

string stone(){
	object me;
	me = this_player();
	if(me->query("class") == "shenshui"){
		tell_object(me, "�ͱ��ϲ����˸�ʽ������ɽʯ������һ��������ơ��������裩\n");
	} else {
		tell_object(me, "�ͱ��ϲ����˸�ʽ������ɽʯ��\n");
	}
	return "";
}

int do_push(string arg){
	object me, room;
	
	me = this_player();
	if(!arg || (arg != "stone" && arg != "ɽʯ" && arg!="�ͱ�")){
		return notify_fail("��Ҫ����ʲô��\n");
	}
	if(me->query("class") == "shenshui"){
		tell_object(me, "��������ɽʯ������һ�ơ�\n");
		tell_object(me, CYN"ɽʯ���ѿ���һ���꣬�������ȥ��ɽʯ����������£��\n\n"NOR);
		message("vision", YEL"����Լ����" + me->name()+"����Ӱ��ʯ����һ������ʧ�����ˡ�\n"NOR, 
				environment(me), me);
		room = find_object(AREA_SHENSHUI"huoyan");
		if(!objectp(room)){
			room = load_object(AREA_SHENSHUI"huoyan");
		}
		me->move(room);
	} else {
		tell_object(me, "����������Ҳ���÷���ɽʯ��˿������\n");
	}
	return 1;
}

