#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"��ޣԷ"NOR);
	set("long", @LONG
��ޣԷϪ�ػ��ƣ�ˮ�����磬�Թ�ס�ı��������ְλ���ߵ�һ��Ů�ӣ�
Է��������ʯ̨һ����ʯ�����ɣ��������Ϊ���£���̵�ÿһ�δ������
�ڴ˴����С�
LONG
        );
	set("exits",([
  		"north" : __DIR__"36",
		"westup" : __DIR__"25",
		"south" : __DIR__"34",
	]) );

	set("objects", ([
	__DIR__"npc/ji" : 1,
	__DIR__"npc/fu" : 1,
					]) );

  	set("coor/x",30);
	set("coor/y",50);
	set("coor/z",0);
	set("outdoors", "potboil");
	setup();
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
