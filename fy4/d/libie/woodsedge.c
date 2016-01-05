// Room: woodsedge.c --- by MapMaker
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���־�ͷ");

	set("long", @LONG
������ҹգ��ߵ���С���ֵľ�ͷ��������СϪ�������ð�˳�������������
���ţ���������Ȼ������̫�������Ҽ仹��������������£�һ��ֻ�ı�������С
Ұ�ú���������㡣·�߿յ��м�������������΢�⣬��Զ���ƺ���һ����ª����
�ɵ�Сľ�ݡ�
LONG);

	//{{ --- by MapMaker
	set("type","forest");
	set("exits",([
	"south":__DIR__"woods1",
	"north":__DIR__"cabin",
	]) );
	
        set("outdoors", "libie");
	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",0);
	//}}

	setup();

}

void init()
{
 	add_action("do_look","look");
 	add_action("do_dig","dig");
}

int do_look(string arg)
{
	if(arg!="����" && arg!="soil" && arg != "huangtu") {
		return 0;
	}
	tell_object(this_player(),"һ������������˶��ٺ���Ӣ�ۡ���dig?��\n");
	return 1;
}   
	
int do_dig(string arg)
{
	object me,delve;
	me=this_player();
	
	if(arg!="����" && arg!="soil" && arg != "huangtu") 
		return notify_fail("��Ҫ��ʲô��\n");
	delve = present("delve",this_object());
	if(objectp(delve)&&(!userp(delve)))
		return notify_fail("�����Ѿ��ں��ˡ�\n");
	if(me->query("kee")<100)
		return notify_fail("��������Ѫ̫�٣������ڿӡ�\n");
	me->add("kee",-100);
	message_vision(YEL"$N���˺ô���������������һ�����ӡ�\n"NOR,me);
	delve=new(__DIR__"obj/delve");
	delve->move(this_object());
	return 1;
}

int	valid_leave(object who, string dir)
{
	object room;
	
	if (dir != "north")	return 1;
	
	room = find_object(__DIR__"cabin");
	if (!objectp(room))	room = load_object(__DIR__"cabin");
	
	if (room->usr_in())
		return notify_fail("ľ���к����Ѿ�������˵�����ȿ�����˵�ɡ�\n");
	
	return 1;
}