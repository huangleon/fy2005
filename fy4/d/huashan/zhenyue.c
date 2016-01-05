#include <ansi.h>
inherit ROOM;
string tree();
void create() 
{
        set("short", "������");
        set("long", @LONG
�˹������嶫´���������¾��ƣ��������ء���ǰ����ƽ̹������������죬
���ɹ�ľ������գ��滨��ݶ಻ʤ������ǰһ�ùŰ�����ƽ���ȸǣ��������ܳ�
�ٳߣ��Ų�֪�ꡣ�������д�˵������ǧҶ�������񾮡�
LONG
        );
    set("exits", ([ 
	    "northwest" : __DIR__"lianhua",
	]));
	set("item_desc", ([
		"tree" : (: tree :),
		"�Ű�" : (: tree :),
	]));   
	set("objects", ([
		__DIR__"obj/vine" : 1,
		__DIR__"npc/youke" : 1,
	]));   
    set("outdoors", "huashan");
	set("coor/x",-72);
	set("coor/y",-64);
	set("coor/z",40);
	setup();
}

void init_scenery()
{
	set("amber", 1);    
}

string tree(){
	object me, room;
	me = this_player();
	if(NATURE_D->is_day_time()){
		tell_object(me, "�Ű�����ڱ������գ��ֲڵ������Ϲ��е���ɫ������֬��\n");
	} else {
		if(!random(10)){
			room = find_object(__DIR__"lianhua");
			tell_object(me, HIY"�㿴���Ű�������΢΢�Ļƹ�һ�����š�\n"NOR);
			message("vision", HIY"ֻ����������������һ��΢΢�Ļƹ⡣\n"NOR, room);
			add_action("do_search", "search");
		} else {
			tell_object(me, "�Ű�����ڱ������գ��ڻ谵��ҹ������ʲôҲ�����塣\n");
		}
	}
	return "";
}

int do_search(){
	object me, amber;
	me = this_player();
	if(me->is_busy() || me->is_fighting()){
		return notify_fail("������æ��\n");
	}
	message_vision("$N��ϸ���ڹŰ�����Ѱ��\n", me);
	if(query("amber") && !random(10)) {
		tell_object(me, "���ڹŰ��Կ���һ�ž�Ө��͸�����꣬�����ʰ��������\n");
		message("vision", me->name() + "��������һ���������뻳�\n", environment(me), me);
		amber = new(__DIR__"obj/amber");
		amber->move(me);
		add("amber", -1);
	} else {
		tell_object(me, "��ʲôҲû�з��֡�\n");
	}
	return 1;
}
