#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"����¥"NOR);
	set("long", @LONG
����ħ�̵Ľ�������֮�أ�Ҳ�����ֵ������Ϊ���صĵط�������������
��Զ��һ��ɱ�����˵��䵶��һ�����޶��������֣�һ��������ɷ�ĵ�����С
¥һҹ�����꣬�����δ����ӻ���
LONG
        );
	set("exits",([
		"eastdown" : __DIR__"25",
	]) );

/*	set("objects", ([
	__DIR__"npc/wall" : 1,
					]) );*/

  	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",20);
	set("indoors", "potboil");
	setup();
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
