#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"������"NOR);
	set("long", @LONG
���С�������������������ᣣ���¥�������������ƵĹ�����ȼ����
��ɫ�Ĺ�â��ľ�ذ����ò���ɫ�Ĳ�֪ʲô���Ź��ܵ�������·����Χ������
��ػ�������Ѫ����ģ�����ë���Ȼ��
LONG
        );
	set("exits",([
		"west" : __DIR__"56",
		"south" : __DIR__"65",
	]) );

	set("objects", ([
	__DIR__"npc/mei" : 1,
					]) );

  	set("coor/x",60);
	set("coor/y",60);
	set("coor/z",0);
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
