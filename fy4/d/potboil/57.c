#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"������"NOR);
	set("long", @LONG
СС�����𾲾�������������������������������ɽ���ء���˵ħ��
�е�ÿһ�������ڷֿ�ʱ�����������һ��������������գ����ϰ�������
����ʱ��ۣ�ȴ�����ⲻ���ٶ����롣
LONG
        );
	set("exits",([
  		"northup" : __DIR__"58",
  		"southdown" : __DIR__"56",
  		"westup" : __DIR__"47",
//  		"east" : __DIR__"57",
	]) );

	set("objects", ([
	__DIR__"npc/gu" : 1,
	__DIR__"npc/tang" : 1,
					]) );

	set("coor/x",50);
	set("coor/y",70);
	set("coor/z",10);
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
