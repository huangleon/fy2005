// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "�����");
    set("long", @LONG
����һ�����ͨ��ССľ�ݣ����ŵ��ӣ�һ��С�����Աߵ���ױ̨��Եб
б����������ɽҰ���洦�ɼ��ĵ���ɫ�����ǻ����ܼ򵥵İ��裬ȴ��������
��״�����ʸо���Ψһ����ͻأ�ı�������֮��������һ���Ҷ��������
��ɱ���������֣��ʷ����м��ᣬ���ǳ���Ů��֮�֡�
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([
	
	]) );
	set("exits",([
  		"east" : "bridge",
	]) );
	set("area","cyan");


	set("coor/x",-60);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}



void init() {
	::init();
	add_action("do_pick","pick");
	add_action("do_get","get");
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


