#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"���ڽ�"NOR);
	set("long", @LONG
���ڼ�����ɰ���˽׶�ȥ��ɽ�����еģ��ƹݣ������ᣬ�ճ�����������
ʮ�����֣�����ĥƽ�����ҽװ塢¶���˽��³�����״����ɰ�����Ǳ����Ϊ
���ڽס�
LONG
        );
	set("exits",([
  		"north" : __DIR__"35",
		"eastup" : __DIR__"44",
		"south" : __DIR__"33",
	]) );

	set("objects", ([
	__DIR__"npc/san1" : 1,
	__DIR__"npc/san2" : 1,
					]) );

  	set("coor/x",30);
	set("coor/y",40);
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
