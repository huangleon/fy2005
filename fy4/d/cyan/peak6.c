// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "��ŭ��");
    set("long", @LONG
��ŭ�屾�Ǵ�ɽ�ڶ��߷壬ȴ���뼫��֮���������������Ե�Զ�����¡�
�Ӵ˴���ȥ��ֻ������һ�°εض���״��������������Ħ��񷣬�������룬
��������һ������������������ɾ���������ƽ�����������ؼ���ƣ����ܴ�
Ϣ��
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/waiter":1,
	__DIR__"obj/tree":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : __DIR__"path7",
  		"northdown" : __DIR__"peak8",
	]) );

	set("outdoors", "cyan");

	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",90);
	setup();
}


void 	init()
{
	add_action("do_climb","climb");
}	

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="��")) 
		return notify_fail("������ʲô��\n");;

	room=find_object(__DIR__"peak14");
	if (!objectp(room)) room=load_object(__DIR__"peak14");
	tell_object(me,"���ֽŲ��ã����ݵؼ�����������ȥ��\n");
	tell_room(room, this_player()->name() + "����������������\n");
	this_player()->move(room);
	return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


