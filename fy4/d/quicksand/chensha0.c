#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��ˮ��ɳ");
	set("long", @LONG
��ͺ��������˿մ�����ͣ���³�����Χ��Ȼ������������ɳ���������޴���
�������������������������Χ��ɳ��һ����ͣ�س���ȥ������ȥ���������ܵ���
ɳ��ͣ�ļ�������������һ�ֽ�����Ϣ�ĸо��� 
LONG
	);
	set("exits", ([ 
  		"down" : __DIR__"sandriver",
	]));

	set("indoors", "quicksand");

set("coor/x",-1060);
	set("coor/y",-10);
	set("coor/z",-30);
	setup();
}
