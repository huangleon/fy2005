#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
̫��ɽ�������ԣ����������족��������֮�ƣ���������̫��ɽ�����壬����
���ƣ��������£����������չ�Ҫ����˳����ȥ���Ǵ�������Ļ�ɽ������������
�Աܹ��ڴˡ�
LONG
        );
        set("exits", ([ 
  		"southdown" : __DIR__"laomu",
	]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"npc/xian2" : 1,
        ]) );
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",10);
	setup();

}
