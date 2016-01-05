#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�˱�һ��֬������,ľ���ϵ���һ�����򣬺�������һ��������һֻ��ױ���ӡ�
���з���һ�Ŵ󴲣�͸��ɴ�ʿ�ȥ�����������廨�Ľ�������ͷ�������������
��һ��Ϸˮԧ�죬��ɫ���ã����������ǰ���������廨��Ь��һ���еģ�һ��
Ů�ģ����Ŷ��á�
LONG
        );
        set("exits", ([ 
		"east": __DIR__"redhouse0",
	]));
        set("item_desc", ([
		"bed": 	"��֨֨�¸µ�ҡ���ţ��������ƺ��������䶯��
���ǲ���Ҫ��ȥ����������裩��һ���أ�\n",
		"��": 	"��֨֨�¸µ�ҡ���ţ��������ƺ��������䶯��
���ǲ���Ҫ��ȥ����������裩��һ���أ�\n",
		"mirror":	"����ž��������գ������Լ��ڷ�����������һ�ꡣ\n",
		"��":		"����ž��������գ������Լ��ڷ�����������һ�ꡣ\n",
		"����":		"�������ý����أ������ܴ򿪡�\n",
	 ]));
        set("objects", ([
        	
        ]));
	set("coor/x",-90);
	set("coor/y",-50);
	set("coor/z",10);
	set("map","taiping");
	set("yuanwai",1);
	setup();
}


void 	init(){
	add_action("do_approach","approach");
}


int	do_approach(string arg){
	object piaoke,me;
	me=this_player();
	piaoke=present("piaoke",this_object());
	if (piaoke && !userp(piaoke))
		return notify_fail("�Ϲ���˵������ôû��û�صģ�����ȥ����\n");
	if (!arg || (arg!="bed" && arg!="��"))
		return notify_fail("��Ҫ�߽����\n");
	message_vision(YEL"$N�߽��󴲣�̽ͷ̽�Ե������п�ȥ��\n",me);
	if (!query("yuanwai"))
		tell_object(me,"����һ��Ů��˯�����죬������¶��һ˫������С�֡�\n");
	
	message_vision(HIR"һ����У�һ��ŭ�ȣ���������������Ĵ󺺣�\n"NOR,me);
	piaoke=new(__DIR__"npc/piaoke2");
	piaoke->move(this_object());
	if (me->query("gender")=="Ů��")
		message_vision("�Ϲ��׺�Ȼ����һЦ˵������ô���������Ҳ�����ү����\n",me);
	else message_vision("�Ϲ���˵����С�ӣ����˴�ү�����£������ȥ����\n",me);
	return 1;
}



