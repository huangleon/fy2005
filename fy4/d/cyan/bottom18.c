// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{

	set("short", RED"�̨ⷨ"NOR);
    set("long", @LONG
��̴ľ����������þ�ʯ�޵����������ķ̨ⷨ�ϣ����������Ŷ�����
��ɫ�ķ�ֽ����������Ҳ�������˵غ����������̨ⷨ�������Ȼ����һ�˴�
�������㰸һ�����㰸�Ϲ�Ʒ�뱸������������Ҫ��һ��������Ȼ����ʿȴ
���ڴ˴���ֻ��һ�������ı�Ӱ����һ�������ϣ��ᴵ�������˵����ɡ�
LONG
NOR
        );
	set("objects", ([
	__DIR__"npc/du":1,
	]));
	set("no_fly",1);
	set("item_desc", ([


	]) );
	set("exits",([
		"down" : __DIR__"maze/exit",
	]) );

	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",1000);
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


