// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "���ƶ�");
    set("long", @LONG
���ƶ������ʯ��ᾡ���ľ�дС��±ڶ��ͣ����ϴ˴����ѿɽ�������ϼ
ɽ������һ�����ɣ���ĿԶ�������ɼ������ߵĺ��ɳǱ����Լ���Զ���ķ���
�ǣ�ֻ�Ǵ�ʱ�ķ��Ƴǿ���ȥ�������ã�����������������Ļƽ����಻����
Ӱ��
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/rock2":1,
	__DIR__"obj/woods":1,
	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"southdown" : "peak1",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",80);
	setup();
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


