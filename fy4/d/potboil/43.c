#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"ǧ����"NOR);
	set("long", @LONG
ǧ�����ɨ�ú�Ǭ��������������һ����Ⱦ�����߸���һ��С�ţ����Ϲ�
������������ϵ������������б�գ�������Ѥ��΢����Ϯ���������������ҡ
�����������졣����û��һ˿ɱ����ȴ��ħ��ÿһ���㸲���µ�ָ��ǣ������
�ġ�
LONG
        );
	set("exits",([
		"west" : __DIR__"33",
		"east" : __DIR__"53",
		"southdown" : __DIR__"42",
	]) );

	set("objects", ([
	__DIR__"npc/huo" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",30);
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
