/* Copyright (C) 1998 Apstone, Inc. */
#include <ansi.h>
#define FATEMARK "����A/��ɽ_����"

inherit ROOM;
void create()
{
    set("short", "���");
    set("long", @LONG
��ر��������壬Ϊ��ɽ�ڶ��߷壬ɽ�������ѩ����ʹ��ʢ����������ˮ
���¶�Ҳ�൱�͡������εĺ�������󣬵���ˮ��Σ����������ģ����˾ͽ��˸�
�����Ե�ϲ����������ܵ�ɽ���ϣ��������ɼ�֣���ɼ���籦����ͦ�Ρ����룬
�������ơ�����ѩ��ʹ���ͦ�ε������ֵ�ӳ���峺�ĺ�ˮ�У���������ص�����
�ľ�ɫ��
LONG
    );
    set("long_night", @LONG
��ر��������壬Ϊ��ɽ�ڶ��߷壬ɽ�������ѩ����ˮ���Ǻ���̹ǡ���
���εĺ����������ҹ��΢΢���ӳ���£����ǵ�㣬��Ө����������ܵ�ɽ
���ϣ�ҹᰳ��𣬳�����ɽ��������������������һ�Դ���ľ�ϡ�Զ��ѩ��ӳ��
�ǹ��ں���΢΢����������һ��������õĸо���
LONG
    );

    	set("exits", ([
        "southdown" : __DIR__"tianshan",
    	]));

    	set("outdoors", "xinjiang");
    	set("resource/water",1);
    	set("liquid/name","�����ĺ�ˮ");
    	set("liquid/container", "���");
	set("coor/x",-10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(10) && !ob->query(FATEMARK)) {
		ob->set(FATEMARK, num);
		tell_object(ob,HIG"\n�ڿ������ǵ�һ˲�䣬��ĬĬ�����������˸�Ը��\n"NOR);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void init_scenery()
{
        remove_call_out("falling_star");
        call_out("falling_star",1);
}


void falling_star(object me) {
    	object room, *ppls;
    	function f=(:add_fate_mark:);
    	room = this_object();
    	message("vision", HIC"\n���Ǵ�Զ���ӹ����֡���������\n"NOR, room);
    	message("vision", HIW"           �ں���ĵ�Ӱ������һ�����ò�������Թ�â��\n"NOR, room);
      	ppls=filter_array(all_inventory(room),(:userp($1) && interactive($1) && !query(FATEMARK):));
    	if(sizeof(ppls))
		map_array(ppls,f);
   
}

