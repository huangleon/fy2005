// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ɽ·һת����ǰ����һ��Сɽ�꣬���ܲ�ľïʢ�����߲�ʱ���������������
һ��СϪ�����������������̧ͷ��ǰ����һ���ٲ���ɽ�����£�������й����ɽ
֮ʱ�����о�ʯ��ɽ��б����������԰�;һ��Ϊ�����γ�һ�����֣�����������
����������ֵ�����ֱ�����¡�
LONG
        );
  	set("exits", ([ 
 		"north" : __DIR__"qingluan",
		"westup" : __DIR__"chayuan",
	]));
        set("objects", ([
                __DIR__"npc/xiangke" : 3,
       ]) );
	set("resource/water",1);
	set("liquid/name","������ˮ");
    set("outdoors", "huangshan");
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
