// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "īȪ");
    set("long", @LONG
�����˴������ǹȵ׾�����������ʯ��ѩ���������ȵ����µ�ˮ��������
��һ����Ȼ��ɵ�ʯ�Ӷ������㼯���峺͸����ˮ��Ȫ�׵Ĵ��ʯ���Գ���ī
֮ɫ��Ȫ�߳����˺ڱ����˵�ʯ����
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/herb":2,
	__DIR__"obj/rock":1,
	]));
	set("item_desc", ([
		"��ʯ":	"�����ʯ����͸���˹����õĺۼ���\n",
		"ʯ��":	"һ����ʯ����ʯ���г������ͷ�������\n",
		"���ʯ":	"Ȫ����ʯ���Ҵ��Һڣ�ûʲô����Ү��\n",
	]) );

	
    set("resource/water", 1);
    set("liquid/container", "ʯ��");   
	set("liquid/name","ʯ��");
	
	set("exits",([
  		"westup" : __DIR__"pathb",
  		"northup" : __DIR__"peak13",
	]) );

    create_door("northup","rock","��ʯ","southdown",DOOR_CLOSED);

	set("outdoors", "cyan");

	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",40);
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


