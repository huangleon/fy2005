// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit __DIR__"bush_base.c";

void create()
{
        set("short", "�����Ե");
        set("long", @LONG
���������ܲ�����ɫ����������ǰ�߾������������������򣭣�[33m������[32m������
���������ܲ������޳�û��������˲����ʱ�������������صĶ���Ȫ����δ�߽���
�������˹�������û�������ڹ������һ��Ҳ�Ǽ��ѡ������ഫ�����������
һ��������ÿ��ҹ���˾�ʱ�����������ĺ�����
LONG
        );
        set("exits", ([ 
  		"north" : AREA_CHENXIANG"cxs8",
	]));

        set("item_desc", ([
                "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
                "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n"

        ]) );

        set("outdoors", "zhaoze");
        
        set("route","south");
        set("route_room",__DIR__"zhaoze1");
        
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_cut", "chop");
        add_action("do_listen","listen");
}

void reset()
{
	::reset();
	delete("exits/"+query("route"));
}


int do_listen(){
	object dragon, room;
	room = find_object(__DIR__"center");
	if (!room)
		room = load_object(__DIR__"center");
		
	if (dragon = present("red dragon",room))
	{
		tell_object(this_player(),HIR"\n�������Լ�����͵͵ĺ������ƺ��Ǿ��޵�����֮����\n"NOR);
	}else
		tell_object(this_player(),HIR"\n������һƬ������ż���м���������ˮ������\n"NOR);
	return 1;
}


