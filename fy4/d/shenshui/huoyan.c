// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
inherit ROOM;
string stone();
void create()
{
        set("short", "���Ҷ���");
        set("long", @LONG
ԭ��������ˮ���ǽ�����ɽ��֮�У��������̵ľ޴�����֪�����ߵ�������
ǰ����һ����ͬ�ľ�ɫ����Զ��һ����������ɢ����������������һ������������
���ϱߵ�ʯ����ԶԶ��Ҳ�м��䷿�ݣ�ֻ���쳣�Ļ谵������̫��������Ե�
ʯ�������Կɼ��˹��ĺۼ���
LONG
        );
        set("exits", ([ 
   "down" : __DIR__"migong2",
  "northup" : __DIR__"gong",
  "southup" : __DIR__"ruanhong",
]));
	set("item_desc", ([
		"stone" : (: stone :),
		"ʯ��" : (: stone :),
		"ɽʯ" : (: stone :),
	]));
   set("objects", ([ 
      __DIR__"npc/jian": 1,
   ]) );
	set("indoors","shenshui");
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}

void init(){
	add_action("do_push", "push");
}


string stone(){
	object me;
	me = this_player();
	if(me->query("class") == "shenshui"){
		tell_object(me, "ʯ���ϲ������˹���̵ĺۼ�������һ��ʯͷ������ơ��������裩\n");
	} else {
		tell_object(me, "ʯ���ϲ������˹���̵ĺۼ���\n");
	}
	return "";
}


int do_push(string arg){
	object me, room, jian;
	
	me = this_player();
	if(!arg || (arg != "stone" && arg != "ɽʯ" && arg!= "ʯ��")){
		return notify_fail("��Ҫ����ʲô��\n");
	}
	if(me->query("class") == "shenshui"){
		tell_object(me, "��������ɽʯ������һ�ơ�\n");
		tell_object(me, CYN"ɽʯ���ѿ���һ���꣬�������ȥ��ɽʯ����������£��\n\n"NOR);
		message("vision", YEL"����Լ����" + me->name()+"����Ӱ��ʯ����һ������ʧ�����ˡ�\n"NOR, 
				environment(me), me);
		room = find_object(AREA_QINGPING"forest4");
		if(!objectp(room)){
			room = load_object(AREA_QINGPING"forest4");
		}
		me->move(room);
	} else if(jian = present("jian er", this_object())){
		message_vision("$N�ȵ���������������ڸ�ʲô����\n", jian);
	} else {
		tell_object(me, "����������Ҳ���÷���ɽʯ��˿������\n");
	}
	return 1;
}
