inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"����"NOR);

	set("long", @LONG
�����Ƕ���ֵ�ľ�ݣ������ھ޴�Ĺ������ϡ�ľ�ݵ����ܶ������ˣ�������
���������������¹������ֹ���ϸ���������ֹ���ϸ�������������ౣ�ľ��
���������бڵ�ľ�嶼�Ѻܳ¾ɣ��е������Ѹ��ѣ��������Ƕ���������ݣ���
��ֻ��һ�ŵͰ���ľ����һ���޴�Ļ����һ���ˡ�
LONG);

	set("type","street");
	set("exits",([
		"down":__DIR__"timetree",
	]) );
        set("indoors", "guanwai");

	set("objects", ([
                __DIR__"npc/xiaofang" : 1,
	]) ); 
	set("coor/x",-10);
	set("coor/y",-60);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
