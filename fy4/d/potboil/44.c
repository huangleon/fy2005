#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"������"NOR);
	set("long", @LONG
�������Ǽ���߰�ǽ�ı���С�ݣ������������࣬��ǰ����ɢ�ң�ٲȻ��
һ��¶��С�ƹݾ�ɫ�����������ħ����һֱ����һ�������ĵĹ�����������
�ݸߵͣ��������ľƹ�������С�ݵ����ˣ��ڱ����⻹Ҫ�����ƹ���̵�
��������
LONG
        );
	set("exits",([
		"westdown" : __DIR__"34",
	]) );

	set("objects", ([
	__DIR__"npc/long" : 1,
	__DIR__"npc/meng" : 1,
					]) );

  	set("coor/x",40);
	set("coor/y",40);
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
