// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;

void create()
{
	object fishbone;
	set("short", "��ɽ��");
        set("long", @LONG
���ȵľ�����һȦ���߰�ǽ����ǽ��һ�Ƕѻ��ų�����ľ�壬һ�Ȳ����
ľ�ſ���ǽ�ϣ�������ǽ���⡣�����ˣ������Ѿ���Ⱥ������ߵ�һ��ɽ
ͷ�������İ�ѩ�����������ļ��紺�Ľ���εΪ��ۡ�
LONG
        );
	set("objects", ([
		__DIR__"npc/leng2" : 1,
		__DIR__"obj/muban" : 1,
	]));
	set("exits",([
  		"east" : __DIR__"nanzoulang",
  		"northup" : __DIR__"huxian",
	]) );

	set("indoors", "xiangsi");

	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",20);
	setup();
    replace_program(ROOM);
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
