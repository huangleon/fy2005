// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
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
	__DIR__"npc/xue":1,
	__DIR__"obj/tree":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "path7",
  		"northdown" : "peak8",
	]) );

	set("outdoors", "cyan");
	set("area","cyan3");

	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",90);
	setup();
}


void init()
{
	::init();
	add_action("do_climb","climb");
}	

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="��")) 
		return notify_fail("������ʲô��\n");;

	room=find_object("peak14");
	if (!objectp(room)) room=load_object("peak14");
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


